////
//// Created by xjc on 2022/4/30.
////
//
//#ifndef QT_O_WIDGET_H
//#define QT_O_WIDGET_H
//
//#include <QWidget>
//#include <QStandardItemModel>
//
//namespace Ui {
//    class Widget;
//}
//
//class QMouseEvent;
//
//class Widget : public QWidget {
//Q_OBJECT
//
//public:
//    explicit Widget(QWidget *parent = nullptr);
//
//    ~Widget();
//
//    int buttonId = 1;
//    typedef struct CardandChannel {
//        int card_number, channel_number, buttonId;
//        struct CardandChannel *next;
//    } CardandChannel;
//    CardandChannel *head{};
//    bool card1state = false;
//    int card1number = 0;
//    bool card_channel= true;
//
//private slots:
//    void dynamicSetColumnWidth();
//    void modifyCardMessage();
//    void on_tableView_2_pressed(const QModelIndex &index);
//    void onTableBtnClicked();
//
//protected:
//    void dropEvent(QDropEvent *event);
//
//private:
//    Ui::Widget *ui{};
//    QStandardItemModel *model{};
//    QStandardItemModel *modelcard{};
//    QTimer *timer{}, *timer2{};
//    int line_number{}, tableWidth{}, tableWidth2{}, card_number{}, channel_number{};
//    void setVerticalHeaderVisible(bool state);
//    void setHorizontalHeaderVisible(bool state);
//    QString getOneData(int row, int col);
//    void setOneData(int row, int col, QString _string);
//    void tableInit();
//    void InitTableHeader();
//    void setTableWidth();
//    void setLineNumber(int num);
//    void addHeader(QStringList list);
//    void setColumnWidth(int width);
//    void addLineMessage(int line, QString list, int buttonId);
//    void disableTableEdit();
//    void deleteLineMessage(int line_number);
//    void refreshCardTable(int channel_number_2, int channel_number, int card_number);
//    void TheListInit();
//    void sqlListTemperatureInsert();
//    void refreshDataTable(int card);
//    typedef struct MaxMin{
//        float max, min, average;
//    }MaxMin;
//    void updateTableMessage(MaxMin date1, int count, float current_data1);
//};
//
//#endif //QT_O_WIDGET_H
