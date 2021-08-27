#pragma once

#include <QImage>


class ImageTransformer : public QObject
{
    Q_OBJECT

public:
    Q_SIGNAL void image_rdy(QImage img);

    Q_SLOT void image_update(QImage img);

};
