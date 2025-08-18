#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtNetwork/QTcpServer>
#include <QtNetwork/QTcpSocket>
#include <QList>
#include <QByteArray>
#include <QString>
#include <QMessageBox>

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
    void newConnection();
    void clientDisconnected();
    void Read_Data_From_Socket();
    
    void on_pushButton_Send_Message_clicked();
    
private:
    void Add_New_Client_Connection(QTcpSocket *client);
    
private:
    Ui::MainWindow *ui;
    QTcpServer *TCP_Server;
    QList<QTcpSocket*> Client_Connection_List;
    
};
#endif // MAINWINDOW_H
