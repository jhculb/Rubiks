# Thank you https://radupopescu.net/2016/06/
# static-linking-for-c-with-docker-and-alpine-linux/

# build-base
# Thank youhttps://blog.overops.com/
# my-alpine-desktop-setting-up-a-software-development-environment-on
# -alpine-linux/

FROM alpine:latest AS builder
ENV DEBIAN_FRONTEND noninteractive
RUN apk update && \
    apk add --no-cache binutils cmake make libgcc musl-dev gcc g++
COPY ./builder usr/cube
WORKDIR usr/cube
RUN make

FROM alpine:latest AS app
RUN apk add bash &&\
    apk add g++
WORKDIR ./usr/cube
COPY --from=builder ./usr/cube/driver .