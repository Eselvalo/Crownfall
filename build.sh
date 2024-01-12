#!/bin/sh

# Define directories
SRC_DIR="."
BIN_DIR="./bin"
MAIN_FILE="$SRC_DIR/main.c" # Replace with your main source file
CHARACTER_FILE="$SRC_DIR/character.c"
MAP_FILE="$SRC_DIR/map.c"
ALL_FILES="$SRC_DIR/*.c"
RAYLIB="$SRC_DIR/raylib/src"
OUTPUT="$BIN_DIR/your_program" # Replace with your desired output binary name

# Create bin directory if it doesn't exist
mkdir -p $BIN_DIR

# Make sure the raylib repo has been downloaded
git submodule init
git submodule update

# Compilation command
make -C $RAYLIB PLATFORM=PLATFORM_DESKTOP && clang $ALL_FILES -o $OUTPUT -L $RAYLIB -isystem $RAYLIB -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Check if compilation was successful
if [ $? -eq 0 ]; then
    echo "Build successful!"
    # Uncomment the following line to run the program after successful build
    # $OUTPUT
else
    echo "Build failed!"
fi
