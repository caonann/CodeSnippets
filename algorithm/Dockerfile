FROM ubuntu:18.04
WORKDIR /app
RUN apt-get -y update && apt-get install -y ssh gcc g++ cmake vim git
ENTRYPOINT /usr/sbin/sshd -D
