#include "active_widget.h"

#include <QPainter>
#include <QMouseEvent>



namespace view {


ActiveWidget::ActiveWidget(QWidget* parent, Qt::WindowFlags f)
    : Widget(parent, f)
    , m_is_painting(false)
    , m_last_pos(-1, -1)
{

}


void ActiveWidget::mousePressEvent(QMouseEvent* e)
{
    m_is_painting = true;
    e->accept();
}


void ActiveWidget::mouseReleaseEvent(QMouseEvent* e)
{
    m_is_painting = false;
    m_last_pos = {-1, -1};
    e->accept();
}


void ActiveWidget::mouseMoveEvent(QMouseEvent* e)
{
    if (m_is_painting) {

        if (m_last_pos.x() != -1 && m_last_pos.y() != -1) {
            QPainter painter(&m_img);
            painter.drawLine(window_to_img(m_last_pos), window_to_img(e->pos()));
        }
        m_last_pos = e->pos();

        update();

        emit image_rdy(m_img);
    }
    e->accept();
}


}
