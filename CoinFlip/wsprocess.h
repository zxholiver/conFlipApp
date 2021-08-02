#ifndef WSPROCESS_H
#define WSPROCESS_H
#include <QByteArray>
#include <QString>
#include <QDebug>
#include <QtWebSockets>

class wsProcess
{
public:
    wsProcess();
    void createConnect(QUrl);
    void onDisconnected();//断开连接后执行方法
    void onConnected();//连接成功后执行方法
    void onBinaryMessageReceived(QByteArray message);//收到数据后执行方法（此处为收到二进制数据方法）
    void onTextMessageReceived(QString message);//收到数据后执行方法（此处为收到字符数据方法）
    void reconnect();//需要重连时执行方法
};

#endif // WSPROCESS_H
