#ifndef WEBSOCKETCLIENT_H
#define WEBSOCKETCLIENT_H

#include <QObject>
#include <QDebug>
#include <QWebSocket>


class websocketClient : public QObject
{
    Q_OBJECT
public:
    explicit websocketClient(QObject *parent = nullptr);
    ~websocketClient() override;
public slots:
    void onNewConnection();//新建连接
    void processMessage(const QString &message);//处理消息
    void socketDisconnected();//未连接
    void sendText();//发送文本消息
    //登录槽函数,参数：账号，密码，
    void login(QString,QString);
    //注册槽函数
    void regist(QString,QString);
signals:
    void logined();
private:
    //连接对象
    QWebSocket * ws = new QWebSocket();
    QString url;
    bool islogin;

};

#endif // WEBSOCKETCLIENT_H



