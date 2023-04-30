
#include "Shapegenerator.h"
#include<iostream>

Shapegenerator::Shapegenerator()
{

}

QVector<int> Shapegenerator::xy() const
{
    return m_xy;
}

void Shapegenerator::setxy(const QVector<int> &newXy)
{
    if (m_xy == newXy)
        return;
    m_xy = newXy;
    emit xyChanged();
}

QVector<int> Shapegenerator::makeline(levelgame a)
{
    std::srand(time(NULL));
    QVector<int> temp;
    m_xy.reserve(30);
    int randx = 0;
    int randy = 0;

    for(int i=0 ; i<28 ; ++i)
    {
        if(i%2==0)
        {
            randx += 75;
            temp.append(randx);
        }

        else
        {
            if(i==27)
            {
                randy=200;
                temp.append(randy);
            }
            if(a==levelgame::easy)
                randy=rand()%150;
            else if(a==levelgame::hard)
                randy=rand()%300;

            temp.append(randy);
        }

    }

    m_xy = temp;
    return m_xy;
}
