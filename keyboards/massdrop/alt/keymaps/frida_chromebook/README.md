# Customized Mac Keymap Layout

This layout is for macos, and uses some macos specific features, in addition to having a mac layout. For instance, it has app hotkeys that work by using spotlight.

## Cloning

```Shell
git clone --recurse-submodules git@github.com:losandes/qmk_firmware.git
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
rm massdrop_alt_cb_frida.bin
make clean
make massdrop/alt:cb_frida
```

## Configuring the LEDS
This keymap has a NodeJS LED configurator. You can copy and modify the `./led-layers.js` file to make an LED map. The map is simply an array that I defined with delimiters that mock the physical layout. It's the integer indexes, and the values that are actually consumed by `./led-maps.js`. The mapper accepts 4 types of values:

* falsey (i.e. `null`, `0`, or `false`) - the mapper will ignore any indexes that are falsey
* '#pppppp' - use the user's chosen pattern (`LED_FLAG_USE_ROTATE_PATTERN`)
* '#pppp00' - use a specific pattern (where 00 is that `.pattern_id` - an integer between 0 and the max pattern id, which is 10 at the time of writing)
* '#ffffff' - any hex color value

Once you configure your layers, run:

```Shell
$ node led-layers.js | pbcopy
```

That should print an `led_instructions` function to your terminal that you can copy and paste into your `keymap.c`.

![configuring-leds](https://www.dropbox.com/s/38mlpbwdzf6qybe/led-configurator.png?dl=0&raw=1)

> The above screenshot is using [atom](https://ide.atom.io/) with the [pigments](https://atom.io/packages/pigments) extension to highlight the colors. If you're using Visual Studio Code, the [vscode-pigments](https://marketplace.visualstudio.com/items?itemName=jaspernorth.vscode-pigments) extension supports the same visualization.
>
> NOTE - I'm overriding all of the default patterns in this keymap. I'm not a fan of modifying the code that I fork, and prefer to extend it instead (Open/Closed Principle). Being new to TMK, QMK, and Massdrop's fork, I wasn't sure how to simply add or replace patterns through extension, so I ended up adding my own programs file, and updating the values of the `led_setups` array. If you know a better way to do this, please open an Issue and tell me about it :)

## Reference

* [Spreadsheet to help calculate bitwise ids for individual keys](https://docs.google.com/spreadsheets/d/1bsaMF4qmJNhvqlxmHmaXnhs7gung7_A0EqAyjStg_7U/edit?usp=sharing) (by @lastcontinue, famguy07, pleasuretek)
* [QMK keymap list of keycodes](https://github.com/qmk/qmk_firmware/blob/master/docs/keycodes.md)
* [Docs on keycodes](https://beta.docs.qmk.fm/features/keycodes_basic)
