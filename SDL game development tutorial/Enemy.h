#ifndef Enemy_h
#define Enemy_h
#include "GameObject.h"
#include "SDLGameObject.h"

class Enemy : public SDLGameObject
{
public:
    
    Enemy(const LoaderParams* Params);
    
    virtual void draw();
    virtual void update();
    virtual void clean();
};

#endif /* Enemy_h */
