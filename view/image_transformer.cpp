#include "image_transformer.h"

#include <complex>


namespace engine {


using namespace std::complex_literals;


void ImageTransformer::image_update(QImage img)
{
    QImage new_img(img.size(), img.format());

    double w = img.width();
    double h = img.height();

    for (int x = 0; x < w; ++x) {
        for (int y = 0; y < h; ++y) {
            if (img.pixelColor(x, y).alpha() == 0) {
                continue;
            }

            std::complex<double> z(x - w / 2.0, h / 2.0 - y);
            std::complex<double> res = std::pow(z, 2.0) / 200.0;

            int res_x = res.real() + w / 2.0;
            int res_y = -res.imag() + h / 2.0;
            if (res_x < 0 || res_x >= w) {
                continue;
            }
            if (res_y < 0 || res_y >= h) {
                continue;
            }

            new_img.setPixelColor(res_x, res_y, img.pixelColor(x, y));
        }
    }

    emit image_rdy(std::move(new_img));
}


}
