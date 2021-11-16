#include "raylib.h"

int main() 
{
    InitWindow(1280, 720, "Bushwhack Babies");
    Rectangle enemy;
    Rectangle baby; 

    while (!WindowShouldClose())
    {
        BeginDrawing();
        enemy.x = 200;
        enemy.y = 200;
        enemy.height = 50;
        enemy.width = 50;

        baby.width = 50;
        baby.height = 25;
        baby.y = 600;
        baby.x = 1280 / 2 - baby.width;

        DrawRectangleRec(enemy, RED);
        DrawRectangleRec(baby, BLUE);

        //check collision
        


        if (IsMouseButtonDown(MOUSE_LEFT_BUTTON))

        ClearBackground(BLACK);
        EndDrawing();
    }

  



    return 0;
}