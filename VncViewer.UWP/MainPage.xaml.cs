using Newtonsoft.Json;
using System;
using System.Collections.Generic;
using System.Diagnostics;
using System.Drawing;
using System.IO;
using System.Linq;
using System.Net;
using System.Net.Sockets;
using System.Runtime.InteropServices.WindowsRuntime;
using System.Text;
using System.Threading;
using System.Threading.Tasks;
using VncViewer.Vnc;
using Windows.Foundation;
using Windows.Foundation.Collections;
using Windows.Gaming.Input;
using Windows.Storage;
using Windows.UI.Core;
using Windows.UI.Xaml;
using Windows.UI.Xaml.Controls;
using Windows.UI.Xaml.Controls.Primitives;
using Windows.UI.Xaml.Data;
using Windows.UI.Xaml.Input;
using Windows.UI.Xaml.Media;
using Windows.UI.Xaml.Media.Imaging;
using Windows.UI.Xaml.Navigation;
using Brush = Windows.UI.Xaml.Media.Brush;

// The Blank Page item template is documented at https://go.microsoft.com/fwlink/?LinkId=402352&clcid=0x409

namespace VncViewer.UWP
{    

    /// <summary>
    /// An empty page that can be used on its own or navigated to within a Frame.
    /// </summary>
    public sealed partial class MainPage : Page
    {
        private VncClient _VncClient;
        private WriteableBitmap _VncImage;
        private TcpClient _TcpClient;


        private DispatcherTimer updateTimer;

        private Dictionary<Gamepad, GamepadReading> gamepads;

        private bool Ready = false;
        private bool WaitingForServer = true;
        private bool ReconnectEnabled = false;
        private bool StatusRefresh = false;

        public MainPage()
        {
            this.InitializeComponent();

            Gamepad.GamepadAdded += Gamepad_GamepadAdded;
            Gamepad.GamepadRemoved += Gamepad_GamepadRemoved;

            gamepads = new Dictionary<Gamepad, GamepadReading>();
            foreach (Gamepad g in Gamepad.Gamepads)
            {
                gamepads.Add(g, g.GetCurrentReading());
            }

            updateTimer = new DispatcherTimer();
            updateTimer.Tick += Timer_Tick;
            updateTimer.Interval = new TimeSpan(0, 0, 0, 0, 32);

            SystemNavigationManager.GetForCurrentView().BackRequested += MainPage_BackRequested;
        }

        private void MainPage_BackRequested(object sender, BackRequestedEventArgs e)
        {
            e.Handled = true;
        }

        // GROSS!
        private static readonly Dictionary<GamepadButtons, uint>[] buttonBindings =
        {
            new Dictionary<GamepadButtons, uint> {
                { GamepadButtons.A, Keysyms.XK_A },
                { GamepadButtons.B, Keysyms.XK_B },
                { GamepadButtons.X, Keysyms.XK_X },
                { GamepadButtons.Y, Keysyms.XK_Y },
                { GamepadButtons.DPadLeft, Keysyms.XK_KP_Left },
                { GamepadButtons.DPadRight, Keysyms.XK_KP_Right },
                { GamepadButtons.DPadUp, Keysyms.XK_KP_Up },
                { GamepadButtons.DPadDown, Keysyms.XK_KP_Down },
                { GamepadButtons.LeftShoulder, Keysyms.XK_L },
                { GamepadButtons.RightShoulder, Keysyms.XK_R },
                { GamepadButtons.View, Keysyms.XK_1 },
                { GamepadButtons.Menu, Keysyms.XK_2 },
                { GamepadButtons.RightThumbstick, Keysyms.XK_asciitilde}
            },
            new Dictionary<GamepadButtons, uint>
            {
                { GamepadButtons.A, Keysyms.XK_C },
                { GamepadButtons.B, Keysyms.XK_D },
                { GamepadButtons.X, Keysyms.XK_V },
                { GamepadButtons.Y, Keysyms.XK_W },
                { GamepadButtons.DPadLeft, Keysyms.XK_5 },
                { GamepadButtons.DPadRight, Keysyms.XK_6 },
                { GamepadButtons.DPadUp, Keysyms.XK_7 },
                { GamepadButtons.DPadDown, Keysyms.XK_8 },
                { GamepadButtons.LeftShoulder, Keysyms.XK_N },
                { GamepadButtons.RightShoulder, Keysyms.XK_S },
                { GamepadButtons.View, Keysyms.XK_3 },
                { GamepadButtons.Menu, Keysyms.XK_4 },
                { GamepadButtons.RightThumbstick, Keysyms.XK_asciitilde }
            }
        };

