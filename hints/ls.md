## List all of the exports in context

```Shell
export -p
```

## List all of the Terraform ENVVARS in context

```Shell
export -p | grep TF_VAR
```

## List all files in a directory, vertically, and differentiate files, folders, executables, and symlinks

```Shell
ls -FGhl1a
```

## List available aliases

```Shell
compgen -a
```

## List available functions

```Shell
compgen -A function
```

## Print the current working directory

```Shell
echo $PWD
```

