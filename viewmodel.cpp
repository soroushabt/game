
#include "viewmodel.h"
#include <iostream>
#include <Shapes.h>

viewmodel::viewmodel(Shapes* helix)
    :m_lvlgame(0)
    ,m_helix(helix)

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


Shapes *viewmodel::snake() const
{
    return m_helix;
}

void viewmodel::setSnake(Shapes *newHelix)
{
    m_helix = newHelix;
}

bool viewmodel::isonline(double xmouse, double ymouse)
{
    return m_helix->isonline(xmouse,ymouse);
}
