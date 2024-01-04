#include "cam.h"

void createCamera(Camera2D *cam, int x, int y){

    
    cam->target = (Vector2){ x, y };
    cam->offset = (Vector2){ GetScreenWidth()/2, GetScreenHeight()/2 };
    cam->rotation = 0.0f;
    cam->zoom = 1.0f;

}


void aggiornaCamera(Camera2D *cam, int x, int y){

    cam->target = (Vector2){ x, y };


}

