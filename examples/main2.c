#include <stdio.h>
#include <raylib.h>
#include <math.h> // Include for sqrtf function

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 450
typedef enum GameState { GAMEPLAY, BATTLE } GameState;
GameState currentGameState = GAMEPLAY;

// Player and NPC variables
Vector2 playerPosition;
Vector2 npcPosition;
// Camera for scrolling
Camera2D camera;

// Battle system variables
int playerHealth = 100;
int enemyHealth = 100;

void InitGame() {
    int px = GetRenderWidth();
    int py = GetRenderHeight();
    // Initialize player, NPC, and camera
    playerPosition = (Vector2){ px/ 2,  py/2  };
    

    npcPosition = (Vector2){ 600, 400 };
    camera.target = playerPosition;
    camera.offset = (Vector2){ px / 2, py / 2 };
    camera.rotation = 0.0f;
    camera.zoom = 1.0f;
}

void UpdateGameplay() {
    // Player movement and camera update
    Vector2 direction = {0};
    if (IsKeyDown(KEY_RIGHT)) direction.x += 1.0f;
    if (IsKeyDown(KEY_LEFT)) direction.x -= 1.0f;
    if (IsKeyDown(KEY_UP)) direction.y -= 1.0f;
    if (IsKeyDown(KEY_DOWN)) direction.y += 1.0f;

    // Calculate direction vector length
    float vectorLength = sqrtf(direction.x * direction.x + direction.y * direction.y);

    // Normalize the direction vector if it's not zero
    if (vectorLength > 0) {
        direction.x /= vectorLength;
        direction.y /= vectorLength;
    }

    // Move the player
    float speed = 2.0f;
    playerPosition.x += direction.x * speed;
    playerPosition.y += direction.y * speed;

    camera.target = playerPosition;

    // Check for battle initiation
    if (CheckCollisionRecs((Rectangle){ playerPosition.x - 20, playerPosition.y - 20, 40, 40 },
                           (Rectangle){ npcPosition.x - 20, npcPosition.y - 20, 40, 40 })) {
        currentGameState = BATTLE;
    }
}

void DrawGameplay() {
    BeginDrawing();
    ClearBackground(RAYWHITE);

    BeginMode2D(camera);

    // Draw the dungeon and characters
    DrawRectangle(0, 0, 1600, 1200, LIGHTGRAY); // Example dungeon size
    DrawCircleV(playerPosition, 20, BLUE);
    DrawCircleV(npcPosition, 20, RED);

    EndMode2D();

    EndDrawing();
}

void UpdateBattle() {
    // Basic battle system logic
    if (IsKeyPressed(KEY_ENTER)) {
        enemyHealth -= 10; // Example attack
        if (enemyHealth <= 0) {
            currentGameState = GAMEPLAY;
            enemyHealth = 100; // Reset enemy health for simplicity
        }
    }
}

void DrawBattle() {
    BeginDrawing();
    ClearBackground(BLACK);

    // Draw battle UI
    DrawText("Battle!", 350, 200, 20, WHITE);
    DrawText(TextFormat("Player Health: %d", playerHealth), 10, 10, 20, WHITE);
    DrawText(TextFormat("Enemy Health: %d", enemyHealth), 600, 10, 20, WHITE);

    EndDrawing();
}

void UnloadGame() {
    
}

int main() {
    int Height = 400;
    int Width = 800;
    InitWindow(Width, Height, "RPG Game");
    ToggleFullscreen();
  
    int screenHeight = GetScreenHeight();
    int screenWidth = GetScreenWidth();
    printf("The value of Height is: %d\n", screenHeight);
    printf("The value of Width is: %d\n", screenWidth);
    InitGame();
    printf("The value of Height is: %d\n", screenHeight);
    printf("The value of Width is: %d\n", screenWidth);
   
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        switch (currentGameState) {
            case GAMEPLAY:
                UpdateGameplay();
                DrawGameplay();
                break;

            case BATTLE:
                UpdateBattle();
                DrawBattle();
                break;
        }
    }

    UnloadGame();
    CloseWindow();
    return 0;
}

