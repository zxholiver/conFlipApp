#include "login.h"
#include "ui_login.h"
#include <QString>
#include <QDebug>
#include <QApplication>
#include "websocketclient.h"
#include <QErrorMessage>


login::login(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::login)
{
    ui->setupUi(this);

    ws->onNewConnection();//创建新连接

    //登录状态----------------------------------
    connect(ui->loginBtn,&QPushButton::clicked,this,&login::loginProcess);
    //如果已登录发送切换界面信号
    connect(ws,&websocketClient::logined,[=](){
        this->hide();
        emit showMain();
    });
    //----------------------------------------------
    //注册-------------------------------------------
    connect(ui->regBtn,&QPushButton::clicked,this,&login::registerProcess);
    //如果已注册发送切换界面信号
    connect(ws,&websocketClient::registered,[=](){
        this->hide();
        emit showMain();
    });
    //----------------------------------------------
    //账号或密码错误--------------
    connect(ws,&websocketClient::err_name_pwd,[=](){
        ui->getName->clear();
        ui->getPwd->clear();
        QErrorMessage err_wa(this);
        err_wa.setWindowTitle("错误警告");
        err_wa.showMessage("账号或密码错误！");
        err_wa.exec();
    });
    //--------------------------
}

login::~login()
{
    delete ui;
}
//登录切换主界面槽函数
void login::loginProcess(){
    QString name = "";
    QString pwd = "";
    name = ui->getName->text();
    pwd = ui->getPwd->text();
    //qDebug()<<user<<' '<<pwd;
    ws->login(name,pwd);//调用登录函数
}
//注册处理槽函数
void login::registerProcess(){
    QString name = "";
    QString pwd = "";
    name = ui->getName->text();
    pwd = ui->getPwd->text();
    //qDebug()<<user<<' '<<pwd;
    ws->regist(name,pwd);//调用注册函数
}

