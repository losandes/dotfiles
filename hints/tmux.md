# TMUX Cheatsheet

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

