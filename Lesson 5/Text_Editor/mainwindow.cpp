#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog(this);

    translator.load(languages[0]);
    qApp->installTranslator(&translator);

    currentTheme = themes[0];
    qApp->setStyleSheet(currentTheme);

    keyMap["Close"] = QKeySequence("Ctrl+Q");
    keyMap["Save"] = QKeySequence("Ctrl+S");
    keyMap["Open"] = QKeySequence("Ctrl+O");
    keyMap["ReadOnly"] = QKeySequence("Ctrl+R");
    keyMap["Help"] = QKeySequence("Ctrl+H");
    keyMap["New"] = QKeySequence("Ctrl+N");

    connect(this, &MainWindow::closeEditor, this, &MainWindow::on_closeButton_clicked);
    connect(this, &MainWindow::saveFile,  this, &MainWindow::on_saveButton_clicked);
    connect(this, &MainWindow::openFile, this, &MainWindow::on_openButton_clicked);
    connect(this, &MainWindow::readOnly, this, &MainWindow::on_readOnlyButton_clicked);
    connect(this, &MainWindow::helpOpen, this, &MainWindow::on_helpButton_clicked);
    connect(this, &MainWindow::newOpen, this, &MainWindow::newFileOpen);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog;
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
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть текстовый файл"), QDir::homePath(), tr("Текст (*.txt)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
            ui->plainTextEdit->setReadOnly(false);
        }
    }
}

void MainWindow::on_readOnlyButton_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Открыть файл для чтения"), QDir::homePath(), tr("Текст (*.txt)"));
    if (!filename.isEmpty())
    {
        QFile file(filename);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
            ui->plainTextEdit->setReadOnly(true);
        }
    }
}

void MainWindow::on_helpButton_clicked()
{
    QFile help(tr(":/help/help (rus).txt"));
    if (help.open(QIODevice::ReadOnly))
    {
        QMessageBox messageBox;
        messageBox.setStyleSheet(currentTheme);
        QTextStream stream(&help);
        messageBox.setText(stream.readAll());
        messageBox.exec();
    }
}

void MainWindow::newFileOpen()
{
    ui->plainTextEdit->clear();
}

void MainWindow::on_changeShortcutsButton_clicked()
{
    connect(dialog, &Dialog::hotkeyChanged, this, &MainWindow::changeHotkey);
    connect(dialog, &Dialog::languageSelected, this, &MainWindow::switchLanguage);
    connect(dialog, &Dialog::themeSelected, this, &MainWindow::switchTheme);
    dialog->setKeyMap(keyMap);

    if (currentLanguage == languages[0])
        dialog->setLanguageRadioButton(true);
    else
        dialog->setLanguageRadioButton(false);

    if (currentTheme == themes[0])
        dialog->setTheme(true);
    else
        dialog->setTheme(false);

    dialog->exec();
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
    if (shortcut == keyMap["ReadOnly"])
        emit readOnly();
    if (shortcut == keyMap["Help"])
        emit helpOpen();
    if (shortcut == keyMap["New"])
        emit newOpen();
}

void MainWindow::changeHotkey(QMap<const QString, QKeySequence> newKeyMap)
{
    keyMap = newKeyMap;
}

void MainWindow::translate()
{
    dialog->translate();

    ui->changeShortcutsButton->setText(tr("Настройки"));
    ui->saveButton->setText(tr("Сохранить"));
    ui->openButton->setText(tr("Открыть"));
    ui->readOnlyButton->setText(tr("Открыть для чтения"));
    ui->closeButton->setText(tr("Закрыть"));
    ui->helpButton->setText(tr("Справка"));
    this->setWindowTitle(tr("Текстовый редактор"));
}

void MainWindow::switchLanguage(bool arg)
{
    if (arg)
        translator.load(languages[0]);
    else
        translator.load(languages[1]);
    qApp->installTranslator(&translator);

    translate();
}

void MainWindow::switchTheme(bool arg)
{
    if (arg)
        currentTheme = themes[0];
    else
        currentTheme = themes[1];
    qApp->setStyleSheet(currentTheme);
}
