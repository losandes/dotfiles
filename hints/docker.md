
## Building a Docker container

Navigate to the directory where your Dockerfile is, and:

```
 docker build -t [PROJECT_ID] .
```

> Note the `.` at the end. I think that means current directory.

## Running a Docker Container

```
docker run -d -p 8080:8080 [PROJECT_ID]
```

## List the running processes

```
docker ps
```

## List all containers

```
docker ps -a
```

## Stopping a Docker container

```
docker stop [PROCESS_ID]
```

## Accessing the host from within a container
-To access the host machine from a running docker container you can resolve the host via `docker.for.mac.localhost`
