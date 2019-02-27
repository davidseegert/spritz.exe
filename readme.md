# spritz.exe

spritz.exe is a tiny (5kb) implementation of [Spritz](https://www.spritz.com/) for the Windows commandline.

[Download](https://github.com/Peplow/spritz.exe/releases/download/v0.1/spritz.exe)

![](https://i.imgur.com/Nzq7vX6.gif)

# Build

Building is tested with `tcc version 0.9.27 (x86_64 Windows)`, however it should compile with other compilers to. Unfortunally there is only windows support right now, because of the use of system functions for copy-pasting and command line formatting.

Build command:
```
tcc .\main.c -o spritz.exe
```

# Setup & Usage

You can run spritz.exe by simply double-clicking it. 

## Spritz Text

Copy the text you want to spritz and paste it into the window by right-clicking into it. The app will start spritzing immediately.

## Change Speed
You can change the display-speend by pressing the letters 1 (slow) to 9 (fast). Please note that you can only change the speed before you paste a text, after that you will have to wait until the software has finished spritzing before you can change the speed again.

# Licence (MIT)
Copyright 2019 David Peplow

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
