#!/bin/bash
go_install_url=https://go.dev/dl/go1.18.2.linux-amd64.tar.gz
wget $go_install_url
docker build -t golanguint .
