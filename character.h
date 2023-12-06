#include <raylib.h>
#include <stdlib.h>


typedef struct character {
    Vector2 posizione;
    Rectangle sprite;
    Texture2D texture;
} character;

typedef struct character *ptrCharacter;

void initCharacter(ptrCharacter personaggio, Texture2D tex);

void drawCharacter(ptrCharacter personaggio);

void updateCharacter(ptrCharacter personaggio);
    
