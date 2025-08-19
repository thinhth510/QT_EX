#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "../flux/dispatcher.h"
#include "../flux/color_store.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_Red_toggled(bool checked);
    void on_pushButton_Green_toggled(bool checked);
    void on_pushButton_Blue_toggled(bool checked);

    void render(flux::RGBState state);

    void on_pushButton_Reset_clicked();

private:
    Ui::MainWindow *ui;

    // Flux components
    flux::Dispatcher dispatcher;  // View -> Dispatcher
    flux::ColorStore store;       // Store giữ state và phát stateChanged
};

#endif // MAINWINDOW_H
