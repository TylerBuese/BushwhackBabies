#include "raylib.h"
#include "raymath.h"
#include <string>
/*Idea for the moment
        Shoot alligators in the sky, if they hit the ground you lose a point. if you hit them, you gain a point
*/

class Bullet
{
    public:
    void DrawBullet(int currX, int currY)
    {
        int bullety {currY}; 
        DrawRectangle(currX, bullety, 5, 20, RED);
    }

    private:
    Rectangle Bullets[100] {0,0,0,0};
};

int main() 
{
    InitWindow(1280, 720, "Bushwhack Babies");
    Rectangle enemy {200, 200, 50, 50};
    Rectangle baby {600, 1280 / 2 - baby.width, 50, 25};

    float gravity {100};
    bool gameOverWin {false};
    bool gameOverLose {false};
    bool bulletFired {false};
    int numberOfBullets {0};
    int counter {0};
    float time {0};
    int bullety {baby.y};
    int bulletx {baby.x};
    bool gotVars {false};
    SetTargetFPS(60);
    

    while (!WindowShouldClose())
    {
        
        BeginDrawing();
        ClearBackground(BLACK);

        DrawRectangleRec(enemy, RED);
        DrawRectangleRec(baby, BLUE);
        time = GetTime();

        //check collision
        bool onEnemy {false};
        if (!gameOverWin || !gameOverLose)
        {
            if (GetMouseX() <= enemy.x + enemy.width &&
                GetMouseX() >=enemy.x &&
                GetMouseY() <= enemy.y + enemy.height &&
                GetMouseY() >= enemy.y)
                onEnemy = true;
        }

        if (CheckCollisionRecs(enemy, baby) || enemy.y >= GetScreenHeight())
        {
            gameOverLose = true;
        }

        enemy.y += gravity * GetFrameTime();

        if (IsKeyDown(KEY_A))
            baby.x -= 100 * GetFrameTime();
        

        if (IsKeyDown(KEY_D))
            baby.x += 100 * GetFrameTime();

        if (IsKeyPressed(KEY_SPACE))
        {
            //fire bullet
            bulletFired = true;
            numberOfBullets++;
            
            

        }

        if (bulletFired)
        {
            // DrawRectangle(bulletx + baby.width / 2, bullety, 5, 20, RED);
            // bullety -= 100 * GetFrameTime();
            Bullet bullet;

            //get vars
            if (!gotVars)
            {
                
                bulletx = baby.x;
                gotVars = true;
            }
            bullety -= 10 * GetFrameTime();
            bullet.DrawBullet(bulletx, bullety);
            
            DrawText("Fired!", 100, 100, 10, RED);
            
        }
        if (IsMouseButtonPressed(MOUSE_LEFT_BUTTON) && onEnemy)
        {
            enemy.x = GetRandomValue(100, 1100);
            enemy.y = GetRandomValue(0, 100);
            counter++;
            gravity *= 1.125;
            bullety = baby.y;
            bulletFired = true;
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

void fireBullet(int x, int y)
{

}