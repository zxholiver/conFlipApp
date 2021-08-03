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
    //初始化注册登录状态
    islogin = false;
    isregister = false;
    qDebug()<<"收到信息"<<message;
    //收到消息后根据消息采取跳转
    if(message == "登录成功！"){
        islogin = true;
    }
    else if(message == "注册成功！"){
        isregister = true;
    }
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
    if(islogin){
        emit logined();
        islogin = false;
    }
}
//注册槽函数
void websocketClient::regist(QString name,QString pwd){
    QString str = "{\"name\":\""+name+"\",\"pwd\":\""+pwd+"\",\"type\":\"register\"}";
    qDebug()<<str;
    ws->sendTextMessage(str);
    if(isregister){
        emit registered();
        isregister = false;
    }
}

