to install raylib on linux
```bash
sudo apt update
sudo apt install build-essential git
sudo apt install libasound2-dev libx11-dev libxrandr-dev libxi-dev libgl1-mesa-dev libglu1-mesa-dev libxcursor-dev libxinerama-dev libwayland-dev libxkbcommon-dev

git clone --depth 1 https://github.com/raysan5/raylib.git raylib
cd raylib/src/
make PLATFORM=PLATFORM_DESKTOP # To make the static version.

sudo make install # Static version.

```
`make` to build
`./chess` to run  

## Theme Selection
When the game starts, you'll be prompted to choose a theme:
```
-----------------------------
|    SELECT CHESS THEME     |
|---------------------------|
|  1. Standard Theme        |
|  2. New Theme             |
-----------------------------
```

https://github.com/user-attachments/assets/460d5901-c219-44a4-9cad-10e54e54fd8f

