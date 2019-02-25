## List Stored Procs

```sql
SELECT  p.proname
  FROM    pg_catalog.pg_namespace n
  JOIN    pg_catalog.pg_proc p
  ON      p.pronamespace = n.oid
  WHERE   n.nspname = 'public'
```

## Turn on logging

Sign on to the machine postgres is running on, and add `log_statement = all` to the "postgresql.conf". Afterwards you MUST RESTART postgres.

```Shell
#!/bin/bash
cat << EOF >> /var/lib/postgresql/data/postgresql.conf
log_statement = all
# log_min_duration_statement = 100
EOF
```
