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
#include "../CatGameHeaderFiles/KittenNeeds.h"
#include "Nest.h"
#include "../FSMHeaderFiles/KittenFSM.h"

using namespace SDL;
using namespace PhysicsEngine;
using namespace FSM;

namespace CatGame{

    class Kitten : public PathfindingUnit {

    private:
        Timer* mTimer;
        InputManager* mInputManager;
        AudioManager* mAudioManager;
        KittenFSM* kittenFSM;

        bool mVisible;
        bool mAnimating;

        Texture* mKittenSprite;

        AnimatedTexture* mRunAnimation;

    private:
        bool IgnoreCollisions() override;

    public:
        Kitten(PathfindingGrid *_grid, KittenNeeds *_needs, Nest *_nest, Timer* _timer,
               std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Vector2*> d3);
        ~Kitten();

        void Visible(bool visible);

        void ContactWithOtherCollider(PhysicsEntity* other) override;

        void Update();
        void Render();
    };
}

#endif //CATGAMESDL_KITTEN_H
