## Find words, and then reduce the results within a folder

```
find src/ | grep migrations | grep users_table
```

## Count instances of a word

```
grep "401" foo.log | wc -l
```

## Find the first instance of a word

```
grep -m 1 "401" foo.log
```

## Get the lines around a query

Get 2 lines before (`-B`) and 3 lines after (`-A`):
```
grep -B 3 -A 2 "401" foo.log
```

Get 3 lines before and 3 lines after:
```
grep -C 3 "401" foo.log
```

# Get the lines around the nth match of a word

```
grep -m 3 -C 3 "401" foo.log
```

# Find in files by file type

```
$EXT=js
$TXT="import"
grep -rn --include="*.$EXT" $TXT *
```

Or interactively:

```
read -p "What extension do you want to search for? " ext; read -p "What text do you want to search for? " txt; grep -rn --include="*.$ext" $txt *;
```

