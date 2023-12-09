#include <raylib.h>
#include <stdlib.h>


typedef struct character {
    Rectangle sprite;
    Texture2D texture;
} character;

typedef struct character *ptrCharacter;

void initCharacter(ptrCharacter personaggio);

void drawCharacter(ptrCharacter personaggio);

void updateCharacter(ptrCharacter personaggio);
    
