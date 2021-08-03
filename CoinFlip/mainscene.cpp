#include "mainscene.h"
#include "ui_mainscene.h"
#include <QAction>
#include <QPainter>
#include <QPixmap>
#include <mypushbutton.h>
#include <QDebug>
#include <QTimer>
MainScene::MainScene(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainScene)
{
    ui->setupUi(this);
    //设置标题、固定大小、图标
    setWindowTitle("翻金币");
    setFixedSize(320,588);
    setWindowIcon(QIcon(":/res/Coin0002.png"));
    //退出按钮实现
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    //开始按钮
    MyPushButton * startBtn = new MyPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    //设置位置
    startBtn->move(this->width() * 0.5 - startBtn->width() * 0.5 , this->height() * 0.7);
    //开始按钮信号

    //实例化选择关卡场景
    chooseScene = new chooseLevelScene;
    //监听返回状态
    connect(chooseScene,&chooseLevelScene::chooseSceneBack,[=](){
        chooseScene->hide();
        this->show();
    });
    connect(startBtn,&MyPushButton::clicked,[=](){
        startBtn->zoom(0);
        startBtn->zoom(1);

        //延时300ms，静态成员函数，可直接调用
        QTimer::singleShot(300,this,[=](){
            //隐藏主场景，显示选择关卡场景
            this->hide();
            chooseScene->show();
        });

    });


}
void MainScene::paintEvent(QPaintEvent *)
{
    QPainter painter(this);//画家对象
    QPixmap pix;
    //背景图
    pix.load(":/res/PlayLevelSceneBg.png");
    //绘制主界面背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //图标
    pix.load(":/res/Title.png");
    //重设图标大小
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    //画图标
    painter.drawPixmap(10,30,pix);

}
MainScene::~MainScene()
{
    delete ui;
}
void MainScene::receiveLogin()
{
  this->show();
}

