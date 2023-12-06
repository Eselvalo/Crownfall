
#include <stdio.h>
#include <raylib.h>
#include <stdio.h>
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
    //ToggleFullscreen();
    SetTargetFPS(60);
    // Load and setup the background image
    Image backgroundImage = LoadImage("/home/sdroggio/crownfall/map.png"); // Replace with your image path
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage); // Unload image from RAM, texture is on the GPU now

    // Load and setup the background image
    Image characterImage = LoadImage("/home/sdroggio/crownfall/character.png"); // Replace with your image path
    Texture2D characterTexture = LoadTextureFromImage(characterImage);
    UnloadImage(characterImage); // Unload image from RAM, texture is on the GPU now
    
    // inizializzazione personaggio
    
    Vector2 squarePosition = { 200.0f, 300.0f };
    int squareSize = 50;
    float squareSpeed = 200.0f; // pixels per second
    printf("il valore di x fuori da init e'%f\n", squarePosition.x);
    //character* player = malloc(sizeof(struct character));
    //*player = initCharacter(squarePosition, characterTexture);
    //character player = initCharacter(squarePosition, characterTexture);
    character player;
  
    initCharacter(&player, characterTexture);  
    
    printf("%f\n", player.sprite.height);
    
    // Main game loop
    while (!WindowShouldClose()) {
        

        updateCharacter(&player);

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);
    
            drawCharacter(&player);

            //DrawTexture(backgroundTexture, 0, 0, WHITE);


        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(backgroundTexture); // Unload texture
    CloseWindow(); // Close window and OpenGL context

    return 0;
}



