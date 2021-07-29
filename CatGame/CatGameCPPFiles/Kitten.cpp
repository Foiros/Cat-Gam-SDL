//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Kitten.h"

namespace CatGame{

    Kitten::Kitten(PathfindingGrid *_grid, KittenNeeds *_needs, Nest *_nest, Timer* _timer,
                   std::vector<Vector2*> d1, std::vector<Vector2*> d2, std::vector<Vector2*> d3) {

        mTimer = Timer::Instance();
        mInputManager = InputManager::Instance();
        mAudioManager = AudioManager::Instance();
        kittenFSM = new KittenFSM(_grid, this, _needs, _nest, _timer, d1, d2, d3);

        mVisible = false;
        mAnimating = false;

        mKittenSprite = new Texture("Kitten.png");
        mKittenSprite->Parent(this);

        mRunAnimation = new AnimatedTexture("KittenWalkAnimation.png", 0, 0, 100, 100, 4, 1.0f, AnimatedTexture::horizontal);
        mRunAnimation->Parent(this);
        mRunAnimation->WrapMode(AnimatedTexture::once);

        AddCollider(new BoxCollider(Vector2(50.0f, 50.0f)));
        mID = PhysicsManager::Instance()->RegisterEntity(this, PhysicsManager::CollisionLayers::Kitten);
    }

    Kitten::~Kitten() {

        mTimer = nullptr;
        mInputManager = nullptr;
        mAudioManager = nullptr;

        delete mKittenSprite;
        mKittenSprite = nullptr;

        delete mRunAnimation;
        mRunAnimation = nullptr;
    }

    void Kitten::Visible(bool visible) {

        mVisible = visible;
    }

    bool Kitten::IgnoreCollisions() {

        return !mVisible;
    }

    void Kitten::ContactWithOtherCollider(PhysicsEntity *other) {

    }

    void Kitten::Update() {

        kittenFSM->Update();
    }

    void Kitten::Render() {

        if(mVisible)
            mKittenSprite->Render();
    }
}