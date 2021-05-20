//
// Created by arttu on 20/05/2021.
//

#include "../CatGameHeaderFiles/PhysicsManager.h"

PhysicsManager* PhysicsManager::sInstance = nullptr;

PhysicsManager *PhysicsManager::Instance() {

    if(sInstance == nullptr)
        sInstance = new PhysicsManager();

    return sInstance;
}

void PhysicsManager::Release() {

    delete sInstance;
    sInstance = nullptr;
}

PhysicsManager::PhysicsManager() {

    mLastID = 0;

    for(unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); ++i){

        mLayerMasks[i] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(CollisionFlags::None));
    }
}

PhysicsManager::~PhysicsManager() {

    for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); ++i) {

        mCollisionLayers[i].clear();
    }
}


void PhysicsManager::SetLayerCollisionMask(PhysicsManager::CollisionLayers layer, PhysicsManager::CollisionFlags flags) {

    mLayerMasks[static_cast<unsigned int>(layer)] = std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)>(static_cast<unsigned int>(flags));
}

unsigned long PhysicsManager::RegisterEntity(PhysicsEntity *entity, PhysicsManager::CollisionLayers layer) {

    mCollisionLayers[static_cast<unsigned int>(layer)].push_back(entity);

    mLastID++;

    return mLastID;
}

void PhysicsManager::UnRegisterEntity(unsigned long id) {

    bool found = false;

    for (int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers) && !found; ++i) {

        for (int j = 0; j < mCollisionLayers->size() && !found; ++j) {

            if(mCollisionLayers[i][j]->GetID() == id){

                mCollisionLayers[i].erase(mCollisionLayers[i].begin() + j);
                found = true;
            }
        }
    }
}

void PhysicsManager::Update() {

    for (unsigned int i = 0; i < static_cast<unsigned int>(CollisionLayers::MaxLayers); ++i) {

        for (unsigned int j = 0; j < static_cast<unsigned int>(CollisionLayers::MaxLayers); ++j) {

            if(mLayerMasks[i].test(j) && i <= j){

                for (unsigned int k = 0; k < mCollisionLayers[i].size(); ++k) {

                    for (unsigned int l = 0; l < mCollisionLayers[j].size(); ++l) {

                        if(mCollisionLayers[i][k]->CheckCollision(mCollisionLayers[j][l])){

                            mCollisionLayers[i][k]->GotHit(mCollisionLayers[j][l]);
                            mCollisionLayers[j][l]->GotHit(mCollisionLayers[i][k]);
                        }
                    }
                }
            }
        }
    }
}