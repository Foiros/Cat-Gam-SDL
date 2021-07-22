//
// Created by arttu on 19/05/2021.
//

#include "../CatGameHeaderFiles/Kitten.h"

namespace CatGame{

    Kitten::Kitten() {

        mTimer = Timer::Instance();
        mInputManager = InputManager::Instance();
        mAudioManager = AudioManager::Instance();

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

    void Kitten::Update(KittenNeeds* needs, Nest* nest, PathfindingGrid* grid, std::vector<Vector2*> trees, std::vector<Vector2*> flowers, std::vector<Vector2*> mice) {

        // CheckState(needs, nest, grid, trees, flowers, mice);
    }

    void Kitten::Render() {

        if(mVisible)
            mKittenSprite->Render();
    }
}