//
// Created by xjc on 2022/4/30.
//

#ifndef MYTABLEMODEL_H
#define MYTABLEMODEL_H

#include <QAbstractTableModel>
#include <QTableView>

class MyTableModel : public QAbstractTableModel {
Q_OBJECT
public:
    enum DragBehavior {
        DragItems,
        DragRows,
        DragColumns
    };

    explicit MyTableModel(QObject *parent = nullptr);

    // 表头数据
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;

    // 行数
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;

    // 列数
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;

    // 单元格数据
    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;

    // 允许的操作，加上drag drop
    Qt::ItemFlags flags(const QModelIndex &index) const override;

    // 允许move
    Qt::DropActions supportedDropActions() const override;

    // drag时携带的信息
    QMimeData *mimeData(const QModelIndexList &indexes) const override;

    // drop时根据drag携带的信息进行处理
    bool
    dropMimeData(const QMimeData *data, Qt::DropAction action, int row, int column, const QModelIndex &parent) override;

    bool setData(const QModelIndex &index, const QVariant &value, int role) override;


public slots:
    //设置拖拽形式
    void setTableModelDragBehavior(int id);

private:
    //自己模拟的数据，便于观察
    QList<QList<QString>> modelData;
    //拖拽形式
    DragBehavior dragBehavior;
};

#endif // MYTABLEMODEL_H