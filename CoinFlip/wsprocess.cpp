#include "wsprocess.h"
#include <QtWebSockets>
#include <QObject>

wsProcess::wsProcess()
{
    //ws.sendTextMessage("你好");//为何接收不到
    //显示主界面连接
    //QObject::connect(&ws,&QWebSocket::connected,this,&wsProcess::onConnected);
    //QWebSocket * websocket = new QWebSocket();
//    connect(websocket,SIGNAL(connected()),this,SLOT(onConnected()),Qt::UniqueConnection);
//    connect(websocket,SIGNAL(disconnected()),this,SLOT(onDisconnected()),Qt::UniqueConnection);
//    connect(websocket, SIGNAL(binaryMessageReceived(QByteArray)), this, SLOT(onBinaryMessageReceived(QByteArray)),Qt::UniqueConnection);
//
}
void wsProcess::createConnect(QUrl url){
    //创建websocket服务
    QWebSocket * ws = new QWebSocket();
    ws->open(url);
}
void wsProcess::onDisconnected()
{
    qDebug()<<"websocket is disconnected";
    reconnect();
}
void wsProcess::onConnected()
{
    qDebug()<<"connect successful";
    QString message =  "";
    //websocket->sendTextMessage(message);

}
void wsProcess::onBinaryMessageReceived(QByteArray message)
{
}
void wsProcess::reconnect()
{
   qDebug()<<"websocket reconnected";
//   websocket->abort();
//   websocket->open((QUrl(url)));
}
