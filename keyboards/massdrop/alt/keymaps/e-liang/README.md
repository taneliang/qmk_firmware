## (Personal) Set up instructions

### Windows + WSL2

1. Set up QMK In WSL:
    1. `qmk setup`
    1. `qmk config user.keymap=e-liang`
    1. `sudo apt install dfu-programmer avrdude dfu-util gcc-avr gcc-arm-none-eabi`
1. Build: `qmk compile -kb massdrop/alt`
1. Flash (in Windows):
    1. Install https://github.com/Massdrop/mdloader
    1. In Powershell: `./mdloader_windows.exe --first --download \\wsl$\Ubuntu-20.04\home\e-liang\qmk_firmware\.build\massdrop_alt_e-liang.hex --restart`
