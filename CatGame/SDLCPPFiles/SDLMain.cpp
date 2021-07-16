//
// Created by arttu on 17/05/2021.
//

#include <iostream>
#include "../CatGameHeaderFiles/GameManager.h"

using namespace SDL;

int main(int argc, char* args[]) {

    GameManager* game = GameManager::Instance();

    game->Run();

    GameManager::Release();
    game = nullptr;

    return 0;
}
