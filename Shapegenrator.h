#ifndef SHAPEGENRATOR_H
#define SHAPEGENRATOR_H

#include <QObject>
#include <QMap>
#include <iostream>
#include<string>
#include<QDebug>
#include<QVector>




class Shapegenrator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<int> numbers READ numbers WRITE setNumbers NOTIFY numbersChanged)
    Q_PROPERTY(QVector<double> distances READ distance WRITE setDistance NOTIFY distanceChanged)
public:
    Shapegenrator();
    Q_INVOKABLE QVector<int> pathline();
    Q_INVOKABLE bool isonline(double xmouse, double ymouse);
    QVector<int> numbers() const;
    void setNumbers(const QVector<int> &newNumbers);

    QVector<double> distance() const;
    void setDistance(const QVector<double> &newDistances);

signals:
    void numbersChanged();

    void distanceChanged();

private:
    QVector<int> m_numbers;
    QVector<double> m_distances;
};

#endif // SHAPEGENRATOR_H




