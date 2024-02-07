#include "graph.h"

Graph::Graph()
{
    count = adjMatrix.getSize();
}

bool Graph::get(int i, int j) {
    return adjMatrix.get(i, j);
}

int Graph::setGraph(QString fileName) {
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return 1;

    QTextStream in(&file);

    count = in.readLine().toInt();
    adjMatrix.setSize(count);

    if (count == 0)
        return 3;

    int i = 0;

    while (!in.atEnd() && i < count) {
        QString line = in.readLine().trimmed();
        if (line.size() != count) {
            file.close();
            return 2;
        }
        for (int j = 0; j < count; j++) {
            adjMatrix.set(i, j, line[j].unicode() - '0');
        }
        i++;
    }
    file.close();
    return 0;
}

int Graph::getCount() {
    return count;
}
