//
// Created by Arttu Paldán on 11/05/2021.
//

#ifndef SDLTUTORIAL_TEXTURE_H
#define SDLTUTORIAL_TEXTURE_H

#include "GameEntity.h"
#include "AssetManager.h"

class Texture : public GameEntity {

    // Variables
protected:

    SDL_Texture* mTexture;

    Graphics* mGraphics;

    int mWidth;
    int mHeight;

    bool mClipped;
    SDL_Rect mRenderRect;
    SDL_Rect mClipRect;

    // Functions
public:

    Texture(std::string fileName);
    Texture(std::string fileName, int x, int y, int w, int h);
    Texture(std::string text, std::string fontpath, int size, SDL_Color color);
    ~Texture();

    Vector2 ScaledDimensions();

    virtual void Render();

};


#endif
