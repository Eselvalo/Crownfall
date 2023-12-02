#include <raylib.h>

typedef struct character {
    int posizione[2];
    int dimensioni[2]; // x e y
    Color colore;
    Texture2D texture;

} *character_;

void initCharacter(Vector2 pos, Texture2D tex, character_ personaggio);

void drawCharacter(character_ personaggio);

void updateCharacter(character_ personaggio);
    
