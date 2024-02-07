#ifndef MATRIX_H
#define MATRIX_H


#include <QVector>

class Matrix
{
    int size;
    QVector <QVector <qint16>> matrix;

public:
    Matrix();

    int getSize();
    void setSize(int);
    qint16 get(int, int);
    void set(int, int, qint16);
};

#endif // MATRIX_H
