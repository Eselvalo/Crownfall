#include <raylib.h>

typedef struct character {
    int posizione[2];
    int dimensioni[2]; // x e y
    Color colore;
    Texture2D texture;

} character;

void initCharacter(Vector2 pos, Texture2D tex, character personaggio);

void drawCharacter(character personaggio);

void updateCharacter(character personaggio);
    
