#pragma once

#include "my_widget.h"



class MyActiveWidget : public MyWidget
{
    Q_OBJECT

public:
    explicit MyActiveWidget(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());


    Q_SIGNAL void image_rdy(QImage img);


protected:
    void mousePressEvent(QMouseEvent* e) override;

    void mouseReleaseEvent(QMouseEvent* e) override;

    void mouseMoveEvent(QMouseEvent* e) override;


    bool m_is_painting;

    QPoint m_last_pos;

};