#include <stdio.h>
#include <raylib.h>

int main() {
    // Window dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Raylib Demo - Moving Square");

    // Square properties
    Vector2 squarePosition = { screenWidth / 2, screenHeight / 2 };
    int squareSize = 50;
    float squareSpeed = 200.0f; // pixels per second

    // Load and setup the background image
    Image backgroundImage = LoadImage("./map.png"); // Replace with your image path
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage); // Unload image from RAM, texture is on the GPU now

    // Main game loop
    while (!WindowShouldClose()) {
        // Update square position
        if (IsKeyDown(KEY_RIGHT)) squarePosition.x += squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_LEFT)) squarePosition.x -= squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_UP)) squarePosition.y -= squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) squarePosition.y += squareSpeed * GetFrameTime();

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw the texture covering the whole screen (background first)
            DrawTexture(backgroundTexture, 0, 0, WHITE);

            // Draw the square
            DrawRectangle(squarePosition.x - squareSize / 2, squarePosition.y - squareSize / 2, squareSize, squareSize, BLACK);

            // Additional drawing...

        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(backgroundTexture); // Unload texture
    CloseWindow(); // Close window and OpenGL context

#include <stdio.h>
#include <raylib.h>

int main() {
    // Window dimensions
    const int screenWidth = 800;
    const int screenHeight = 450;

    // Initialize the window
    InitWindow(screenWidth, screenHeight, "Raylib Demo - Moving Square");

    // Square properties
    Vector2 squarePosition = { screenWidth / 2, screenHeight / 2 };
    int squareSize = 50;
    float squareSpeed = 200.0f; // pixels per second

    // Load and setup the background image
    Image backgroundImage = LoadImage("./map.png"); // Replace with your image path
    Texture2D backgroundTexture = LoadTextureFromImage(backgroundImage);
    UnloadImage(backgroundImage); // Unload image from RAM, texture is on the GPU now

    // Main game loop
    while (!WindowShouldClose()) {
        // Update square position
        if (IsKeyDown(KEY_RIGHT)) squarePosition.x += squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_LEFT)) squarePosition.x -= squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_UP)) squarePosition.y -= squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) squarePosition.y += squareSpeed * GetFrameTime();

        // Draw
        BeginDrawing();

            ClearBackground(RAYWHITE);

            // Draw the texture covering the whole screen (background first)
            DrawTexture(backgroundTexture, 0, 0, WHITE);

            // Draw the square
            DrawRectangle(squarePosition.x - squareSize / 2, squarePosition.y - squareSize / 2, squareSize, squareSize, BLACK);

            // Additional drawing...

        EndDrawing();
    }

    // De-Initialization
    UnloadTexture(backgroundTexture); // Unload texture
    CloseWindow(); // Close window and OpenGL context

    return 0;
}
    return 0;
}

