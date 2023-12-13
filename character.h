#pragma once
#include <raylib.h>
#include <stdlib.h>
#include "map.h"


typedef struct character {
    Rectangle sprite;
    Texture2D texture;
} character;

typedef struct character *ptrCharacter;

void initCharacter(ptrCharacter personaggio, ptrMap mappa);

void drawCharacter(ptrCharacter personaggio);

void updateCharacter(ptrCharacter personaggio);
    
