## List Stored Procs

```sql
SELECT  p.proname
FROM    pg_catalog.pg_namespace n
JOIN    pg_catalog.pg_proc p
ON      p.pronamespace = n.oid
WHERE   n.nspname = 'public'
```

## Turn on logging:

Execute this, or connect to the docker container, and execute these lines. Afterwards you MUST RESTART postgres.

```Shell
#!/bin/bash
cat << EOF >> /var/lib/postgresql/data/postgresql.conf
log_statement = all
# log_min_duration_statement = 100
EOF
```

