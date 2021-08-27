#include "my_widget.h"

#include <QPainter>
#include <QPaintEvent>

#include <utility>




MyWidget::MyWidget(QWidget* parent, Qt::WindowFlags f)
    : QWidget(parent, f)
    , m_img(800, 600, QImage::Format_ARGB32)
{

}


void MyWidget::image_update(QImage img)
{
    m_img = std::move(img);
    update();
}


void MyWidget::paintEvent(QPaintEvent* e)
{
    QPainter painter(this);
    painter.drawImage(img_to_window(QPoint(0, 0)), m_img);
    painter.setPen(Qt::gray);
    painter.drawLine(width() / 2, 0, width() / 2, height());
    painter.drawLine(0, height() / 2, width(), height() / 2);
    e->accept();
}


QPoint MyWidget::window_to_img(QPoint p)
{
    QPoint offs { (m_img.width() - width()) / 2,
                  (m_img.height() - height()) / 2 };
    return p + offs;
}


QPoint MyWidget::img_to_window(QPoint p)
{
    QPoint offs { (width() - m_img.width()) / 2,
                  (height() - m_img.height()) / 2 };
    return p + offs;
}
