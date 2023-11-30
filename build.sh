#!/bin/bash

# Check if an argument is provided
if [ "$#" -ne 1 ]; then
    echo "Usage: ./build.sh <sourcefile.c>"
    exit 1
fi

# Define directories
SRC_DIR="./"
BIN_DIR="./bin"
MAIN_FILE="$SRC_DIR/$1" # Use the provided argument as the source file
OUTPUT="$BIN_DIR/$(basename $1 .c)" # Create output name based on the source file name

# Create bin directory if it doesn't exist
mkdir -p $BIN_DIR

# Compilation command
clang $MAIN_FILE -o $OUTPUT -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
    # Uncomment the following line to run the program after a successful build
    # $OUTPUT
else
    echo "Build failed!"
fi

