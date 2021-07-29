//
// Created by arttu on 28/07/2021.
//

#ifndef CATGAMESDL_WOLF_H
#define CATGAMESDL_WOLF_H

#include "../PathfindingHeaderFiles/PathfindingUnit.h"
#include "../PhysicsEngineHeaderFiles/PhysicsEntity.h"
#include "../SDLHeaderFiles/Texture.h"
#include "../PhysicsEngineHeaderFiles/PhysicsManager.h"
#include "../FSMHeaderFiles/WolfFSM.h"

using namespace SDL;
using namespace PhysicsEngine;
using namespace FSM;

namespace CatGame{

    class Wolf : public PathfindingUnit{

    private:
        WolfFSM* wolfFSM;
        bool visible;
        Texture* wolfSprite;

    private:
        bool IgnoreCollisions() override;

    public:
        Wolf(PathfindingGrid *_grid, KittenNeeds *_needs, Nest *_nest, Timer* _timer,
             std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Meat*> meats, std::vector<Water*> waters);
        ~Wolf();

        void Visible(bool _visible);

        void ContactWithOtherCollider(PhysicsEntity* other) override;

        void Update(Vector2* kittenLocation);
        void Render();
    };
}

#endif //CATGAMESDL_WOLF_H
