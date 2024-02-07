#include "widget.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Graph graph;
    Widget w(graph);
    w.show();

    return a.exec();
}
