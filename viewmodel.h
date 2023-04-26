
#ifndef VIEWMODEL_H
#define VIEWMODEL_H


#include <QObject>


class viewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lvlgame READ lvlgame WRITE setLvlgame NOTIFY lvlgameChanged)

public:
    viewmodel();
    int lvlgame() const;
    void setLvlgame(int newLvlgame);
    void test();
signals:
    void lvlgameChanged();
private:
    int m_lvlgame;
};

#endif // VIEWMODEL_H
