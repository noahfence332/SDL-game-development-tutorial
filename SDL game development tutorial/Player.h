#ifndef Player_h
#define Player_h
#include "GameObject.h"
#include "SDLGameObject.h"
#include "InputHandler.h"

class Player : public SDLGameObject
{
public:

    Player(const LoaderParams* Params);
    
    
    virtual void draw();
    virtual void update();
    virtual void clean(){}
    
private:
    void handleInput();
};

#endif /* Player_h */
