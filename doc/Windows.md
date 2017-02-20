# Install VS2013
- Visual Studio
Express 2013 for Windows Desktop (with Update 4)


# Compile wxWidgets-3.0.2
- open project
wxWidgets-3.0.2\build\msw\wx_vc12.sln
-

# App
- The program can't start because MSVCP120.dll is missing from you computer
copy MSVCP120.dll

- unresolved external symbol _WinMain@16 referenced in function ___tmainCRTStartup
project -> Properties -> Linker -> System -> SubSystem: Console

- unresolved+external+symbol+wxSTCNameStr