        private void HandleBinding(GamepadReading reading, GamepadButtons button, uint keysym, Gamepad g)
        {
            try
            {
                if (reading.Buttons.HasFlag(button))
                    _VncClient.SendKey(keysym, true);
                else if (!reading.Buttons.HasFlag(button) && gamepads[g].Buttons.HasFlag(button))
                {
                    _VncClient.RequestScreenUpdate();
                    _VncClient.SendKey(keysym, false);
                }
            } 
            catch (Exception ex)
            {
                ReconnectEnabled = true;
                StatusRefresh = false;
                Ready = false;
                StatusText.Text = "SHIT!";
            }
        }

        int ticks = 0;
        long total_ticks = 0;
        private async void Timer_Tick(object sender, object e)
        {
            ticks++;
            total_ticks++;
            // Check controls
            foreach (Gamepad g in gamepads.Keys.ToList())
            {
                int i = gamepads.Keys.ToList().IndexOf(g);
                if (i > (buttonBindings.Length - 1))
                    continue;

                var currentReading = g.GetCurrentReading();

                if (currentReading.Buttons.Equals(gamepads[g].Buttons))
                    continue;

                if (ReconnectEnabled && ticks >= 240)
                    DoVncConnection();

                if (!Ready && !WaitingForServer)
                {
                    if (currentReading.Buttons.HasFlag(GamepadButtons.A))
                    {
                        Ready = true;
                        DoVncConnection();
                    }
                    continue;
                }

                if (Ready)
                    foreach (var button in buttonBindings[i].Keys) 
                        HandleBinding(currentReading, button, buttonBindings[i][button], g);

                gamepads[g] = currentReading;
            }


            // Clean status text when game is running
            if (StatusRefresh && ticks >= 120) // every two seconds(ish)
            {
                StatusText.Text = "";
                ticks = 0;
            }

            if (Ready && _VncImage != null)
            {
                _VncImage.Invalidate();
                VncImage.Source = _VncImage;
            }
        }

        private void Gamepad_GamepadAdded(object sender, Gamepad e)
        {
            gamepads.Add(e, e.GetCurrentReading());
        }

        private void Gamepad_GamepadRemoved(object sender, Gamepad e)
        {
            gamepads.Remove(e);
        }

        private void UpdateRectangle(Stream stream, Framebuffer framebuffer, Rectangle r )
        {
            byte[] buffer = new byte[r.Width * 4];

            for (int y = 0; y < r.Height; y++)
            {
                int p = 4 * (r.X + (r.Y + y) * framebuffer.Width);
                Buffer.BlockCopy(framebuffer.PixelData, p, buffer, 0, buffer.Length);
                stream.Position = p;
                stream.Write(buffer, 0, buffer.Length);
            }
        }

        long nanos = 0;
        long update = 0;
        Dictionary<long, long> updates = new Dictionary<long, long> { { 0, 0 } };
        private async void _VncClient_OnFramebufferUpdate(VncClient sender, FramebufferUpdateEventArgs e)
        {
            try
            {
                Stream stream = null;

                await Dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.High, () =>
                {
                    stream = _VncImage.PixelBuffer.AsStream();
                });

                foreach (var item in e.Rectangles)
                {
                    UpdateRectangle(stream, e.Framebuffer, item);
                }

                await Dispatcher.RunAsync(Windows.UI.Core.CoreDispatcherPriority.High, () =>
                {
                    stream?.Dispose();
                    _VncImage.Invalidate();
                });
            }
            catch (Exception ex)
            {
                Ready = false;
                WaitingForServer = false;
            }

