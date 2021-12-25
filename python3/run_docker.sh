#!/bin/bash
set -x
containerid=`docker container ls -a -f "name=pythonuint" -q`
if [ -z ${containerid} ];then
    docker run -itd --name pythonuint --rm -p 80:8888 --mount type=bind,source=$(pwd),target=/app pythonuint
else
    docker exec -it ${containerid} /bin/bash
fi
