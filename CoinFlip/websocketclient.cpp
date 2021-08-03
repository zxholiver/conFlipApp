#include "websocketclient.h"
#include <QJsonObject>
#include <QByteArray>
#include <iostream>

using namespace std;
websocketClient::websocketClient(QObject *parent) : QObject(parent)
{

}
websocketClient::~websocketClient(){
    //关闭连接
    ws->close();
}
//新建连接
void websocketClient::onNewConnection(){
    ws->open(QUrl("ws://127.0.0.1:9511"));
    ws->sendTextMessage(QString("你好"));
    //连接处理信息槽函数
    connect(ws, &QWebSocket::textMessageReceived,this,&websocketClient::processMessage);
    //连接关闭槽函数
    connect(ws, &QWebSocket::disconnected,this, &websocketClient::socketDisconnected);
}
//接收消息处理
void websocketClient::processMessage(const QString &message){
    qDebug()<<"收到信息"<<message;
}
//断开连接
void websocketClient::socketDisconnected(){
    ws->close();
}
//发送文本
void websocketClient::sendText(){
    ws->sendTextMessage(QString("你好"));
}
//登录槽函数
void websocketClient::login(QString name,QString pwd){
    QString str = "{\"name\":\""+name+"\",\"pwd\":\""+pwd+"\",\"type\":\"login\"}";
    qDebug()<<str;
    ws->sendTextMessage(str);
}
//注册槽函数
void websocketClient::regist(QString name,QString pwd){

}

