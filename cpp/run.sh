#!/bin/bash
set -x
name=cppuint
containerid=$(docker container ls -a -f "name=${name}" -q)
if [ -z ${containerid} ];then
    docker run -it --name ${name} --rm --cap-add=SYS_PTRACE --mount type=bind,source=$(pwd),target=/app ${name}
else
    docker exec -it ${containerid} /bin/bash
fi
