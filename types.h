#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>


typedef struct room {
    Rectangle shape;
    Rectangle door;
    Texture2D tex;
    int number;
    struct room *nextRoom;
    struct room *prevRoom;

} room;

typedef struct room *ptrRoom;


typedef struct map {

    int maxRooms;
    ptrRoom listRoom;
    struct map *nextMap;

} map;

typedef struct map *ptrMap;



typedef struct character {
    Rectangle sprite;
    Texture2D texture;
} character;

typedef struct character *ptrCharacter;
