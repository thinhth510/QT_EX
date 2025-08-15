#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_server = new QTcpServer(this);
    if(m_server->listen(QHostAddress::AnyIPv4,50000))
    {
        connect(m_server, &QTcpServer::newConnection, this, &MainWindow::newConnection);
        QMessageBox::information(this,"Message", "TCP Server Started Success");
    }
    else
    {
        QMessageBox::information(this, "Message", "TCP Server Error: " + m_server->errorString());
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::readSocket()
{

}

void MainWindow::discardSocket()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    if (!socket) return;

    //Remove client
    QString clientDisconnect = "Client " + QString::number(socket->property("descriptor").toLongLong()) + " Disconnected";
    ui->textEdit_Message->append(clientDisconnect);

    m_clientList.removeOne(socket);

    // Xóa khỏi comboBox
    int index = ui->comboBox_Client_List->findText(QString::number(socket->property("descriptor").toLongLong()));
    if (index != -1)
        ui->comboBox_Client_List->removeItem(index);

    // Giải phóng bộ nhớ
    socket->deleteLater();
}

void MainWindow::newConnection()
{
    while(m_server->hasPendingConnections())
    {
        addToSocketList(m_server->nextPendingConnection());
    }
}

void MainWindow::addToSocketList(QTcpSocket *socket)
{
    //Luu socketDescriptor de xoa khoi comboBox ke ca khi socket disconnected
    socket->setProperty("descriptor", socket->socketDescriptor());

    m_clientList.append(socket);

    connect(socket,&QTcpSocket::readyRead,this, &MainWindow::readSocket);
    connect(socket, &QTcpSocket::disconnected, this, &MainWindow::discardSocket);

    ui->comboBox_Client_List->addItem(QString::number(socket->socketDescriptor()));
    QString clientConnect = "Client " + QString::number(socket->socketDescriptor()) + " Connect To The Server";
    ui->textEdit_Message->append(clientConnect);
}


void MainWindow::on_pushButton_Send_File_clicked()
{
    // Now Let's Send File To The Client

    // Browse File
    QString filePath = QFileDialog::getOpenFileName(this, "Select File", QCoreApplication::applicationDirPath(), "File (*.jpg *.png *.txt *.bmp)");

    // Send File to All Connected Clients
    if (ui->comboBox_Transfer_Type->currentText() == "Broadcast")
    {
        foreach (QTcpSocket *socket, m_clientList)
        {
            sendFile(socket, filePath);
        }
    }
    else if (ui->comboBox_Transfer_Type->currentText() == "Receiver")
    {
        // Send File to Selected Connected Clients
        QString receiverid = ui->comboBox_Client_List->currentText();
        foreach (QTcpSocket *socket, m_clientList)
        {
            if (socket->socketDescriptor() == receiverid.toLongLong())
            {
                sendFile(socket, filePath);
            }
        }
    }
}


void MainWindow::sendFile(QTcpSocket *socket, QString filePath)
{
    if (socket)
    {
        if (socket->isOpen())
        {
            QFile filedata(filePath);
            if (filedata.open(QIODevice::ReadOnly))
            {
                QFileInfo fileinfo(filedata);
                QString FileNameWithExt(fileinfo.fileName());

                QDataStream socketstream(socket);
                socketstream.setVersion(QDataStream::Qt_DefaultCompiledVersion); // this is my qt version

                // This code use send file name also with file data
                QByteArray header;
                header.prepend(QString("filename:%1,filesize:%2")
                                .arg(FileNameWithExt)
                                .arg(filedata.size())
                                .toUtf8());      // <-- chuyển sang QByteArray
                header.resize(128);

                // Now Lets Add FileData
                QByteArray ByteFileData = filedata.readAll();
                ByteFileData.prepend(header);

                // Write in socket
                socketstream << ByteFileData;
            }
            else
            {
                qDebug() << "File not open";
            }
        }
        else
        {
            qDebug() << "Client Socket not open";
        }
    }
    else
    {
        qDebug() << "Client Socket is invalid";
    }
}

