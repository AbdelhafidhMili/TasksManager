#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE"); //add db with SQLite driver
    db.setDatabaseName("/home/mili/Projects/Projet App Qt For Project Tasks/DataBase/TasksManagerDataBas"); // path of db


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked( )
{
QString s =   ui->lineEditUser->text(); //capter le ID
QString q="SELECT FirstName FROM Collab"; // query to getuser name
user1.userId=s.toUInt(); //transformer le ID en Integer
if (db.open()){                 // vérifier la database
        //ui->lineEdit_2->setText("database connected");
        //query.prepare();

        if (!query.exec("SELECT * FROM collab")){
            ui->lineEdit_2->setText("query not executed");
            ui->lineEditUser->setText(query.lastError().text());
        } else {
            QString Sfn = query.value(1).toString();
            ui->lineEdit_2->setText(Sfn);
            //user1.Status=true;
            }
}
}



void MainWindow::on_pushButtonRefresh_clicked()
{
QString s = QString::number(user1.userId);
ui->lineEdit_2->setText(s);
}
