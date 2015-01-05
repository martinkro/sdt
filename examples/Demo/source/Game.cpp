#include "Game.h"

#include <stdlib.h>
Game* Game::instance = NULL;

Game* Game::getInstance()
{
    if (instance == NULL)
    {
        instance = new Game();
        instance->init();
    }

    return instance;
}

bool Game::init()
{
    m_playerA = new PlayerA(100,100,30,20);
    m_playerB = new PlayerB(100,100,30,20);

    return true;
}

void Game::addHP(int flag, int hp)
{
    if (flag == 0)
    {
        m_playerA->addHP(hp);
    }
    else
    {
        m_playerB->addHP(hp);
    }
}

void Game::attack(int flag)
{
    if (flag == 0)
    {
        m_playerA->attack(*m_playerB);
    }
    else
    {
        m_playerB->attack(*m_playerA);
    }
}
