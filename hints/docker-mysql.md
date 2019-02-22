## db-up

```Shell
#!/bin/bash
#
# Creates a docker image for MySQL, and runs it
# NOTE: the variables in this script can be overridden by exporting the values
# in your terminal i.e. export MYSQL_IMAGE_NAME=my-db-name

set -e                                            # stop on error (e)
printf "\nrunning db-up...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')                  # remove "bin" to get the parent/base directory
VOLUME_DIR="$BASE_DIR/db/mysql"                               # the path where the data will reside

# MySQL variables
MYSQL_PORT=${MYSQL_PORT:=3306}                                # the port mysql will broadcast on
MYSQL_ROOT_PASSWORD=${MYSQL_ROOT_PASSWORD:=password_here}     # the password for the root user
MYSQL_USER=${MYSQL_USER:=username_here}                       # the user we will connect to mysql with
MYSQL_PASSWORD=${MYSQL_PASSWORD:=password_here}               # the password for that user
MYSQL_DATABASE=${MYSQL_DATABASE:=db_name_here}                # the database we will connect to

# Docker image variables
MYSQL_IMAGE_VERSION=${MYSQL_IMAGE_VERSION:=5.7.25}            # the version of mysql we want
MYSQL_IMAGE=${MYSQL_IMAGE:=mysql:$MYSQL_IMAGE_VERSION}        # the full name of the docker image (i.e. mysql:5.7.25)
MYSQL_IMAGE_NAME=${MYSQL_IMAGE_NAME:=image_name_here}         # a custom name for the image (instead of random names)
MYSQL_IMAGE_PORT=${MYSQL_IMAGE_PORT:=$MYSQL_PORT:$MYSQL_PORT} # the port mapping (i.e. 3306:3306)

printf "\nrunning $MYSQL_IMAGE_NAME...\n\n"
mkdir -p $VOLUME_DIR                                          # Make sure the directory exists
docker run \                                                  # Run mysql in daemon mode, expose port 3306 and mount this directory to /repo
  --name $MYSQL_IMAGE_NAME \                                  # give the image a specific name
  --mount "type=bind,src=$BASE_DIR,dst=/repo" \               # mount the parent directory to the repo folder
  -p $MYSQL_IMAGE_PORT \                                      # set the port mapping (i.e. 3306:3306)
  -d \                                                        # run it detached (don't attach in this terminal)
  -e MYSQL_ROOT_PASSWORD=$MYSQL_ROOT_PASSWORD \               # set the root password
  -e MYSQL_USER=$MYSQL_USER \                                 # set the default username
  -e MYSQL_PASSWORD=$MYSQL_PASSWORD \                         # set the default password
  -e MYSQL_DATABASE=$MYSQL_DATABASE \                         # set the default database
  -v $VOLUME_DIR:/var/lib/mysql \                             # mount the mysql volume to support session persistence
  $MYSQL_IMAGE                                                # the docker image name (i.e. mysql:5.7.25)
```

## db-down

```Shell
#!/bin/bash
#
# Destroys a docker image, and the volumes associated with it
# NOTE: the variables in this script can be overridden by exporting the values
# in your terminal i.e. export MYSQL_IMAGE_NAME=my-db-name

set -e                                                # stop on error (e)
printf "\nrunning db-up...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')          # remove "bin" to get the parent/base directory
VOLUME_DIR="$BASE_DIR/db/mysql"                       # the path where the data resides
MYSQL_IMAGE_NAME=${MYSQL_IMAGE_NAME:=image_name_here} # the name of the image we're destroying

echo "removing $MYSQL_IMAGE_NAME"
docker rm -fv $MYSQL_IMAGE_NAME                       # Drop existing container (and remove volume it created)
rm -rf $VOLUME_DIR                                    # Destroy the local data directory
```

## db-stop

```Shell
#!/bin/bash
#
# Stops the database container

printf "\nrunning db-stop...\n\n"
MYSQL_IMAGE_NAME=${MYSQL_IMAGE_NAME:=image_name_here} # the name of the image we're stopping
docker container stop $MYSQL_IMAGE_NAME               # stop the container
```

## db-repl

```Shell
#!/bin/bash
#
# Brings up a mysql command prompt connected to the docker host

set -e                                            # stop on error (e)
printf "\nrunning db-repl...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')      # remove "bin" to get the parent/base directory
VOLUME_DIR="$BASE_DIR/db/mysql"                               # the path where the data will reside

# MySQL variables
MYSQL_USER=${MYSQL_USER:=username_here}                       # the user we will connect to mysql with
MYSQL_PASSWORD=${MYSQL_PASSWORD:=password_here}               # the password for that user
MYSQL_DATABASE=${MYSQL_DATABASE:=db_name_here}                # the database we will connect to

# Docker image variables
MYSQL_IMAGE_VERSION=${MYSQL_IMAGE_VERSION:=5.7.25}            # the version of mysql we want
MYSQL_IMAGE=${MYSQL_IMAGE:=mysql:$MYSQL_IMAGE_VERSION}        # the full name of the docker image (i.e. mysql:5.7.25)
MYSQL_IMAGE_NAME=${MYSQL_IMAGE_NAME:=image_name_here}         # a custom name for the image (instead of random names)

docker run -it --link $MYSQL_IMAGE_NAME:mysql --rm $MYSQL_IMAGE \
  sh -c 'exec mysql "$MYSQL_ENV_MYSQL_DATABASE" -h"$MYSQL_PORT_3306_TCP_ADDR" -P"$MYSQL_PORT_3306_TCP_PORT" -u"$MYSQL_ENV_MYSQL_USER" -p"$MYSQL_ENV_MYSQL_PASSWORD"'
```

## db-sh

```Shell
#!/bin/bash
#
# Brings up a bash command prompt connected to the docker host

printf "\nrunning db-sh...\n\n"
MYSQL_IMAGE_NAME=${MYSQL_IMAGE_NAME:=image_name_here}         # a custom name for the image (instead of random names)
docker exec -it $MYSQL_IMAGE_NAME bash
```
