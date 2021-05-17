//
// Created by arttu on 17/05/2021.
//

#include <iostream>
#include "../HeaderFiles/GameManager.h"

using namespace SDL;

int main(int argc, char* args[]) {

    GameManager* game = GameManager::Instance();

    game->Run();

    GameManager::Release();
    game = NULL;

    return 0;
}
