#ifndef __GAME_H__
#define __GAME_H__

#include "Player.h"

class Game
{
public:
    static Game* getInstance();

    ~Game()
    {
        if (m_playerA != NULL)
        {
            delete m_playerA;
            m_playerA = NULL;
        }

        if (m_playerB != NULL)
        {
            delete m_playerB;
            m_playerB = NULL;
        }
    }

private:
    bool init();

public:
    void attack(int flag);
    void addHP(int flag, int hp);

public:
    int getHP(int flag)
    {
       if (flag == 0)
       {
           return m_playerA->getHP();
       }

       return m_playerB->getHP();
    }

    float getMP(int flag)
    {
        if (flag == 0)
        {
            return m_playerA->getMP();
        }

        return m_playerB->getMP();
    }

    unsigned int getAttack(int flag)
    {
        if (flag == 0)
        {
            return m_playerA->getAttack();
        }

        return m_playerB->getAttack();
    }

    long getDefense(int flag)
    {
        if (flag == 0)
        {
            return m_playerA->getDefense();
        }

        return m_playerB->getDefense();
    }

private:
    Game(){}
private:
    PlayerA* m_playerA;
    PlayerB* m_playerB;

private:
    static Game* instance;
};

#endif
