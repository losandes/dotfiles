# Customized Mac Keymap Layout

This is a 60%, mac HHKB layout for the Drop Alt for the purpose of evaluating the 60% layout before purchasing a 60% board.

## Cloning

```Shell
git clone --recurse-submodules git@github.com:Massdrop/qmk_firmware.git
```

## Installation

```Shell
brew install nvm
nvm install --lts
nvm alias default node

brew install pyenv
pyenv install 3.7.4

brew tap osx-cross/avr
brew tap PX4/homebrew-px4
brew update
brew install avr-gcc@8 gcc-arm-none-eabi dfu-programmer avrdude dfu-util
brew link --force avr-gcc@8
pip3 install -r ~/src/losandes/qmk-firmware/requirements.txt

# If you need to have this software first in your PATH instead consider running:
#  echo 'export PATH="/usr/local/opt/avr-gcc@8/bin:$PATH"' >> ~/.zshrc
```

Test the installation:

```Shell
make massdrop/alt:default
```

## Building Firmware

```Shell
rm massdrop_alt_mac_losandes_60.bin
make clean
make massdrop/alt:mac_losandes_60
```

## Configuring the LEDS

See the mac_losandes layout for information on configuring the LEDs

## Reference

* [Spreadsheet to help calculate bitwise ids for individual keys](https://docs.google.com/spreadsheets/d/1bsaMF4qmJNhvqlxmHmaXnhs7gung7_A0EqAyjStg_7U/edit?usp=sharing) (by @lastcontinue, famguy07, pleasuretek)
* [QMK keymap list of keycodes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)
* [Docs on keycodes](https://beta.docs.qmk.fm/features/keycodes_basic)
