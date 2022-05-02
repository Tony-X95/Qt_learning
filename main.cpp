#include "include/mainwindow.h"
#include <QApplication>
#include <QTableWidget>
#include <QHeaderView>  // 对表头操作时必须引用
#include <QPushButton>
#include <iostream>
#include <QStandardItemModel>
#include <QTreeView>

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
//    auto *tableWidget = new QTableWidget(10, 5);
//    tableWidget->setContextMenuPolicy(Qt::CustomContextMenu);
//    // 无法编辑单元格
//    tableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
//    //选中整列
//    tableWidget->setSelectionBehavior(QAbstractItemView::SelectColumns);
//    //设置只能选择一行/列，不能选择多行/列
//    tableWidget->setSelectionMode(QAbstractItemView::SingleSelection);
////    QStringList header;
////    header << "Month" << "Description";
////    tableWidget->setHorizontalHeaderLabels(header);
//    tableWidget->horizontalHeader()->setVisible(false);  // 隐藏列头
//    tableWidget->verticalHeader()->setVisible(false);  // 隐藏行号
//    tableWidget->horizontalHeader()->setSectionsMovable(true);  //列拖拽，只有当列头显示的时候才有效
//    //隐藏某一行
////    tableWidget->hideRow(0);
////    QPushButton button("Hello world!", nullptr);
////    button.resize(200, 100);
////    button.show();
//    QStringList headerList;
//    headerList << "ID" << "Name" << "Sex" << "Month" << "Description";
//    int32_t headerColumn = 0;
//    QColor headerColor = QColor(246, 246, 246);
//    for (auto &&headerItem: headerList) {
//
//        tableWidget->setItem(0, headerColumn, new QTableWidgetItem(headerItem));
//        tableWidget->item(0, headerColumn)->setBackgroundColor(headerColor);
//        headerColumn++;
//    }
//    tableWidget->setMinimumSize(500, 400);
//    tableWidget->show();
    MainWindow w;
    w.show();

    return QApplication::exec();
}
