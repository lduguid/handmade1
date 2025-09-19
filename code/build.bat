@echo off

mkdir ..\..\build
pushd ..\..\build

cl -Zi ..\handmade\code\win32_handmade.c user32.lib

popd