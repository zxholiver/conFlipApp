#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QDebug>
#include <QApplication>

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);
    //登录状态
    connect(ui->loginBtn,&QPushButton::clicked,this,&login::loginProcess);
    QUrl url = QUrl("ws://127.0.0.1:9511");
    wsProcess * ws = new wsProcess();
    ws->createConnect(url);
    //connect(ui->regBtn,&QPushButton::clicked,this,&login::onConnected(ws));
}

login::~login()
{
    delete ui;
}
void login::loginProcess(){
    QString user = "";
    QString pwd = "";
    user = ui->getName->text();
    pwd = ui->getPwd->text();
    qDebug()<<user<<' '<<pwd;
    //隐藏登录界面
    this->hide();
    //登陆时发送信号展示主界面
    emit showMain();
}
void login::onConnected(QWebSocket * ws){
    ws->sendTextMessage("你好");
}
