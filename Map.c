#include "Map.h"


void initMap(ptrMap mappa){
    
    
    mappa->maxRooms = 5 + rand() % 5;
    mappa->listRoom = NULL;
    mappa->listRoom = createRoom(mappa);
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

ptrRoom createRoom(ptrMap mappa) {
        
        
        printf("INIZIO CREATE ROOM\n");
        int roomNumber = 0;
        //mappa->listRoom = NULL;
        //ptrRoom head = mappa->listRoom;
       
        printf("INIZIO CICLO\n");
        ptrRoom head = NULL;
        ptrRoom tail = NULL;

        for (int roomNumber = 0; roomNumber < mappa->maxRooms; roomNumber++) {
            ptrRoom newRoom = (ptrRoom)malloc(sizeof(room));
            if (!newRoom) {
                // Gestione dell'errore di allocazione
                break;
            }

            // Configurazione della stanza
            newRoom->shape.height = GetRandomValue(1, GetScreenHeight());
            newRoom->shape.width = GetRandomValue(1, GetScreenWidth());
            newRoom->shape.x = (GetScreenWidth() - newRoom->shape.width) / 2;
            newRoom->shape.y = (GetScreenHeight() - newRoom->shape.height) / 2;
            newRoom->door.height = 10;
            newRoom->door.width = 50;
            positionDoor(newRoom);
            newRoom->number = roomNumber;

            // Collegamento nella lista
            newRoom->nextRoom = NULL;
            newRoom->prevRoom = tail;
            if (tail) {
                tail->nextRoom = newRoom;
            } else {
                head = newRoom;
            }
            tail = newRoom;
    }

    return head;

}


void updateMap(ptrMap mappa, ptrCharacter personaggio){
 
    if (mappa == NULL || personaggio == NULL) {
        printf("Errore: mappa o personaggio non valido.\n");
        return;
    }

    if (mappa->listRoom == NULL) {
        printf("Errore: la lista delle stanze è vuota.\n");
        return;
    }

    int stanzaCorrente = mappa->listRoom->number;
    printf("%d\n", stanzaCorrente);

    if (CheckCollisionRecs(personaggio->sprite, mappa->listRoom->door)) {
        if (mappa->listRoom->nextRoom != NULL) {
            mappa->listRoom = mappa->listRoom->nextRoom;
            personaggio->sprite.x = mappa->listRoom->shape.x + mappa->listRoom->shape.width/2;
            personaggio->sprite.y = mappa->listRoom->shape.y + mappa->listRoom->shape.height/2;
        } else {
            printf("Non ci sono altre stanze precedenti.\n");
        }
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

