ignore commands in history (i.e. export password=)
http://stackoverflow.com/questions/8473121/execute-command-without-keeping-it-in-history

## find out what's running on a port:

```
lsof -n -i:[PORT] | grep LISTEN
# i.e. lsof -n -i:3308 | grep LISTEN
```

## list all running services for all users:

```
ps -e
```

## list a running service:

```
# adding f provides more verbose output
ps -ef [PID]
```

## kill a service:

```
kill [ID]
```

## force-kill a service:

```
kill -9 [ID]
```

## kill all process that match

```
killall node
```

## Generate a secret

```
openssl rand -hex 32 | pbcopy
```

## I/O Redirection
https://stackoverflow.com/questions/592620/how-to-check-if-a-program-exists-from-a-bash-script
http://tldp.org/LDP/abs/html/io-redirection.html

### Redirecting output to a noop
This example finds the path for node, and hides the output if it doesn't exist. `2>/dev/null` redirects the output to a noop.

```Shell
# find the path for node, and hide the output if it doesn't exist
# 2>/dev/null redirects the output to a noop
type node 2>/dev/null
```

> NOTE that `2>&-` is not the same as `2>/dev/null`. The former closes the file descriptor, while the latter simply redirects it to `/dev/null`. You may not see an error because the program tries to inform you on stderr that stderr is closed.

