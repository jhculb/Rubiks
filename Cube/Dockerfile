<<<<<<< HEAD
FROM alpine:latest AS builder
ENV DEBIAN_FRONTEND noninteractive
RUN apk update && \
    apk add --no-cache binutils cmake make libgcc musl-dev gcc g++
COPY ./builder usr/cube
WORKDIR usr/cube
RUN make

# Thank you https://radupopescu.net/2016/06/
# static-linking-for-c-with-docker-and-alpine-linux/

# build-base
# Thank youhttps://blog.overops.com/
# my-alpine-desktop-setting-up-a-software-development-environment-on
# -alpine-linux/


FROM alpine:latest
RUN apk add libc6-compat &&\
    apk add bash &&\
    apk add g++
    #Do we need libc60-compact???
WORKDIR ./usr/cube
COPY docker-entrypoint.sh .
COPY --from=builder ./usr/cube/driver .
RUN chmod +x, docker-entrypoint.sh
ENTRYPOINT ["bash", "docker-entrypoint.sh"]
=======
FROM ubuntu AS builder
ENV DEBIAN_FRONTEND noninteractive
RUN apt-get update && \
    apt-get -y install gcc mono-mcs && \
    apt-get -y install make && \
    rm -rf /var/lib/apt/lists/*
COPY . usr/src/cube
WORKDIR usr/src/cube
RUN make
RUN make clean
RUN ls

FROM alpine:latest
WORKDIR /root/cube
COPY --from=builder /usr/src/cube/driver .
CMD ["./driver"]
>>>>>>> cd47b5bc8e21feeaf3bf86aba628e7ec872a554b
