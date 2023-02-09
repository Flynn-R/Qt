#include "task_1.h"
#include "task_2.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Task_1 w1;
    w1.show();
    a.exec();

    Task_2 w2;
    w2.show();
    a.exec();

    return EXIT_SUCCESS;
}
