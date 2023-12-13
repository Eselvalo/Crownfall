#!/bin/bash

<<<<<<< HEAD
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
=======
# Define directories
SRC_DIR="./"
BIN_DIR="./bin"
MAIN_FILE="$SRC_DIR/main.c" # Replace with your main source file
CHARACTER_FILE="$SRC_DIR/character.c"
MAP_FILE="$SRC_DIR/map.c"
OUTPUT="$BIN_DIR/your_program" # Replace with your desired output binary name
>>>>>>> origin/sdroggio

# Create bin directory if it doesn't exist
mkdir -p $BIN_DIR

# Compilation command
<<<<<<< HEAD
clang $MAIN_FILE -o $OUTPUT -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
=======
clang $MAIN_FILE $CHARACTER_FILE $MAP_FILE -o $OUTPUT -lraylib -lGL -lm -lpthread -ldl -lrt -lX11
>>>>>>> origin/sdroggio

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
<<<<<<< HEAD
    # Uncomment the following line to run the program after a successful build
=======
    # Uncomment the following line to run the program after successful build
>>>>>>> origin/sdroggio
    # $OUTPUT
else
    echo "Build failed!"
fi
<<<<<<< HEAD

=======
>>>>>>> origin/sdroggio
