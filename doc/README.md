
# Compile wxWidgets
## Linux

## Windows

## MaxOX
- Download wxWidgets and compile
```
cd wxWidgets-3.0.2
mkdir bin
cd bin
../configure --disable-shared --disable-webkit --disable-webview --disable-mediatrl --disable-sound --with-osx_cocoa --with-macosx-sdk=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.9.sdk --with-macosx-version-min=10.9
```
- Configure wxWidgets
Create file /etc/paths.d/wxWidgets
```
/Users/sandy/dev/wxWidgets-3.0.2/bin
```
- Download and install CMake
To use cmake command, you should add PATH environment.
Create file /etc/paths.d/cmake
```
/Applications/CMake.app/Contents/bin
```

# Build citty with cmake
## Linux
```
cd Citty
mkdir build
cd build
cmake .. -G"Unix Makefiles"
make
```

## Windows
```
cd Citty
mkdir build
cd build
cmake .. -G"MinGW Makefiles" -DwxWidgets_ROOT_DIR="C:\wxWidgets"
C:\TDM-GCC-32\bin\mingw32-make.exe
```

## MacOS
```
cd Citty
mkdir build
cd build
cmake .. -G"Unix Makefiles"
make
```

## wxwidgets cmake usage
https://wiki.wxwidgets.org/CMake
