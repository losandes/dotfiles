DBJourney
=========

[DBJourney](https://github.com/db-journey/journey) is a project written in go, for performing schema migrations.

## Example usage From Terminal

```Shell
# help
journey --help

# create new migration file in path
journey --url driver://url --path ./migrations migrate create migration_file_xyz

# apply all available migrations
journey --url driver://url --path ./migrations migrate up

# roll back all migrations
journey --url driver://url --path ./migrations migrate down

# roll back the most recently applied migration, then run it again.
journey --url driver://url --path ./migrations migrate redo

# run down and then up command
journey --url driver://url --path ./migrations migrate reset

# show the current migration version
journey --url driver://url --path ./migrations migrate version

# apply the next n migrations
journey --url driver://url --path ./migrations migrate migrate +1
journey --url driver://url --path ./migrations migrate migrate +2
journey --url driver://url --path ./migrations migrate migrate +n

# roll back the previous n migrations
journey --url driver://url --path ./migrations migrate migrate -1
journey --url driver://url --path ./migrations migrate migrate -2
journey --url driver://url --path ./migrations migrate migrate -n

# go to specific migration
journey --url driver://url --path ./migrations migrate goto 1
journey --url driver://url --path ./migrations migrate goto 10
journey --url driver://url --path ./migrations migrate goto v
```

## Common Examples

```Shell
# create new migration file
$ ./journey \
  -url "postgres://${DB_USER}:${DB_PASSWORD}@localhost/${DB_NAME}?sslmode=disable" \
  -path ${PATH_TO_SCHEMA_FILES} \
  migrate create [describe_your_script]

# apply all available migrations
$ ./journey \
  -url "postgres://${DB_USER}:${DB_PASSWORD}@localhost/${DB_NAME}?sslmode=disable" \
  -path ${PATH_TO_SCHEMA_FILES} \
  migrate up

# roll back all migrations
$ ./journey
  -url "postgres://${DB_USER}:${DB_PASSWORD}@localhost/${DB_NAME}?sslmode=disable" \
  -path ${PATH_TO_SCHEMA_FILES} \
  migrate down
```

## Connecting to Aurora DB
Before connecting to an Aurora DB, check to make sure the IP Address of the machine you will be performing migrations from is whitelisted:

```
$ nc -zv demo-cluster-1.cluster-abcd1234fghi.us-east-1.rds.amazonaws.com 5432
#   => Connection to demo-cluster-1.cluster-abcd1234fghi.us-east-1.rds.amazonaws.com port 5432 [tcp/postgresql] succeeded!
```

> Where "demo-cluster-1.cluster-abcd1234fghi.us-east-1.rds.amazonaws.com" is the URL of your aurora cluster

If your IP is not whitelisted, you can add it to the whitelist by adding it to the [appropriate security group](https://console.aws.amazon.com/ec2/v2/home?region=us-east-1#SecurityGroups:search=[SECURITY_GROUP_ID_HERE];sort=groupId). To add your IP:

1. Find your IP Address: `curl ipecho.net/plain ; echo` or `curl ifconfig.me ; echo`
1. Navigate to the security group you need to add it to, click, "Actions" => "Edit inbound rules" => "Add Rule"
1. Choose "PostgreSQL" as the type
1. Add your IP Address with a prefix length of 32 (i.e. a.b.c.d/32)
1. Add a comment describing the IP Address you are whitelisting (i.e. "USER_NAME home IP yyyyMMdd")

## Example "up" script

```Shell
#!/bin/bash
#
# Runs "up" migrations found in ${SCHEMA_PATH}

set -e                                            # stop on error (e)
printf "\nrunning schema-up...\n\n"

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')      # remove "bin" to get the parent/base directory
SCHEMA_DIR="$BASE_DIR/db/schema"                  # the path where the schema migrations will reside

# Add any
PGUSER=${PGUSER:=username_here}                   # the user we will connect to postgres with
PGPASSWORD=${PGPASSWORD:=password_here}           # the password for that user
PGDATABASE=${PGDATABASE:=db_name_here}            # the database we will connect to
MY_DB_HOST=${MY_DB_HOST:="0.0.0.0"}
MY_DB_URL=${MY_DB_URL:="postgres://${PGUSER}:${PGPASSWORD}@${MY_DB_HOST}/${PGDATABASE}"}

# Assumes you have two journey binaries: one for macos, and another for linux, named appropriately
if [ "$(uname)" == "Darwin" ]; then
    $BIN_DIR/journey-macos -url ${MY_DB_URL} -path ${SCHEMA_PATH} migrate up
elif [ "$(expr substr $(uname -s) 1 5)" == "Linux" ]; then
    $BIN_DIR/journey-linux -url ${MY_DB_URL} -path ${SCHEMA_PATH} migrate up
fi
```