Compression
===========

## Tar GZip
```
First option must be a mode specifier:
  -c Create  -r Add/Replace  -t List  -u Update  -x Extract

Common Options:
  -b #  Use # 512-byte records per I/O block
  -f <filename>  Location of archive
  -v    Verbose
  -w    Interactive

Create: tar -c [options] [<file> | <dir> | @<archive> | -C <dir> ]
  <file>, <dir>  add these items to archive
  -z, -j, -J, --lzma  Compress archive with gzip/bzip2/xz/lzma
  --format {ustar|pax|cpio|shar}  Select archive format
  --exclude <pattern>  Skip files that match pattern
  -C <dir>  Change to <dir> before processing remaining files
  @<archive>  Add entries from <archive> to output

List: tar -t [options] [<patterns>]
  <patterns>  If specified, list only entries that match

Extract: tar -x [options] [<patterns>]
  <patterns>  If specified, extract only entries that match
  -k    Keep (don't overwrite) existing files
  -m    Don't restore modification times
  -O    Write entries to stdout, don't restore to disk
  -p    Restore permissions (including ACLs, owner, file flags)
```

### To List Contents

* **-t**: List
* **-z**: Decompress archive with gzip
* **-j**: Decompress archive with bzip2
* **-J**: Decompress archive with xy
* **--lzma**: Decompress archive with lzma
* **-v**: Verbose
* **-f**: File-location

```Shell
tar -tzvf archive-name.tar.gz
```

### To Compress

* **-c**: Create
* **-z**: Compress archive with gzip
* **-v**: Verbose
* **-f**: File-location

```
tar -czvf archive-name.tar.gz folder-to-compress
```

### To Extract

* **-x**: Extract
* **-z**: Decompress archive with gzip
* **-v**: Verbose
* **-f**: File-location

```
tar -xzvf archive-name.tar.gz
```

## Zip

```
zip function.zip function.py
```

