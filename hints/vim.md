VIM
===

## Editor Commands
Vim is an editor to create or edit a text file. There are two modes in vim. One is the command mode and another is the insert mode. In the command mode, user can move around the file, delete text, etc. In the insert mode, user can insert text.

### Changing mode from one to another
* From command mode to insert mode, type `a/A/i/I/o/O` (see details below).
* From insert mode to command mode, type `Esc` (escape key)

## My Common Keystrokes

### Modes

### Normal Mode
* esc       | exit current mode to Normal mode

#### Navigation
* `h`           | left <-
* `l`           | right ->
* `j`           | down
* `k`           | up
* _n_ _letter_  | navigate _n_ times in _letter_ direction (i.e. 10j will navigate down 10 lines)
* `gg`          | scroll to top of the file
* `G`           | scroll to the bottom of the file
* `0`           | scroll to the beginning of the current line
* `$`           | scroll to the end of the current line
* `w`           | Forward one word
* `b`           | Backward one word

> http://vim.wikia.com/wiki/Moving_around

#### Text Selection

* `v`           | highlight a character
* `shift+v`     | highlight a row
* `gcc`		| comment out a line (vim-commentary plugin)

### Copy (Yank (has most of the options of delete))

* `yy` yank current line
* `y$` yank to end of current line from cursor
* `yw` yank from cursor to end of current word
* `5yy` yank 5 lines
* `5"+yy` yank 5 lines to the OS clipboard

### Paste (used after delete or yank to recover lines.)

* `p` paste below cursor
* `P` paste above cursor
* `"2p` paste from buffer 2 (there are 9)
* `u` Undo last change
* `U` Restore line
* `J` Join next line down to the end of the current line
* `"+p` paste from the OS clipboard

#### Delete

* `x` Delete character
* `dw` Delete word from cursor on
* `db` Delete word backward
* `dd` Delete line
* `d$` Delete to end of line
* `d^` (d caret, not CTRL d) Delete to beginning of line
* `d` Delete the selection (i.e. what you selected with `shift+v`, or `v`)

#### Replace

* `:/` pattern Search forward for the pattern
* `:?` pattern Search backward for the pattern
* `n` used after either of the 2 search commands above to continue to find next occurrence of the pattern.
* `:g/<replace_this>/s//<with_this>/g` replace every occurrence of pattern1 (replace_this) with pat2 (with_this) using grep
* `:%s/<replace_this>/<with_this>/` replace every occurrence of pattern1 (replace_this) with pat2 (with_this)

> Examples
> * `:g/tIO/s//Ada.Text_IO/g` will find and replace tIO by Ada.text_IO everywhere in the file.
> * `:g/a/s// /g` replace the letter a, by blank
> * `:g/a/s///g` replace a by nothing
>
> note: Even this command be undone by u
>
> highlight the current word at the cursor with `*`, then `:%s//<replace_with>/g`

#### Undo

* `u`           | undo

### Insert Mode

* `i`       | enter insert mode
* `O`       | new line and start insert mode
* `A`       | navigate to the end of the current line and enter insert mode
* `I`       | navigate to the beginning of the current line and enter insert mode

### Command Mode
* `:`       | enter command mode

* `q`       | quit
* `w`       | save the file
* `write`   | save the file
* `x`       | save the file AND quit
* `e`       | open a file

> Examples
> `:e %:h/filename` will create or open a file relative to this directory (`%` refers to the current file, `:h` is a modifier for its directory)


---

#### Text Entry Commands (Used to start text entry)

* `a` Append text following current cursor position
* `A` Append text to the end of current line
* `i` Insert text before the current cursor position
* `I` Insert text at the beginning of the cursor line
* `o` Open up a new line following the current line and add text there
* `O` Open up a new line in front of the current line and add text there

## Command Mode

### Cursor Movement Commands

* `h` Moves the cursor one character to the left
* `l` Moves the cursor one character to the right
* `k` Moves the cursor up one line
* `j` Moves the cursor down one line
* `nG` or :n Cursor goes to the specified (n) line (ex. 10G goes to line 10)
* `^F` (CTRl F) Forward screenful
* `^B` Backward screenful
* `^f` One page forward
* `^b` One page backward
* `^U` Up half screenful
* `^D` Down half screenful
* `$` Move cursor to the end of current line
* `0` (zero) Move cursor to the beginning of current line
* `w` Forward one word
* `b` Backward one word

### Exit Commands

* `:wq` Write file to disk and quit the editor
* `ZZ` Save workspace and quit the editor (same as :wq)
* `:q` Quit (a warning is printed if a modified file has not been saved)
* `:q!` Quit (no warning)
* `: 10,25 w temp` write lines 10 through 25 into file named temp. Of course, other line numbers can be used. (Use :f to find out the line numbers you want.

### File Manipulation Commands

* `:w` Write workspace to original file
* `:w` file Write workspace to named file
* `:e` file Start editing a new file
* `:r` file Read contents of a file to the workspace

### Page Breaks
To create a page break, while in the insert mode, press the `CTRL+l`. `^L` will appear in your text and will cause the printer to start a new page.


## Other Useful Commands
Most commands can be repeated n times by typing a number, n, before the command. For example 10dd means delete 10 lines.

* `.` Repeat last command
* `cw` Change current word to a new word
* `r` Replace one character at the cursor position
* `R` Begin overstrike or replace mode � use ESC key to exit
* `:/` pattern Search forward for the pattern
* `:?` pattern Search backward for the pattern
* `n` used after either of the 2 search commands above to continue to find next occurrence of the pattern.
* `:g/pat1/s//pat2/g` replace every occurrence of pattern1 (pat1) with pat2

> Examples
> * `:g/tIO/s//Ada.Text_IO/g` will find and replace tIO by Ada.text_IO everywhere in the file.
> * `:g/a/s// /g` replace the letter a, by blank
> * `:g/a/s///g` replace a by nothing
>
> note: Even this command be undone by u



## Examples

### Opening a New File

1. Create a file, `vim [filename]`
2. Switch to insert mode, `i`
3. Enter text
4. Exit insert mode - enter command mode, `Esc`
5. Save file and exit vim, `:wq`

