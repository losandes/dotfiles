# POST JSON Body
There are several ways to post a body, all using bash syntax, rather than curl style -d:

You can pipe a file to http, using `<`:
```shell
$ http POST http://localhost:3000/something < my-file.json
```

You can pipe raw content to http, using `<<<`:
```shell
$ http POST http://localhost:3000/something <<< "{ foo: 'bar' }"
```

You can also pipe raw content to http, using `echo`:
```shell
$ echo "{ foo: 'bar' }" | http POST http://localhost:3000/something
```

