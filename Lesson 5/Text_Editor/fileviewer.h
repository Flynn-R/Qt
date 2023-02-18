#ifndef FILEVIEWER_H
#define FILEVIEWER_H

#include <QWidget>
#include <QTreeView>
#include <QGridLayout>
#include <QComboBox>
#include <QPushButton>
#include <QStandardItemModel>
#include <QApplication>
#include <QLineEdit>

class FileViewer : public QWidget
{
    Q_OBJECT
public:
    explicit FileViewer(QWidget *parent = nullptr);
    void clearTree();
    QStandardItemModel* getCurrentModel() const { return model; }
    void setNewModel(QStandardItemModel*);
    void rebuildModel(QString);

private:
    QGridLayout* gridLayout;
    QTreeView* tree;
    QPushButton* mainPath;
    QComboBox* diskSelBox;
    QStandardItemModel* model;
    QString currentPath;
    QLineEdit* pathSpec;

private slots:
    void chgDsk(int);
    void goMainPath();
    void pwd();

signals:

};

#endif // FILEVIEWER_H
