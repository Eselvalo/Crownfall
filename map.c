#include "map.h"


void initMap(ptrMap mappa){

    

    mappa->listRoom = createRoom();
    mappa->nextMap = NULL;

    Image backgroundImage = LoadImage("./map.png"); // Replace with your image path
    ImageResize(&backgroundImage, mappa->listRoom->shape.width, mappa->listRoom->shape.height);
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    mappa->listRoom->tex = backgroundTexture;
    UnloadTexture(backgroundTexture);

    
}


void drawMap(ptrMap mappa){

    //printf("DRAW MAPPA\t");
    DrawRectangle(mappa->listRoom->shape.x, mappa->listRoom->shape.x, mappa->listRoom->shape.width, mappa->listRoom->shape.height, WHITE);
    DrawTexture(mappa->listRoom->tex, mappa->listRoom->shape.x, mappa->listRoom->shape.y, BLUE);
    //printf("DRAW MAPPA TERMINATO\n");
}

ptrRoom createRoom() {
    ptrRoom newRoom = (ptrRoom)malloc(sizeof(room));
    if (newRoom != NULL) {
        // Inizializza i campi della stanza a valori di default o come desideri
        newRoom->shape.height = 500;
        newRoom->shape.width = 500;
        newRoom->shape.x = 400;
        newRoom->shape.y = 225;
        // Inizializza altri campi della stanza, se necessario
        newRoom->nextRoom = NULL;
        newRoom->prevRoom = NULL;
    }
    return newRoom;
}

