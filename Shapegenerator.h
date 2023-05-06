
#ifndef SHAPEGENERATOR_H
#define SHAPEGENERATOR_H

#include<QObject>
#include<QVector>

//enum class levelgame
//{
//    easy,
//    hard
//};

class Shapegenerator : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QVector<int> xy READ xy WRITE setxy NOTIFY xyChanged)
public:
    Shapegenerator();
    QVector<int> xy() const;
    void setxy(const QVector<int> &newXy);
    Q_INVOKABLE QVector<int> makeline();
signals:
    void xyChanged();
private:
    QVector<int> m_xy;
};

#endif // SHAPEGENERATOR_H
