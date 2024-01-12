#!/bin/bash
#
#
SRC_DIR="./"
BIN_DIR="./bin"
MAIN="$SRC_DIR/main.c"
OUTPUT="$BIN_DIR/main"

mkdir -p $BIN_DIR

clang $MAIN -o $OUTPUT -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

if [ $? -eq 0 ]; then
	echo "Build Successful!"
	$OUTPUT
else 
	echo "Build Failed!"
fi
