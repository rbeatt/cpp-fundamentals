#include "raylib.h"

int main()
{

    //window dimensions
    const int windowWidth{512};
    const int windowHeight{380};

    //initialise window
    InitWindow(windowWidth, windowHeight, "Dapper Dasher");


    //acceleration due to gravity (pixels/s)/s
    const int gravity{1000};

    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight/2 - scarfyRec.height;

    //is the rectangle in the air?
    bool isInAir{}; 

    //jump velocity (pixels/s)
    const int jumpVel{-600};

    int velocity{0};

    SetTargetFPS(60);

    while(!WindowShouldClose()) {

        //delta time (time since last frame)
        const float dT{GetFrameTime()};

        //start drawing
        BeginDrawing();
        ClearBackground(WHITE);

        //perform ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.width)
        {
            //rectangle on ground
            velocity = 0;
            isInAir = false;
        }
        else
        {
            //rectangle in air
            velocity += gravity * dT;
        }

        //jump check
        if (IsKeyPressed(KEY_SPACE) && !isInAir) 
        {
            velocity += jumpVel;
            isInAir = true;
        }

        //update position 
        scarfyPos.y += velocity * dT;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);

        //stop drawing
        EndDrawing();
    }
    UnloadTexture(scarfy);
    CloseWindow();
}