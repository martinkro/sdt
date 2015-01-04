#ifndef __PLAYER_H__
#define __PLAYER_H__

#include "sdt.h"

class PlayerA
{
public:
    PlayerA(int hp, float mp,unsigned int attack,long defense)
        :m_hp(hp),m_mp(mp),m_attack(attack),m_defense(defense)
    {

    }

public:
    void addHP(int deltaHP)
    {
        m_hp += deltaHP;
        if (m_hp >= 100) m_hp = 100;
    }

    void subHP(int deltaHP)
    {
        m_hp -= deltaHP;
        if (m_hp <= 0) m_hp += m_defense * 0.1;
    }

    void addMP(float deltaMP)
    {
        m_mp += deltaMP;
        if (m_mp >= 100) m_mp = 100;
    }

    void subHP()
    {

    }
private:
    int m_hp;
    float m_mp;
    unsigned int m_attack;
    long m_defense;
};

class PlayerB
{
private:
    sdt_int m_hp;
    sdt_float m_mp;
    sdt_uint m_attack;
    sdt_long m_defense;
};

#endif
