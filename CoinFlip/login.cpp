#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QDebug>
#include <QApplication>
#include "websocketclient.h"

login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ws->onNewConnection();//创建新连接

    //登录状态
    connect(ui->loginBtn,&QPushButton::clicked,this,&login::loginProcess);
    //注册-----
    connect(ui->regBtn,&QPushButton::clicked,ws,&websocketClient::sendText);
}

login::~login()
{
    delete ui;
}
//切换主界面槽函数
void login::loginProcess(){
    QString name = "";
    QString pwd = "";
    name = ui->getName->text();
    pwd = ui->getPwd->text();
    //qDebug()<<user<<' '<<pwd;
    ws->login(name,pwd);
    //隐藏登录界面
    this->hide();
    //登陆时发送信号展示主界面
    emit showMain();
}

