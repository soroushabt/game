
#include "Shapegenrator.h"
#include<random>
#include<QVariant>
#include<QDebug>

Shapegenrator::Shapegenrator()
    :m_numbers({})
{

}

QMap<int,int> Shapegenrator::pathline()
{
    for(int i=0 ; i<10 ; ++i)
    {
        int randx=rand()%50;
        int randy=rand()%50;
        m_numbers[randx] = randy;
    }
    return m_numbers;
}

QMap<int, int> Shapegenrator::numbers() const
{
    return m_numbers;
}

void Shapegenrator::setNumbers(const QMap<int, int> &newNumbers)
{
    if (m_numbers == newNumbers)
        return;
    m_numbers = newNumbers;
    emit numbersChanged();


}


