VIM
===

Vim is a text file editor with multiple modes: command mode, insert mode, visual mode, and replace mode.

Perhaps better than this hint sheet is this [freeCodeCamp tutorial](https://www.freecodecamp.org/news/learn-linux-vim-basic-features-19134461ab85/)

## Insert Mode

* `i`    | enter insert mode
* `I`    | navigate to the beginning of the current line and enter insert mode
* `o`    | add a new line below and enter insert mode
* `O`    | add a new line above and enter insert mode
* `a`    | enter insert mode, one character to the right
* `A`    | navigate to the end of the current line and enter insert mode
* `r`    | enter overstrike/replace mode (will exit automatically)
* `R`    | enter overstrike/replace mode (ESC to exit)

## Command Mode

* esc               | exit current mode to Normal mode
* `:`               | enter command mode
* `.`               | repeat last command
* `:q`              | quit
* `:q!`             | quit without saving
* `:w`, `:write`    | save the file
* `:wq`, `:x`, `ZZ` | save the file AND quit
* `:e`              | open a file
* `:r <filename>`   | read contents of a file to the current buffer
* `: 10,25 w temp`  | write lines 10 through 25 into file named temp

> Examples
> `:e %:h/filename` will create or open a file relative to this directory (`%` refers to the current file, `:h` is a modifier for its directory)

### Navigation

* `h`            | left <-
* `l`            | right ->
* `j`            | down
* `k`            | up
* `5{h|j|k|l}`   | navigate _n_ times (5 in this example) in _letter_ direction (i.e. 10j will navigate down 10 lines)
* `5G`           | goto line _n_ (5 in this example)
* `gg`           | scroll to top of the file
* `G`            | scroll to the bottom of the file
* `0`            | scroll to the beginning of the current line
* `$`            | scroll to the end of the current line
* `w`            | forward one word
* `b`            | backward one word
* `ctrl + f`     | page forward
* `ctrl + b`     | page backward
* `ctrl + u`     | half page forward
* `ctrl + d`     | half page backward

> http://vim.wikia.com/wiki/Moving_around

### Text Selection

* `v`           | highlight a character
* `shift + v`   | highlight a row
* `gcc`		      | comment out a line (vim-commentary plugin)
* `shift + *`   | select the text at the cursor (Ctrl + n to navigate to each selection; `:noh` to clear)

### Copy (Yank (has most of the options of delete))

* `yy`      | yank current line
* `y$`      | yank to end of current line from cursor
* `yw`      | yank from cursor to end of current word
* `5yy`     | yank 5 lines
* `5"+yy`   | yank 5 lines to the OS clipboard
* `mk`      | to mark beginning of selection, then navigate to end of selection and `y'k` to copy a block

### Paste (used after delete or yank to recover lines.)

* `p`     | paste below cursor
* `P`     | paste above cursor
* `"2p`   | paste from buffer 2 (there are 9)
* `"+p`   | paste from the OS clipboard

### Delete / Cut

* `x`     | delete character at cursor
* `dw`    | delete word at cursor
* `db`    | delete previous word
* `dd`    | delete line
* `d$`    | delete to end of line
* `d0`    | delete to beginning of line
* `d^`    | (d caret, not CTRL d) delete to beginning of line
* `d`     | delete the selection (i.e. what you selected with `shift+v`, or `v`)
* `mk`    | mark beginning of selection, then navigate to end of selection and `d'k` to delete a block

### Replace

* `cw`                                 | remove word at cursor position
* `r`                                  | enter overstrike/replace mode (will exit automatically)
* `R`                                  | enter overstrike/replace mode (ESC to exit)
* `J`                                  | join next line down to the end of the current line
* `:/`                                 | pattern Search forward for the pattern
* `:?`                                 | pattern Search backward for the pattern
* `n`                                  | used after either of the 2 search commands above to continue to find next occurrence of the pattern.
* `:g/<replace_this>/s//<with_this>/g` | replace every occurrence of pattern1 (replace_this) with pat2 (with_this) using grep
* `:%s/<replace_this>/<with_this>/`    | replace every occurrence of pattern1 (replace_this) with pat2 (with_this)

> Examples
> * `:g/tIO/s//Ada.Text_IO/g` will find and replace tIO by Ada.text_IO everywhere in the file.
> * `:g/a/s// /g` replace the letter a, by blank
> * `:g/a/s///g` replace a by nothing
>
> note: this command can be undone by `u`
>
> highlight the current word at the cursor with `*`, then `:%s//<replace_with>/g`

### Undo

* `u`    | undo
* `U`    | restore line

### Buffers

* `:ls`              | list the current buffers
* `:b <number>`      | switch to a buffer by number (i.e. `:b 4`)
* `_n_ ctrl+shift+^` | switch to a buffer by number (i.e. `4 ctrl+shift+^`)
* `:b <name>`        | switch to a buffer by name (i.e. `:b vim.md`; supports TAB completion)
* `:bd`              | close/delete the current buffer; will fail if unsaved (nothing is deleted)
* `:bd!`             | close/delete the current buffer; will discard any changes (changes are lost) 

> https://vim.fandom.com/wiki/Buffers
> https://vim.fandom.com/wiki/Easier_buffer_switching

### Tabs

* `:tabedit`      | open a new tab
* `gt`            | next tab
* `gT`            | previous tab
* `ngt`           | goto tab
* `:tabclose`     | close current tab
* `:tabonly`      | close other tabs
* `:tabs`         | list tabs

### Bookmarks

* `m{lowercaseletter}`  | add a bookmark, assigned to _lowercaseletter_
* `:marks`              | show all bookmarks
* `\`{lowercaseletter}` | navigate to bookmarks assigned to _lowercaseletter_

### Printing Output

You can print the buffer to PDF (*.ps) like so:\

* `:ha > %.ps`, or `:hardcopy > %.ps`

#### Page Breaks

To create a page break, while in the insert mode, press the `CTRL+l`. `^L` will appear in your text and will cause the printer to start a new page.

