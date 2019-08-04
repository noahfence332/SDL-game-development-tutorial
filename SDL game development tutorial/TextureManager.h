#ifndef TextureManager_h
#define TextureManager_h

#include <string>
#include "SDL2/SDL.h"
#include <iostream>
#include "SDL2_image/SDL_image.h"
#include <map>
#include "Game.h"

class TextureManager
{
    
public:
    
    ~TextureManager(){}

bool load(std::string fileName, std::string id, SDL_Renderer* renderer);

void draw(std::string id, int x, int y, int width, int height, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

void drawFrame(std::string id, int x, int y, int width, int height, int currentRow, int currentFrame, SDL_Renderer* renderer, SDL_RendererFlip flip = SDL_FLIP_NONE);

   
    
    static TextureManager* Instance()
    {
        if(instance == 0)
        {
            instance = new TextureManager();
            return instance;
        }
        return instance;
    }
    
    private:
    
    std::map<std::string, SDL_Texture*> textureMap;
    
    static TextureManager* instance;
    
    TextureManager(){};
    
};

typedef TextureManager TheTextureManager;

#endif /* TextureManager_h */
