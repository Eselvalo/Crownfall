
#include <stdio.h>
#include <raylib.h>
#include "character.h"

/*




int main(void){

    InitWindow(500,600, "Crownfall");
    SetTargetFPS(60);

    Image background = LoadImage("./map.png");
    Texture2D backgroundTexture = LoadTextureFromImage(background);
    UnloadImage(background);

    while (!WindowShouldClose())
    {
        BeginDrawing();
            ClearBackground(RAYWHITE);
            DrawTexture(backgroundTexture, 0, 0, WHITE);

        //ClearBackground(RED);
        EndDrawing();
        

    }
    UnloadTexture(backgroundTexture);
    CloseWindow();
    return 0;

}*/
int main() {
    // Window dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;


    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Raylib Demo - Moving Square");
    SetTargetFPS(60);
    // Load and setup the background image
    Image backgroundImage = LoadImage("/home/sdroggio/crownfall/map.png"); // Replace with your image path
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage); // Unload image from RAM, texture is on the GPU now

    // Load and setup the background image
    Image characterImage = LoadImage("/home/sdroggio/crownfall/image.jpg"); // Replace with your image path
    Texture2D characterTexture = LoadTextureFromImage(characterImage);
    UnloadImage(characterImage); // Unload image from RAM, texture is on the GPU now
    
    // inizializzazione personaggio
    character player;
    Vector2 squarePosition = { screenWidth / 2, screenHeight / 2 };
    int squareSize = 50;
    float squareSpeed = 200.0f; // pixels per second
    initCharacter(squarePosition, characterTexture, player);

    // Main game loop
    while (!WindowShouldClose()) {
        

        updateCharacter(player);

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            DrawTexture(backgroundTexture, 0, 0, WHITE);

            drawCharacter(player);

        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(backgroundTexture); // Unload texture
    CloseWindow(); // Close window and OpenGL context

    return 0;
}



