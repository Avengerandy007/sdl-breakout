# About
I just didn't have anything better to do and so I decided to try to learn C++ and what better way to do that than using SDL2 to make games. I like classic arcade games (because they're easy to remake) and I picked Breakout as my next experiment.

# Important!! Windows defender for some reason might flag it as a Trojan, you can look through the source code yourself, there is nothing malicious about it.

# Build instructions

Download Make for your respective platform and add it to your system PATH.

## Windows
Install the x64 MinGW version of g++ (if you don't have it already) and add the bin folder to your PATH.

Download the SDL2 for Windows library in any desired directory.

Open the Makefile and edit:
```make
SDL2Win_PATH = /usr/include/SDL2Win
```
to be your SDL2 directory. Make sure to don't add any subdirectory under it, because later, the compiler add the needed subdirectories accordingly.
Also check if CXX points to your compiler.

Open powershell and run:
```Powershell
cd Path/To/Makefile
make
```

## Linux
Install clang++ and add that it to your PATH.

Download the SDL2 library for linux using your desired package manager:
```Bash
sudo apt update
sudo apt upgrade
sudo apt-get install libsdl2-2.0-0
sudo apt-get install libsdl2-dev
```
or manually from the manually from their website but make sure the downloaded files are inside of /usr/include/SDL2.

Open the Makefile and edit:
```make
CXX = x86_64-w64-mingw32-g++
#CXX = clang++
```
to:
```make
#CXX = x86_64-w64-mingw32-g++
CXX = clang++
```

To build the project simply open your favourite terminal emulator and run the following commands:
```Bash
cd Path/To/Makefile
make
```
