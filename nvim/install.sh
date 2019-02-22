#!/bin/sh

mkdir -p $HOME/.config/nvim
# ln -s $DOT/nvim/init.vim $HOME/.config/nvim/init.vim

ln -s ~/.vim/** ~/.config/nvim
ln -s ~/.vimrc ~/.config/nvim/init.vim
