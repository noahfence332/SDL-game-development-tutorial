#include <stdio.h>
#include "Game.h"
#include "TextureManager.h"
#include "InputHandler.h"

Game* Game::instance = 0;

bool Game::init(const char* title, int xpos, int ypos, int width, int height, bool fullscreen)
{
    int flags = 0;
    
    if(fullscreen)
    {
        flags = SDL_WINDOW_FULLSCREEN;
    }
    
    if(SDL_Init(SDL_INIT_EVERYTHING) == 0)
    {
        std::cout << "SDL init success\n";
        window = SDL_CreateWindow(title, xpos, ypos, width, height, fullscreen);
        if(window !=0)
        {
            std::cout << "window creation success\n";
            renderer = SDL_CreateRenderer(window, -1, 0);
            
            if(renderer != 0)
            {
                std::cout << "renderer creation success\n";
                SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
            }
            else
            {
                std::cout << "renderer init fail\n";
                return false;
            }
        }
        else
        {
            std::cout << "window init fail\n";
            return false;
        }
    }
    else
    {
        std::cout << "SDL init fail\n";
        return false;
    }
    
    std::cout << "init success\n";
    
    running = true;
    
    if(!TheTextureManager::Instance()->load("/Users/noah/Desktop/SDL game development tutorial/SDL-game-development-tutorial/assets/animate-alpha.png","animate", renderer))
    {
        return false;
    }
    
    m_pGameStateMachine = new GameStateMachine();
    m_pGameStateMachine->changeState(new MenuState());
    
    gameObject.push_back(new Player(new LoaderParams(100, 100, 128, 82, "animate")));
    
    gameObject.push_back(new Enemy(new LoaderParams(300, 300, 128, 82, "animate")));
    
    TheInputHandler::Instance()->initializeJoysticks();
    
    return true;
}

void Game::handleEvents()
{
    
    TheInputHandler::Instance()->update();
    
    if(TheInputHandler::Instance()->isKeyDown(SDL_SCANCODE_RETURN))
    {
        m_pGameStateMachine->changeState(new PlayState());
    }
    
}

void Game::update()
{
    m_pGameStateMachine->update();
}

void Game::render()
{
    SDL_RenderClear(renderer);
    
    m_pGameStateMachine->render();
    
    SDL_RenderPresent(renderer);
}

void Game::clean()
{
    
    TheInputHandler::Instance()->clean();
    
    std::cout << "cleaning game\n";
    SDL_DestroyWindow(window);
    SDL_DestroyRenderer(renderer);
    SDL_Quit();
    
}
