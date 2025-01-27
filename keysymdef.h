/* Keypad functions, keypad numbers cleverly chosen to map to ASCII */

#define XK_KP_Space                      0xff80  /* Space */
#define XK_KP_Tab                        0xff89
#define XK_KP_Enter                      0xff8d  /* Enter */
#define XK_KP_F1                         0xff91  /* PF1, KP_A, ... */
#define XK_KP_F2                         0xff92
#define XK_KP_F3                         0xff93
#define XK_KP_F4                         0xff94
#define XK_KP_Home                       0xff95
#define XK_KP_Left                       0xff96
#define XK_KP_Up                         0xff97
#define XK_KP_Right                      0xff98
#define XK_KP_Down                       0xff99
#define XK_KP_Prior                      0xff9a
#define XK_KP_Page_Up                    0xff9a
#define XK_KP_Next                       0xff9b
#define XK_KP_Page_Down                  0xff9b
#define XK_KP_End                        0xff9c
#define XK_KP_Begin                      0xff9d
#define XK_KP_Insert                     0xff9e
#define XK_KP_Delete                     0xff9f
#define XK_KP_Equal                      0xffbd  /* Equals */
#define XK_KP_Multiply                   0xffaa
#define XK_KP_Add                        0xffab
#define XK_KP_Separator                  0xffac  /* Separator, often comma */
#define XK_KP_Subtract                   0xffad
#define XK_KP_Decimal                    0xffae
#define XK_KP_Divide                     0xffaf

#define XK_KP_0                          0xffb0
#define XK_KP_1                          0xffb1
#define XK_KP_2                          0xffb2
#define XK_KP_3                          0xffb3
#define XK_KP_4                          0xffb4
#define XK_KP_5                          0xffb5
#define XK_KP_6                          0xffb6
#define XK_KP_7                          0xffb7
#define XK_KP_8                          0xffb8
#define XK_KP_9                          0xffb9



/*
 * Auxilliary functions; note the duplicate definitions for left and right
 * function keys;  Sun keyboards and a few other manufactures have such
 * function key groups on the left and/or right sides of the keyboard.
 * We've not found a keyboard with more than 35 function keys total.
 */

#define XK_F1                            0xffbe
#define XK_F2                            0xffbf
#define XK_F3                            0xffc0
#define XK_F4                            0xffc1
#define XK_F5                            0xffc2
#define XK_F6                            0xffc3
#define XK_F7                            0xffc4
#define XK_F8                            0xffc5
#define XK_F9                            0xffc6
#define XK_F10                           0xffc7
#define XK_F11                           0xffc8
#define XK_L1                            0xffc8
#define XK_F12                           0xffc9
#define XK_L2                            0xffc9
#define XK_F13                           0xffca
#define XK_L3                            0xffca
#define XK_F14                           0xffcb
#define XK_L4                            0xffcb
#define XK_F15                           0xffcc
#define XK_L5                            0xffcc
#define XK_F16                           0xffcd
#define XK_L6                            0xffcd
#define XK_F17                           0xffce
#define XK_L7                            0xffce
#define XK_F18                           0xffcf
#define XK_L8                            0xffcf
#define XK_F19                           0xffd0
#define XK_L9                            0xffd0
#define XK_F20                           0xffd1
#define XK_L10                           0xffd1
#define XK_F21                           0xffd2
#define XK_R1                            0xffd2
#define XK_F22                           0xffd3
#define XK_R2                            0xffd3
#define XK_F23                           0xffd4
#define XK_R3                            0xffd4
#define XK_F24                           0xffd5
#define XK_R4                            0xffd5
#define XK_F25                           0xffd6
#define XK_R5                            0xffd6
#define XK_F26                           0xffd7
#define XK_R6                            0xffd7
#define XK_F27                           0xffd8
#define XK_R7                            0xffd8
#define XK_F28                           0xffd9
#define XK_R8                            0xffd9
#define XK_F29                           0xffda
#define XK_R9                            0xffda
#define XK_F30                           0xffdb
#define XK_R10                           0xffdb
#define XK_F31                           0xffdc
#define XK_R11                           0xffdc
#define XK_F32                           0xffdd
#define XK_R12                           0xffdd
#define XK_F33                           0xffde
#define XK_R13                           0xffde
#define XK_F34                           0xffdf
#define XK_R14                           0xffdf
#define XK_F35                           0xffe0
#define XK_R15                           0xffe0

