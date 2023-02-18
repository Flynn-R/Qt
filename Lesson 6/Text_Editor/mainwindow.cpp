#include "mainwindow.h"
#include "qmdisubwindow.h"
#include "ui_mainwindow.h"
#include <QMenuBar>
#include <QMenu>
#include <QPrinter>
#include <QPrintDialog>
#include <QPlainTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    dialog = new Dialog(this);
    
    connect(ui->mdiArea, &QMdiArea::subWindowActivated, this, &MainWindow::subwindowChanged);
    currentSubwindow = ui->mdiArea->addSubWindow(new QPlainTextEdit(this));
    ui->mdiArea->setViewMode(QMdiArea::TabbedView);

    currentLanguage = languages[0];
    translator.load(currentLanguage);
    qApp->installTranslator(&translator);

    currentTheme = themes[0];
    qApp->setStyleSheet(currentTheme);
    
    QMenu* fileMenu = menuBar()->addMenu(tr("Файл"));
    connect(fileMenu->addAction(tr("Новый")), &QAction::triggered, this, &MainWindow::newFileOpen);
    fileMenu->addSeparator();
    QMenu* saveSubMenu = fileMenu->addMenu(tr("Открыть"));
    connect(saveSubMenu->addAction(tr("Открыть")), &QAction::triggered, this, &MainWindow::on_openButton_clicked);
    connect(saveSubMenu->addAction(tr("Открыть для чтения")), &QAction::triggered, this, &MainWindow::on_readOnlyButton_clicked);
    connect(fileMenu->addAction(tr("Сохранить")), &QAction::triggered, this, &MainWindow::on_saveButton_clicked);
    connect(fileMenu->addAction(tr("Печать")), &QAction::triggered, this, &MainWindow::on_printButton_clicked);
    fileMenu->addSeparator();
    connect(fileMenu->addAction(tr("Закрыть")), &QAction::triggered, this, &MainWindow::on_closeButton_clicked);
    
    QMenu* settingsMenu = menuBar()->addMenu(tr("Настройки"));
    connect(settingsMenu->addAction(tr("Настройки")), &QAction::triggered, this, &MainWindow::on_settingsButton_clicked);
    settingsMenu->addSeparator();
    QMenu* themeSubMenu = settingsMenu->addMenu(tr("Тема"));
    QAction* light = themeSubMenu->addAction(tr("Светлая"));
    light->setCheckable(true);
    light->setChecked(true);
    connect(light, &QAction::triggered, this, &MainWindow::themeMenuTriggered);
    themeActions.append(light);
    QAction* dark = themeSubMenu->addAction(tr("Тёмная"));
    dark->setCheckable(true);
    dark->setChecked(false);
    themeActions.append(dark);
    connect(dark, &QAction::triggered, this, &MainWindow::themeMenuTriggered);
    QMenu* languageSubMenu = settingsMenu->addMenu(tr("Язык"));
    QAction* rus = languageSubMenu->addAction("Русский");
    rus->setCheckable(true);
    rus->setChecked(true);
    languageActions.append(rus);
    connect(rus, &QAction::triggered, this, &MainWindow::languageMenuTriggered);
    QAction* eng = languageSubMenu->addAction("English");
    eng->setCheckable(true);
    eng->setChecked(false);
    languageActions.append(eng);
    connect(eng, &QAction::triggered, this, &MainWindow::languageMenuTriggered);

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
    connect(ui->newButton, &QPushButton::clicked, this, &MainWindow::newFileOpen);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dialog;
}

void MainWindow::on_closeButton_clicked()
{
    if (ui->mdiArea->subWindowList().empty())
        close();
    else
        currentSubwindow->close();
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
            stream << dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->toPlainText();
//            stream << ui->plainTextEdit->toPlainText();
            stream.flush();
            file.close();
            ui->mdiArea->currentSubWindow()->setWindowTitle(fileName);
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
            dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->setPlainText(stream.readAll());
//            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
            dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->setReadOnly(false);
//            ui->plainTextEdit->setReadOnly(false);
            ui->mdiArea->currentSubWindow()->setWindowTitle(fileName);
        }
    }
}

void MainWindow::on_readOnlyButton_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Открыть файл для чтения"), QDir::homePath(), tr("Текст (*.txt)"));
    if (!fileName.isEmpty())
    {
        QFile file(fileName);
        if (file.open(QIODevice::ReadOnly))
        {
            QTextStream stream(&file);
            dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->setPlainText(stream.readAll());
//            ui->plainTextEdit->setPlainText(stream.readAll());
            file.close();
            dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->setReadOnly(true);
//            ui->plainTextEdit->setReadOnly(true);
            ui->mdiArea->currentSubWindow()->setWindowTitle(fileName);
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
    currentSubwindow = ui->mdiArea->addSubWindow(new QPlainTextEdit(this));
    currentSubwindow->show();
//    ui->mdiArea->setActiveSubWindow(currentSubwindow);
    dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->clear();
    ui->mdiArea->currentSubWindow()->setWindowTitle("(Untitled)");
//    ui->plainTextEdit->clear();
}

void MainWindow::on_settingsButton_clicked()
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

    ui->newButton->setText(tr("Новый"));
    ui->settingsButton->setText(tr("Настройки"));
    ui->saveButton->setText(tr("Сохранить"));
    ui->openButton->setText(tr("Открыть"));
    ui->readOnlyButton->setText(tr("Открыть для чтения"));
    ui->printButton->setText(tr("Печать"));
    ui->closeButton->setText(tr("Закрыть"));
    ui->helpButton->setText(tr("Справка"));
    this->setWindowTitle(tr("Текстовый редактор"));
}

void MainWindow::switchLanguage(bool arg)
{
    if (arg)
    {
    	currentLanguage = languages[0];
    	languageActions.first()->setChecked(true);
    	languageActions.last()->setChecked(false);
    }
    else
    {
    	currentLanguage = languages[1];
    	languageActions.first()->setChecked(false);
    	languageActions.last()->setChecked(true);
    }
    translator.load(currentLanguage);
    qApp->installTranslator(&translator);

    translate();
}

void MainWindow::switchTheme(bool arg)
{
    if (arg)
    {
    	currentTheme = themes[0];
    	themeActions.first()->setChecked(true);
    	themeActions.last()->setChecked(false);
    }
    else
    {
    	currentTheme = themes[1];
    	themeActions.first()->setChecked(false);
    	themeActions.last()->setChecked(true);
    }
    qApp->setStyleSheet(currentTheme);
}

void MainWindow::on_printButton_clicked()
{
    QPrinter printer;
    QPrintDialog printDialog(&printer, this);
    printDialog.setWindowTitle(tr("Печать"));
    if (printDialog.exec() != QDialog::Accepted)
    	return;
    dynamic_cast<QPlainTextEdit*>(currentSubwindow->widget())->print(&printer);
//    ui->plainTextEdit->print(&printer);
}

void MainWindow::themeMenuTriggered()
{
    if (sender() == themeActions.first())
        switchTheme(true);
    else
        switchTheme(false);
}

void MainWindow::languageMenuTriggered()
{
    if (sender() == languageActions.first())
        switchLanguage(true);
    else
        switchLanguage(false);
}

void MainWindow::subwindowChanged(QMdiSubWindow* subwindow)
{
    currentSubwindow = subwindow;
}
