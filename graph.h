#ifndef GRAPH_H
#define GRAPH_H

#include <matrix.h>
#include <QPainter>
#include <QFile>
#include <QTextStream>
#include <QDebug>
#include <QChar>

class Graph
{
    int count;
    Matrix adjMatrix;

public:
    Graph();
    int setGraph(QString);

    int getCount();
    bool get(int, int);
};

#endif // GRAPH_H
