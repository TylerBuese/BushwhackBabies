#include "raylib.h"
#include "raymath.h"
#include <string>
/*Idea for the moment
        Shoot alligators in the sky, if they hit the ground you lose a point. if you hit them, you gain a point
*/

int main() 
{
    InitWindow(1280, 720, "Bushwhack Babies");
    Rectangle enemy {200, 200, 50, 50};
    Rectangle baby {600, 1280 / 2 - baby.width, 50, 25};
    Rectangle bullet[10000] {0, 0, 5, 20};

    float gravity {100};
    bool gameOverWin {false};
    bool gameOverLose {false};
    bool bulletFired {false};
    int counter {0};
    int bulletNum {0};
    float time {0};
    SetTargetFPS(60);
    

    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangleRec(enemy, RED);
        DrawRectangleRec(baby, BLUE);
        time = GetTime();

        //check collision
        // bool onEnemy {false};
        // if (!gameOverWin || !gameOverLose)
        // {
        //     if (GetMouseX() <= enemy.x + enemy.width &&
        //         GetMouseX() >=enemy.x &&
        //         GetMouseY() <= enemy.y + enemy.height &&
        //         GetMouseY() >= enemy.y)
        //         onEnemy = true;
        // }

        for (int i = 0; i <= bulletNum; i++)
        {
            if (CheckCollisionRecs(bullet[i], enemy))
            {
                enemy.x = GetRandomValue(100, 1100);
                enemy.y = GetRandomValue(0, 100);
                counter++;
                gravity *= 1.125;
            }
        }

        if (CheckCollisionRecs(enemy, baby) || enemy.y >= GetScreenHeight())
        {
            gameOverLose = true;
        }

        enemy.y += gravity * GetFrameTime();

        if (IsKeyDown(KEY_A))
            baby.x -= 750 * GetFrameTime();
        

        if (IsKeyDown(KEY_D))
            baby.x += 750 * GetFrameTime();
            

        if (IsKeyPressed(KEY_SPACE))
        {
            //fire bullet
            bulletFired = true;
            bulletNum += 1;
            bullet[bulletNum].y = baby.y;
            bullet[bulletNum].x = baby.x + 20;
            bullet[bulletNum].width = 5;
            bullet[bulletNum].height = 20;
        }

        if (bulletFired)
        {   
            for (int i = 0; i <= bulletNum; i++)
            {
                bullet[i].y -= 500 * GetFrameTime();
                DrawRectangleRec(bullet[i], WHITE);
            }
            
        }

        if (counter == 100)
        {
            gameOverWin = true;
        }

        if (gameOverWin)
        {
            DrawText("You win!", 1280 / 2, 720 / 2, 50, WHITE);
        } else if (gameOverLose)
        {
            DrawText("You lose!", 1280 / 2, 720 / 2, 50, WHITE);
        }

        //stats
        DrawText("Alligators flogged: ", 20, 680, 30, RED);
        DrawText(std::to_string(counter).c_str(), 320, 680, 30, WHITE);
        DrawText("Time elapsed: ", 20, 640, 30, RED);
        DrawText(std::to_string(time).c_str(), 225, 640, 30, WHITE);


        EndDrawing();
    }
    return 0;
}