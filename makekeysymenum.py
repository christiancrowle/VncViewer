import os
import re
rex = re.compile(r'\s+')

with open("keysymdef.h", "r") as keysymdef:
    keysymdef_lines = keysymdef.readlines()

with open("keysymenum.txt", "w") as keysymenum:
    for line in keysymdef_lines:
        if line.startswith("/*"):
            continue
        if line.startswith(" *"):
            continue
        if line.startswith("#endif"):
            continue
        if line.strip() == '':
            continue
        line_parts = rex.sub(' ', line).split(' ')
        #print(rex.sub(' ', line) + " " + str(line_parts))
        line_new = f'uint {line_parts[1]} = {line_parts[2]};\n'
        keysymenum.write(line_new)
