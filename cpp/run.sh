#!/bin/bash
set -x
containerid=`docker container ls -a -f "name=cppuint" -q`
if [ -z ${containerid} ];then
    docker run -it --name cppuint --rm --mount type=bind,source=$(pwd),target=/app cppuint
else
    docker exec -it ${containerid} /bin/bash
fi
