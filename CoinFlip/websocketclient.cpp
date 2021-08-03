#include "websocketclient.h"
#include <QJsonObject>
#include <QByteArray>
#include <iostream>

using namespace std;
websocketClient::websocketClient(QObject *parent) : QObject(parent)
{

}

//新建连接
void websocketClient::onNewConnection(){
    ws->open(QUrl("ws://127.0.0.1:9511"));
    qDebug()<<"已连接服务器";
    //连接处理信息槽函数
    connect(ws, &QWebSocket::textMessageReceived,this,&websocketClient::processMessage);
    //连接关闭槽函数
    connect(ws, &QWebSocket::disconnected,this, &websocketClient::socketDisconnected);
}
//接收消息处理
void websocketClient::processMessage(const QString &message){
    qDebug()<<"收到信息:"<<message;
    //收到消息后根据消息采取跳转
    if(message == "登录成功！"){
        emit logined();
    }
    else if(message == "注册成功！"){
        emit registered();
    }
    else if(message == "账号或密码错误！" || message == "该用户已注册，请勿重复注册！"){
        emit err_name_pwd();
    }

}
//发送文本
void websocketClient::sendText(){
    ws->sendTextMessage(QString("你好"));
}
//登录槽函数
void websocketClient::login(QString name,QString pwd){
    QString str = "{\"name\":\""+name+"\",\"pwd\":\""+pwd+"\",\"type\":\"login\"}";
    qDebug()<<str;
    if(name == "" || pwd == ""){
        emit err_name_pwd();
    }
    else{
        ws->sendTextMessage(str);
    }
}
//注册槽函数
void websocketClient::regist(QString name,QString pwd){
    QString str = "{\"name\":\""+name+"\",\"pwd\":\""+pwd+"\",\"type\":\"register\"}";
    qDebug()<<str;
    //判空----
    if(name == "" || pwd == ""){
        emit err_name_pwd();
    }
    else{
        ws->sendTextMessage(str);
    }

}


//断开连接
void websocketClient::socketDisconnected(){
    ws->close();
}
websocketClient::~websocketClient(){
    //关闭连接
    ws->close();
}
