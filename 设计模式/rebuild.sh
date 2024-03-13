#!/bin/bash

#rebuild 
echo "rebuild my project "

cd build && cmake ../ && make -j4

#finished
echo "rebuild project finished"
