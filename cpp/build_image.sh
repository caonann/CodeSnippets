#!/bin/bash
cp ../generate.py .
docker build -t cppuint .
rm generate.py