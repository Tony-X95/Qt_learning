//
// Created by xjc on 2022/4/30.
//
#include <QRadioButton>
#include <QMessageBox>
#include "../include/mainwindow.h"
#include "../include/ui_mainwindow.h"

#include "../include/MyTableModel.h"
#include "../include/MyStandardItemModel.h"
#include "../include/MyTableStyleDelegate.h"

MainWindow::MainWindow(QWidget *parent) :
        QMainWindow(parent),
        ui(new Ui::MainWindow) {
    ui->setupUi(this);

    initMyTableModel();
    initMyStandardItemModel();
}

MainWindow::~MainWindow() {
    delete ui;
    delete view;
}

void MainWindow::initMyTableModel() {
    view = ui->tableViewA;
    QButtonGroup *radioGroup = ui->buttonGroup;
    auto *model = new MyTableModel;
    auto *delegate = new MyTableStyleDelegate;
    view->setModel(model);
    view->horizontalHeader()->setVisible(false);
    view->verticalHeader()->setVisible(false);
    view->setItemDelegate(delegate);
    ui->buttonGroup->setId(ui->radioButton, 0);
    ui->buttonGroup->setId(ui->radioButton_2, 1);
    ui->buttonGroup->setId(ui->radioButton_3, 2);
//    ui->radioButton->setChecked(true);

    view->setSelectionMode(QAbstractItemView::SingleSelection); //不是必要的
    //可以配合行/列选中，需要在Model中做相应处理
    view->setSelectionBehavior(QAbstractItemView::SelectRows);
    model->setTableModelDragBehavior(1);

    connect(radioGroup, SIGNAL(buttonClicked(int)), this, SLOT(setDragBehavior(int)));
    connect(radioGroup, SIGNAL(buttonClicked(int)), model, SLOT(setTableModelDragBehavior(int)));

    view->setDragEnabled(true);
    view->setSortingEnabled(true);
    view->setDefaultDropAction(Qt::MoveAction); //不是必要的
    view->setDragDropMode(QAbstractItemView::InternalMove);

}

void MainWindow::initMyStandardItemModel() {
    //QStandardItemModel类提供用于存储自定义数据的通用模型
    MyStandardItemModel *model = new MyStandardItemModel(this);

    const int row_count = 10;
    const int col_count = 6;
    //设置列表头
    model->setColumnCount(col_count);
    for (int col = 0; col < col_count; col++) {
        model->setHeaderData(col, Qt::Horizontal, QString::number(col));
    }

    //设置行表头
    model->setRowCount(row_count);
    for (int row = 0; row < row_count; row++) {
        model->setHeaderData(row, Qt::Vertical, QString::number(row));
    }
    //设置数据
    for (int row = 0; row < row_count; row++) {
        for (int col = 0; col < col_count; col++) {
            QStandardItem *new_item = new QStandardItem(
                    QString("%1 %2").arg(row).arg(col));
            model->setItem(row, col, new_item);
        }
    }


    QTableView *view = ui->tableViewB;
    view->setModel(model);

    view->setSelectionMode(QAbstractItemView::SingleSelection);
    view->setDragEnabled(true);
    view->setDefaultDropAction(Qt::MoveAction);//不是必要的
    view->setDragDropMode(QAbstractItemView::InternalMove);
}

void MainWindow::setDragBehavior(int id) {
    switch (id) {
        case 0:
            view->setSelectionBehavior(QAbstractItemView::SelectItems);
            break;
        case 1:
            view->setSelectionBehavior(QAbstractItemView::SelectRows);
            break;
        case 2:
            view->setSelectionBehavior(QAbstractItemView::SelectColumns);
            break;
        default:
            break;
    }
}