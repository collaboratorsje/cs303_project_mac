#ifndef WEBHISTORY_H
#define WEBHISTORY_H

#include "linkedlist.h"
#include <QMainWindow>
#include <QLineEdit>
#include <QInputDialog>
#include <chrono>
#include <ctime>

QT_BEGIN_NAMESPACE
namespace Ui { class webHistory; }
QT_END_NAMESPACE

class webHistory : public QMainWindow
{
    Q_OBJECT

public:
    webHistory(QWidget *parent = nullptr);
    ~webHistory();

private slots:
    // slots named on_foo_bar are error prone?
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void on_pushButton_4_clicked();

    void on_pushButton_7_clicked();

    void on_pushButton_6_clicked();

    void on_pushButton_5_clicked();

private:
    Ui::webHistory *ui;
    LinkedList myList;
};
#endif // WEBHISTORY_H
