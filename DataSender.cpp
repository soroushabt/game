
#include "DataSender.h"
#include <iostream>

DataSender::DataSender(QTcpSocket *tcpSocket , std::shared_ptr<Shapes> myshape )
    : m_tcpSocket(tcpSocket)
    , m_shape(myshape)
{
    setCurrentStatus("red");
    QObject::connect(m_tcpSocket, &QTcpSocket::connected, this, &DataSender::handleConnected);
}

void DataSender::send(long time)
{
//    std::cerr << "start to write " << std::endl;
    double value = m_shape->mindist();
    int precision = 2;
    data.append(QString::number(value, 'f', 2));
    data.append(',');
    data.append(QString::number(time));
    data.append('$');
    m_tcpSocket->write(data.toLocal8Bit());
    qDebug() << "datasend" <<  data;
    data.clear();
//    m_tcpSocket->flush();
//    m_tcpSocket->waitForBytesWritten();
}

void DataSender::sendname()
{

}

void DataSender::connect()
{
    while (!m_isConnected) {
        setCurrentStatus("yellow");
        m_tcpSocket->connectToHost("127.0.0.1", 2000);
        std::cerr << "connecting" << std::endl;
        std::cerr << m_isConnected << std::endl;
        m_tcpSocket->waitForConnected();
    }
}

void DataSender::handleConnected()
{
    std::cerr << "connected" << std::endl;
    setCurrentStatus("green");
    setIsConnected(true);
}

QString DataSender::name() const
{
    return m_name;
}

bool DataSender::isConnected() const
{
    return m_isConnected;
}

void DataSender::setIsConnected(bool newIsConnected)
{
    m_isConnected = newIsConnected;
}


QString DataSender::currentStatus() const
{
    return m_currentStatus;
}

void DataSender::setCurrentStatus(const QString &newCurrentStatus)
{
    if (m_currentStatus == newCurrentStatus)
        return;
    m_currentStatus = newCurrentStatus;
    emit currentStatusChanged();
}
