//
// Created by xjc on 2022/5/1.
//

#include <QColorDialog>
#include <QDebug>
#include <QDateTimeEdit>
#include <QComboBox>
#include <QLineEdit>
#include <QPainter>
#include "../include/MyTableStyleDelegate.h"

MyTableStyleDelegate::MyTableStyleDelegate(QObject *parent) : QStyledItemDelegate(parent) {

}

QWidget *MyTableStyleDelegate::createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                                            const QModelIndex &index) const {
    qDebug() << "123213";
    if (index.row() == 0 && index.column() != 0) {
//        QWidget *lineEdit =  new QLineEdit();
//        return lineEdit;
        return QStyledItemDelegate::createEditor(parent, option, index);
    }
    else if (index.row() == 0 && index.column() == 0) {
        QWidget *comboBox =  new QComboBox();
        return comboBox;
    }
    return nullptr;
}

void MyTableStyleDelegate::setEditorData(QWidget *editor, const QModelIndex &index) const {
//    QStyledItemDelegate::setEditorData(editor, index);
    if (editor && index.column() != 0){
        QStyledItemDelegate::setEditorData(editor, index);
    }
}

void MyTableStyleDelegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const {
//    model->setData(index, editor->text(), Qt::EditRole);
    qDebug() << "setModelData";
    QStyledItemDelegate::setModelData(editor, model, index);
}

void MyTableStyleDelegate::updateEditorGeometry(QWidget *editor, const QStyleOptionViewItem &option,
                                                const QModelIndex &index) const {
    editor->setGeometry(option.rect);
}

void
MyTableStyleDelegate::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const {
    painter->save();
    if (option.state & QStyle::State_Selected) {
//        QVariant variant = index.model()->data(index, Qt::BackgroundRole);
        //draw
//        painter->save();

        painter->drawText(option.rect, index.model()->data(index, Qt::DisplayRole).toString());
        painter->fillRect(option.rect, QColor(255,103,56,1));
        QStyledItemDelegate::paint(painter, option, index);
//        painter->restore();
    } else
        QStyledItemDelegate::paint(painter, option, index);
    painter->restore();
}

QSize MyTableStyleDelegate::sizeHint(const QStyleOptionViewItem &option, const QModelIndex &index) {
    return QSize();
}

void MyTableStyleDelegate::initStyleOption(QStyleOptionViewItem *option, const QModelIndex &index) const {
    QStyledItemDelegate::initStyleOption(option, index);
}

MyTableStyleDelegate::~MyTableStyleDelegate() = default;