/* Modifiers */

#define XK_Shift_L                       0xffe1  /* Left shift */
#define XK_Shift_R                       0xffe2  /* Right shift */
#define XK_Control_L                     0xffe3  /* Left control */
#define XK_Control_R                     0xffe4  /* Right control */
#define XK_Caps_Lock                     0xffe5  /* Caps lock */
#define XK_Shift_Lock                    0xffe6  /* Shift lock */

#define XK_Meta_L                        0xffe7  /* Left meta */
#define XK_Meta_R                        0xffe8  /* Right meta */
#define XK_Alt_L                         0xffe9  /* Left alt */
#define XK_Alt_R                         0xffea  /* Right alt */
#define XK_Super_L                       0xffeb  /* Left super */
#define XK_Super_R                       0xffec  /* Right super */
#define XK_Hyper_L                       0xffed  /* Left hyper */
#define XK_Hyper_R                       0xffee  /* Right hyper */
#endif /* XK_MISCELLANY */

/*
 * Keyboard (XKB) Extension function and modifier keys
 * (from Appendix C of "The X Keyboard Extension: Protocol Specification")
 * Byte 3 = 0xfe
 */

#ifdef XK_XKB_KEYS
#define XK_ISO_Lock                      0xfe01
#define XK_ISO_Level2_Latch              0xfe02
#define XK_ISO_Level3_Shift              0xfe03
#define XK_ISO_Level3_Latch              0xfe04
#define XK_ISO_Level3_Lock               0xfe05
#define XK_ISO_Group_Shift               0xff7e  /* Alias for mode_switch */
#define XK_ISO_Group_Latch               0xfe06
#define XK_ISO_Group_Lock                0xfe07
#define XK_ISO_Next_Group                0xfe08
#define XK_ISO_Next_Group_Lock           0xfe09
#define XK_ISO_Prev_Group                0xfe0a
#define XK_ISO_Prev_Group_Lock           0xfe0b
#define XK_ISO_First_Group               0xfe0c
#define XK_ISO_First_Group_Lock          0xfe0d
#define XK_ISO_Last_Group                0xfe0e
#define XK_ISO_Last_Group_Lock           0xfe0f

#define XK_ISO_Left_Tab                  0xfe20
#define XK_ISO_Move_Line_Up              0xfe21
#define XK_ISO_Move_Line_Down            0xfe22
#define XK_ISO_Partial_Line_Up           0xfe23
#define XK_ISO_Partial_Line_Down         0xfe24
#define XK_ISO_Partial_Space_Left        0xfe25
#define XK_ISO_Partial_Space_Right       0xfe26
#define XK_ISO_Set_Margin_Left           0xfe27
#define XK_ISO_Set_Margin_Right          0xfe28
#define XK_ISO_Release_Margin_Left       0xfe29
#define XK_ISO_Release_Margin_Right      0xfe2a
#define XK_ISO_Release_Both_Margins      0xfe2b
#define XK_ISO_Fast_Cursor_Left          0xfe2c
#define XK_ISO_Fast_Cursor_Right         0xfe2d
#define XK_ISO_Fast_Cursor_Up            0xfe2e
#define XK_ISO_Fast_Cursor_Down          0xfe2f
#define XK_ISO_Continuous_Underline      0xfe30
#define XK_ISO_Discontinuous_Underline   0xfe31
#define XK_ISO_Emphasize                 0xfe32
#define XK_ISO_Center_Object             0xfe33
#define XK_ISO_Enter                     0xfe34

