
#include "viewmodel.h"
#include <iostream>
#include <Shapes.h>

viewmodel::viewmodel(std::shared_ptr<Shapes> helix, DataSender* sender)
    :m_helix(helix)
    ,m_sender(sender)
    ,m_lvlgame(0)
    ,m_mindsit(0)

{
    connect(m_sender,&DataSender::currentStatusChanged,this,&viewmodel::currentstautsChanged);
    m_helix->callbackmethod(std::bind(&viewmodel::setdatamindist,this));
}

bool viewmodel::isonline(double xmouse, double ymouse)
{
    return m_helix->isonline(xmouse,ymouse,m_lvlgame);
}

void viewmodel::sendname(QString name , QString family)
{
    QMetaObject::invokeMethod(m_sender, "sendname", Q_ARG(QString, name) ,Q_ARG(QString, family));
}

void viewmodel::setdatamindist()
{
    setMindsit(m_helix->mindist());
}

void viewmodel::send(long time)
{
    QMetaObject::invokeMethod(m_sender, "send", Q_ARG(long, time));
}

std::shared_ptr<Shapes> viewmodel::helix() const
{
    return m_helix;
}

void viewmodel::setHelix(const std::shared_ptr<Shapes> &newHelix)
{
    m_helix = newHelix;
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


QString viewmodel::currentstauts() const
{

    return m_sender->currentStatus();
}


QString viewmodel::myname() const
{
    return m_myname;
}

void viewmodel::setMyname(const QString &newMyname)
{
    if (m_myname == newMyname)
        return;
    m_myname = newMyname;
    emit mynameChanged();
}

double viewmodel::mindsit() const
{
    return m_mindsit;
}

void viewmodel::setMindsit(double newMindsit)
{
    if (qFuzzyCompare(m_mindsit, newMindsit))
        return;
    m_mindsit = newMindsit;
    emit mindsitChanged();
}


QString viewmodel::myfamily() const
{
    return m_myfamily;
}

void viewmodel::setMyfamily(const QString &newMyfamily)
{
    if (m_myfamily == newMyfamily)
        return;
    m_myfamily = newMyfamily;
    emit myfamilyChanged();
}
