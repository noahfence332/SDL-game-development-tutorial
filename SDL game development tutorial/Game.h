#ifndef Game_h
#define Game_h

#include "SDL2/SDL.h"
#include <iostream>
#include "SDL2_image/SDL_image.h"
#include "GameObject.h"
#include "Player.h"
#include "Enemy.h"
#include <vector>
#include "GameStateMachine.h"
#include "GameState.h"
#include "MenuState.h"
#include "PlayState.h"

class Game
{
public:
    
    static Game* Instance()
    {
        if(instance == 0)
        {
            instance = new Game();
            return instance;
        }
        return instance;
    }
    
    bool init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen);
    
    void render();
    void update();
    void handleEvents();
    void clean();
    
    bool isRunning() {return running;}
    
    SDL_Renderer* getRenderer() const { return renderer; }
    
private:
    
    static Game* instance;
    
    bool running;
    SDL_Window* window;
    SDL_Renderer* renderer;
    
    int currentFrame;
    
    GameStateMachine* m_pGameStateMachine;
    
    std::vector<GameObject*> gameObject;
    
    Game() {}
    ~Game() {}
    
};

typedef Game TheGame;

#endif /* Game_h */
