#include "fileviewer.h"
#include <QDir>
#include <QStatusBar>

// ==================================================================================================================================

FileViewer::FileViewer(QWidget *parent)
    : QWidget(parent), model(nullptr)
{
    layout = new QGridLayout(this);
    this->setLayout(layout);

    tree = new QTreeView(this);
    layout->addWidget(tree, 1, 0, 10, 10);

    pathfinder = new QLineEdit(this);
    connect(tree->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileViewer::selectionChanged);
    layout->addWidget(pathfinder, 1, 0);

    goTo = new QPushButton(this);
    goTo->setText("Перейти");
    connect(goTo, &QPushButton::clicked, this, &FileViewer::goToSelectedPath);
    layout->addWidget(goTo, 1, 1);

    search = new QLineEdit(this);
    layout->addWidget(search, 0, 3, 1, 3);

    startSearch = new QPushButton(this);
    startSearch->setText("Найти");
    layout->addWidget(startSearch, 0, 6);
    connect(startSearch, &QPushButton::clicked, this, &FileViewer::searchFiles);

    info = new QTextEdit(this);
    layout->addWidget(info, 1, 3, 10, 10);

    controller = new Controller(this);
    status = new QLabel(this);
    auto statusBar = new QStatusBar(this);
    statusBar->addWidget(status);
    layout->addWidget(statusBar, 11, 13);
    connect(controller, &Controller::changeSearchPath, this, &FileViewer::changeStatus);
    connect(controller, &Controller::generatePathOfFile, this, &FileViewer::printInfo);
    connect(controller, &Controller::newSearch, info, &QTextEdit::clear);

    setMinimumSize(500, 600);

    if (QSysInfo::productType() == "windows")
    {
        diskSelection = new QComboBox(this);
        QFileInfoList list = QDir::drives();
        for (auto& it : list)
            diskSelection->addItem(it.path());
        if (!list.empty())
            rebuildModel(list.at(0).path());

        layout->addWidget(diskSelection, 0, 0, 1, 2);
        connect(diskSelection, &QComboBox::activated, this, &FileViewer::changeDisk);
    }
    else
    {
        mainPath = new QPushButton(this);
        mainPath->setText("/");
        layout->addWidget(mainPath, 0, 0, 1, 2);
        connect(mainPath, &QPushButton::clicked, this, &FileViewer::goToMainPath);
        rebuildModel("/");
    }
}

void FileViewer::changeDisk(qint32 index)
{
    QFileInfoList list = QDir::drives();
    rebuildModel(list.at(index).path());
}

void FileViewer::goToMainPath()
{
    rebuildModel("/");
}

void FileViewer::setNewModel(QStandardItemModel* newModel)
{
    disconnect(tree->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileViewer::selectionChanged);
    tree->setModel(newModel);
    model = newModel;
    connect(tree->selectionModel(), &QItemSelectionModel::selectionChanged, this, &FileViewer::selectionChanged);
}

void FileViewer::rebuildModel(QString path)
{
    previousPath = currentPath;
    currentPath = path;
    pathfinder->setText(currentPath);
    QStandardItemModel* newModel = new QStandardItemModel(this);
    QList<QStandardItem*> items;
    items.append(new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DriveHDIcon)), path));
    newModel->appendRow(items);

    QDir dir(path);
    dir.setFilter(QDir::NoSymLinks | QDir::Dirs);
    QStringList list = dir.entryList();
    QList<QStandardItem*> folders;
    for (auto& it : list)
    {
        QStandardItem* folder = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_DirIcon)), it);
        folders.append(folder);
    }
    items.at(0)->appendRows(folders);

    dir.setFilter(QDir::NoSymLinks | QDir::Files);
    QList<QStandardItem*> files;
    for (auto& it : list)
    {
        QStandardItem* file = new QStandardItem(QIcon(QApplication::style()->standardIcon(QStyle::SP_FileIcon)), it);
        files.append(file);
    }

    items.at(0)->appendRows(files);
    setNewModel(newModel);
}

void FileViewer::selectionChanged()
{
    QString newPath;
    if (currentPath != "/")
        newPath = currentPath + "/" + model->itemFromIndex(tree->selectionModel()->currentIndex())->text();
    else
        newPath = currentPath + model->itemFromIndex(tree->selectionModel()->currentIndex())->text();

    pathfinder->setText(newPath);
}

void FileViewer::goToSelectedPath()
{
    QString newPath = pathfinder->text();
    auto length = newPath.length();
    if (newPath[length - 2] == '.' && newPath[length - 1] == '.')
        rebuildModel(previousPath);
    else if (newPath[length - 1] != '.')
        rebuildModel(newPath);
}

// ==================================================================================================================================

ThreadSearch::ThreadSearch(QString _folder, QString _file, QObject* parent) : QThread(parent)
{
    folder = _folder;
    file = _file;
    searching = true;
}

void ThreadSearch::run()
{
    QStringList folders = { folder };
    for (auto& it1 : folders)
    {
        if (!searching)
            break;

        QDir search(it1);
        emit showFoundPath(it1);

        search.setFilter(QDir::Dirs | QDir::NoSymLinks);
        QStringList foundFolders = search.entryList();
        for (auto& it2 : foundFolders)
        {
            if (!searching)
                break;

            QString newPath = it1 + it2 + "/";
            if (newPath.indexOf("/.") == -1)
                folders << newPath;
        }

        search.setFilter(QDir::Files | QDir::NoSymLinks);
        QStringList foundFiles = search.entryList();
        for (auto& it2 : foundFiles)
        {
            if (!searching)
                break;

            QString fileName = it2;
            if (fileName.indexOf(file) != -1)
                emit searchFile(fileName);
        }

        folders.removeFirst();
    }

    emit stoppedThread();
}

void ThreadSearch::searchStop()
{
    searching = false;
}

// ==================================================================================================================================

Controller::~Controller()
{
    if (searchThread != nullptr)
    {
        if (searchThread->isRunning())
        {
            searchThread->searchStop();
            searchThread->terminate();
        }
        searchThread.reset();
    }
}

void Controller::startSearch(QString folder, QString file)
{
    if (searchThread.get())
    {
        searchThread->searchStop();
        searchThread->terminate();
        searchThread.reset();
        return;
    }

    searchThread = QSharedPointer<ThreadSearch>::create(folder, file);
    searchThread->start(QThread::NormalPriority);

    connect(searchThread.get(), &ThreadSearch::stoppedThread, this, &Controller::deleteThread);         // Здесь ошибка, но не могу понять в чём она заключается
    connect(searchThread.get(), &ThreadSearch::showFoundPath, this, &Controller::printCurrentPath);
    connect(searchThread.get(), &ThreadSearch::searchFile, this, &Controller::generateStringPathFile);
    emit newSearch();
}

void Controller::deleteThread()
{
    searchThread.reset();
}

void Controller::printCurrentPath(QString path)
{
    currentPath = path;
    emit changeSearchPath(path);
}

void Controller::generateStringPathFile(QString file)
{
    emit generatePathOfFile(currentPath + file);
}

void Controller::finishThread()
{
    emit changeSearchPath("Готовою. Поиск завершён");
}

// ==================================================================================================================================

void FileViewer::searchFiles()
{
    QString string = search->text();
    if (string.length() == 0)
        return;

    controller->startSearch(currentPath, string);
}

void FileViewer::changeStatus(QString string)
{
    status->setText(string);
}

void FileViewer::printInfo(QString string)
{
    info->append(string);
}
