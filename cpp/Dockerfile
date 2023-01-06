ARG UBUNTU_VERSION=20
FROM ubuntu:${UBUNTU_VERSION}.04
RUN mv /etc/apt/sources.list /etc/apt/sources.list.bak
COPY ./.sources.list.ubuntu20.04 /etc/apt/sources.list
COPY ./generate.py /generate.py
RUN apt-get clean all && apt-get update && \
    DEBIAN_FRONTEND=noninteractive \
    apt-get install -y wget git curl iputils-ping net-tools vim cmake gcc g++ gdb libboost-all-dev python3.9 && \
    ln -s /usr/bin/python3.9 /usr/bin/python && \
    apt-get clean && \
    apt-get autoremove &&\
    echo "alias g='/generate.py'" >> ~/.bashrc &&\
    rm -rf /var/lib/apt/lists/* &&\
    rm -rf /var/cache/apt/archives/*
    
WORKDIR /app
ENTRYPOINT ["g++"]