# losandes Massdrop Alt Keymaps

This folder is meant to be symlinked into qmk:

```Shell
# Clone QMK
git clone git@github.com:qmk/qmk_firmware.git

# Delete or remove the planck keymaps
cd qmk-firmware/keyboards/whitefox
mv keymaps keymaps-default

# Link this folder to the qmk clone
ln -s ~/.dotfiles/keyboards/whitefox/keymaps ~/src/losandes/qmk-firmware/keyboards/whitefox/keymaps
```
