#include "mainCharacter.h"

void initCharacter(ptrCharacter personaggio, ptrMap mappa){
    
    personaggio->sprite.x = mappa->listRoom->shape.x + (mappa->listRoom->shape.width/2);
    personaggio->sprite.y = mappa->listRoom->shape.y + (mappa->listRoom->shape.height/2);
  
    personaggio->sprite.width = 30.0f;
    personaggio->sprite.height = 50.0f;
    
    Image characterImage = LoadImage("./character.png");
    ImageResize(&characterImage, personaggio->sprite.width, personaggio->sprite.height);
    Texture2D characterTexture = LoadTextureFromImage(characterImage);
    //UnloadImage(characterImage);

    personaggio->texture = characterTexture;
    //UnloadTexture(characterTexture);
   

}


void drawCharacter(ptrCharacter personaggio){

    DrawRectangle(personaggio->sprite.x, personaggio->sprite.y, personaggio->sprite.width, personaggio->sprite.height, GREEN);
    DrawTexture(personaggio->texture, personaggio->sprite.x, personaggio->sprite.y, WHITE);

}


void updateCharacter(ptrCharacter personaggio){


// Update square position
        if (IsKeyDown(KEY_LEFT))   personaggio->sprite.x -= 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_RIGHT)) personaggio->sprite.x += 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) personaggio->sprite.y += 200.0f * GetFrameTime();
        if (IsKeyDown(KEY_UP)) personaggio->sprite.y -= 200.0f * GetFrameTime();



}