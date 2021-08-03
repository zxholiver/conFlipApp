#include "mainscene.h"
#include "login.h"
#include <QApplication>
#include <QtWebSockets>
#include <QDebug>
#include "websocketclient.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainScene w;
    login login;
    login.show();
    QObject::connect(&login,&login::showMain, &w, &MainScene::receiveLogin);
    return a.exec();
}