#define XK_dead_grave                    0xfe50
#define XK_dead_acute                    0xfe51
#define XK_dead_circumflex               0xfe52
#define XK_dead_tilde                    0xfe53
#define XK_dead_macron                   0xfe54
#define XK_dead_breve                    0xfe55
#define XK_dead_abovedot                 0xfe56
#define XK_dead_diaeresis                0xfe57
#define XK_dead_abovering                0xfe58
#define XK_dead_doubleacute              0xfe59
#define XK_dead_caron                    0xfe5a
#define XK_dead_cedilla                  0xfe5b
#define XK_dead_ogonek                   0xfe5c
#define XK_dead_iota                     0xfe5d
#define XK_dead_voiced_sound             0xfe5e
#define XK_dead_semivoiced_sound         0xfe5f
#define XK_dead_belowdot                 0xfe60
#define XK_dead_hook                     0xfe61
#define XK_dead_horn                     0xfe62

#define XK_First_Virtual_Screen          0xfed0
#define XK_Prev_Virtual_Screen           0xfed1
#define XK_Next_Virtual_Screen           0xfed2
#define XK_Last_Virtual_Screen           0xfed4
#define XK_Terminate_Server              0xfed5

#define XK_AccessX_Enable                0xfe70
#define XK_AccessX_Feedback_Enable       0xfe71
#define XK_RepeatKeys_Enable             0xfe72
#define XK_SlowKeys_Enable               0xfe73
#define XK_BounceKeys_Enable             0xfe74
#define XK_StickyKeys_Enable             0xfe75
#define XK_MouseKeys_Enable              0xfe76
#define XK_MouseKeys_Accel_Enable        0xfe77
#define XK_Overlay1_Enable               0xfe78
#define XK_Overlay2_Enable               0xfe79
#define XK_AudibleBell_Enable            0xfe7a

#define XK_Pointer_Left                  0xfee0
#define XK_Pointer_Right                 0xfee1
#define XK_Pointer_Up                    0xfee2
#define XK_Pointer_Down                  0xfee3
#define XK_Pointer_UpLeft                0xfee4
#define XK_Pointer_UpRight               0xfee5
#define XK_Pointer_DownLeft              0xfee6
#define XK_Pointer_DownRight             0xfee7
#define XK_Pointer_Button_Dflt           0xfee8
#define XK_Pointer_Button1               0xfee9
#define XK_Pointer_Button2               0xfeea
#define XK_Pointer_Button3               0xfeeb
#define XK_Pointer_Button4               0xfeec
#define XK_Pointer_Button5               0xfeed
#define XK_Pointer_DblClick_Dflt         0xfeee
#define XK_Pointer_DblClick1             0xfeef
#define XK_Pointer_DblClick2             0xfef0
#define XK_Pointer_DblClick3             0xfef1
#define XK_Pointer_DblClick4             0xfef2
#define XK_Pointer_DblClick5             0xfef3
#define XK_Pointer_Drag_Dflt             0xfef4
#define XK_Pointer_Drag1                 0xfef5
#define XK_Pointer_Drag2                 0xfef6
#define XK_Pointer_Drag3                 0xfef7
#define XK_Pointer_Drag4                 0xfef8
#define XK_Pointer_Drag5                 0xfefd

#define XK_Pointer_EnableKeys            0xfef9
#define XK_Pointer_Accelerate            0xfefa
#define XK_Pointer_DfltBtnNext           0xfefb
#define XK_Pointer_DfltBtnPrev           0xfefc

#endif /* XK_XKB_KEYS */

/*
 * 3270 Terminal Keys
 * Byte 3 = 0xfd
 */

#ifdef XK_3270
#define XK_3270_Duplicate                0xfd01
#define XK_3270_FieldMark                0xfd02
#define XK_3270_Right2                   0xfd03
#define XK_3270_Left2                    0xfd04
#define XK_3270_BackTab                  0xfd05
#define XK_3270_EraseEOF                 0xfd06
#define XK_3270_EraseInput               0xfd07
#define XK_3270_Reset                    0xfd08
#define XK_3270_Quit                     0xfd09
#define XK_3270_PA1                      0xfd0a
#define XK_3270_PA2                      0xfd0b
#define XK_3270_PA3                      0xfd0c
#define XK_3270_Test                     0xfd0d
#define XK_3270_Attn                     0xfd0e
#define XK_3270_CursorBlink              0xfd0f
#define XK_3270_AltCursor                0xfd10
#define XK_3270_KeyClick                 0xfd11
#define XK_3270_Jump                     0xfd12
#define XK_3270_Ident                    0xfd13
#define XK_3270_Rule                     0xfd14
#define XK_3270_Copy                     0xfd15
#define XK_3270_Play                     0xfd16
#define XK_3270_Setup                    0xfd17
#define XK_3270_Record                   0xfd18
#define XK_3270_ChangeScreen             0xfd19
#define XK_3270_DeleteWord               0xfd1a
#define XK_3270_ExSelect                 0xfd1b
#define XK_3270_CursorSelect             0xfd1c
#define XK_3270_PrintScreen              0xfd1d
#define XK_3270_Enter                    0xfd1e
#endif /* XK_3270 */

