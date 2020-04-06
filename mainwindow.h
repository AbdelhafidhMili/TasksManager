#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include <QtSql> // HF: pour database

#include <QFileInfo>
//#include <QSqlQuery>
//#include <QSqlDatabase>
//#include <QSqlDriver>
//#include <QSqlError>
#include <QDebug> // HF: pour debug
#include <QMainWindow>
#include "user.h" // HF


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:

    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked(); // Auto
    void on_pushButtonRefresh_clicked(); // Auto

private:

    Ui::MainWindow *ui;
    QSqlDatabase db; // HF: declarer un data base
    user user1; // HF: déclarer un user
    QSqlQuery query;
};


#endif // MAINWINDOW_H
