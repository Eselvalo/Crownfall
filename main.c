#include <stdio.h>
#include <raylib.h>
#include "character.h"
#include "map.h"

int main() {


    InitWindow(WIDTH, HEIGHT, "Raylib Demo - Moving Square");
    SetTargetFPS(60);

    printf("INIZIALIZZIAZZIONE MAPPA\n");
    map mappa;
    initMap(&mappa);
    printf("INIZIALIZZAZIONE MAPPA TEMINATA\n");
    
    character player;
    initCharacter(&player);  
    
    

    while (!WindowShouldClose()) {
        
        updateCharacter(&player);

        BeginDrawing();

            ClearBackground(BLACK);

            drawMap(&mappa);
            drawCharacter(&player);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}



