```
docker-compose up --build

# or to stand up a particular service in docker-compose:
docker-compose up --build node-client
# where "node-client" is the name of the service in the yaml
```

example yaml:

```yaml
version: "2.1"
services:
  some_service:
    container_name: some-service
    build:
      context: .
      dockerfile: ./server/Dockerfile
    ports:
      - 3000:3000
    depends_on:
      database-service:
        condition: service_healthy
    volumes:
      - ./server/database/scripts/migrations.sh:/docker-entrypoint-initdb.d/migrations.sh
      - ./server/:/home/app/ # TODO: just map in what is specific to the service
      - ./certificates:/home/app/certificates # TODO: Some default certificates could be in the base image
    environment:
      CONNECTION_STRING: 'postgresql://setting_app@database-service:5432/some-db'
      # TODO: research these:
      THREAD_COUNT: 1
      PROCESS_COUNT: 1

  database-service:
    container_name: database-service
    image: mybiz.jfrog.io/database-service
    ports:
      - 15432:5432
    healthcheck:
      test: "psql 'postgresql://postgres@localhost:5432/some-db' -c 'SELECT 1;' && ! test -e /var/lib/postgresql/initdb.lock"
      interval: 3s
      retries: 10

  node-client:
    build:
      context: .
      dockerfile: ./client/node/Dockerfile
    depends_on:
      some_service:
        condition: service_healthy
    volumes:
      - ./certificates:/client/certificates
    links:
      - 'some_service:some-service'
    environment:
      HELLO_WORLD: 'ENVVARS!'
    command: 'npm run test:tap/'
```

