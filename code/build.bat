@echo off

mkdir ..\..\build
pushd ..\..\build

cl -Wall -Zi ..\handmade\code\win32_handmade.c user32.lib

popd
