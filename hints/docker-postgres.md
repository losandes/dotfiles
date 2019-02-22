## db-up

```Shell
#!/bin/bash
#
# Creates a docker image for Postgres, and runs it
# NOTE: the variables in this script can be overridden by exporting the values
# in your terminal i.e. export PG_IMAGE_NAME=my-db-name

set -e                                            # stop on error (e)
printf "\nrunning db-up...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')      # remove "bin" to get the parent/base directory
VOLUME_DIR="$BASE_DIR/db/postgres"                # the path where the data will reside

# Postgres variables
PGPORT=${PGPORT:=5432}                            # the port postgres will broadcast on
PGUSER=${PGUSER:=username_here}                   # the user we will connect to postgres with
PGPASSWORD=${PGPASSWORD:=password_here}           # the password for that user
PGDATABASE=${PGDATABASE:=db_name_here}            # the database we will connect to

# Other available Postgre ENVVARS
# PGHOST PGHOSTADDR PGPORT PGDATABASE PGSERVICE PGOPTIONS PGSSLMODE
# PGREQUIRESSL PGSSLCOMPRESSION PGREQUIREPEER PGKRBSRVNAME PGKRBSRVNAME
# PGGSSLIB PGCONNECT_TIMEOUT PGCLIENTENCODING PGTARGETSESSIONATTRS

# Docker image variables
PG_IMAGE_VERSION=${PG_IMAGE_VERSION:=10.5}        # the version of postgres we want
PG_IMAGE=${PG_IMAGE:=postgres:$PG_IMAGE_VERSION}  # the full name of the docker image (i.e. postgres:10.5)
PG_IMAGE_NAME=${PG_IMAGE_NAME:=image_name_here}   # a custom name for the image (instead of random names)
PG_IMAGE_PORT=${PG_IMAGE_PORT:=$PGPORT:$PGPORT}   # the port mapping (i.e. 5432:5432)

printf "\nrunning $PG_IMAGE_NAME...\n\n"
mkdir -p $VOLUME_DIR                              # Make sure the directory exists
docker run \                                      # Run postgres in daemon mode, expose port 5423 and mount this directory to /repo
  --name $PG_IMAGE_NAME \                         # give the image a specific name
  --mount "type=bind,src=$BASE_DIR,dst=/repo" \   # mount the parent directory to the repo folder
  -p $PG_IMAGE_PORT \                             # set the port mapping (i.e. 5432:5432)
  -d \                                            # run it detached (don't attach in this terminal)
  -e POSTGRES_USER=$PGUSER \                      # set the default username
  -e POSTGRES_PASSWORD=$PGPASSWORD \              # set the default password
  -e POSTGRES_DB=$PGDATABASE \                    # set the default database
  -v $VOLUME_DIR:/var/lib/postgresql \            # mount the postgres volume to support session persistence
  $PG_IMAGE                                       # the docker image name (i.e. postgres:10.5)
```

## db-down

```Shell
#!/bin/bash
#
# Destroys a docker image, and the volumes associated with it
# NOTE: the variables in this script can be overridden by exporting the values
# in your terminal i.e. export PG_IMAGE_NAME=my-db-name

set -e                                            # stop on error (e)
printf "\nrunning db-down...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')      # remove "bin" to get the parent/base directory
VOLUME_DIR="$BASE_DIR/db/postgres"                # the path where the data resides
PG_IMAGE_NAME=${PG_IMAGE_NAME:=image_name_here}   # the name of the image we're removing

echo "removing $PG_IMAGE_NAME"
docker rm -fv $PG_IMAGE_NAME                      # Drop existing container (and remove volume it created)
rm -rf $VOLUME_DIR                                # Destroy the local data directory
```

## db-stop

```Shell
#!/bin/bash
#
# Stops the database container

printf "\nrunning db-stop...\n\n"
PG_IMAGE_NAME=${PG_IMAGE_NAME:=image_name_here}   # the name of the image we're stopping
docker container stop $PG_IMAGE_NAME              # stop the container
```

## db-repl

```Shell
#!/bin/bash
#
# Brings up a postgres command prompt connected to the docker host

set -e                                            # stop on error (e)
printf "\nrunning db-repl...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')      # remove "bin" to get the parent/base directory
VOLUME_DIR="$BASE_DIR/db/postgres"                # the path where the data resides

# Postgres variables
PGUSER=${PGUSER:=username_here}                   # the user we will connect to postgres with
PGPASSWORD=${PGPASSWORD:=password_here}           # the password for that user
PGDATABASE=${PGDATABASE:=db_name_here}            # the database we will connect to

# Docker image variables
PG_IMAGE_VERSION=${PG_IMAGE_VERSION:=10.5}        # the version of postgres we want
PG_IMAGE=${PG_IMAGE:=postgres:$PG_IMAGE_VERSION}  # the full name of the docker image (i.e. postgres:10.5)
PG_IMAGE_NAME=${PG_IMAGE_NAME:=image_name_here}   # a custom name for the image (instead of random names)

docker run -it --rm --link ${PG_IMAGE_NAME}:postgres --rm ${PG_IMAGE} \
  psql --host=0.0.0.0 --username=${PGUSER} --dbname=${PGDATABASE}
```

## db-sh

```Shell
#!/bin/bash
#
# Brings up a bash command prompt connected to the docker host

printf "\nrunning db-sh...\n\n"
PG_IMAGE_NAME=${PG_IMAGE_NAME:=image_name_here}   # a custom name for the image (instead of random names)
docker exec -it $PG_IMAGE_NAME bash
```
