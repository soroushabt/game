
#ifndef VIEWMODEL_H
#define VIEWMODEL_H


#include <QObject>
#include "Shapes.h"
#include "DataSender.h"
#include <functional>


class viewmodel : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int lvlgame READ lvlgame WRITE setLvlgame NOTIFY lvlgameChanged)
    Q_PROPERTY(std::shared_ptr<Shapes> helix READ helix WRITE setHelix CONSTANT)
    Q_PROPERTY(QString currentstauts READ currentstauts NOTIFY currentstautsChanged)
    Q_PROPERTY(QString myname READ myname WRITE setMyname NOTIFY mynameChanged)
    Q_PROPERTY(QString myfamily READ myfamily WRITE setMyfamily NOTIFY myfamilyChanged)
    Q_PROPERTY(double mindsit READ mindsit WRITE setMindsit NOTIFY mindsitChanged)

public:
    viewmodel(std::shared_ptr<Shapes> helix , DataSender *sender);
    Q_INVOKABLE bool isonline(double xmouse, double ymouse);
    Q_INVOKABLE void send(long time);
    Q_INVOKABLE void sendname(QString name , QString family);
    void setdatamindist();

    std::shared_ptr<Shapes> helix() const;
    void setHelix(const std::shared_ptr<Shapes> &newHelix);

    int lvlgame() const;
    void setLvlgame(int newLvlgame);

    QString currentstauts() const;

    QString myname() const;
    void setMyname(const QString &newMyname);

    double mindsit() const;

    void setMindsit(double newMindsit);


    QString myfamily() const;
    void setMyfamily(const QString &newMyfamily);

signals:
    void lvlgameChanged();
    void currentstautsChanged();

    void datasenderChanged();
    void mynameChanged();

    void mindsitChanged();


    void myfamilyChanged();

private:
    std::shared_ptr<Shapes> m_helix;
    DataSender* m_sender;
    int m_lvlgame;
    QString m_currentstauts;
    QString m_myname;
    double m_mindsit;
    QString m_myfamily;
};

#endif // VIEWMODEL_H
