#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    TCP_Server = new QTcpServer();
    if(TCP_Server->listen(QHostAddress::Any,8080))
    {
        connect(TCP_Server,&QTcpServer::newConnection, this, &MainWindow::newConnection);

        QMessageBox::information(this,"Message", "Server Start");
    }
    else
    {
        QMessageBox::information(this,"Message", "Server Start Fail");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::newConnection()
{
    while(TCP_Server->hasPendingConnections())
    {
        Add_New_Client_Connection(TCP_Server->nextPendingConnection());
    }
}

void MainWindow::clientDisconnected()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    if (!client) return;

    // Thông báo client out
    QString clientDisconnect = "Client " + QString::number(client->property("descriptor").toLongLong()) + " Disconnected";
    ui->textEdit_Client_Message->append(clientDisconnect);

    // Xóa khỏi danh sách kết nối
    Client_Connection_List.removeOne(client);

    // Xóa khỏi comboBox
    int index = ui->comboBox_Client_List->findText(QString::number(client->property("descriptor").toLongLong()));
    if (index != -1)
        ui->comboBox_Client_List->removeItem(index);

    // Giải phóng bộ nhớ
    client->deleteLater();
}

void MainWindow::Read_Data_From_Socket()
{
    QTcpSocket *client = qobject_cast<QTcpSocket*>(sender());
    QByteArray Massage_From_Server = client->readAll();
    QString MassageString = "Client: " + QString::number(client->socketDescriptor()) + " : " + QString::fromUtf8(Massage_From_Server);

    ui->textEdit_Client_Message -> append(MassageString);
}

void MainWindow::Add_New_Client_Connection(QTcpSocket *client)
{
    client->setProperty("descriptor", client->socketDescriptor());

    Client_Connection_List.append(client);

    connect(client,&QTcpSocket::readyRead,this, &MainWindow::Read_Data_From_Socket);
    connect(client, &QTcpSocket::disconnected, this, &MainWindow::clientDisconnected);

    ui->comboBox_Client_List->addItem(QString::number(client->socketDescriptor()));
    QString clientConnect = "Client " + QString::number(client->socketDescriptor()) + " Connect To The Server";
    ui->textEdit_Client_Message->append(clientConnect);
}


void MainWindow::on_pushButton_Send_Message_clicked()
{
    QString Message_For_Client = ui->lineEdit_Send_Message->text();
    QString Receiver = ui->comboBox_Client_List->currentText();

    if(ui->comboBox_Send_Message_Type->currentText() == "All")
    {
        foreach(QTcpSocket *client, Client_Connection_List)
        {
                client->write(Message_For_Client.toUtf8() + "\n");

        }
    }
    else
    {
        foreach(QTcpSocket *client, Client_Connection_List)
        {
            if(client->socketDescriptor()== Receiver.toLongLong())
                client->write(Message_For_Client.toUtf8() + "\n");
        }
    }
}
