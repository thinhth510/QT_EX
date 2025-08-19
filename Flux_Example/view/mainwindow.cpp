#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include "../flux/logger_middleware.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pushButton_Red->setCheckable(true);
    ui->pushButton_Green->setCheckable(true);
    ui->pushButton_Blue->setCheckable(true);

    // Kết nối đồ thị Flux
    connect(&dispatcher, &flux::Dispatcher::action,&store,&flux::ColorStore::onAction);
    connect(&store, &flux::ColorStore::stateChanged,this,&MainWindow::render);

    // (tuỳ chọn) middleware log action
    new flux::LoggerMiddleware(&dispatcher, this);

    // Đăng ký metatype để queued-connection an toàn
    qRegisterMetaType<flux::RGBState>("flux::RGBState");

    // Render lần đầu theo state hiện tại
    render(store.state());
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::on_pushButton_Red_toggled(bool checked) {
    dispatcher.dispatch({flux::ActionType::ToggleRed, checked});
}

void MainWindow::on_pushButton_Green_toggled(bool checked) {
    dispatcher.dispatch({flux::ActionType::ToggleGreen, checked});
}

void MainWindow::on_pushButton_Blue_toggled(bool checked) {
    dispatcher.dispatch({flux::ActionType::ToggleBlue, checked});
}


// Helper: ON -> nền xanh lá, OFF -> trả về mặc định
static void styleButton(QPushButton* btn, bool on) {
    if (!btn) return;
    btn->setStyleSheet(on ? "background-color: green;" : "");
}

void MainWindow::render(flux::RGBState state) {
    // Đổi trang theo state
    if (ui->stackedWidget->currentIndex() != state.pageIndex)
        ui->stackedWidget->setCurrentIndex(state.pageIndex);

    // Tô nền nút theo trạng thái
    styleButton(ui->pushButton_Red,   state.red);
    styleButton(ui->pushButton_Green, state.green);
    styleButton(ui->pushButton_Blue,  state.blue);

    // Đồng bộ lại trạng thái check (phòng khi có ResetAll hoặc thay đổi từ chỗ khác)
    if (ui->pushButton_Red->isChecked()   != state.red)   ui->pushButton_Red->setChecked(state.red);
    if (ui->pushButton_Green->isChecked() != state.green) ui->pushButton_Green->setChecked(state.green);
    if (ui->pushButton_Blue->isChecked()  != state.blue)  ui->pushButton_Blue->setChecked(state.blue);
}

void MainWindow::on_pushButton_Reset_clicked() {
    dispatcher.dispatch({flux::ActionType::ResetAll, false});
}
