#pragma once

#include <QWidget>
#include <QImage>



namespace view {


class Widget : public QWidget
{
    Q_OBJECT

public:
    explicit Widget(QWidget* parent = nullptr, Qt::WindowFlags f = Qt::WindowFlags());


    Q_SLOT void image_update(QImage img);

protected:
    void paintEvent(QPaintEvent* e) override;

    QPoint window_to_img(QPoint p);

    QPoint img_to_window(QPoint p);


    QImage m_img;

};


}