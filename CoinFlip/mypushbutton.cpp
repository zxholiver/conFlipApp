#include "mypushbutton.h"
#include <QPixmap>
#include <QDebug>
#include <QPropertyAnimation>
//MyPushButton::MyPushButton(QWidget *parent) : QWidget(parent)
//{

//}

MyPushButton::MyPushButton(QString normalImg,QString pressImg)
{
    this->normalImgPath = normalImg;
    this->pressImgPath = pressImg;
    QPixmap pix;
    //加载图片
    bool ret = pix.load(normalImg);
    if(!ret)
    {
        qDebug()<<"图片加载错误";
        return;
    }
    this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
    //设置不规则图片样式，border:0px;
    this->setStyleSheet("QPushButton{border:0px}");
    this->setIcon(pix);
    this->setIconSize(QSize(pix.width(),pix.height()));

}
//弹跳动作，direction = 0为向下弹，1为向上弹
void MyPushButton::zoom(int direction){
    int startyDirect = 0;//开始位置y偏移量
    int endyDirect = 0;//结束位置y偏移量
    if(direction == 0)
        endyDirect = 10;
    if(direction == 1)
        startyDirect = 10;
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    //动作时间
    animation->setDuration(200);
    //开始位置，结束位置
    animation->setStartValue(QRect(this->x(),this->y() + startyDirect,this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y() + endyDirect,this->width(),this->height()));
    //设置弹跳曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}
//重写按下、释放事件
void MyPushButton::mousePressEvent(QMouseEvent * e){
    //如果没有按下图片，则不执行
    if(pressImgPath != ""){
        QPixmap pix;
        //加载图片
        bool ret = pix.load(this->pressImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载错误";
            return;
        }
        this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
        //设置不规则图片样式，border:0px;
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //返回其他事件给父类执行
    return QPushButton::mousePressEvent(e);

}
void MyPushButton::mouseReleaseEvent(QMouseEvent * e){
    if(pressImgPath != ""){
        QPixmap pix;
        //加载图片
        bool ret = pix.load(this->normalImgPath);
        if(!ret)
        {
            qDebug()<<"图片加载错误";
            return;
        }
        this->setFixedSize(pix.width(),pix.height());//设置图片固定大小
        //设置不规则图片样式，border:0px;
        this->setStyleSheet("QPushButton{border:0px}");
        this->setIcon(pix);
        this->setIconSize(QSize(pix.width(),pix.height()));
    }
    //返回其他事件给父类执行
    return QPushButton::mouseReleaseEvent(e);
}
