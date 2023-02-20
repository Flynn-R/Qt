/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 6.4.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAbstractButton>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QKeySequenceEdit>
#include <QtWidgets/QLabel>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_5;
    QGroupBox *groupBox_2;
    QRadioButton *lightButton;
    QRadioButton *darkButton;
    QSpacerItem *verticalSpacer_3;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QRadioButton *russian;
    QRadioButton *english;
    QSpacerItem *verticalSpacer_2;
    QVBoxLayout *verticalLayout;
    QLabel *shortcutLabel;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout_8;
    QLabel *closeLabel;
    QLabel *saveLabel;
    QLabel *openLabel;
    QLabel *readOnlyLabel;
    QLabel *helpLabel;
    QLabel *newLabel;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_7;
    QKeySequenceEdit *closeSeq;
    QKeySequenceEdit *saveSeq;
    QKeySequenceEdit *openSeq;
    QKeySequenceEdit *readOnlySeq;
    QKeySequenceEdit *helpSeq;
    QKeySequenceEdit *newSeq;
    QDialogButtonBox *buttonBox;
    QSpacerItem *verticalSpacer;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName("Dialog");
        Dialog->resize(600, 260);
        Dialog->setMinimumSize(QSize(600, 260));
        gridLayout_2 = new QGridLayout(Dialog);
        gridLayout_2->setObjectName("gridLayout_2");
        gridLayout = new QGridLayout();
        gridLayout->setObjectName("gridLayout");
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setObjectName("verticalLayout_5");
        verticalLayout_5->setContentsMargins(5, -1, 5, -1);
        groupBox_2 = new QGroupBox(Dialog);
        groupBox_2->setObjectName("groupBox_2");
        QFont font;
        font.setPointSize(15);
        groupBox_2->setFont(font);
        groupBox_2->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        lightButton = new QRadioButton(groupBox_2);
        lightButton->setObjectName("lightButton");
        lightButton->setGeometry(QRect(0, 30, 97, 23));
        QFont font1;
        font1.setPointSize(11);
        lightButton->setFont(font1);
        lightButton->setChecked(true);
        darkButton = new QRadioButton(groupBox_2);
        darkButton->setObjectName("darkButton");
        darkButton->setGeometry(QRect(0, 70, 97, 23));
        darkButton->setFont(font1);

        verticalLayout_5->addWidget(groupBox_2);

        verticalSpacer_3 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_5->addItem(verticalSpacer_3);


        gridLayout->addLayout(verticalLayout_5, 0, 4, 1, 1);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName("verticalLayout_4");
        verticalLayout_4->setContentsMargins(5, -1, 5, -1);
        groupBox = new QGroupBox(Dialog);
        groupBox->setObjectName("groupBox");
        groupBox->setFont(font);
        groupBox->setAlignment(Qt::AlignLeading|Qt::AlignLeft|Qt::AlignTop);
        russian = new QRadioButton(groupBox);
        russian->setObjectName("russian");
        russian->setGeometry(QRect(0, 30, 97, 23));
        russian->setFont(font1);
        russian->setText(QString::fromUtf8("\320\240\321\203\321\201\321\201\320\272\320\270\320\271"));
        russian->setChecked(true);
        english = new QRadioButton(groupBox);
        english->setObjectName("english");
        english->setGeometry(QRect(0, 70, 97, 23));
        english->setFont(font1);
        english->setText(QString::fromUtf8("English"));

        verticalLayout_4->addWidget(groupBox);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Minimum);

        verticalLayout_4->addItem(verticalSpacer_2);


        gridLayout->addLayout(verticalLayout_4, 0, 3, 1, 1);

        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName("verticalLayout");
        shortcutLabel = new QLabel(Dialog);
        shortcutLabel->setObjectName("shortcutLabel");
        shortcutLabel->setFont(font);

        verticalLayout->addWidget(shortcutLabel);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setObjectName("verticalLayout_8");
        closeLabel = new QLabel(Dialog);
        closeLabel->setObjectName("closeLabel");

        verticalLayout_8->addWidget(closeLabel);

        saveLabel = new QLabel(Dialog);
        saveLabel->setObjectName("saveLabel");

        verticalLayout_8->addWidget(saveLabel);

        openLabel = new QLabel(Dialog);
        openLabel->setObjectName("openLabel");

        verticalLayout_8->addWidget(openLabel);

        readOnlyLabel = new QLabel(Dialog);
        readOnlyLabel->setObjectName("readOnlyLabel");

        verticalLayout_8->addWidget(readOnlyLabel);

        helpLabel = new QLabel(Dialog);
        helpLabel->setObjectName("helpLabel");

        verticalLayout_8->addWidget(helpLabel);

        newLabel = new QLabel(Dialog);
        newLabel->setObjectName("newLabel");

        verticalLayout_8->addWidget(newLabel);


        horizontalLayout->addLayout(verticalLayout_8);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Minimum, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setObjectName("verticalLayout_7");
        closeSeq = new QKeySequenceEdit(Dialog);
        closeSeq->setObjectName("closeSeq");
        closeSeq->setClearButtonEnabled(false);

        verticalLayout_7->addWidget(closeSeq);

        saveSeq = new QKeySequenceEdit(Dialog);
        saveSeq->setObjectName("saveSeq");

        verticalLayout_7->addWidget(saveSeq);

        openSeq = new QKeySequenceEdit(Dialog);
        openSeq->setObjectName("openSeq");

        verticalLayout_7->addWidget(openSeq);

        readOnlySeq = new QKeySequenceEdit(Dialog);
        readOnlySeq->setObjectName("readOnlySeq");

        verticalLayout_7->addWidget(readOnlySeq);

        helpSeq = new QKeySequenceEdit(Dialog);
        helpSeq->setObjectName("helpSeq");

        verticalLayout_7->addWidget(helpSeq);

        newSeq = new QKeySequenceEdit(Dialog);
        newSeq->setObjectName("newSeq");

        verticalLayout_7->addWidget(newSeq);


        horizontalLayout->addLayout(verticalLayout_7);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout, 0, 0, 1, 1);

        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName("buttonBox");
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);

        gridLayout_2->addWidget(buttonBox, 2, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout_2->addItem(verticalSpacer, 1, 0, 1, 1);


        retranslateUi(Dialog);
        QObject::connect(buttonBox, &QDialogButtonBox::accepted, Dialog, qOverload<>(&QDialog::accept));
        QObject::connect(buttonBox, &QDialogButtonBox::rejected, Dialog, qOverload<>(&QDialog::reject));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QCoreApplication::translate("Dialog", "\320\235\320\260\321\201\321\202\321\200\320\276\320\271\320\272\320\270", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("Dialog", "\320\242\320\265\320\274\320\260", nullptr));
        lightButton->setText(QCoreApplication::translate("Dialog", "\320\241\320\262\320\265\321\202\320\273\320\260\321\217", nullptr));
        darkButton->setText(QCoreApplication::translate("Dialog", "\320\242\321\221\320\274\320\275\320\260\321\217", nullptr));
        groupBox->setTitle(QCoreApplication::translate("Dialog", "\320\257\320\267\321\213\320\272", nullptr));
        shortcutLabel->setText(QCoreApplication::translate("Dialog", "\320\223\320\276\321\200\321\217\321\207\320\270\320\265 \320\272\320\273\320\260\320\262\320\270\321\210\320\270", nullptr));
        closeLabel->setText(QCoreApplication::translate("Dialog", "\320\227\320\260\320\272\321\200\321\213\321\202\321\214", nullptr));
        saveLabel->setText(QCoreApplication::translate("Dialog", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214", nullptr));
        openLabel->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214", nullptr));
        readOnlyLabel->setText(QCoreApplication::translate("Dialog", "\320\236\321\202\320\272\321\200\321\213\321\202\321\214 \320\264\320\273\321\217 \321\207\321\202\320\265\320\275\320\270\321\217", nullptr));
        helpLabel->setText(QCoreApplication::translate("Dialog", "\320\241\320\277\321\200\320\260\320\262\320\272\320\260", nullptr));
        newLabel->setText(QCoreApplication::translate("Dialog", "\320\235\320\276\320\262\321\213\320\271", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
