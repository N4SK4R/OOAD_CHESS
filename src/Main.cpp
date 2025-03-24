#include "GameFacade.h"

int main() {
    const int screenWidth = 800;
    const int screenHeight = 800;
    
    InitWindow(screenWidth, screenHeight, "Chess Game");
    SetTargetFPS(60);

    GameFacade game;

    while (!WindowShouldClose()) {
        game.ProcessInput();
        
        game.Render();
    }

    CloseWindow();
    return 0;
}