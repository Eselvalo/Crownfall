#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>

typedef struct room {
    Rectangle shape;
    Texture2D tex;
    struct room *nextRoom;
    struct room *prevRoom;
} room;

typedef struct room *ptrRoom;


typedef struct map {

    ptrRoom listRoom;

    struct map *nextMap;
} map;

typedef struct map *ptrMap;

void initMap(ptrMap mappa);

void drawMap(ptrMap mappa);

void updateMap(ptrMap mappa);

ptrRoom createRoom();