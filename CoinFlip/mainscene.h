#ifndef MAINSCENE_H
#define MAINSCENE_H

#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainScene; }
QT_END_NAMESPACE

class MainScene : public QMainWindow
{
    Q_OBJECT

public:
    MainScene(QWidget *parent = nullptr);
    ~MainScene();
    //重写paintEvent事件
    void paintEvent(QPaintEvent *);
    void receiveLogin();

private:
    Ui::MainScene *ui;
};
#endif // MAINSCENE_H
