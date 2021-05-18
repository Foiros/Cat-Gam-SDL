//
// Created by Arttu Paldán on 11/05/2021.
//

#ifndef SDLTUTORIAL_ASSETMANAGER_H
#define SDLTUTORIAL_ASSETMANAGER_H

#include <SDL_mixer.h>
#include "Graphics.h"
#include <map>

namespace SDL{

    class AssetManager {

        // Variables
    private:

        static AssetManager* sInstance;

        std::map<std::string, SDL_Texture*> mTextures;
        std::map<std::string, SDL_Texture*> mTexts;
        std::map<std::string, TTF_Font*> mFonts;
        std::map<std::string, Mix_Music*> mMusic;
        std::map<std::string, Mix_Chunk*> mSFX;

        //Functions
    public:

        static AssetManager* Instance();
        static void Release();

        SDL_Texture* GetTexture(std::string filename);
        SDL_Texture* GetText(std::string text, std::string filename, int size, SDL_Color color);

        Mix_Music* GetMusic(std::string filename);
        Mix_Chunk* GetSFX(std::string filename);


    private:
        AssetManager();
        ~AssetManager();

        TTF_Font* GetFont(std::string filename, int size);
    };
}

#endif
