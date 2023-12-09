#include "map.h"


void initMap(ptrMap mappa){

    

    //mappa->nextMap = NULL;
    //mappa->listRoom->nextRoom = NULL;
    //mappa->listRoom->prevRoom = NULL;
    mappa->listRoom->shape.height = 500;
    mappa->listRoom->shape.width = 500;
    mappa->listRoom->shape.x = 400;
    mappa->listRoom->shape.y = 225;
  

    Image backgroundImage = LoadImage("/home/sdroggio/crownfall/map.png"); // Replace with your image path
    ImageResize(&backgroundImage, mappa->listRoom->shape.width, mappa->listRoom->shape.height);
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    mappa->listRoom->tex = backgroundTexture;
    UnloadTexture(backgroundTexture);

    
}


void drawMap(ptrMap mappa){

    printf("DRAW MAPPA\t");
    DrawRectangle(mappa->listRoom->shape.x, mappa->listRoom->shape.x, mappa->listRoom->shape.width, mappa->listRoom->shape.height, WHITE);
    DrawTexture(mappa->listRoom->tex, mappa->listRoom->shape.x, mappa->listRoom->shape.y, BLUE);
    printf("DRAW MAPPA TERMINATO\n");
}


