#include "widget.h"

Widget::Widget(TSample s, QWidget *parent)
    : QWidget(parent), sample(s)
{

    setWindowTitle("Работа №7");
    setFixedSize(600, 500);

    btn = new QPushButton("Выбрать файл", this);
    btn->setGeometry(20, 20, 120, 25);

    connect(btn, &QPushButton::pressed, this, &Widget::OpenFile);

    fileName = new QLabel(this);
    fileName->setGeometry(150, 20, 430, 25);

}

Widget::~Widget()
{
    delete btn;
    delete fileName;
}

void Widget::OpenFile() {
    fileName->setText(QFileDialog::getOpenFileName(this,
        tr("Открыть файл"), "/", tr("Text files (*.txt)")));
    if (fileName->text() != "") {
        Graph graph;
        if (graph.setGraph(fileName->text()) != 0) {
            fileName->setText("Произошла ошибка");
            return;
        }
        sample = TSample(graph);
        repaint();
    }
}


void Widget::paintEvent(QPaintEvent*)
{
    QPainter p;
    p.begin(this);
    sample.draw(&p, QRect(QPoint(0, 50), QSize(600, 400)));
    p.end();
}


