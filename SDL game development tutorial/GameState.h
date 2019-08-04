#ifndef GameState_h
#define GameState_h

#include <string>

class GameState
{
public:
    
    virtual void update() = 0;
    virtual void render() = 0;
    
    virtual bool onEnter() = 0;
    virtual bool onExit() = 0;
    
    virtual std::string getStateID() const = 0;
    
    virtual ~GameState() {}
};
#endif /* GameState_h */
