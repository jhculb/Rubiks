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
