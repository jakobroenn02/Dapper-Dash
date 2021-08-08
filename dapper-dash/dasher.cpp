#include "raylib.h"

int main()
{
    const int windowWidth{512};
    const int windowHeight{380};
    InitWindow(windowWidth, windowHeight, "Dapper Dash!");
    //rectangle dimensions
    const int gravity{1'000};
    Texture2D scarfy = LoadTexture("textures/scarfy.png");
    Rectangle scarfyRec;
    scarfyRec.width = scarfy.width/6;
    scarfyRec.height = scarfy.height;
    scarfyRec.x = 0;
    scarfyRec.y = 0;
    Vector2 scarfyPos;
    scarfyPos.x = windowWidth/2 - scarfyRec.width/2;
    scarfyPos.y = windowHeight - scarfyRec.height;
    
    bool isInAir{};
    int Jumpvel{-600};
   
    int velocity{0};

    SetTargetFPS(60);
    while (!WindowShouldClose())
    { 
        const float dT{GetFrameTime()};
       //window
        BeginDrawing();
        ClearBackground(WHITE);
        
        //Ground check
        if (scarfyPos.y >= windowHeight - scarfyRec.width)
        {
            velocity = 0;
            isInAir = false;
        }
        else
        {
         velocity += gravity * dT;
         isInAir = true;
        }
        if (IsKeyPressed(KEY_SPACE) && !isInAir)
        {
            velocity += Jumpvel;
        }

        //CODE
        
        scarfyPos.y += velocity * dT;

        DrawTextureRec(scarfy, scarfyRec, scarfyPos, WHITE);


        EndDrawing();
    }
    

    UnloadTexture(scarfy);
    CloseWindow();

}