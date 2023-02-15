#include "dialog.h"
#include "ui_dialog.h"

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::setKeyMap(QMap<const QString, QKeySequence> keyMap)
{
    newKeyMap = keyMap;
}

void Dialog::on_closeSeq_editingFinished()
{
    newKeyMap["Close"] = ui->closeSeq->keySequence();
}


void Dialog::on_saveSeq_editingFinished()
{
    newKeyMap["Save"] = ui->saveSeq->keySequence();
}


void Dialog::on_openSeq_editingFinished()
{
    newKeyMap["Open"] = ui->openSeq->keySequence();
}


void Dialog::on_helpSeq_editingFinished()
{
    newKeyMap["Help"] = ui->helpSeq->keySequence();
}


void Dialog::on_newSeq_editingFinished()
{
    newKeyMap["New"] = ui->newSeq->keySequence();
}


void Dialog::on_buttonBox_accepted()
{
    if (ui->russian->isChecked())
        emit languageSelected(true);
    else if (ui->english->isChecked())
        emit languageSelected(false);
    emit hotkeyChanged(newKeyMap);
    close();
}


void Dialog::on_buttonBox_rejected()
{
    close();
}

