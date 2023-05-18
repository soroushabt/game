
#ifndef DATASENDER_H
#define DATASENDER_H

#include <QObject>
#include <QTcpSocket>
#include "Shapes.h"


class DataSender : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString currentStatus READ currentStatus WRITE setCurrentStatus NOTIFY currentStatusChanged)
public:
    DataSender(QTcpSocket *tcpSocket, std::shared_ptr<Shapes> myshape);
    void sendname();

    bool isConnected() const;
    void setIsConnected(bool newIsConnected);

    QString currentStatus() const;
    void setCurrentStatus(const QString &newCurrentStatus);

    QString name() const;

public slots:
    void connect();
    void send(long time);
    void sendname(QString name , QString family);
    void sendfinish();
    void handleConnected();
signals:
    void currentStatusChanged();

private:
    QTcpSocket *m_tcpSocket;
    std::shared_ptr<Shapes> m_shape;
    bool m_isConnected =false;
    QString m_currentStatus;
    QString m_name;
    QString data;
};

#endif // DATASENDER_H

//Q_DECLARE_METATYPE(DataSender)
