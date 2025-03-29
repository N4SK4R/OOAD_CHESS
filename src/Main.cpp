#include "Game.h"
#include <iostream>

int main() {
    int theme;
    const int screenWidth = 800;
    const int screenHeight = 800;

    std::cout << "-----------------------------\n";
    std::cout << "|    SELECT CHESS THEME     |\n";
    std::cout << "|---------------------------|\n";
    std::cout << "|  1. Standard Theme        |\n";
    std::cout << "|  2. New Theme             |\n";
    std::cout << "-----------------------------\n";
  
    std::cin >> theme;
    
    InitWindow(screenWidth, screenHeight, "Chess Game");
    SetTargetFPS(60);

    Game game(theme);

    while (!WindowShouldClose()) {

        game.Render();

        game.ProcessInput();
        
    }

    CloseWindow();
    return 0;
}