#!/bin/bash

# Define directories
SRC_DIR="./"
BIN_DIR="./bin"
MAIN_FILE="$SRC_DIR/main.c" # Replace with your main source file
CHARACTER_FILE="$SRC_DIR/mainCharacter.c"
MAP_FILE="$SRC_DIR/Map.c"
CAM_FILE="$SRC_DIR/cam.c"
OUTPUT="$BIN_DIR/your_program" # Replace with your desired output binary name

# Create bin directory if it doesn't exist
mkdir -p $BIN_DIR

# Compilation command
clang $MAIN_FILE $CHARACTER_FILE $MAP_FILE $CAM_FILE -o $OUTPUT -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
    # Uncomment the following line to run the program after successful build
    # $OUTPUT
else
    echo "Build failed!"
fi
