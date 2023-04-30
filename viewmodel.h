
#ifndef VIEWMODEL_H
#define VIEWMODEL_H


#include <QObject>
#include"Shapes.h"


class viewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lvlgame READ lvlgame WRITE setLvlgame NOTIFY lvlgameChanged)
    Q_PROPERTY(Shapes* helix READ snake WRITE setSnake CONSTANT)
public:
    viewmodel(Shapes* helix);
    int lvlgame() const;
    void setLvlgame(int newLvlgame);
    Shapes *snake() const;
    void setSnake(Shapes *newHelix);
    Q_INVOKABLE bool isonline(double xmouse, double ymouse);
signals:
    void lvlgameChanged();
private:
    int m_lvlgame;

    Shapes *m_helix = nullptr;
};

#endif // VIEWMODEL_H
