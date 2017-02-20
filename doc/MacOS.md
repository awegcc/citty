# Xcode configuration
## Xcode 8.2.1 (Macos 10.12.3)
### Linking 
1. run shell command in terminal
``` Shell
wx-config --libs
-L/opt/wxWidgets-3.0.2/bin/lib   -framework IOKit -framework Carbon -framework Cocoa -framework AudioToolbox -framework System -framework OpenGL /opt/wxWidgets-3.0.2/bin/lib/libwx_osx_cocoau_xrc-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_osx_cocoau_qa-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_baseu_net-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_osx_cocoau_html-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_osx_cocoau_adv-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_osx_cocoau_core-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_baseu_xml-3.0.a /opt/wxWidgets-3.0.2/bin/lib/libwx_baseu-3.0.a -lexpat -lwxregexu-3.0 -lwxtiff-3.0 -lwxjpeg-3.0 -lwxpng-3.0 -lz -lpthread -liconv -llzma 
```
2. Copy the above contents to:
Project -> Targets -> Build Settings -> Linking -> Other Linker Flags

### Custom Compiler Flags
1. run shell command terminal
``` Shell
wx-config --cxxflags
-I/opt/wxWidgets-3.0.2/bin/lib/wx/include/osx_cocoa-unicode-static-3.0 -I/opt/wxWidgets-3.0.2/include -D_FILE_OFFSET_BITS=64 -D__WXMAC__ -D__WXOSX__ -D__WXOSX_COCOA__ 
```
2. Copy the above contents to:
Project -> Targets -> Build Settings -> Apple LLVM 8.0-Custom Compiler Flags

# Others

