# your project folder that we can `c [tab]` to
export PROJECTS="$HOME/src"

# use ripgreip for fzf (fuzzy find)
[ -f ~/.fzf.zsh ] && source ~/.fzf.zsh
export FZF_DEFAULT_COMMAND='rg --files --smart-case'

# set my editor (for use with bin/e)
export EDITOR=nvim

# always start tmux in 256 color mode
alias tmux="TERM=screen-256color-bce tmux"

# pipe my public key to my clipboard.
alias pubkey="more ~/.ssh/id_rsa.pub | pbcopy | echo '=> Public key copied to pasteboard.'"

# for checking shasums
alias sha256sum="shasum -a 256"

# for powershell
alias pshell=pwsh
alias powershell=pwsh
