#include "Player.h"

void PlayerA::attack(PlayerB& player)
{
    player.subHP(this->m_attack);
}

void PlayerB::attack(PlayerA& player)
{
    player.subHP(this->m_attack);
}
