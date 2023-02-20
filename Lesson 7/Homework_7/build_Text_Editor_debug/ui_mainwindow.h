/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMdiArea>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QVBoxLayout *verticalLayout_4;
    QVBoxLayout *verticalLayout;
    QMdiArea *mdiArea;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout_3;
    QPushButton *newButton;
    QSpacerItem *verticalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *openButton;
    QPushButton *readOnlyButton;
    QVBoxLayout *verticalLayout_5;
    QPushButton *saveButton;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout_9;
    QPushButton *printButton;
    QSpacerItem *verticalSpacer_6;
    QVBoxLayout *verticalLayout_6;
    QPushButton *helpButton;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_7;
    QPushButton *settingsButton;
    QSpacerItem *verticalSpacer_4;
    QVBoxLayout *verticalLayout_8;
    QPushButton *closeButton;
    QSpacerItem *verticalSpacer_5;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(800, 650);
        MainWindow->setMinimumSize(QSize(800, 650));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        verticalLayout_4 = new QVBoxLayout(centralwidget);
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        mdiArea = new QMdiArea(centralwidget);
        mdiArea->setObjectName("mdiArea");

        verticalLayout->addWidget(mdiArea);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName("verticalLayout_3");
        newButton = new QPushButton(centralwidget);
        newButton->setObjectName("newButton");

        verticalLayout_3->addWidget(newButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_3->addItem(verticalSpacer);


        horizontalLayout_2->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName("verticalLayout_2");
        verticalLayout_2->setContentsMargins(-1, -1, -1, 10);
        openButton = new QPushButton(centralwidget);
        openButton->setObjectName("openButton");

        verticalLayout_2->addWidget(openButton);

        readOnlyButton = new QPushButton(centralwidget);
        readOnlyButton->setObjectName("readOnlyButton");

        verticalLayout_2->addWidget(readOnlyButton);


        horizontalLayout_2->addLayout(verticalLayout_2);

        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        saveButton = new QPushButton(centralwidget);
        saveButton->setObjectName("saveButton");

        verticalLayout_5->addWidget(saveButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_5->addItem(verticalSpacer_2);


        horizontalLayout_2->addLayout(verticalLayout_5);

        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setObjectName("verticalLayout_9");
        printButton = new QPushButton(centralwidget);
        printButton->setObjectName("printButton");

        verticalLayout_9->addWidget(printButton);

        verticalSpacer_6 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_9->addItem(verticalSpacer_6);


        horizontalLayout_2->addLayout(verticalLayout_9);

        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setObjectName("verticalLayout_6");
        helpButton = new QPushButton(centralwidget);
        helpButton->setObjectName("helpButton");

        verticalLayout_6->addWidget(helpButton);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_6->addItem(verticalSpacer_3);


        horizontalLayout_2->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        settingsButton = new QPushButton(centralwidget);
        settingsButton->setObjectName("settingsButton");

        verticalLayout_7->addWidget(settingsButton);

        verticalSpacer_4 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_7->addItem(verticalSpacer_4);


        horizontalLayout_2->addLayout(verticalLayout_7);

        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        closeButton = new QPushButton(centralwidget);
        closeButton->setObjectName("closeButton");

        verticalLayout_8->addWidget(closeButton);

        verticalSpacer_5 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Preferred);

        verticalLayout_8->addItem(verticalSpacer_5);


        horizontalLayout_2->addLayout(verticalLayout_8);


        verticalLayout->addLayout(horizontalLayout_2);


        verticalLayout_4->addLayout(verticalLayout);

        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 800, 22));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "\320\242\320\265\320\272\321\201\321\202\320\276\320\262\321\213\320\271 \321\200\320\265\320\264\320\260\320\272\321\202\320\276\321\200", nullptr));
        newButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\320\262\321\213\320\271", nullptr));
        openButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        readOnlyButton->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
        saveButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        printButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\207\320\260\321\202\321\214", nullptr));
        helpButton->setText(QCoreApplication::translate("MainWindow", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        settingsButton->setText(QCoreApplication::translate("MainWindow", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        closeButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
