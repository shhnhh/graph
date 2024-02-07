#include "matrix.h"

Matrix::Matrix()
{
    size = 3;
    for (int i = 0; i < size; i++) {
        matrix.push_back(QVector<qint16>(size));
        for (int j = 0; j < size; j++)
            matrix[i][j] = 1;
    }
}

int Matrix::getSize() {
    return size;
}

void Matrix::setSize(int newSize) {
    size = newSize;
    matrix.clear();

    for (int i = 0; i < size; i++) {
        matrix.push_back(QVector<qint16>(size));
        for (int j = 0; j < size; j++)
            matrix[i][j] = 0;
    }
}

qint16 Matrix::get(int i, int j) {
    return matrix[i][j];
}

void Matrix::set(int i, int j, qint16 a) {
    matrix[i][j] = a;
}
