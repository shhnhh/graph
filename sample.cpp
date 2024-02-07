#include "sample.h"
#include <cmath>

TSample::TSample(Graph g)
{
    graph = g;
}

void TSample::draw(QPainter* p, QRect r)
{
    int count = graph.getCount();

    qreal x0 = 0, y0 = 70;

    qreal cw = 0.5 * r.width();
    qreal ch = 0.5 * r.height();
    qreal cr = 0.9 * (cw > ch ? ch : cw);
    qreal a = 2.0 * acos(-1.0) / count;

    QFont font;
    qreal cf = 20;
    font.setPointSize(cf);
    font.setBold(true);
    p->setFont(font);

    p->setPen(QPen(Qt::black));

    QPointF t[3];

    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (i != j && graph.get(i, j)) {
                qreal x1 = x0 + cw + cr * sin(i * a),
                      y1 = y0 + ch - cr * cos(i * a),
                      x2 = x0 + cw + cr * sin(j * a),
                      y2 = y0 + ch - cr * cos(j * a);
                qreal new_x1, new_y1, new_x2, new_y2;
                qreal rad = M_PI / 2;
                qreal l = 10;
                qreal a = 0.5;
                if (x1 != x2)
                    rad = atan((y2 - y1) / (x2 - x1));
                if (x1 < x2 || (x1 == x2 && y1 < y2)) {
                    x1 += cf * cos(rad);
                    x2 -= cf * cos(rad);
                    y1 += cf * sin(rad);
                    y2 -= cf * sin(rad);
                    new_x1 = x2 - l * cos(rad - a);
                    new_y1 = y2 - l * sin(rad - a);
                    new_x2 = x2 - l * cos(rad + a);
                    new_y2 = y2 - l * sin(rad + a);

                } else {
                    x1 -= cf * cos(rad);
                    x2 += cf * cos(rad);
                    y1 -= cf * sin(rad);
                    y2 += cf * sin(rad);
                    new_x1 = x2 + l * cos(rad - a);
                    new_y1 = y2 + l * sin(rad - a);
                    new_x2 = x2 + l * cos(rad + a);
                    new_y2 = y2 + l * sin(rad + a);
                }
                p->drawLine(QPoint(x1, y1), QPoint(x2, y2));

                t[0] = {x2, y2};
                t[1] = {new_x1, new_y1};
                t[2] = {new_x2, new_y2};

                p->setBrush(Qt::black);
                p->drawPolygon(t, 3);

            } else if (i == j && graph.get(i, j)) {
                qreal x = x0 + cw + cr * sin(i * a) + cf * sin(i * a),
                      y = y0 + ch - cr * cos(i * a) - cf * cos(i * a);

                p->setBrush(QBrush());
                p->drawEllipse(x - 15, y - 15, 30, 30);
            }

    p->setBrush(Qt::lightGray);
    for (int i = 0; i < count; i++)
    {
        qreal x = x0 + cw + cr * sin(i * a),
              y = y0 + ch - cr * cos(i * a);
        p->drawEllipse(x - cf, y - cf, 2.0 * cf, 2.0 * cf);
        p->drawText(QRectF(x - cf, y - cf, 2.0 * cf, 2.0 * cf),
                    QString().setNum(i + 1),
                    QTextOption(Qt::AlignCenter));
    }
}
