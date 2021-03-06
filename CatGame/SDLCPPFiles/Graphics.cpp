//
// Created by Arttu Paldán on 11/05/2021.
//


#include "../SDLHeaderFiles/Graphics.h"

namespace SDL{

    Graphics* Graphics::sInstance = NULL;
    bool Graphics::sInitialized = false;

    Graphics* Graphics::Instance() {

        if(sInstance == NULL)
            sInstance = new Graphics();

        return sInstance;
    }

    void Graphics::Release() {
        delete sInstance;
        sInstance = NULL;

        sInitialized = false;
    }

    bool Graphics::Initialized() {

        return sInitialized;
    }

    Graphics::Graphics() {

        mBackBuffer = NULL;

        sInitialized = Init();
    }

    Graphics::~Graphics() {

        SDL_DestroyWindow(mWindow);
        mWindow = NULL;

        SDL_DestroyRenderer(mRenderer);
        mRenderer = NULL;

        TTF_Quit();
        IMG_Quit();
        SDL_Quit();
    }

    bool Graphics::Init() {

        if(SDL_Init(SDL_INIT_VIDEO) < 0){
            printf("SDLFramework Initialization error: $s\n", SDL_GetError());
            return false;
        }

        mWindow = SDL_CreateWindow(WINDOW_TITLE, SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);

        if(mWindow == NULL){

            printf("Window Creation Error: $s\n", SDL_GetError());
            return false;
        }

        mRenderer = SDL_CreateRenderer(mWindow, -1, SDL_RENDERER_ACCELERATED);

        if(mRenderer == NULL){
            printf("Renderer Creation Error: %s\n", SDL_GetError());
            return false;
        }

        SDL_SetRenderDrawColor(mRenderer, 0xff, 0xff, 0xff, 0xff);

        int flags = IMG_INIT_PNG;
        if(!(IMG_Init(flags) & flags)){

            printf("IMG Initialization Error: %s\n", IMG_GetError());
            return false;
        }

        if(TTF_Init() == -1){

            printf("TTF Initilization Error: %s\n", TTF_GetError());
            return false;
        }

        mBackBuffer = SDL_GetWindowSurface(mWindow);

        return true;
    }

    SDL_Texture* Graphics::LoadTexture(std::string path) {

        SDL_Texture* texture = NULL;

        SDL_Surface* surface = IMG_Load(path.c_str());
        if(surface == NULL){
            printf("Image Load Error: Path(%s) - Error(%s)\n", path.c_str(), IMG_GetError());
            return texture;
        }

        texture = SDL_CreateTextureFromSurface(mRenderer, surface);
        if(texture == NULL){

            printf("Create Texture Error: %s\n", SDL_GetError());
            return texture;
        }
        // if neither triggers, we have created a texture.
        SDL_FreeSurface(surface);

        return texture;
    }

    SDL_Texture* Graphics::CreateTextTexture(TTF_Font *font, std::string text, SDL_Color color) {

        SDL_Surface* surface = TTF_RenderText_Solid(font, text.c_str(), color);
        if(surface == NULL){

            printf("Text Render Error: %s\n", TTF_GetError());
            return NULL;
        }

        SDL_Texture* texture = SDL_CreateTextureFromSurface(mRenderer, surface);
        if(texture == NULL){

            printf("Text Texture Creation Error: %s\n", SDL_GetError());
            return NULL;
        }

        SDL_FreeSurface(surface);

        return texture;
    }

    void Graphics::ClearBackBuffer() {

        SDL_RenderClear(mRenderer);
    }

    void Graphics::DrawTexture(SDL_Texture* texture, SDL_Rect* clip,  SDL_Rect* rend, float angle, SDL_RendererFlip flip) {

        SDL_RenderCopyEx(mRenderer, texture, clip, rend, angle, NULL, flip);
    }

    void Graphics::DrawLine(float startX, float startY, float endX, float endY) {

        SDL_SetRenderDrawColor(mRenderer, 105, 105, 105, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawLine(mRenderer, startX, startY, endX, endY);
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    }

    void Graphics::Render() {

        SDL_RenderPresent(mRenderer);
    }

    void Graphics::DrawDot(float x, float y, int r, int g, int b) {

        SDL_SetRenderDrawColor(mRenderer, r, g, b, SDL_ALPHA_OPAQUE);
        SDL_RenderDrawPoint(mRenderer, x, y);
        SDL_SetRenderDrawColor(mRenderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
    }
}