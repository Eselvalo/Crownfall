
#include <stdio.h>
#include <raylib.h>
#include <stdio.h>
#include "character.h"
#include "map.h"

int main() {

    const int screenWidth = 800;
    const int screenHeight = 450;

    InitWindow(screenWidth, screenHeight, "Raylib Demo - Moving Square");
    SetTargetFPS(60);

    printf("INIZIALIZZIAZZIONE MAPPA\t");
    map ERMAPPONE;
    initMap(&ERMAPPONE);
    printf("INIZIALIZZAZIONE MAPPA TEMINATA\n");
    
    character player;
    initCharacter(&player);  
    
    

    while (!WindowShouldClose()) {
        
        updateCharacter(&player);

        BeginDrawing();

            ClearBackground(RAYWHITE);

            drawMap(&ERMAPPONE);
            drawCharacter(&player);

        EndDrawing();
    }

    CloseWindow();

    return 0;
}



