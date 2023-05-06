
#ifndef VIEWMODEL_H
#define VIEWMODEL_H


#include <QObject>
#include "Shapes.h"
#include "DataSender.h"


class viewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lvlgame READ lvlgame WRITE setLvlgame NOTIFY lvlgameChanged)
    Q_PROPERTY(std::shared_ptr<Shapes> helix READ helix WRITE setHelix CONSTANT)
    Q_PROPERTY(QString currentstauts READ currentstauts WRITE setCurrentstauts NOTIFY currentstautsChanged)
    Q_PROPERTY(QString myname READ myname WRITE setMyname NOTIFY mynameChanged)

public:
    viewmodel(std::shared_ptr<Shapes> helix , DataSender *sender);
    Q_INVOKABLE bool isonline(double xmouse, double ymouse);
    Q_INVOKABLE void send(QString time);
    Q_INVOKABLE void sendname();

    std::shared_ptr<Shapes> helix() const;
    void setHelix(const std::shared_ptr<Shapes> &newHelix);

    int lvlgame() const;
    void setLvlgame(int newLvlgame);

    QString currentstauts() const;

    void setCurrentstauts(const QString &newCurrentstauts);

    QString myname() const;
    void setMyname(const QString &newMyname);

signals:
    void lvlgameChanged();
    void currentstautsChanged();

    void datasenderChanged();
    void mynameChanged();

private:
    std::shared_ptr<Shapes> m_helix;
    DataSender* m_sender;
    int m_lvlgame;
    QString m_currentstauts;
    QString m_myname;
};

#endif // VIEWMODEL_H
