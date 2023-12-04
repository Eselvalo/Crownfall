#!/bin/bash

if [ "$#" -ne 1 ]; then
    echo "Usage: ./build.sh <sourcefile.c>"
    exit 1
fi

SRC_DIR="./"
BIN_DIR="./bin"
MAIN_FILE="$SRC_DIR/$1"
OUTPUT="$BIN_DIR/$(basename $1 .c)"
mkdir -p $BIN_DIR
clang $MAIN_FILE -o $OUTPUT -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
if [ $? -eq 0 ]; then
    echo "Build successful!"
else
    echo "Build failed!"
fi
