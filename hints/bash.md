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

## Script arguments

Positional arguments can be accessed by their 1-based number: `${1}` is the first argument, `${2}`, etc.

When accepting multiple arguments, and we can't rely on position, we can find arguments using `getopts`. The example belowdemonstrates how we would find a switch argument: `-w` (i.e. `start-app -w`)

```Shell
#!/bin/sh

while getopts ":w" opt; do
    case $opt in
        w)
            echo "The -w switch for watching for file changes is on"
            ;;
        \?)
            echo "Invalid option: -$OPTARG" >&2
            ;;
    esac
done
```

If our argument _takes_ an argument, we can find the value with `$OPTARG` (i.e. `start-app -w js`).

```Shell
#!/bin/sh

while getopts ":w:" opt; do
  case $opt in
    w)
      echo "The -w switch for watching $OPTARG files is on" >&2
      ;;
    \?)
      echo "Invalid option: -$OPTARG" >&2
      exit 1
      ;;
    :)
      echo "Option -$OPTARG requires an argument." >&2
      exit 1
      ;;
  esac
done
```

### Forwarding arguments from one script to another
If we need to forward the arguments of one script to other script(s), we can use `$@`, and `$*`. The difference between the two is that `$*` combines all of the arguments into a single string, while `$@` requotes each argument. In the following example, we use `$*` to add all of the arguments to a string that is being executed by a third party tool, _mocha_.

```Shell
#!/bin/sh

$PWD/node_modules/nodemon/bin/nodemon.js "$PWD/dist" -e js --exec "$PWD/bin/od-test $* || true"
```

Where as if we were calling it directly, we could use `$@`

```Shell
#!/bin/sh

./od-test $@
```

More here: [bash by example](http://matt.might.net/articles/bash-by-example/), and [small getopts tutorial](https://wiki.bash-hackers.org/howto/getopts_tutorial).

