@echo off
setlocal

:: Configurable renderer backend, default is SDL2
:: Usage: build.bat [RENDER_BACKEND]
set RENDER_BACKEND=%1
if "%RENDER_BACKEND%"=="" set RENDER_BACKEND=SDL2

echo Building LitePM with renderer backend: %RENDER_BACKEND%

if not exist build mkdir build
cd build
cmake .. -DRENDER_BACKEND=%RENDER_BACKEND%
cmake --build . --config Debug

endlocal
