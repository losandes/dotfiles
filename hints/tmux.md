TMUX Cheatsheet
===============

* https://hackernoon.com/a-gentle-introduction-to-tmux-8d784c404340
* https://gist.github.com/MohamedAlaa/2961058

```Shell
$ tmux new -s [session name]              # Start new named session
$ ctrl+b d                                # Detach from session
$ tmux ls                                 # List sessions
$ tmux a -t [name of session]             # Attach to named session
$ tmux kill-session -t [name of session]  # Kill named session
$ ctrl+b "                                # Split panes horizontally
$ ctrl+b %                                # Split panes vertically
$ ctrl+b x                                # Kill current pane
$ ctrl+b [arrow key]                      # Move to another pane
$ ctrl+b o                                # Cycle through panes
$ ctrl+b ;                                # Cycle just between previous and current pane
$ tmux kill-server                        # Kill tmux server, along with all sessions
```

## Example tmux script

```Shell
#!/usr/local/Cellar/tmux/2.8/bin/tmux source-file
#
# Displays 4 panes: 1 empty terminal, one with an app started, one
# with the tests running, and one with ngrok connected to port 3000
#
# USAGE:
#    $ tmux
#    $ develop  # (assuming you named this script develop)
#    => starts the panes and the commands associated with them

new-session -d
split-window -t 0 -h
split-window -t 1 -v
split-window -t 2 -v

send-keys -t 2 './start' enter
send-keys -t 1 './test -w -R nyan' enter
send-keys -t 3 'ngrok http 3000' enter

# usage: resize-pane [-DLRUZ] [-x width] [-y height] [-t target-pane] [adjustment]
resize-pane -t 0 -x 50
resize-pane -t 1 -y 10
resize-pane -t 3 -y 10

# select the 1st pane
select-pane -t 0

attach
```
