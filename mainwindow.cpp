#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE"); //add db with SQLite driver
    db.setDatabaseName("/home/mili/Projects/Projet App Qt For Project Tasks/Taskmanager/DataBase/TasksManagerDataBase"); // path of db


}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked( )
{
QString s =   ui->lineEditUser->text(); //capter le ID
QString q="SELECT FirstName FROM Collab"; // text of query to getuser name
user1.userId=s.toUInt(); //transformer le ID en Integer

    if (db.open()){                 // vérifier la database
        //ui->lineEdit_2->setText("database connected");
        //query.prepare();
        QSqlQuery query1;

        if (!query1.exec("SELECT * FROM Collab")){
            ui->lineEdit_2->setText("query not executed");
            ui->lineEditUser->setText(query1.lastError().text());
        } else {
            //QString Sfn = query1.value(1).toString();
            ui->lineEdit_2->setText(s);
            //user1.Status=true;
            }
    }else{
        ui->lineEdit_2->setText("can not open DB : folder not exist");
    }

}



void MainWindow::on_pushButtonRefresh_clicked()
{
QString s = QString::number(user1.userId);
ui->lineEdit_2->setText(s);
}
