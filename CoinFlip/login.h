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
    void showMain();
public:
    explicit login(QWidget *parent = nullptr);
    //登录处理槽函数
    void loginProcess();
    ~login();
    websocketClient * ws = new websocketClient();
private:
    Ui::login *ui;
};

#endif // LOGIN_H
