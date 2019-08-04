#ifndef InputHandler_h
#define InputHandler_h

#include "SDL2/SDL.h"
#include <vector>
#include "Vector2D.h"

enum mouse_buttons
{
    LEFT = 0,
    MIDDLE = 1,
    RIGHT = 2
};

const int m_joystickDeadZone = 10000;

class InputHandler
{
public:

    static InputHandler* Instance()
    {
        if(instance == 0)
        {
            instance = new InputHandler();
        }
        return instance;
    }
    
    int xValue(int joy, int stick);
    int yValue(int joy, int stick);
    
    void initializeJoysticks();
    
    bool joysticksInitialized()
    {
        return m_bJoysticksInitialized;
    }
    
    bool getButtonState(int joy, int buttonNumber)
    {
        return m_buttonStates[joy][buttonNumber];
    }
    
    bool getMouseButtonState(int buttonNumber)
    {
        return m_mouseButtonStates[buttonNumber];
    }
    
    Vector2D* getMousePosition()
    {
        return m_mousePosition;
    }
    
    bool isKeyDown(SDL_Scancode key);
    
    void clean();
    void update();
    
private:
    
    InputHandler();
    ~InputHandler() {}
    
    static InputHandler* instance;
    
    std::vector<SDL_Joystick*> m_joysticks;
    std::vector<std::pair<Vector2D*, Vector2D*>> m_joystickValues;
    std::vector<std::vector<bool>> m_buttonStates;
    std::vector<bool> m_mouseButtonStates;
    
    Vector2D* m_mousePosition;
    Uint8* m_keystates;
    
    bool m_bJoysticksInitialized;
    
    void onKeyDown();
    void onKeyUp();
    
    void onMouseMove(SDL_Event& event);
    void onMouseButtonDown(SDL_Event& event);
    void onMouseButtonUp(SDL_Event& event);
    
    void onJoystickAxisMove(SDL_Event& event);
    void onJoystickButtonDown(SDL_Event& event);
    void onJoystickButtonUp(SDL_Event& event);
};

typedef InputHandler TheInputHandler;

#endif /* InputHandler_h */
