#include "fileviewer.h"
#include <QDir>
#include <QDebug>

FileViewer::FileViewer(QWidget *parent)
    : QWidget{parent}, model(nullptr)
{
    gridLayout = new QGridLayout(this);
    this->setLayout(gridLayout);

    tree = new QTreeView(this);

    gridLayout->addWidget(tree, 1, 0, 10, 10);

    setMinimumSize(500, 600);

    if (QSysInfo::productType() == "Windows")
    {
        diskSelBox = new QComboBox(this);
        QFileInfoList list = QDir::drives();
        for (auto& listDisk : list)
            diskSelBox->addItem(listDisk.path());

        if (list.count() > 0)
            rebuildModel(list.at(0).path());

        gridLayout->addWidget(diskSelBox, 0, 0, 1, 2);
        connect(diskSelBox, &QComboBox::activated, this, &FileViewer::chgDsk);
    }
    else
    {
        mainPath = new QPushButton(this);
        mainPath->setText("/");
        gridLayout->addWidget(mainPath, 0, 0, 1, 2);
        connect(mainPath, &QPushButton::clicked, this, &FileViewer::goMainPath);
        rebuildModel("/");
    }

    pathSpec = new QLineEdit(this);
    pathSpec->setText(currentPath);

    connect(tree->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileViewer::pwd);

    gridLayout->addWidget(pathSpec, 1, 0);
}

void FileViewer::chgDsk(int index)
{
    QFileInfoList list = QDir::drives();
    rebuildModel(list.at(index).path());
}

void FileViewer::goMainPath()
{
    rebuildModel("/");
}

void FileViewer::setNewModel(QStandardItemModel* newModel)
{
    disconnect(tree->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileViewer::pwd);
    model = newModel;
    tree->setModel(model);
    connect(tree->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileViewer::pwd);
}

void FileViewer::rebuildModel(QString path)
{
    currentPath = path;
    auto mdl = new QStandardItemModel(this);
    QList<QStandardItem*> items;
    items.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)), path));
    mdl->appendRow(items);

    QDir dir(path);
    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir::Dirs);
    QStringList list = dir.entryList();
    QList<QStandardItem*> folders;
    for (auto& it : list)
        folders.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirIcon)), it));
    items.at(0)->appendRows(folders);

    dir.setFilter(QDir::Hidden | QDir::NoSymLinks | QDir::Files);
    QList<QStandardItem*> files;
    for (auto& it : list)
        files.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)), it));
    items.at(0)->appendRows(files);
    setNewModel(mdl);
}

void FileViewer::pwd()
{
    auto selectedItem = tree->selectionModel()->currentIndex();
    auto path = currentPath + model->itemFromIndex(selectedItem)->text();
    pathSpec->setText(path);
    connect(tree->selectionModel(), &QItemSelectionModel::currentChanged, this, &FileViewer::pwd);
}
