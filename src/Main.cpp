#include "GameFacade.h"
#include <iostream>

int main() {
    int theme;
    const int screenWidth = 800;
    const int screenHeight = 800;

    std::cout << "-----------------------------\n";
    std::cout << "|    SELECT CHESS THEME     |\n";
    std::cout << "|---------------------------|\n";
    std::cout << "|  1. Standard Theme           |\n";
    std::cout << "|  2. Dark Theme            |\n";
    std::cout << "-----------------------------\n";
    std::cout << "Enter your choice (1 or 2): ";
    
    std::cin >> theme;
    
    InitWindow(screenWidth, screenHeight, "Chess Game");
    SetTargetFPS(60);

    GameFacade game;

    while (!WindowShouldClose()) {

        game.Render();

        game.ProcessInput();
        
    }

    CloseWindow();
    return 0;
}