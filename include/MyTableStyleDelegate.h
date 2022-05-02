//
// Created by xjc on 2022/5/1.
//

#ifndef MYTABLESTYLEDELEGATE_H
#define MYTABLESTYLEDELEGATE_H

#include <QStyledItemDelegate>

class MyTableStyleDelegate : public QStyledItemDelegate {
Q_OBJECT
public:
    explicit MyTableStyleDelegate(QObject *parent = nullptr);

    ~MyTableStyleDelegate() override;
    void initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const override;

    //创建用于编辑模型数据的widget组件，如一个QSpinBox组件，或一个QComboBox组件；
    QWidget *createEditor(QWidget *parent, const QStyleOptionViewItem &option, const QModelIndex &index) const override;

    //从数据模型获取数据，供widget组件进行编辑；
    void setEditorData(QWidget *editor, const QModelIndex &index) const override;

    //将widget上的数据更新到数据模型；
    void setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const override;

    //用于给widget组件设置一个合适的大小；
    void
    updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //用于重新描绘Item样式
    void paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const override;
    //
    QSize sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index);

signals:
};

#endif //MYTABLESTYLEDELEGATE_H
