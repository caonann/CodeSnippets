#!/bin/bash
./go-stress-testing-linux -c 9 -n 20 -u http://127.0.0.1:8000/benchmark/

#docker run --rm --read-only -v `pwd`:`pwd` go-stress-testing -c 10000 -n 20 -u http://9.134.173.151:8000/benchmark