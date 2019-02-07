## Check the permissions of a file

```Shell
ls -l [filename]
```

The output displays the permissions of the owner, the group, and others

Owner	-rwx------
Group	----rwx---
Other	-------rwx

## Change the permissions of a file

| Example                | Outcome    | Description |
|------------------------|------------|-------------|
| `chmod 700 [filename]` | -rwx------ | Grant full permissions to the owner, and lock everyone else out |
| `chmod 755 [filename]` | -rwxr-xr-x | Grant full access to the owner, and read+execute to everyone else |
| `chmod 777 [filename]` | -rwxrwxrwx | (avoid) Grant full access to everyone |
| `chmod +x [filename]`  | -rwx--x--x | Grant full permissions to the owner, and allow everyone else to execute, but not read or write |
| `chmod 600 [filename]` | -rw------- | Grant read+write to the owner, and lock everyone else out |
| `chmod 644 [filename]` | -rw-r--r-- | Grant read+write to the owner, and read to everyone else |
| `chmod 666 [filename]` | -rw-rw-rw- | (avoid) Grant read+write to everyone |

