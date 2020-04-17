#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>




MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    db = QSqlDatabase::addDatabase("QSQLITE"); //add db with SQLite driver
    db.setDatabaseName("/home/mili/Projects/Projet App Qt For Project Tasks/TasksManager/DataBase/TasksManagerDataBase"); // path of db
    user1.userId=0;

}

MainWindow::~MainWindow()
{
    delete ui;
}



void MainWindow::on_pushButton_clicked( )
{


QString Vusername =   ui->lineEditUser->text(); //capter le username
QString Vpassword = ui->lineEditPassWord->text(); //capter password
QString q="SELECT Id, Password FROM Collab WHERE Username='" + Vusername + "'"; // text of query to getuser name


    if (db.open()){                 // vérifier la database

        QSqlQuery query1;

        if (!query1.exec(q)){
            ui->lineEdit_2->setText("query not executed");
            ui->lineEditUser->setText(query1.lastError().text());
        } else {
            query1.first();
            QString Qid= query1.value(0).toString();
            ui->lineEdit_2->setText(Qid);
            user1.userId= query1.value(0).toInt();  //transformer le ID en Integer

            }
    }else{
        ui->lineEdit_2->setText("can not open DB : folder not exist");
    }

}



void MainWindow::on_pushButtonRefresh_clicked()
{
QString s = QString::number(ConnectionId);
ui->lineEdit_2->setText(s);
}
