#include "map.h"


void initMap(ptrMap mappa){

    srand(time(NULL));
    mappa->maxRooms = 5 + rand() % 5;
    mappa->listRoom = createRoom(0, mappa->maxRooms, NULL);
    mappa->nextMap = NULL;

    

    Image backgroundImage = LoadImage("./map.png"); // Replace with your image path
    ImageResize(&backgroundImage, mappa->listRoom->shape.width, mappa->listRoom->shape.height);
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage);

    mappa->listRoom->tex = backgroundTexture;
    //UnloadTexture(backgroundTexture);

    
}


void drawMap(ptrMap mappa){
  
    DrawRectangle(mappa->listRoom->shape.x, mappa->listRoom->shape.y, mappa->listRoom->shape.width, mappa->listRoom->shape.height, WHITE);
    //DrawTexture(mappa->listRoom->tex, mappa->listRoom->shape.x, mappa->listRoom->shape.y, WHITE);

    
    
    if((mappa->listRoom->door.x == mappa->listRoom->shape.x) || (mappa->listRoom->door.x == (mappa->listRoom->shape.x + mappa->listRoom->shape.width)))
        DrawRectanglePro(mappa->listRoom->door, (Vector2){0, 0}, 90.0f, BLUE);
    
    else
        DrawRectangle(mappa->listRoom->door.x, mappa->listRoom->door.y, mappa->listRoom->door.width, mappa->listRoom->door.height, BLUE);

}

ptrRoom createRoom(int roomNumber, int maxRooms, ptrRoom prev) {
    


    if (roomNumber == 0){
        ptrRoom newRoom = (ptrRoom)malloc(sizeof(room));
        if (newRoom != NULL) {
        // Inizializza i campi della stanza a valori di default o come desideri
            newRoom->shape.height = 500;
            newRoom->shape.width = 500;
            newRoom->shape.x = 400;
            newRoom->shape.y = 225;
            

            newRoom->door.height = 10;
            newRoom->door.width = 50;
            positionDoor(newRoom);
            // Inizializza altri campi della stanza, se necessario
            newRoom->nextRoom = createRoom(roomNumber+1, maxRooms, newRoom);
            newRoom->prevRoom = NULL;
            return newRoom;
        }
    } else if (roomNumber < maxRooms){
            
            ptrRoom newRoom = (ptrRoom)malloc(sizeof(room));
            if (newRoom != NULL) {
                // Inizializza i campi della stanza a valori di default o come desideri
                newRoom->shape.height = 700;
                newRoom->shape.width = 500;
                newRoom->shape.x = 400;
                newRoom->shape.y = 225;
                

                newRoom->door.height = 10;
                newRoom->door.width = 50;
                positionDoor(newRoom);
                // Inizializza altri campi della stanza, se necessario
                newRoom->nextRoom = createRoom(roomNumber+1, maxRooms, newRoom);
                newRoom->prevRoom = prev;
                return newRoom;
            }
    } else if (roomNumber >= maxRooms)
                return NULL;


    
}


void updateMap(ptrMap mappa, ptrCharacter personaggio){

    if (CheckCollisionRecs(mappa->listRoom->door, personaggio->sprite)){
        
        mappa->listRoom = mappa->listRoom->nextRoom

    }

}


void positionDoor(ptrRoom stanza){
     
    srand(time(NULL));
    int latoPorta = rand() % 4; // 0: in alto, 1: a destra, 2: in basso, 3: a sinistra

    // Posiziona la porta sul lato casuale
    switch (latoPorta) {
        case 0: // In alto
            stanza->door.x = (int)(stanza->shape.x + (stanza->shape.width/2));
            stanza->door.y = stanza->shape.y;
            break;
        case 1: // A destra
            stanza->door.x = stanza->shape.width + stanza->shape.x;
            stanza->door.y = (int)(stanza->shape.y + (stanza->shape.height/2));
            break;
        case 2: // In basso
            stanza->door.x = (int)(stanza->shape.x + (stanza->shape.width/2));
            stanza->door.y = stanza->shape.height + stanza->shape.y;
            break;
        case 3: // A sinistra
            stanza->door.y = (int)(stanza->shape.y + (stanza->shape.height/2));
            stanza->door.x = stanza->shape.x;
            break;
    }
}

