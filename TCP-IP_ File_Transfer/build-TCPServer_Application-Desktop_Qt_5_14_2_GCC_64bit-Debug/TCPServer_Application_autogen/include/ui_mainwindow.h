/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGridLayout *gridLayout;
    QTextEdit *textEdit_Message;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *comboBox_Transfer_Type;
    QLabel *label_2;
    QComboBox *comboBox_Client_List;
    QPushButton *pushButton_Send_File;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(800, 519);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName(QString::fromUtf8("centralwidget"));
        gridLayout = new QGridLayout(centralwidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textEdit_Message = new QTextEdit(centralwidget);
        textEdit_Message->setObjectName(QString::fromUtf8("textEdit_Message"));
        QFont font;
        font.setPointSize(15);
        font.setBold(true);
        font.setWeight(75);
        textEdit_Message->setFont(font);

        gridLayout->addWidget(textEdit_Message, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        label = new QLabel(centralwidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setFont(font);

        horizontalLayout->addWidget(label);

        comboBox_Transfer_Type = new QComboBox(centralwidget);
        comboBox_Transfer_Type->addItem(QString());
        comboBox_Transfer_Type->addItem(QString());
        comboBox_Transfer_Type->setObjectName(QString::fromUtf8("comboBox_Transfer_Type"));
        comboBox_Transfer_Type->setFont(font);

        horizontalLayout->addWidget(comboBox_Transfer_Type);

        label_2 = new QLabel(centralwidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setFont(font);

        horizontalLayout->addWidget(label_2);

        comboBox_Client_List = new QComboBox(centralwidget);
        comboBox_Client_List->setObjectName(QString::fromUtf8("comboBox_Client_List"));
        comboBox_Client_List->setFont(font);

        horizontalLayout->addWidget(comboBox_Client_List);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        pushButton_Send_File = new QPushButton(centralwidget);
        pushButton_Send_File->setObjectName(QString::fromUtf8("pushButton_Send_File"));
        pushButton_Send_File->setFont(font);

        gridLayout->addWidget(pushButton_Send_File, 2, 0, 1, 1);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName(QString::fromUtf8("menubar"));
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName(QString::fromUtf8("statusbar"));
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "Transfer Type:", nullptr));
        comboBox_Transfer_Type->setItemText(0, QCoreApplication::translate("MainWindow", "Broadcast", nullptr));
        comboBox_Transfer_Type->setItemText(1, QCoreApplication::translate("MainWindow", "Receiver", nullptr));

        label_2->setText(QCoreApplication::translate("MainWindow", "Client List:", nullptr));
        pushButton_Send_File->setText(QCoreApplication::translate("MainWindow", "Send File", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
