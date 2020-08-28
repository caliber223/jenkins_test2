ARG BASE_IMAGE=ubuntu:18.04
FROM ${BASE_IMAGE}

WORKDIR /dir1

ARG BUILD_PACKAGES='\
    git \
    g++ \
    make'

RUN apt-get update -qq && \
    DEBIAN_FRONTEND=noninteractive apt-get install -y --no-install-recommends $BUILD_PACKAGES

COPY ./Dockerfile ./Dockerfile
COPY ./Makefile ./Makefile
COPY ./Jenkinsfile ./Jenkinsfile
COPY ./README.md ./README.md
COPY ./repeat_check.cpp ./repeat_check.cpp
COPY ./repeat_check.h ./repeat_check.h
#COPY ./docker-entrypoint.sh ./docker-entrypoint.sh

RUN make

EXPOSE 4009

#ENTRYPOINT ["/docker-entrypoint.sh"]
CMD ["./repeat_check"]
