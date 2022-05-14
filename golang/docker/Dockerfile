ARG UBUNTU_VERSION=20
FROM ubuntu:${UBUNTU_VERSION}.04
RUN mv /etc/apt/sources.list /etc/apt/sources.list.bak
COPY ./.sources.list.ubuntu20.04 /etc/apt/sources.list
ARG GO_PACKAGE=go1.18.2.linux-amd64.tar.gz
COPY ${GO_PACKAGE} /root

RUN apt-get clean all && apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y wget git curl iputils-ping net-tools vim cmake gcc g++ gdb libboost-all-dev python3.9 && \
    ln -s /usr/bin/python3.9 /usr/bin/python && \
    apt-get clean && \
    apt-get autoremove &&\
    rm -rf /var/lib/apt/lists/* &&\
    rm -rf /var/cache/apt/archives/*


RUN rm -rf /usr/local/go && tar -C /usr/local -xzf /root/${GO_PACKAGE}
RUN echo "export PATH=\$PATH:/usr/local/go/bin" >> $HOME/.bashrc
RUN rm /root/${GO_PACKAGE}

WORKDIR /app
