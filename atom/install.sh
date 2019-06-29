#!/bin/sh

mkdir -p $HOME/.atom

rm $HOME/.atom/config.cson
rm $HOME/.atom/keymap.cson

ln -s $DOT/atom/config.cson $HOME/.atom/config.cson
ln -s $DOT/atom/keymap.cson $HOME/.atom/keymap.cson

apm install --packages-file $DOT/atom/packages.list
