//
// Created by xjc on 2022/4/30.
//
#include "../include/MyTableModel.h"

#include <QMimeData>
#include <QDebug>
#include <QAbstractButton>
#include <QRadioButton>
#include <QMessageBox>
#include <QTableView>

MyTableModel::MyTableModel(QObject *parent)
        : QAbstractTableModel(parent) {
    //初始化模拟的model，便于观察
    for (int row = 0; row < 10; row++) {
        QList<QString> row_data;
        for (int col = 0; col < 6; col++) {
            row_data.push_back(QString("%1 %2").arg(row).arg(col));
        }
        modelData.push_back(row_data);
    }
    //默认单元格拖拽
    dragBehavior = DragBehavior::DragItems;
}

QVariant MyTableModel::headerData(int section, Qt::Orientation orientation, int role) const {
    if (role == Qt::DisplayRole) {
        return QString::number(section);
    }
    return QVariant();
}

int MyTableModel::rowCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;

    return modelData.count();
}

int MyTableModel::columnCount(const QModelIndex &parent) const {
    if (parent.isValid())
        return 0;

    return 6;
}

QVariant MyTableModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid())
        return QVariant();

    if (role == Qt::DisplayRole) {
        return modelData.at(index.row()).at(index.column());
    }
    //双击后显示并选中文本
    if (role == Qt::EditRole)
        return modelData.at(index.row()).at(index.column());

    return QVariant();
}

Qt::ItemFlags MyTableModel::flags(const QModelIndex &index) const {
    if (index.isValid())
        return Qt::ItemIsDragEnabled | Qt::ItemIsDropEnabled | Qt::ItemIsEditable | QAbstractTableModel::flags(index);
    return QAbstractTableModel::flags(index);
}

Qt::DropActions MyTableModel::supportedDropActions() const {
    return Qt::MoveAction | QAbstractTableModel::supportedDropActions();
}

QMimeData *MyTableModel::mimeData(const QModelIndexList &indexes) const {
    QMimeData *data = QAbstractTableModel::mimeData(indexes);
    if (data) {
        // parent mimeData中已判断indexes有效性，无效的会返回nullptr
        // 也可以把信息放到model的mutable成员中
        data->setData("row", QByteArray::number(indexes.at(0).row()));
        data->setData("col", QByteArray::number(indexes.at(0).column()));
    }
    return data;
}

bool MyTableModel::dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column,
                                const QModelIndex &parent) {
    if (!data || action != Qt::MoveAction)
        return false;

    //这里没有判断toint ok（数据转换有效性）
    const QModelIndex old_index = index(data->data("row").toInt(),
                                        data->data("col").toInt());
    const QModelIndex current_index = parent;
    //可以先对index有效性进行判断，无效返回false，此处略过
    //此处的转换需要判断是单元格还是整行或是整列
    if (dragBehavior == DragBehavior::DragItems && current_index.column() != -1 && current_index.row() != -1)
        std::swap(modelData[old_index.row()][old_index.column()],
                  modelData[current_index.row()][current_index.column()]);
    else if (dragBehavior == DragBehavior::DragColumns && current_index.column() != -1) {
        for (int i = 0; i < modelData.count(); i++)
            std::swap(modelData[i][old_index.column()], modelData[i][current_index.column()]);
    } else if (dragBehavior == DragBehavior::DragRows && current_index.row() != -1)
        std::swap(modelData[old_index.row()], modelData[current_index.row()]);



    return true;
}

void MyTableModel::setTableModelDragBehavior(int id) {
    switch (id) {
        case 0:
            dragBehavior = DragItems;
            break;
        case 1:
            dragBehavior = DragRows;
            break;
        case 2:
            dragBehavior = DragColumns;
            break;
        default:
            break;
    }
}

//修改单元格数据
bool MyTableModel::setData(const QModelIndex &index, const QVariant &value, int role) {
    if (role == Qt::EditRole)
    {
        modelData[index.row()][index.column()] = value.toString();
        return true;
    }
    return false;
}
