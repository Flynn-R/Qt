#ifndef MAINWINDOW
#define MAINWINDOW

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QMap>
#include <QTranslator>
#include <QApplication>
#include <QMdiSubWindow>
#include "dialog.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_closeButton_clicked();
    void on_saveButton_clicked();
    void on_openButton_clicked();
    void on_helpButton_clicked();
    void newFileOpen();
    void on_settingsButton_clicked();
    void changeHotkey(QMap<const QString, QKeySequence>);
    void switchLanguage(bool);
    void switchTheme(bool);
    void on_readOnlyButton_clicked();
    void on_printButton_clicked();
    void themeMenuTriggered();
    void languageMenuTriggered();
//    void subwindowChanged(QMdiSubWindow*);

signals:
    void closeEditor();
    void saveFile();
    void openFile();
    void readOnly();
    void helpOpen();
    void newOpen();

private:
    Ui::MainWindow *ui;

    QMap<const QString, QKeySequence> keyMap;
    void keyReleaseEvent(QKeyEvent*) override;

    QTranslator translator;
    void translate();
    const QString languages[2] = {
        ":/translations/QtLanguage_ru.qm",

        ":/translations/QtLanguage_en.qm"
    };
    QString currentLanguage;

    const QString themes[2] = {
        "QMainWindow { background-color: white }"
        "QPushButton { color: black; background-color: grey }"
        "QCheckBox { color: black; background-color: white }"
        "QPlainTextEdit { color: black; background-color: white }"
        "QDialog { background-color: white }"
        "QLabel { color: black; background-color: white }"
        "QKeySequenceEdit { color: black; background-color: grey }"
        "QGroupBox { color: black; background-color: white }"
        "QRadioButton { color: black; background-color: white }",

        "QMainWindow { background-color: black }"
        "QPushButton { color: black; background-color: white }"
        "QCheckBox { color: white; background-color: black }"
        "QPlainTextEdit { color: black; background-color: grey }"
        "QDialog { background-color: black }"
        "QLabel { color: white; background-color: black }"
        "QKeySequenceEdit { color: white; background-color: black }"
        "QGroupBox { color: white; background-color: black }"
        "QRadioButton { color: white; background-color: black }"
    };
    QString currentTheme;
    Dialog* dialog;
    QList<QAction*> themeActions;
    QList<QAction*> languageActions;
    QMdiSubWindow* currentSubwindow;
};
#endif // MAINWINDOW
