#ifndef GameObject_h
#define GameObject_h

#include <string>
#include "SDL2/SDL.h"
#include <iostream>
#include "SDL2_image/SDL_image.h"
#include "LoaderParams.h"

class GameObject
{
public:
    
    virtual void draw() = 0;
    virtual void update() = 0;
    virtual void clean() = 0;
    
protected:
    
    GameObject(const LoaderParams* Params) {}
    virtual ~GameObject(){}
    
};

#endif /* GameObject_h */
