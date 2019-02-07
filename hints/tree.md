## print a tree

```
#!/usr/bin/env bash

CMD="find . -print | grep -v .*\.git | grep -v .*\.vscode | grep -v .*node_modules* | grep -v .*\.eslintrc"

for EXT in js json md html less css sh sql ts
do
    CMD="$CMD | grep -v .*\.$EXT$"
done

eval $CMD | sed -e 's;[^/]*/;|____;g;s;____|; |;g'
```

## OR install tree

```
$ brew install tree
$ tree -d -I *node_modules*
```

