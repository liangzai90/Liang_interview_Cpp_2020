#!/bin/bash

#begin
echo "build my project begin"

mkdir build && cd build && cmake ../ && make -j4

#finished
echo "build project finished"
