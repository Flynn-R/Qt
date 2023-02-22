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

bool Dialog::finder(QKeySequence& keySeq)
{
    for (int i = Qt::Key_A; i <= Qt::Key_Z; ++i)
    {
        if (keySeq.count() == 1 && (keySeq == (Qt::CTRL | static_cast<Qt::Key>(i)) || (keySeq >= Qt::Key_F1 && keySeq <= Qt::Key_F12)))
            return true;
    }

    return false;
}

void Dialog::on_closeSeq_editingFinished()
{
    auto keySeq = ui->closeSeq->keySequence();
    if (finder(keySeq))
        newKeyMap["Close"] = keySeq;
    else
        ui->closeSeq->clear();
}


void Dialog::on_saveSeq_editingFinished()
{
    auto keySeq = ui->saveSeq->keySequence();
    if (finder(keySeq))
        newKeyMap["Save"] = keySeq;
    else
        ui->saveSeq->clear();
}


void Dialog::on_openSeq_editingFinished()
{
    auto keySeq = ui->openSeq->keySequence();
    if (finder(keySeq))
        newKeyMap["Open"] = keySeq;
    else
        ui->openSeq->clear();
}

void Dialog::on_readOnlySeq_editingFinished()
{
    auto keySeq = ui->readOnlySeq->keySequence();
    if (finder(keySeq))
        newKeyMap["ReadOnly"] = keySeq;
    else
        ui->readOnlySeq->clear();
}

void Dialog::on_helpSeq_editingFinished()
{
    auto keySeq = ui->helpSeq->keySequence();
    if (finder(keySeq))
        newKeyMap["Help"] = keySeq;
    else
        ui->helpSeq->clear();
}


void Dialog::on_newSeq_editingFinished()
{
    auto keySeq = ui->newSeq->keySequence();
    if (finder(keySeq))
        newKeyMap["New"] = keySeq;
    else
        ui->newSeq->clear();
}

void Dialog::setLanguageRadioButton(bool arg)
{
    if (arg)
        ui->russian->setChecked(true);
    else
        ui->english->setChecked(true);
}

void Dialog::setTheme(bool arg)
{
    if (arg)
        ui->lightButton->setChecked(true);
    else
        ui->darkButton->setChecked(true);
}

void Dialog::on_buttonBox_accepted()
{
    if (ui->russian->isChecked())
        emit languageSelected(true);
    else if (ui->english->isChecked())
        emit languageSelected(false);

    if (ui->lightButton->isChecked())
        emit themeSelected(true);
    else
        emit themeSelected(false);

    emit hotkeyChanged(newKeyMap);
    close();
}


void Dialog::on_buttonBox_rejected()
{
    close();
}

void Dialog::translate()
{
    this->setWindowTitle(tr("Настройки"));

    ui->shortcutLabel->setText(tr("Горячие клавиши"));
    ui->closeLabel->setText(tr("Закрыть"));
    ui->saveLabel->setText(tr("Сохранить"));
    ui->openLabel->setText(tr("Открыть"));
    ui->readOnlyLabel->setText(tr("Открыть для чтения"));
    ui->helpLabel->setText(tr("Справка"));
    ui->newLabel->setText(tr("Новый"));

    ui->groupBox->setTitle(tr("Язык"));

    ui->groupBox_2->setTitle(tr("Тема"));
    ui->lightButton->setText(tr("Светлая"));
    ui->darkButton->setText(tr("Тёмная"));
}
