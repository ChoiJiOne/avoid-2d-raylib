#include <raylib.h>

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Avoid");
    SetTargetFPS(60);
    
    while (!WindowShouldClose())
    {
        float deltaSeconds = GetFrameTime();

        BeginDrawing();
        ClearBackground(RAYWHITE);
        EndDrawing();
    }

    CloseWindow();
    return 0;
}