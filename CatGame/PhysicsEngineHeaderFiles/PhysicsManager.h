//
// Created by arttu on 20/05/2021.
//

#ifndef CATGAMESDL_PHYSICSMANAGER_H
#define CATGAMESDL_PHYSICSMANAGER_H

#include "PhysicsEntity.h"
#include <bitset>
#include <vector>

class PhysicsManager{

public:
    enum class CollisionLayers{

        MotherCat = 0,
        Kitten,
        Nest,
        Meat,
        Water,
        Activity,
        Wolf,

        MaxLayers
    };

    enum class CollisionFlags{

        None = 0x00,
        MotherCat = 0x01,
        Kitten = 0x02,
        Nest = 0x03,
        Meat = 0x08,
        Water = 0x10,
        Activity = 0x11,
        Wolf = 0x12
    };

private:
    static PhysicsManager* sInstance;

    std::vector<PhysicsEntity*> mCollisionLayers[static_cast<unsigned int>(CollisionLayers::MaxLayers)];
    std::bitset<static_cast<unsigned int>(CollisionLayers::MaxLayers)> mLayerMasks[static_cast<unsigned int>(CollisionLayers::MaxLayers)];

    unsigned long mLastID;

public:
    static PhysicsManager* Instance();
    static void Release();

    void SetLayerCollisionMask(CollisionLayers layer, CollisionFlags flags);

    unsigned long RegisterEntity(PhysicsEntity* entity, CollisionLayers layer);
    void UnRegisterEntity(unsigned  long id);

    void Update();

private:
    PhysicsManager();
    ~PhysicsManager();
};

inline PhysicsManager::CollisionFlags operator |(PhysicsManager::CollisionFlags a, PhysicsManager::CollisionFlags b){

    return static_cast<PhysicsManager::CollisionFlags>(static_cast<unsigned int>(a) | static_cast<unsigned int>(b));
};

inline PhysicsManager::CollisionFlags operator &(PhysicsManager::CollisionFlags a, PhysicsManager::CollisionFlags b){

    return static_cast<PhysicsManager::CollisionFlags>(static_cast<unsigned int>(a) & static_cast<unsigned int>(b));
}

#endif
