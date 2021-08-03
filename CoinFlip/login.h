#ifndef LOGIN_H
#define LOGIN_H
#include "mainscene.h"
#include <QWidget>
#include "websocketclient.h"

namespace Ui {
class login;
}

class login : public QWidget
{
    Q_OBJECT
signals:
    void showMain();//显示主界面信号
public:
    explicit login(QWidget *parent = nullptr);
    ~login();
public slots:
    //登录处理槽函数
    void loginProcess();
private:
    Ui::login *ui;
    websocketClient * ws = new websocketClient();
};

#endif // LOGIN_H
