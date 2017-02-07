# Windows
## Windows 7 x64
0. insatll codelite
1. install tdm-gcc
	http://tdm-gcc.tdragon.net/download
2. compile wxWidgets
	compile filed with misunderstand error(try to install tdm-gcc-32)
	http://codelite.org/Developers/BuildingWxWidgetsWin
3. codelite configurations:
	* Settings -> Environment Variables:
		```
		CodeLiteDir=C:\dev\CodeLite
		WXWIN=C:\dev\wxWidgets3
		WXCFG=gcc_lib\mswud
		```
	* libgcc_s_dw2-1.dll is missing
		Why? Maybe, you just need reboot you windows !
		
	* gcc_lib/mswu/wx/setup.h: no such file or directory
		cd  \Path\To\wxWidgets\Sources\build\msw
		`mingw32-make -j8 -f Makefile.gcc BUILD=release`
	* gcc_lib/mswu/wx/setup.h: no such file or directory
		cd  \Path\To\wxWidgets\Sources\build\msw
		`mingw32-make -j8 -f Makefile.gcc BUILD=debug`

## Others

# MacOS

## 10.10.2


# Linux
## Ubuntu
* install build essential
` apt-get install gcc make libwxbase3.0 libwxgtk3.0-dev `
* install codelite IDE
` apt-get install codelite `

## Centos
