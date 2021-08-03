#ifndef MYPUSHBUTTON_H
#define MYPUSHBUTTON_H

#include <QPushButton>
#include <QMouseEvent>

class MyPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MyPushButton(QWidget *parent = nullptr);
    //构造函数，常规状态图片，按下状态图片；
    MyPushButton(QString normalImg,QString pressImg = "");
    QString normalImgPath;
    QString pressImgPath;
    void zoom(int);//弹跳判断
    //重写按下、释放事件
    void mousePressEvent(QMouseEvent *);
    void mouseReleaseEvent(QMouseEvent *);
signals:

};

#endif // MYPUSHBUTTON_H
