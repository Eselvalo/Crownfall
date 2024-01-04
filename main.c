#include "types.h"
#include "cam.h"

int main() {
    srand(time(NULL));

    InitWindow(0, 0, "Raylib Demo - Moving Square");
    SetTargetFPS(60);

    map mappa;
    initMap(&mappa);
    
    character player;
    initCharacter(&player, &mappa);  
    
    Camera2D camera1 = { 0 };
    createCamera(&camera1, player.sprite.x, player.sprite.y);

    while (!WindowShouldClose()) {
        
        updateCharacter(&player);
        updateMap(&mappa,&player);
        aggiornaCamera(&camera1, player.sprite.x, player.sprite.y);

        
            BeginDrawing();
                
                ClearBackground(BLACK);
                BeginMode2D(camera1);
                drawMap(&mappa);
                
                drawCharacter(&player);
                EndMode2D();
            EndDrawing();

    }

    CloseWindow();

    return 0;
}



