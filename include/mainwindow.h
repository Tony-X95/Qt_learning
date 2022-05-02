//
// Created by xjc on 2022/4/30.
//
#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "MyTableModel.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

    void initMyTableModel();
    void initMyStandardItemModel();
public slots:
    void setDragBehavior(int id);
private:
    Ui::MainWindow *ui;
    QTableView *view;
};

#endif // MAINWINDOW_H