            updates[update] = Stopwatch.GetTimestamp() - nanos;
            nanos = Stopwatch.GetTimestamp();
            update++;
        }

        private async Task<Config> ReadConfigAsync()
        {
            var packageFolder = Windows.ApplicationModel.Package.Current.InstalledLocation;
            var sampleFile = await packageFolder.GetFileAsync("Config.json");
            var str = await FileIO.ReadTextAsync(sampleFile);
            return JsonConvert.DeserializeObject<Config>(str);
        }

        private async void SendToServer(NetworkStream sock, string message)
        {
            StatusText.Text += "Sending message to server: " + message + "\n";

            await sock.WriteAsync(message.ToCharArray().Select(c => (byte)c).ToArray(), 0, message.Length);
        }

        private async Task WaitForServerResponse(NetworkStream sock, string desiredResponse)
        {
            StatusText.Text += "Waiting for server to say: " + desiredResponse + "\n";

            while (true)
            {
                byte[] result = new byte[desiredResponse.Length];
                await sock.ReadAsync(result, 0, desiredResponse.Length);
                if (Encoding.ASCII.GetString(result) == desiredResponse)
                    return;
            }
        }

        private void Page_Loaded(object sender, RoutedEventArgs e)
        {
            ApplicationDataContainer localSettings = Windows.Storage.ApplicationData.Current.LocalSettings;
            if (localSettings.Values.Keys.Contains("GBAIPip"))
                txtIp.Text = localSettings.Values["GBAIPip"].ToString();
        }

        private async void DoVncConnection()
        {
            try
            {
                var config = await ReadConfigAsync();

                _VncClient = new VncClient(config.BitsPerPixel, config.Depth);
                _VncClient.Connect(txtIp.Text, config.Port);

                var auth = new VncAuthenticator(config.Password);
                _VncClient.Authenticate(auth);
                _VncClient.Initialize();

                _VncImage = new WriteableBitmap(_VncClient.Framebuffer.Width, _VncClient.Framebuffer.Height);
                VncImage.Source = _VncImage;

                _VncClient.OnFramebufferUpdate += _VncClient_OnFramebufferUpdate;
                _VncClient.ReceiveUpdates();

                VncImage.Opacity = 100;
                btnIpConfirm.IsEnabled = false;
                btnIpConfirm.Opacity = 0;
                txtIp.IsEnabled = false;
                txtIp.Opacity = 0;
                MainPageControl.Background = new SolidColorBrush(Windows.UI.Colors.Black);
            }
            catch (Exception e) 
            {
                Thread.Sleep(1000);
                DoVncConnection();
            }

            Ready = true;
            ReconnectEnabled = false;
            StatusRefresh = true;
        }

        private async void btnIpConfirm_Click(object sender, RoutedEventArgs e)
        {
            ApplicationDataContainer localSettings = Windows.Storage.ApplicationData.Current.LocalSettings;
            localSettings.Values["GBAIPip"] = txtIp.Text;

            StatusText.Text += "Welcome!\n";
            StatusText.Text += "Trying to create the TCP client...";

            _TcpClient = new TcpClient(txtIp.Text, 28008);
            NetworkStream stream = _TcpClient.GetStream();
            StatusText.Text += "Success!\n";

            SendToServer(stream, "start up");

            await WaitForServerResponse(stream, "game is ready");

            StatusText.Text += "We're ready. Press A to start the display.";

            WaitingForServer = false;
            StatusRefresh = true;
            updateTimer.Start();
        }

        private void MainPageControl_Unloaded(object sender, RoutedEventArgs e)
        {
            SendToServer(_TcpClient.GetStream(), "shut down");
        }
    }
}
