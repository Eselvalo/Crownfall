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

    // Set the target FPS (Frames Per Second)
    SetTargetFPS(60);

    // Main game loop
    while (!WindowShouldClose()) { // Detect window close button or ESC key
        // Update
        if (IsKeyDown(KEY_RIGHT)) squarePosition.x += squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_LEFT)) squarePosition.x -= squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_UP)) squarePosition.y -= squareSpeed * GetFrameTime();
        if (IsKeyDown(KEY_DOWN)) squarePosition.y += squareSpeed * GetFrameTime();

        // Draw
        BeginDrawing();

            ClearBackground(GREEN);

            DrawRectangle(squarePosition.x - squareSize / 2, squarePosition.y - squareSize / 2, squareSize, squareSize, BLACK);

        EndDrawing();
    }

    // De-Initialization
    CloseWindow(); // Close window and OpenGL context

    return 0;
}


