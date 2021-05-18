//
// Created by arttu on 11/05/2021.
//

#ifndef SDLTUTORIAL_GRAPHICS_H
#define SDLTUTORIAL_GRAPHICS_H

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <stdio.h>
#include <string>

namespace SDL{

    class Graphics{

        // Variables
    public:
        static const int SCREEN_WIDTH = 1620;
        static const int SCREEN_HEIGHT = 1080;
        const char* WINDOW_TITLE = "Cat Game";

    private:
        static Graphics* sInstance;
        static bool sInitialized;

        SDL_Window* mWindow;
        SDL_Surface* mBackBuffer;

        SDL_Renderer* mRenderer;

        // Functions
    public:
        static Graphics* Instance();
        static void Release();
        static bool Initialized();

        SDL_Texture* LoadTexture(std::string path);
        SDL_Texture* CreateTextTexture(TTF_Font* font, std::string text, SDL_Color color);

        void ClearBackBuffer();

        void DrawTexture(SDL_Texture* texture, SDL_Rect* clip = NULL, SDL_Rect* rend = NULL, float angle = 0.0f, SDL_RendererFlip flip = SDL_FLIP_NONE);

        void DrawLine(float startX, float startY, float endX, float endY);

        void DrawDot(float x, float y);

        void Render();

    private:
        Graphics();
        ~Graphics();

        bool Init();
    };
}

#endif
