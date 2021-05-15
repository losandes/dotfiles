# losandes Massdrop Alt Keymaps

This folder is meant to be symlinked into qmk:

```Shell
# Clone Massdrop's fork of QMK
git clone git@github.com:Massdrop/qmk_firmware.git

# Delete or remove the Alt keymaps
cd qmk-firmware/keyboards/massdrop/alt
mv keymaps keymaps-default

# Link this folder to the qmk clone
ln -s ~/.dotfiles/keyboards/massdrop/alt/keymaps ~/src/losandes/qmk-firmware/keyboards/massdrop/alt/keymaps
```
