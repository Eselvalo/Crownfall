#include "character.h"

void initCharacter(Vector2 pos, Texture2D tex, character_ personaggio){

    character init;
    personaggio = init;
    personaggio->dimensioni[0] = 100.0f;
    personaggio->dimensioni[1] = 300.0f;

    personaggio->posizione[0] = 100;
    personaggio->posizione[1] = 200;
    printf("La x e': %d\n", personaggio->posizione[0]);
    printf("La y e': %d\n", personaggio->posizione[1]);
  //  personaggio.texture = tex;

  //  personaggio.colore = GREEN;

}


void drawCharacter(character_ personaggio){


    printf("dentro draw la x e': %d\n", personaggio->posizione[0]);
    printf("dentro draw la y e': %d\n", personaggio->posizione[1]);
    //rawTexture(personaggio.texture, personaggio.posizione.x, personaggio.posizione.y, WHITE);
    
    //DrawRectangle(150, 150, 100, 200, BLACK);
    DrawRectangle(personaggio->posizione[0], personaggio->posizione[1], personaggio->dimensioni[0], personaggio->dimensioni[1], GREEN);


}


void updateCharacter(character_ personaggio){


// Update square position
    /*    if (IsKeyDown(KEY_RIGHT))   personaggio.posizione.x += 200 * GetFrameTime();
        if (IsKeyDown(KEY_LEFT)) personaggio.posizione.x -= 200 * GetFrameTime();
        if (IsKeyDown(KEY_UP)) personaggio.posizione.y -= 200 * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) personaggio.posizione.y += 200 * GetFrameTime();
*/


}