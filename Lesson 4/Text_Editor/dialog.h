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
    void setKeyMap(QMap<const QString, QKeySequence>);
    ~Dialog();

private slots:
    void on_closeSeq_editingFinished();
    void on_saveSeq_editingFinished();
    void on_openSeq_editingFinished();
    void on_helpSeq_editingFinished();
    void on_newSeq_editingFinished();
    void on_buttonBox_accepted();
    void on_buttonBox_rejected();

signals:
    void hotkeyChanged(QMap<const QString, QKeySequence>);
    void languageSelected(bool arg);

private:
    Ui::Dialog *ui;
    QMap<const QString, QKeySequence> newKeyMap;
};

#endif // DIALOG_H
