#ifndef MAINWINDOW
#define MAINWINDOW

#include <QMainWindow>
#include <QFileDialog>
#include <QTextStream>
#include <QMessageBox>
#include <QMap>
#include <QTranslator>
#include <QApplication>

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
    void on_readOnlyBox_stateChanged(int arg1);
    void newFileOpen();
    void on_changeShortcutsButton_clicked();
    void changeHotkey(QMap<const QString, QKeySequence>);
    void switchLanguage(bool arg);

signals:
    void closeEditor();
    void saveFile();
    void openFile();
    void helpOpen();
    void newOpen();

private:
    Ui::MainWindow *ui;
    bool readOnly;
    QMap<const QString, QKeySequence> keyMap;
    void keyReleaseEvent(QKeyEvent*) override;
    QTranslator translator;
};
#endif // MAINWINDOW
