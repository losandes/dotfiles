Database Migrations
===================

This document is a hint sheet for using [sqitch](https://sqitch.org) for database migrations.

## Getting Started
Before running the migrations, make sure you have [docker installed](https://www.digitalocean.com/community/tutorials/how-to-install-and-use-docker-on-ubuntu-16-04)

### Sqitch Docker Script

```Shell
#!/bin/bash

SQITCH_IMAGE=${SQITCH_IMAGE:=sqitch/sqitch:latest}        # Determine which Docker image to run.

# Find the directory of this script
# Assumes your scripts are nested in a "bin" directory
BIN_DIR="$( cd "$( dirname "${BASH_SOURCE[0]}" )" >/dev/null 2>&1 && pwd )"
BASE_DIR=$(echo $BIN_DIR | sed 's/\/bin//g')              # remove "bin" to get the parent/base directory
SQITCH_IMAGE_NAME=${SQITCH_IMAGE_NAME:=image_name_here}   # a custom name for the image (instead of random names)
user=${USER-$(whoami)}                                    # figure out who I am.

if [ "Darwin" = $(uname) ]; then                          # find my fullname, based on OS
    fullname=$(id -P $user | awk -F '[:]' '{print $8}')
else
    fullname=$(getent passwd $user | cut -d: -f5 | cut -d, -f1)
fi

passenv=(                                                 # Set up required pass-through variables.
    -e "SQITCH_ORIG_SYSUSER=$user"
    -e "SQITCH_ORIG_FULLNAME=$fullname"
    -e "SQITCH_ORIG_EMAIL=$user@$(hostname)"
    -e "TZ=$(date +%Z)" \
    -e "LESS=${LESS:--R}" \
)

# Iterate over optional Sqitch and engine variables.
for var in \
    SQITCH_CONFIG SQITCH_USERNAME SQITCH_PASSWORD SQITCH_FULLNAME SQITCH_EMAIL \
    DBI_TRACE \
    PGUSER PGPASSWORD PGHOST PGHOSTADDR PGPORT PGDATABASE PGSERVICE PGOPTIONS PGSSLMODE PGREQUIRESSL PGSSLCOMPRESSION PGREQUIREPEER PGKRBSRVNAME PGKRBSRVNAME PGGSSLIB PGCONNECT_TIMEOUT PGCLIENTENCODING PGTARGETSESSIONATTRS \
    MYSQL_PWD MYSQL_HOST MYSQL_TCP_PORT \
    TNS_ADMIN TWO_TASK ORACLE_SID \
    ISC_USER ISC_PASSWORD \
    VSQL_HOST VSQL_PORT VSQL_USER VSQL_PASSWORD VSQL_SSLMODE \
    SNOWSQL_ACCOUNT SNOWSQL_USER SNOWSQL_PWD SNOWSQL_HOST SNOWSQL_PORT SNOWSQL_DATABASE SNOWSQL_REGION NOWSQL_WAREHOUSE
do
    if [ -n "${!var}" ]; then
       passenv+=(-e $var)
    fi
done

# NOTE: the comments might need to be removed for the slashes to work
docker run \                                                        # run the container
    --name ${SQITCH_IMAGE_NAME} \                                   # the name the container should be given (or for which to run)
    -it \                                                           # interactive with pseudo TTY
    --rm \                                                          # automatically remove the container when it exits
    --network host \                                                # connect the container to the "host" network
    --mount "type=bind,src=$BASE_DIR,dst=/repo" \                   # mount the project directory so we can access migration scripts
    --mount "type=bind,src=$HOME,dst=/home" \                       # (WHY?) mount the user's ~ directory
    "${passenv[@]}" \                                               # sqitch pass-through variables (i.e. `-e "SQITCH_ORIG_SYSUSER=$user"`
    "$SQITCH_IMAGE" \                                               # the docker image to use
    "$@"                                                            # pipe other argument passed on the command line to this
```

## Connecting to Aurora DB
See `hint journey` _=> ## Connecting to Aurora DB_

## Verification (Postgres)

!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
TODO: 
select exists is not the correct way to verify

they will always verify to true

exists will pass even on an empty result set

`select 1/count(*)` is the correct way

and a simpler way to verify column existance

```sql
BEGIN;

SELECT is_active FROM my_schema.departments;

ROLLBACK;
```
!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!

### Verifying Roles

```sql
BEGIN;

SELECT EXISTS (
    SELECT 1
    FROM pg_catalog.pg_roles
    WHERE rolname = 'my_role_name'
);

ROLLBACK;
```

### Verifying Schemas

```sql
BEGIN;

SELECT EXISTS (
    SELECT 1
    FROM information_schema.schemata
    WHERE schema_name = 'my_schema'
);

ROLLBACK;
```

### Verifying Users

```sql
BEGIN;

SELECT EXISTS (
    SELECT 1
    FROM pg_catalog.pg_roles
    WHERE rolname = 'my_role_name'
);

SELECT has_database_privilege('my_role_name', 'my_database', 'CONNECT, TEMPORARY');
SELECT has_schema_privilege('my_role_name', 'my_schema', 'USAGE');

ROLLBACK;
```

### Verifying Table Creation

```sql
BEGIN;

SELECT EXISTS (
  SELECT 1
  FROM pg_catalog.pg_tables
  WHERE schemaname = 'my_schema'
    AND tablename = 'departments'
);

SELECT EXISTS (
  SELECT 1
  FROM pg_catalog.pg_indexes
  WHERE schemaname = 'my_schema'
    AND tablename = 'departments'
    AND indexname = 'departments_company_id_idx'
);

ROLLBACK;
```

### Verifying Unique Constraints

```sql
BEGIN;

SELECT EXISTS (
  SELECT 1
  FROM information_schema.constraint_column_usage
  WHERE table_schema = 'my_schema'
    AND table_name = 'departments'
    AND constraint_name = 'departments_something_unq'
);

ROLLBACK;
```

### Verifying Column Existence

```sql
BEGIN;

SELECT EXISTS (
    SELECT 1
    FROM information_schema.columns
    WHERE table_schema = 'my_schema'
        AND table_name   = 'departments'
        AND column_name = 'is_active'
);

ROLLBACK;
```
