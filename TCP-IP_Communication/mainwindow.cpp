#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCPSocket = new QTcpSocket(this);
    //Going to connect to the localhost server
    //To connect with any third party server, then provide its host adress like this
    //TCPSocket->connectToHost(QHostAddress(HOST_ADDRESS),PORT_NUMBER);
    TCPSocket->connectToHost(QHostAddress::LocalHost,8080);
    connect(TCPSocket,&QTcpSocket::readyRead, this, &MainWindow::Read_Data_From_Socket);
    TCPSocket->open(QIODevice::ReadWrite);
    if (TCPSocket->isOpen())
    {
        QMessageBox::information(this, "Message", "Connected To The Server");
    }
    else
    {
        QMessageBox::information(this, "Message", "Not Connected To The Server");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pushButton_Send_Data_clicked()
{
    if(TCPSocket)
    {
        if(TCPSocket->isOpen())
        {
            QString WriteData = ui->lineEdit_Write_Data->text();

            TCPSocket->write(WriteData.toUtf8());
        }
        else
        {
            QMessageBox::information(this,"Message","Error : " + TCPSocket->errorString());
        }
    }
    else
    {
        QMessageBox::information(this,"Message","Error : " + TCPSocket->errorString());
    }
}

void MainWindow::Read_Data_From_Socket()
{
    if(TCPSocket)
    {
        if(TCPSocket->isOpen())
        {
            QByteArray Data_From_Server = TCPSocket->readAll();
            QString MassageString = QString::fromUtf8(Data_From_Server);

            ui->textEdit_Message_From_Server -> append(MassageString);
        }
        else
        {
            QMessageBox::information(this,"Message","Error : " + TCPSocket->errorString());
        }
    }
    else
    {
        QMessageBox::information(this,"Message","Error : " + TCPSocket->errorString());
    }
}