/*
 * Latin 1
 * (ISO/IEC 8859-1 = Unicode U+0020..U+00FF)
 * Byte 3 = 0
 */
#ifdef XK_LATIN1
#define XK_space                         0x0020  /* U+0020 SPACE */
#define XK_exclam                        0x0021  /* U+0021 EXCLAMATION MARK */
#define XK_quotedbl                      0x0022  /* U+0022 QUOTATION MARK */
#define XK_numbersign                    0x0023  /* U+0023 NUMBER SIGN */
#define XK_dollar                        0x0024  /* U+0024 DOLLAR SIGN */
#define XK_percent                       0x0025  /* U+0025 PERCENT SIGN */
#define XK_ampersand                     0x0026  /* U+0026 AMPERSAND */
#define XK_apostrophe                    0x0027  /* U+0027 APOSTROPHE */
#define XK_quoteright                    0x0027  /* deprecated */
#define XK_parenleft                     0x0028  /* U+0028 LEFT PARENTHESIS */
#define XK_parenright                    0x0029  /* U+0029 RIGHT PARENTHESIS */
#define XK_asterisk                      0x002a  /* U+002A ASTERISK */
#define XK_plus                          0x002b  /* U+002B PLUS SIGN */
#define XK_comma                         0x002c  /* U+002C COMMA */
#define XK_minus                         0x002d  /* U+002D HYPHEN-MINUS */
#define XK_period                        0x002e  /* U+002E FULL STOP */
#define XK_slash                         0x002f  /* U+002F SOLIDUS */
#define XK_0                             0x0030  /* U+0030 DIGIT ZERO */
#define XK_1                             0x0031  /* U+0031 DIGIT ONE */
#define XK_2                             0x0032  /* U+0032 DIGIT TWO */
#define XK_3                             0x0033  /* U+0033 DIGIT THREE */
#define XK_4                             0x0034  /* U+0034 DIGIT FOUR */
#define XK_5                             0x0035  /* U+0035 DIGIT FIVE */
#define XK_6                             0x0036  /* U+0036 DIGIT SIX */
#define XK_7                             0x0037  /* U+0037 DIGIT SEVEN */
#define XK_8                             0x0038  /* U+0038 DIGIT EIGHT */
#define XK_9                             0x0039  /* U+0039 DIGIT NINE */
#define XK_colon                         0x003a  /* U+003A COLON */
#define XK_semicolon                     0x003b  /* U+003B SEMICOLON */
#define XK_less                          0x003c  /* U+003C LESS-THAN SIGN */
#define XK_equal                         0x003d  /* U+003D EQUALS SIGN */
#define XK_greater                       0x003e  /* U+003E GREATER-THAN SIGN */
#define XK_question                      0x003f  /* U+003F QUESTION MARK */
#define XK_at                            0x0040  /* U+0040 COMMERCIAL AT */
#define XK_A                             0x0041  /* U+0041 LATIN CAPITAL LETTER A */
#define XK_B                             0x0042  /* U+0042 LATIN CAPITAL LETTER B */
#define XK_C                             0x0043  /* U+0043 LATIN CAPITAL LETTER C */
#define XK_D                             0x0044  /* U+0044 LATIN CAPITAL LETTER D */
#define XK_E                             0x0045  /* U+0045 LATIN CAPITAL LETTER E */
#define XK_F                             0x0046  /* U+0046 LATIN CAPITAL LETTER F */
#define XK_G                             0x0047  /* U+0047 LATIN CAPITAL LETTER G */
#define XK_H                             0x0048  /* U+0048 LATIN CAPITAL LETTER H */
#define XK_I                             0x0049  /* U+0049 LATIN CAPITAL LETTER I */
#define XK_J                             0x004a  /* U+004A LATIN CAPITAL LETTER J */
#define XK_K                             0x004b  /* U+004B LATIN CAPITAL LETTER K */
#define XK_L                             0x004c  /* U+004C LATIN CAPITAL LETTER L */
#define XK_M                             0x004d  /* U+004D LATIN CAPITAL LETTER M */
#define XK_N                             0x004e  /* U+004E LATIN CAPITAL LETTER N */
#define XK_O                             0x004f  /* U+004F LATIN CAPITAL LETTER O */
#define XK_P                             0x0050  /* U+0050 LATIN CAPITAL LETTER P */
#define XK_Q                             0x0051  /* U+0051 LATIN CAPITAL LETTER Q */
#define XK_R                             0x0052  /* U+0052 LATIN CAPITAL LETTER R */
#define XK_S                             0x0053  /* U+0053 LATIN CAPITAL LETTER S */
#define XK_T                             0x0054  /* U+0054 LATIN CAPITAL LETTER T */
#define XK_U                             0x0055  /* U+0055 LATIN CAPITAL LETTER U */
#define XK_V                             0x0056  /* U+0056 LATIN CAPITAL LETTER V */
#define XK_W                             0x0057  /* U+0057 LATIN CAPITAL LETTER W */
#define XK_X                             0x0058  /* U+0058 LATIN CAPITAL LETTER X */
#define XK_Y                             0x0059  /* U+0059 LATIN CAPITAL LETTER Y */
#define XK_Z                             0x005a  /* U+005A LATIN CAPITAL LETTER Z */
#define XK_bracketleft                   0x005b  /* U+005B LEFT SQUARE BRACKET */
#define XK_backslash                     0x005c  /* U+005C REVERSE SOLIDUS */
#define XK_bracketright                  0x005d  /* U+005D RIGHT SQUARE BRACKET */
#define XK_asciicircum                   0x005e  /* U+005E CIRCUMFLEX ACCENT */
#define XK_underscore                    0x005f  /* U+005F LOW LINE */
#define XK_grave                         0x0060  /* U+0060 GRAVE ACCENT */
#define XK_quoteleft                     0x0060  /* deprecated */
#define XK_a                             0x0061  /* U+0061 LATIN SMALL LETTER A */
#define XK_b                             0x0062  /* U+0062 LATIN SMALL LETTER B */
#define XK_c                             0x0063  /* U+0063 LATIN SMALL LETTER C */
#define XK_d                             0x0064  /* U+0064 LATIN SMALL LETTER D */
#define XK_e                             0x0065  /* U+0065 LATIN SMALL LETTER E */
#define XK_f                             0x0066  /* U+0066 LATIN SMALL LETTER F */
#define XK_g                             0x0067  /* U+0067 LATIN SMALL LETTER G */
#define XK_h                             0x0068  /* U+0068 LATIN SMALL LETTER H */
#define XK_i                             0x0069  /* U+0069 LATIN SMALL LETTER I */
#define XK_j                             0x006a  /* U+006A LATIN SMALL LETTER J */
#define XK_k                             0x006b  /* U+006B LATIN SMALL LETTER K */
#define XK_l                             0x006c  /* U+006C LATIN SMALL LETTER L */
#define XK_m                             0x006d  /* U+006D LATIN SMALL LETTER M */
#define XK_n                             0x006e  /* U+006E LATIN SMALL LETTER N */
#define XK_o                             0x006f  /* U+006F LATIN SMALL LETTER O */
#define XK_p                             0x0070  /* U+0070 LATIN SMALL LETTER P */
#define XK_q                             0x0071  /* U+0071 LATIN SMALL LETTER Q */
#define XK_r                             0x0072  /* U+0072 LATIN SMALL LETTER R */
#define XK_s                             0x0073  /* U+0073 LATIN SMALL LETTER S */
#define XK_t                             0x0074  /* U+0074 LATIN SMALL LETTER T */
#define XK_u                             0x0075  /* U+0075 LATIN SMALL LETTER U */
#define XK_v                             0x0076  /* U+0076 LATIN SMALL LETTER V */
#define XK_w                             0x0077  /* U+0077 LATIN SMALL LETTER W */
#define XK_x                             0x0078  /* U+0078 LATIN SMALL LETTER X */
#define XK_y                             0x0079  /* U+0079 LATIN SMALL LETTER Y */
#define XK_z                             0x007a  /* U+007A LATIN SMALL LETTER Z */
#define XK_braceleft                     0x007b  /* U+007B LEFT CURLY BRACKET */
#define XK_bar                           0x007c  /* U+007C VERTICAL LINE */
#define XK_braceright                    0x007d  /* U+007D RIGHT CURLY BRACKET */
#define XK_asciitilde                    0x007e  /* U+007E TILDE */

