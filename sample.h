#ifndef SAMPLE_H
#define SAMPLE_H

#include <QPainter>
#include <graph.h>

class TSample
{
    Graph graph;
public:
    TSample(Graph);
    void draw(QPainter*, QRect);
};

#endif // SAMPLE_H
