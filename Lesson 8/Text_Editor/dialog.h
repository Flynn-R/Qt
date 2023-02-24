#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = nullptr);
    void setKeyMap(QMap<QString, QKeySequence>);
    void setLanguageRadioButton(bool);
    void setTheme(bool);
    void translate();
    ~Dialog();

private slots:
    void on_closeSeq_editingFinished();
    void on_saveSeq_editingFinished();
    void on_openSeq_editingFinished();
    void on_helpSeq_editingFinished();
    void on_newSeq_editingFinished();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();
    void on_readOnlySeq_editingFinished();

signals:
    void hotkeyChanged(QMap<QString, QKeySequence>);
    void languageSelected(bool);
    void themeSelected(bool);

private:
    Ui::Dialog *ui;
    QMap<QString, QKeySequence> newKeyMap;
    bool finder(QKeySequence&);
};

#endif // DIALOG_H
