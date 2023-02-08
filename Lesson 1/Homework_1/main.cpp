#include "task_1.h"
#include "task_2.h"
#include "task_3.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Task_1 t1;
    t1.show();
    a.exec();

    Task_2 t2;
    t2.show();
    a.exec();

    Task_3 t3;
    t3.show();
    a.exec();

    return EXIT_SUCCESS;
}
