#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QFileDialog>
#include <QPushButton>
#include <QLayout>
#include <QLabel>
#include <QString>
#include <QPaintEvent>
#include <sample.h>
#include <QPoint>
#include <QSize>

class Widget : public QWidget
{
    Q_OBJECT

    QLabel *fileName;
    QPushButton *btn;
    TSample sample;

public:
    Widget(TSample, QWidget *parent = nullptr);
    ~Widget();

public slots:
    void OpenFile();

protected:
    void paintEvent(QPaintEvent*);
};
#endif // WIDGET_H
