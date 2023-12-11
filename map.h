#pragma once
#include <raylib.h>
#include <stdlib.h>
#include <stdio.h>
#include "character.h"

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

void initMap(ptrMap mappa);

void drawMap(ptrMap mappa);

void updateMap(ptrMap mappa, ptrCharacter personaggio);

ptrRoom createRoom(int roomNumber, int maxRooms, ptrRoom prev);

void positionDoor(ptrRoom stanza);