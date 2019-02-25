Node.js
=======

## Encoding/Decoding base64 without btoa/atob
btoa (encoding), and atob (decoding) are not available in nodejs. We could install packages to use them, but it's really not necessary because we can use buffers to encode and decode UTF8 input.

```JavaScript
const input = 'hello world!'
const encoded = Buffer.from(input)
    .toString('base64')

const decoded = Buffer.from(encoded, 'base64').toString()

assert.strictEquals(decoded, input)
```

## Start script

```Shell
#!/bin/bash
#
# Starts the node app from the dist folder
#
# USAGE:
#     $ start
#     # => starts the app with node
#
#     $ start -w
#     # => starts the app with nodemon

set -e                                              # stop on error (e)
printf "\nrunning start...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')        # remove "bin" to get the parent/base directory
NODE_BIN="$BASE_DIR/node_modules/.bin"              # the directory of the executable node modules that are installed in this project
APP_PATH="$BASE_DIR/dist/app.js"                    # the path to the app composition (i.e. app.js|server.js|index.js)
WATCH=false                                         # start with node by default
set -x                                              # print each command (x)

while getopts ":w" opt; do                          # look for the `-w` switch and turn on WATCH if it's there
    case $opt in
        w)
            WATCH=true
            ;;
    esac
done

if [ $WATCH == true ]; then                         # if the watch switch was passed
    $NODE_BIN/nodemon $APP_PATH -e js,html,css $@   # start the app with nodemon & restart on changes to js, html, or css files
else                                                # otherwise
    node $APP_PATH                                  # start the process with node
fi
```