#define XK_nobreakspace                  0x00a0  /* U+00A0 NO-BREAK SPACE */
#define XK_exclamdown                    0x00a1  /* U+00A1 INVERTED EXCLAMATION MARK */
#define XK_cent                          0x00a2  /* U+00A2 CENT SIGN */
#define XK_sterling                      0x00a3  /* U+00A3 POUND SIGN */
#define XK_currency                      0x00a4  /* U+00A4 CURRENCY SIGN */
#define XK_yen                           0x00a5  /* U+00A5 YEN SIGN */
#define XK_brokenbar                     0x00a6  /* U+00A6 BROKEN BAR */
#define XK_section                       0x00a7  /* U+00A7 SECTION SIGN */
#define XK_diaeresis                     0x00a8  /* U+00A8 DIAERESIS */
#define XK_copyright                     0x00a9  /* U+00A9 COPYRIGHT SIGN */
#define XK_ordfeminine                   0x00aa  /* U+00AA FEMININE ORDINAL INDICATOR */
#define XK_guillemotleft                 0x00ab  /* U+00AB LEFT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define XK_notsign                       0x00ac  /* U+00AC NOT SIGN */
#define XK_hyphen                        0x00ad  /* U+00AD SOFT HYPHEN */
#define XK_registered                    0x00ae  /* U+00AE REGISTERED SIGN */
#define XK_macron                        0x00af  /* U+00AF MACRON */
#define XK_degree                        0x00b0  /* U+00B0 DEGREE SIGN */
#define XK_plusminus                     0x00b1  /* U+00B1 PLUS-MINUS SIGN */
#define XK_twosuperior                   0x00b2  /* U+00B2 SUPERSCRIPT TWO */
#define XK_threesuperior                 0x00b3  /* U+00B3 SUPERSCRIPT THREE */
#define XK_acute                         0x00b4  /* U+00B4 ACUTE ACCENT */
#define XK_mu                            0x00b5  /* U+00B5 MICRO SIGN */
#define XK_paragraph                     0x00b6  /* U+00B6 PILCROW SIGN */
#define XK_periodcentered                0x00b7  /* U+00B7 MIDDLE DOT */
#define XK_cedilla                       0x00b8  /* U+00B8 CEDILLA */
#define XK_onesuperior                   0x00b9  /* U+00B9 SUPERSCRIPT ONE */
#define XK_masculine                     0x00ba  /* U+00BA MASCULINE ORDINAL INDICATOR */
#define XK_guillemotright                0x00bb  /* U+00BB RIGHT-POINTING DOUBLE ANGLE QUOTATION MARK */
#define XK_onequarter                    0x00bc  /* U+00BC VULGAR FRACTION ONE QUARTER */
#define XK_onehalf                       0x00bd  /* U+00BD VULGAR FRACTION ONE HALF */
#define XK_threequarters                 0x00be  /* U+00BE VULGAR FRACTION THREE QUARTERS */
#define XK_questiondown                  0x00bf  /* U+00BF INVERTED QUESTION MARK */
#define XK_Agrave                        0x00c0  /* U+00C0 LATIN CAPITAL LETTER A WITH GRAVE */
#define XK_Aacute                        0x00c1  /* U+00C1 LATIN CAPITAL LETTER A WITH ACUTE */
#define XK_Acircumflex                   0x00c2  /* U+00C2 LATIN CAPITAL LETTER A WITH CIRCUMFLEX */
#define XK_Atilde                        0x00c3  /* U+00C3 LATIN CAPITAL LETTER A WITH TILDE */
#define XK_Adiaeresis                    0x00c4  /* U+00C4 LATIN CAPITAL LETTER A WITH DIAERESIS */
#define XK_Aring                         0x00c5  /* U+00C5 LATIN CAPITAL LETTER A WITH RING ABOVE */
#define XK_AE                            0x00c6  /* U+00C6 LATIN CAPITAL LETTER AE */
#define XK_Ccedilla                      0x00c7  /* U+00C7 LATIN CAPITAL LETTER C WITH CEDILLA */
#define XK_Egrave                        0x00c8  /* U+00C8 LATIN CAPITAL LETTER E WITH GRAVE */
#define XK_Eacute                        0x00c9  /* U+00C9 LATIN CAPITAL LETTER E WITH ACUTE */
#define XK_Ecircumflex                   0x00ca  /* U+00CA LATIN CAPITAL LETTER E WITH CIRCUMFLEX */
#define XK_Ediaeresis                    0x00cb  /* U+00CB LATIN CAPITAL LETTER E WITH DIAERESIS */
#define XK_Igrave                        0x00cc  /* U+00CC LATIN CAPITAL LETTER I WITH GRAVE */
#define XK_Iacute                        0x00cd  /* U+00CD LATIN CAPITAL LETTER I WITH ACUTE */
#define XK_Icircumflex                   0x00ce  /* U+00CE LATIN CAPITAL LETTER I WITH CIRCUMFLEX */
#define XK_Idiaeresis                    0x00cf  /* U+00CF LATIN CAPITAL LETTER I WITH DIAERESIS */
#define XK_ETH                           0x00d0  /* U+00D0 LATIN CAPITAL LETTER ETH */
#define XK_Eth                           0x00d0  /* deprecated */
#define XK_Ntilde                        0x00d1  /* U+00D1 LATIN CAPITAL LETTER N WITH TILDE */
#define XK_Ograve                        0x00d2  /* U+00D2 LATIN CAPITAL LETTER O WITH GRAVE */
#define XK_Oacute                        0x00d3  /* U+00D3 LATIN CAPITAL LETTER O WITH ACUTE */
#define XK_Ocircumflex                   0x00d4  /* U+00D4 LATIN CAPITAL LETTER O WITH CIRCUMFLEX */
#define XK_Otilde                        0x00d5  /* U+00D5 LATIN CAPITAL LETTER O WITH TILDE */
#define XK_Odiaeresis                    0x00d6  /* U+00D6 LATIN CAPITAL LETTER O WITH DIAERESIS */
#define XK_multiply                      0x00d7  /* U+00D7 MULTIPLICATION SIGN */
#define XK_Oslash                        0x00d8  /* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
#define XK_Ooblique                      0x00d8  /* U+00D8 LATIN CAPITAL LETTER O WITH STROKE */
#define XK_Ugrave                        0x00d9  /* U+00D9 LATIN CAPITAL LETTER U WITH GRAVE */
#define XK_Uacute                        0x00da  /* U+00DA LATIN CAPITAL LETTER U WITH ACUTE */
#define XK_Ucircumflex                   0x00db  /* U+00DB LATIN CAPITAL LETTER U WITH CIRCUMFLEX */
#define XK_Udiaeresis                    0x00dc  /* U+00DC LATIN CAPITAL LETTER U WITH DIAERESIS */
#define XK_Yacute                        0x00dd  /* U+00DD LATIN CAPITAL LETTER Y WITH ACUTE */
#define XK_THORN                         0x00de  /* U+00DE LATIN CAPITAL LETTER THORN */
#define XK_Thorn                         0x00de  /* deprecated */
#define XK_ssharp                        0x00df  /* U+00DF LATIN SMALL LETTER SHARP S */
#define XK_agrave                        0x00e0  /* U+00E0 LATIN SMALL LETTER A WITH GRAVE */
#define XK_aacute                        0x00e1  /* U+00E1 LATIN SMALL LETTER A WITH ACUTE */
#define XK_acircumflex                   0x00e2  /* U+00E2 LATIN SMALL LETTER A WITH CIRCUMFLEX */
#define XK_atilde                        0x00e3  /* U+00E3 LATIN SMALL LETTER A WITH TILDE */
#define XK_adiaeresis                    0x00e4  /* U+00E4 LATIN SMALL LETTER A WITH DIAERESIS */
#define XK_aring                         0x00e5  /* U+00E5 LATIN SMALL LETTER A WITH RING ABOVE */
#define XK_ae                            0x00e6  /* U+00E6 LATIN SMALL LETTER AE */
#define XK_ccedilla                      0x00e7  /* U+00E7 LATIN SMALL LETTER C WITH CEDILLA */
#define XK_egrave                        0x00e8  /* U+00E8 LATIN SMALL LETTER E WITH GRAVE */
#define XK_eacute                        0x00e9  /* U+00E9 LATIN SMALL LETTER E WITH ACUTE */
#define XK_ecircumflex                   0x00ea  /* U+00EA LATIN SMALL LETTER E WITH CIRCUMFLEX */
#define XK_ediaeresis                    0x00eb  /* U+00EB LATIN SMALL LETTER E WITH DIAERESIS */
#define XK_igrave                        0x00ec  /* U+00EC LATIN SMALL LETTER I WITH GRAVE */
#define XK_iacute                        0x00ed  /* U+00ED LATIN SMALL LETTER I WITH ACUTE */
#define XK_icircumflex                   0x00ee  /* U+00EE LATIN SMALL LETTER I WITH CIRCUMFLEX */
#define XK_idiaeresis                    0x00ef  /* U+00EF LATIN SMALL LETTER I WITH DIAERESIS */
#define XK_eth                           0x00f0  /* U+00F0 LATIN SMALL LETTER ETH */
#define XK_ntilde                        0x00f1  /* U+00F1 LATIN SMALL LETTER N WITH TILDE */
#define XK_ograve                        0x00f2  /* U+00F2 LATIN SMALL LETTER O WITH GRAVE */
#define XK_oacute                        0x00f3  /* U+00F3 LATIN SMALL LETTER O WITH ACUTE */
#define XK_ocircumflex                   0x00f4  /* U+00F4 LATIN SMALL LETTER O WITH CIRCUMFLEX */
#define XK_otilde                        0x00f5  /* U+00F5 LATIN SMALL LETTER O WITH TILDE */
#define XK_odiaeresis                    0x00f6  /* U+00F6 LATIN SMALL LETTER O WITH DIAERESIS */
#define XK_division                      0x00f7  /* U+00F7 DIVISION SIGN */
#define XK_oslash                        0x00f8  /* U+00F8 LATIN SMALL LETTER O WITH STROKE */
#define XK_ooblique                      0x00f8  /* U+00F8 LATIN SMALL LETTER O WITH STROKE */
#define XK_ugrave                        0x00f9  /* U+00F9 LATIN SMALL LETTER U WITH GRAVE */
#define XK_uacute                        0x00fa  /* U+00FA LATIN SMALL LETTER U WITH ACUTE */
#define XK_ucircumflex                   0x00fb  /* U+00FB LATIN SMALL LETTER U WITH CIRCUMFLEX */
#define XK_udiaeresis                    0x00fc  /* U+00FC LATIN SMALL LETTER U WITH DIAERESIS */
#define XK_yacute                        0x00fd  /* U+00FD LATIN SMALL LETTER Y WITH ACUTE */
#define XK_thorn                         0x00fe  /* U+00FE LATIN SMALL LETTER THORN */
#define XK_ydiaeresis                    0x00ff  /* U+00FF LATIN SMALL LETTER Y WITH DIAERESIS */
#endif /* XK_LATIN1 */