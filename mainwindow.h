#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "bashuma.h"
#include <QLineEdit>
#include <QTextBrowser>
#include <vector>

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);

    ~MainWindow();

    Game game;

    QString str1, str2;

    //记录当前时第几步
    int pathNum = 0;

    //清除输入
    void clearLineValue(QLineEdit *a[9]);

    //设置默认输入
    void setLineValue(QString str, QLineEdit *a[9]);

    //设置输入框状态
    void setLineStatus(QLineEdit *a[9], bool flag);

    //将九宫格输入转化为字符串
    QString getLinesValue(QLineEdit *a[9]);

    //产生随机字符串
    string randomStr();

    //延时函数
    void wait(int times);

    //输出路径
    void displayNowPath(int num);

    //输出open与close表
    void ouputTable(QTextBrowser text, vector<string> v);

    //判断LineEdit的合法性
    bool judgeInput(QString s);

private slots:
    void on_autoOuputBtn_clicked();

    void on_autoInputBtn_clicked();

    void on_clearBtn_clicked();

    void on_manuOuputBtn_clicked();

    void on_findPathBtn_clicked();

    void on_horizontalSlider_valueChanged(int value);

    void on_pathTextBrowser_sourceChanged(const QUrl &arg1);

    void on_manuInputBtn_clicked();

    void on_afterPathBtn_clicked();

    void on_nextPathBtn_clicked();

private:
    Ui::MainWindow *ui;

    QLineEdit *originLine[9], *endLine[9];
};

#endif // MAINWINDOW_H
