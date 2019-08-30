if [ ! -d ~/.vim ] || [ ! -d ~/.vim/autoload ]; then
  mkdir -p ~/.vim/autoload ~/.vim/bundle
  curl -LSso ~/.vim/autoload/pathogen.vim https://tpo.pe/pathogen.vim
fi

# 'tpope/vim-sensible': Some good default settings for vim from tpope
# 'tpope/vim-commentary': comment out code/lines (i.e. with gcc)
# 'tpope/vim-abolish': easily search for, substitute, and abbreviate multiple variants of a word
# 'tpope/vim-fugitive': git wrapper for vim
# 'tpope/vim-eunuch': adds a dozen core Unix file operations as Vim commands in the context of the current file
# 'vim-airline/vim-airline': vim-airline makes the command bar at the bottom of vim pretty
# 'bling/vim-bufferline': bufferline shows the list of buffers in the command mode
# 'rakr/vim-one': one-dark, and one-light themes for vim
# 'w0rp/ale': Asynchronous linting/fixing for Vim and Language Server Protocol (LSP) integration
# 'junegunn/goyo.vim.git': Zen mode
# 'terryma/vim-multiple-cursors': Sublime Text style multiple selections for Vim
# 'junegunn/fzf.vim': “fuzzy finder” works similarly to the Goto Anything menu in Sublime Text, allowing you to open a file instantly after typing a rough representation of its name
# 'airblade/vim-gitgutter': adds a column to the left margin indicating lines changed in the active file since the last Git revision
# 'mattn/emmet-vim': a  completion tool for HTML, CSS and JavaScript which allows you to make dynamic completions from a shorthand expression
# 'ArtBIT/vim-modularvimrc': Load directory specific .vimrc files (including the ones from parent directories)

git clone https://github.com/tpope/vim-sensible ~/.vim/bundle/vim-sensible
git clone https://github.com/tpope/vim-commentary ~/.vim/bundle/vim-commentary
git clone https://github.com/tpope/vim-abolish ~/.vim/bundle/vim-abolish
git clone https://github.com/tpope/vim-fugitive.git ~/.vim/bundle/vim-fugitive
git clone https://github.com/tpope/vim-eunuch.git ~/.vim/bundle/vim-eunuch
git clone https://github.com/vim-airline/vim-airline ~/.vim/bundle/vim-airline
git clone https://github.com/bling/vim-bufferline ~/.vim/bundle/vim-bufferline
git clone https://github.com/rakr/vim-one ~/.vim/bundle/vim-one
git clone https://github.com/w0rp/ale.git ~/.vim/bundle/ale
git clone https://github.com/junegunn/goyo.vim.git ~/.vim/bundle/goyo.vim
git clone https://github.com/terryma/vim-multiple-cursors.git ~/.vim/bundle/vim-multiple-cursors
# brew update
# brew install fzf
# $(brew --prefix)/opt/fzf/install
# brew install ripgrep
# echo "# use ripgreip for fzf (fuzzy find)"$'\n'"export FZF_DEFAULT_COMMAND='rg --files --smart-case'"$'\n' >> ~/.bash_profile
# brew cleanup -s
# rm -rf "$(brew --cache)"
git clone https://github.com/junegunn/fzf.vim.git ~/.vim/bundle/fzf.vim
git clone https://github.com/airblade/vim-gitgutter.git ~/.vim/bundle/vim-gitgutter
git clone https://github.com/mattn/emmet-vim.git ~/.vim/bundle/emmet-vim
git clone https://github.com/ArtBIT/vim-modularvimrc.git ~/.vim/bundle/vim-modularvimrc

# Optional Themes
git clone https://github.com/evturn/cosmic-barf.git ~/.vim/bundle/cosmic-barf

# Using TypeScript?
# git clone https://github.com/leafgarland/typescript-vim.git
# git clone https://github.com/HerringtonDarkholme/yats.vim.git ~/.vim/bundle/yats.vim
# Maybe checkout https://github.com/mhartington/nvim-typescript
