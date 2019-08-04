#include <stdio.h>
#include "SDLGameObject.h"
#include "TextureManager.h"
#include "Vector2D.h"

SDLGameObject::SDLGameObject(const LoaderParams* Params) :
    GameObject(Params),
    m_postion(Params->getX(),Params->getY()),
    m_velocity(0,0),
    m_acceleration(0,0)
{
    m_width = Params->getWidth();
    m_height = Params->getHeight();
    m_textureID = Params->getTextureID();
    
    m_currentRow = 1;
    m_currentFrame = 1;
}

void SDLGameObject::draw()
{
    TextureManager::Instance()->drawFrame(m_textureID, (int)m_postion.getX(), (int)m_postion.getY(), m_width, m_height, m_currentRow, m_currentFrame, TheGame::Instance()->getRenderer());
}

void SDLGameObject::update()
{
    m_postion += m_velocity;
    m_velocity += m_acceleration;
}

void SDLGameObject::clean(){}
