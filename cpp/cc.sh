#!/bin/bash

docker run --rm -v $(pwd):/app cppuint "$*"