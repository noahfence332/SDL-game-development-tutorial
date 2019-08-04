#include <stdio.h>
#include "Enemy.h"

Enemy::Enemy(const LoaderParams* Params) : SDLGameObject(Params) {}

void Enemy::draw()
{
    SDLGameObject::draw();
}

void Enemy::update()
{
    m_postion.setX(m_postion.getX() + 1);
    m_postion.setY(m_postion.getY() + 1);
}

void Enemy::clean(){}
