//
// Created by arttu on 19/05/2021.
//

#ifndef CATGAMESDL_KITTEN_H
#define CATGAMESDL_KITTEN_H

#include "../PathfindingHeaderFiles/PathfindingUnit.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../SDLHeaderFiles/AnimatedTexture.h"
#include "../SDLHeaderFiles/AudioManager.h"
#include "../PathfindingHeaderFiles//Pathfinding.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"
#include "../FSMHeaderFiles/FSMAgent.h"
#include "../CatGameHeaderFiles/KittenNeeds.h"

using namespace SDL;
using namespace PhysicsEngine;
using namespace FSM;

namespace CatGame{

    class Kitten : public FSMAgent {

    private:
        Timer* mTimer;
        InputManager* mInputManager;
        AudioManager* mAudioManager;

        bool mVisible;
        bool mAnimating;

        Texture* mKittenSprite;

        AnimatedTexture* mRunAnimation;

    private:
        bool IgnoreCollisions() override;

    public:
        Kitten();
        ~Kitten();

        void Visible(bool visible);

        void ContactWithOtherCollider(PhysicsEntity* other) override;

        void Update(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid);
        void Render();
    };
}

#endif //CATGAMESDL_KITTEN_H
