#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>
#include <QtWidgets>
#include <QtGui>
#include <QtNetwork>

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
    void readSocket();
    void discardSocket();

    void newConnection();
    void addToSocketList(QTcpSocket *socket);

    void on_pushButton_Send_File_clicked();

private:
    void sendFile(QTcpSocket *socket, QString filePath);

private:
    Ui::MainWindow *ui;

    QTcpServer *m_server;
    QList<QTcpSocket*> m_clientList;
};
#endif // MAINWINDOW_H
