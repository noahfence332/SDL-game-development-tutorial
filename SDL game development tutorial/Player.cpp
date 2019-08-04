#include <stdio.h>
#include "Player.h"


Player::Player(const LoaderParams* Params) : SDLGameObject(Params) {}

void Player::draw()
{
    SDLGameObject::draw();
}

void Player::update()
{
    m_velocity.setX(0);
    m_velocity.setY(0);
    
    handleInput();
    
    m_currentFrame = int(((SDL_GetTicks() / 100) % 6));
    
    SDLGameObject::update();
}

void Player::handleInput()
{
    
    Vector2D* vec = TheInputHandler::Instance()->getMousePosition();
    
    m_velocity = (*vec - m_postion) / 100;
}
