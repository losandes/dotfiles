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
| `chmod a-w [filename]` | ---------- | Remove write from user/group/global (myscript.sh), symbolic mode |
| `chmod = [filename]`   | ---------- | Remove read/write/execute from user/group/global (myscript.sh), symbolic mode |

## Roles
u - user (owner of the file)
g - group (members of file's group)
o - global (all users who are not owner and not part of group)
a - all (all 3 roles above)

## Numeric representations
7 - full (rwx)
6 - read and write (rw-)
5 - read and execute (r-x)
4 - read only (r--)
3 - write and execute (-wx)
2 - write only (-w-)
1 - execute only (--x)
0 - none (---)

