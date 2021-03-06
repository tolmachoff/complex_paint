#include "active_widget.h"
#include "image_transformer.h"

#include <QApplication>


int main(int argc, char** argv)
{
    QApplication a(argc, argv);

    view::Widget w1;
    w1.setWindowTitle("slave");
    view::ActiveWidget w2;
    w2.setWindowTitle("master");

    engine::ImageTransformer tr;
    QObject::connect(&w2, SIGNAL(image_rdy(QImage)), &tr, SLOT(image_update(QImage)));
    QObject::connect(&tr, SIGNAL(image_rdy(QImage)), &w1, SLOT(image_update(QImage)));

    w1.show();
    w2.show();

    return QApplication::exec();
}