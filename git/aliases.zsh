# Use `hub` as our git wrapper:
#   http://defunkt.github.com/hub/
hub_path=$(which hub)
if (( $+commands[hub] ))
then
  alias git=$hub_path
fi

local ONELINE_FORMAT='%C(yellow)%h %C(cyan)%an: %C(reset)%s%C(blue)%d %C(green)%cr%C(reset)'
local VERBOSE_FORMAT='%C(yellow)%h %C(cyan)%an %C(reset)%cr %C(blue) %d %C(reset)%n%C(red)## %s%C(reset)%n%b'
local TITLE_MSG_FORMAT='%n%C(red)## %s%C(reset)%n%b'

# Show the git log in one line format
# `glgo -- path/to/something` # show the log for a single file
# `glgo --follow -- path/to/something` # show the moves, and renames of a file
# `glgo --since 2019-01-01` # show changes since a time
# `glgo -S search_string` # find the commit history of a string of code (considercombining with -u)
alias glgo="git log --pretty=format:'${ONELINE_FORMAT}' $@"

# Show the git log in verbose format
alias glgv="git log --pretty=format:'${VERBOSE_FORMAT}' $@"

# Show just the commit titles and messages from the git log
alias glgpr="git log --pretty=format:'${TITLE_MSG_FORMAT}' $@"

# Show the log of master
alias glg-master="git log -u origin/master --pretty=format:'${ONELINE_FORMAT}' $@"

# See if there are changes on master that aren't in my HEAD
alias glg-changes-to-master-not-in-head="git log HEAD..origin/master --pretty=format:'${ONELINE_FORMAT}' $@"

# See if there are changes to HEAD that aren't in master
alias glg-changes-to-head-not-in-master="git log origin/master..HEAD --pretty=format:'${ONELINE_FORMAT}' $@"

# Copy the commit tiles and messages to the clipboard
alias glgcp="git-copy-since-hash"

# Set this branches upstream
alias gsu="git branch --set-upstream-to=origin/`git symbolic-ref --short HEAD`"

# Push HEAD to the origin 
alias gp='git push origin HEAD'

local REMOVE_PLUSMINUS="s/^\([^-+ ]*\)[-+ ]/\\1/"

# Remove `+` and `-` from start of diff lines; just rely upon color.
alias gd="git diff --color | sed '${REMOVE_PLUSMINUS}' | less -r"

# Show _commited_ changes between HEAD and master
alias gdm="git diff origin/master HEAD --color | sed '${REMOVE_PLUSMINUS}' | less -r"

# Show _uncommited and commited_ changes between HEAD and master
alias gdm-uncommited="git diff origin/master --color | sed '${REMOVE_PLUSMINUS}' | less -r"

alias ga='git add -A'
alias gc='git commit'
alias gcb='git copy-branch-name'
alias gb='git branch'
alias gs='git status -sb' # upgrade your git if -sb breaks for you. it's fun.

# Git add interactive, to choose which chunks to include, and then commit
alias gaic='git add -p && git commit'

# Git stash (include untracked files)
alias gstash='git stash -u'

