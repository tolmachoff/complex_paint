#include "my_active_widget.h"

#include <QPainter>
#include <QMouseEvent>


MyActiveWidget::MyActiveWidget(QWidget* parent, Qt::WindowFlags f)
    : MyWidget(parent, f)
    , m_is_painting(false)
    , m_last_x(-1)
    , m_last_y(-1)
{

}


void MyActiveWidget::mousePressEvent(QMouseEvent* e)
{
    m_is_painting = true;
    e->accept();
}


void MyActiveWidget::mouseReleaseEvent(QMouseEvent* e)
{
    m_is_painting = false;
    m_last_x = -1;
    m_last_y = -1;
    e->accept();
}


void MyActiveWidget::mouseMoveEvent(QMouseEvent* e)
{
    if (m_is_painting) {

        if (m_last_x != -1 && m_last_y != -1) {
            QPainter painter(&m_img);
            painter.drawLine(m_last_x, m_last_y, e->x(), e->y());
        }
        m_last_x = e->x();
        m_last_y = e->y();

        update();

        emit image_rdy(m_img);
    }
    e->accept();
}
