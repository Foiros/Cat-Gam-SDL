//
// Created by arttu on 12/05/2021.
//

#ifndef SDLTUTORIAL_AUDIOMANAGER_H
#define SDLTUTORIAL_AUDIOMANAGER_H

#include "AssetManager.h"

class AudioManager {

private:

    static AudioManager* sInstance;

    AssetManager* mAssetManager;

public:

    static AudioManager* Instance();
    static void Release();

    // -1 loops the music
    void PlayMusic(std::string filename, int loops = -1);
    void PauseMusic();
    void ResumeMusic();

    // 0 plays music or sound effect once
    void PlaySFX(std::string filename, int loops = 0, int channel = 0);

private:

    AudioManager();
    ~AudioManager();
};


#endif
