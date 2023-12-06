#include "character.h"

void initCharacter(ptrCharacter personaggio, Texture2D tex){
    
    personaggio->posizione.x = 200;
    personaggio->posizione.y = 300;

    personaggio->sprite.x = 200;
    personaggio->sprite.y = 300;
    personaggio->sprite.width = 200.0f;
    personaggio->sprite.height = 300.0f;
    
    personaggio->texture = tex;

}


void drawCharacter(ptrCharacter personaggio){

    //rawTexture(TMP.texture, TMP.posizione.x, TMP.posizione.y, WHITE);
    
    //DrawRectangle(150, 150, 100, 200, BLACK);
    DrawRectanglePro(personaggio->sprite, personaggio->posizione, 0.0f, GREEN);
    DrawTexture(personaggio->texture, personaggio->posizione.x, personaggio->posizione.y, WHITE);
    printf("%f\n", personaggio->posizione.x);
    printf("%f\n", personaggio->posizione.y);

}


void updateCharacter(ptrCharacter personaggio){


// Update square position
        if (IsKeyDown(KEY_LEFT))   personaggio->posizione.x += 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) personaggio->posizione.x -= 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) personaggio->posizione.y -= 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_UP)) personaggio->posizione.y += 200.0f * GetFrameTime();



}