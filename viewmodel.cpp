
#include "viewmodel.h"
#include <iostream>

viewmodel::viewmodel()
    :m_lvlgame(0)
{

}


int viewmodel::lvlgame() const
{
    return m_lvlgame;
}

void viewmodel::setLvlgame(int newLvlgame)
{
    if (m_lvlgame == newLvlgame)
        return;
    m_lvlgame = newLvlgame;
    emit lvlgameChanged();
}

void viewmodel::test()
{
    std::cerr << m_lvlgame << std::endl;
}
