<<<<<<< HEAD
#include <stdio.h>
#include <raylib.h>

int main() {
    // Window dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Crownfall");

    // Square properties
    Vector2 squarePosition = { screenWidth / 2, screenHeight / 2 };
    int squareSize = 50;
    float squareSpeed = 200.0f; // pixels per second

    // Load and setup the background image
    Image backgroundImage = LoadImage("./map.png");
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage); // Unload image from RAM, texture is on the GPU now

    // Main game loop
    while (!WindowShouldClose()) {
        // Update square position
        if (IsKeyDown(KEY_RIGHT)) squarePosition.x += squareSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_LEFT)) squarePosition.x -= squareSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_UP)) squarePosition.y -= squareSpeed * GetFrameTime();
        else if (IsKeyDown(KEY_DOWN)) squarePosition.y += squareSpeed * GetFrameTime();
        else 
        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw the texture covering the whole screen (background first)
            DrawTexture(backgroundTexture, 0, 0, WHITE);

            // Draw the square
            DrawRectangle(squarePosition.x - squareSize / 2, squarePosition.y - squareSize / 2, squareSize, squareSize, BLACK);
=======

#include <stdio.h>
#include <raylib.h>
#include <stdio.h>
#include "character.h"
#include "map.h"

int main() {


    InitWindow(0, 0, "Raylib Demo - Moving Square");
    SetTargetFPS(60);

    printf("INIZIALIZZIAZZIONE MAPPA\t");
    map mappa;
    initMap(&mappa);
    printf("INIZIALIZZAZIONE MAPPA TEMINATA\n");
    
    character player;
    initCharacter(&player, &mappa);  
    
    

    while (!WindowShouldClose()) {
        
        updateCharacter(&player);

        BeginDrawing();

            ClearBackground(BLACK);

            drawMap(&mappa);
            drawCharacter(&player);
>>>>>>> origin/sdroggio

        EndDrawing();
    }

<<<<<<< HEAD
    // De-Initialization
    UnloadTexture(backgroundTexture);
    CloseWindow(); 

    return 0;
}
=======
    CloseWindow();

    return 0;
}



>>>>>>> origin/sdroggio
