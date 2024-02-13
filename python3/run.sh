#!/bin/bash

# Enable debugging
set -x

# Name of the Docker container
CONTAINER_NAME="pythonuint"

# Port mapping
HOST_PORT=80
CONTAINER_PORT=8888

# Volume mapping
HOST_VOLUME=$(pwd)
CONTAINER_VOLUME="/app"

# Docker image name
IMAGE_NAME="pythonuint"

# Check if the container already exists
CONTAINER_ID=$(docker container ls -a -f "name=${CONTAINER_NAME}" -q)

# If the container does not exist, run it
if [ -z "${CONTAINER_ID}" ]; then
    echo "Container ${CONTAINER_NAME} does not exist. Running a new one."
    docker run -itd --name "${CONTAINER_NAME}" --rm -p ${HOST_PORT}:${CONTAINER_PORT} --mount type=bind,source="${HOST_VOLUME}",target="${CONTAINER_VOLUME}" "${IMAGE_NAME}"
else
    # If the container exists but is not running, start it
    RUNNING=$(docker inspect --format="{{.State.Running}}" "${CONTAINER_ID}")
    if [ "${RUNNING}" == "false" ]; then
        echo "Container ${CONTAINER_NAME} exists but is not running. Starting the container."
        docker start "${CONTAINER_ID}"
    fi
    # Enter the running container
    echo "Entering the container ${CONTAINER_NAME}."
    docker exec -it "${CONTAINER_ID}" /bin/bash
fi

# Disable debugging
set +x
