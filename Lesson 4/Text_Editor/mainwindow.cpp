#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "dialog.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    readOnly = false;

    translator.load(":/translations/QtLanguage_ru.qm");
    qApp->installTranslator(&translator);

    keyMap["Close"] = QKeySequence("Ctrl+Q");
    keyMap["Save"] = QKeySequence("Ctrl+S");
    keyMap["Open"] = QKeySequence("Ctrl+O");
    keyMap["Help"] = QKeySequence("Ctrl+H");
    keyMap["New"] = QKeySequence("Ctrl+N");

    connect(this, &MainWindow::closeEditor, this, &MainWindow::on_closeButton_clicked);
    connect(this, &MainWindow::saveFile,  this, &MainWindow::on_saveButton_clicked);
    connect(this, &MainWindow::openFile, this, &MainWindow::on_openButton_clicked);
    connect(this, &MainWindow::helpOpen, this, &MainWindow::on_helpButton_clicked);
    connect(this, &MainWindow::newOpen, this, &MainWindow::newFileOpen);
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_closeButton_clicked()
{
    close();
}


void MainWindow::on_saveButton_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Сохранить текстовый файл"), QDir::homePath(), "Текст (*.txt)");
    if (!fileName.isEmpty())
    {
        QString ext = ".txt";
        if (!(fileName.indexOf(".txt") == fileName.length() - ext.length()))
            fileName += ".txt";
        QFile file(fileName);

        if (file.open(QIODevice::WriteOnly))
        {
            QTextStream stream(&file);
            stream << ui->plainTextEdit->toPlainText();
            stream.flush();
            file.close();
        }
    }
}


void MainWindow::on_openButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть текстовый файл"), QDir::homePath(), "Текст (*.txt)");
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
            ui->plainTextEdit->setReadOnly(readOnly);
        }
    }
}


void MainWindow::on_helpButton_clicked()
{
    QFile help(tr(":/help/help (rus).txt"));
    if (help.open(QIODevice::ReadOnly))
    {
        QMessageBox messageBox;
        QTextStream stream(&help);
        messageBox.setText(stream.readAll());
        messageBox.exec();
    }
}

void MainWindow::on_readOnlyBox_stateChanged(int arg1)
{
    if (arg1 == 0)
        readOnly = false;
    else if (arg1 == 2)
        readOnly = true;
}

void MainWindow::newFileOpen()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_changeShortcutsButton_clicked()
{
    Dialog d(this);
    connect(&d, &Dialog::hotkeyChanged, this, &MainWindow::changeHotkey);
    connect(&d, &Dialog::languageSelected, this, &MainWindow::switchLanguage);
    d.setKeyMap(keyMap);
    d.exec();
}

void MainWindow::keyReleaseEvent(QKeyEvent *event)
{
    auto shortcut = QKeySequence(event->keyCombination());
    if (shortcut == keyMap["Close"])
        emit closeEditor();
    if (shortcut == keyMap["Save"])
        emit saveFile();
    if (shortcut == keyMap["Open"])
        emit openFile();
    if (shortcut == keyMap["Help"])
        emit helpOpen();
    if (shortcut == keyMap["New"])
        emit newOpen();
}

void MainWindow::changeHotkey(QMap<const QString, QKeySequence> newKeyMap)
{
    keyMap = newKeyMap;
}

void MainWindow::switchLanguage(bool arg)
{
    if (arg)
        translator.load(":/translations/QtLanguage_ru.qm");
    else
        translator.load(":/translations/QtLanguage_en.qm");
    qApp->installTranslator(&translator);

    ui->changeShortcutsButton->setText(tr("Настроить"));
    ui->saveButton->setText(tr("Сохранить"));
    ui->openButton->setText(tr("Открыть"));
    ui->closeButton->setText(tr("Закрыть"));
    ui->helpButton->setText(tr("Справка"));
    ui->readOnlyBox->setText(tr("Только для чтения"));
    this->setWindowTitle(tr("Текстовый редактор"));
}
