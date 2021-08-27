#include "my_widget.h"

#include <QPainter>
#include <QPaintEvent>

#include <utility>




MyWidget::MyWidget(QWidget* parent, Qt::WindowFlags f)
    : QWidget(parent, f)
    , m_img(1920, 1080, QImage::Format_ARGB32)
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
    painter.drawImage(0, 0, m_img);
    painter.setPen(Qt::gray);
    painter.drawLine(width() / 2, 0, width() / 2, height());
    painter.drawLine(0, height() / 2, width(), height() / 2);
    e->accept();
}


void MyWidget::resizeEvent(QResizeEvent* e)
{
    if (!e->size().isEmpty()) {
        if (!e->oldSize().isEmpty()) {
            QPoint old_center = {e->oldSize().width() / 2, e->oldSize().height() / 2};
            QPoint new_center = {e->size().width() / 2, e->size().height() / 2};
            QPoint new_topleft = old_center - new_center;

            m_img = m_img.copy(QRect(new_topleft, e->size()));
        }
        else {
            m_img = m_img.copy(QRect(QPoint(0, 0), e->size()));
        }
    }
    e->accept();
}
