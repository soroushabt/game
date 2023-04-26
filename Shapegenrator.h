#ifndef SHAPEGENRATOR_H
#define SHAPEGENRATOR_H


#include <QObject>
#include <QMap>
#include <iostream>
#include<string>
#include<QDebug>


class Shapegenrator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QMap<int,int> numbers READ numbers WRITE setNumbers NOTIFY numbersChanged)
public:
    Shapegenrator();
    Q_INVOKABLE QMap<int,int> pathline();
    QMap<int, int> numbers() const;
    void setNumbers(const QMap<int, int> &newNumbers);

signals:
    void numbersChanged();
private:
    QMap<int, int> m_numbers;
};

#endif // SHAPEGENRATOR_H




