/********************************************************************************
** Form generated from reading UI file 'webhistory.ui'
**
** Created by: Qt User Interface Compiler version 6.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WEBHISTORY_H
#define UI_WEBHISTORY_H

#include <QtCore/QVariant>
#include <QtGui/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_webHistory
{
public:
    QWidget *centralwidget;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_6;
    QListWidget *listWidget;
    QPushButton *pushButton_7;
    QListWidget *listWidget_2;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QMenuBar *menubar;
    QMenu *menuWebsite_History;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *webHistory)
    {
        if (webHistory->objectName().isEmpty())
            webHistory->setObjectName("webHistory");
        webHistory->resize(744, 439);
        centralwidget = new QWidget(webHistory);
        centralwidget->setObjectName("centralwidget");
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(10, 110, 100, 32));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(10, 150, 100, 32));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(10, 230, 100, 32));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(10, 270, 100, 32));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(10, 310, 100, 32));
        listWidget = new QListWidget(centralwidget);
        listWidget->setObjectName("listWidget");
        listWidget->setGeometry(QRect(130, 60, 281, 281));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(10, 190, 100, 32));
        listWidget_2 = new QListWidget(centralwidget);
        listWidget_2->setObjectName("listWidget_2");
        listWidget_2->setGeometry(QRect(430, 60, 281, 281));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(520, 0, 101, 51));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(230, 0, 91, 51));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(10, 10, 101, 91));
        label_3->setPixmap(QPixmap(QString::fromUtf8(":/new/prefix1/detective_magnifying_glass1.jpg")));
        label_3->setScaledContents(true);
        webHistory->setCentralWidget(centralwidget);
        menubar = new QMenuBar(webHistory);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 744, 37));
        menuWebsite_History = new QMenu(menubar);
        menuWebsite_History->setObjectName("menuWebsite_History");
        webHistory->setMenuBar(menubar);
        statusbar = new QStatusBar(webHistory);
        statusbar->setObjectName("statusbar");
        webHistory->setStatusBar(statusbar);

        menubar->addAction(menuWebsite_History->menuAction());

        retranslateUi(webHistory);

        QMetaObject::connectSlotsByName(webHistory);
    } // setupUi

    void retranslateUi(QMainWindow *webHistory)
    {
        webHistory->setWindowTitle(QCoreApplication::translate("webHistory", "webHistory", nullptr));
        pushButton->setText(QCoreApplication::translate("webHistory", "Add", nullptr));
        pushButton_2->setText(QCoreApplication::translate("webHistory", "Remove", nullptr));
        pushButton_4->setText(QCoreApplication::translate("webHistory", "Sort by date", nullptr));
        pushButton_5->setText(QCoreApplication::translate("webHistory", "Archive", nullptr));
        pushButton_6->setText(QCoreApplication::translate("webHistory", "Export", nullptr));
        pushButton_7->setText(QCoreApplication::translate("webHistory", "Sort A-Z", nullptr));
        label->setText(QCoreApplication::translate("webHistory", "Archived History", nullptr));
        label_2->setText(QCoreApplication::translate("webHistory", "Web History", nullptr));
        label_3->setText(QString());
        menuWebsite_History->setTitle(QCoreApplication::translate("webHistory", "Website History", nullptr));
    } // retranslateUi

};

namespace Ui {
    class webHistory: public Ui_webHistory {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WEBHISTORY_H
