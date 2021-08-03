#include "chooselevelscene.h"
#include <QMenuBar>
#include <QDebug>
#include <QPainter>
#include "mypushbutton.h"
#include <QTimer>
chooseLevelScene::chooseLevelScene(QWidget *parent) : QMainWindow(parent)
{
    //设置固定大小
    this->setFixedSize(320,588);
    //设置图标
    setWindowIcon(QIcon(":/res/Coin0002.png"));
    //设置标题
    setWindowTitle("翻金币");
    //创建menubar
    QMenuBar * bar = menuBar();
    setMenuBar(bar);//设置为menubar
    //创建开始菜单
    QMenu * startMenu = bar->addMenu("开始");
    //添加退出菜单项
    QAction * quitAction =  startMenu->addAction("退出");
    //退出实现
    connect(quitAction,&QAction::triggered,[=](){
        this->close();
    });
    //实现返回按钮
    MyPushButton * backBtn = new MyPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    //找个爹，挂在这个场景的树上，会自动释放
    backBtn->setParent(this);
    //换位置
    backBtn->move(this->width() - backBtn->width(),this->height() - backBtn->height());
    //返回按钮连接
    connect(backBtn,&MyPushButton::clicked,[=](){
        //qDebug()<<"点击了返回";
        //延时返回
        QTimer::singleShot(300,this,[=](){
           emit this->chooseSceneBack();
        });
    });
}

//重写绘图事件
void chooseLevelScene::paintEvent(QPaintEvent *){
    //实例画家
    QPainter painter(this);
    QPixmap pix;
    //背景图
    pix.load(":/res/OtherSceneBg.png");
    //绘制主界面背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);
    //图标
    pix.load(":/res/Title.png");
    //画图标
    painter.drawPixmap((this->width() - pix.width()) * 0.5,30,pix.width(),pix.height(),pix);

}

