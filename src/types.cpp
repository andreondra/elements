//
// Created by golas on 10.2.23.
//

#include "elements/types.h"
#include <stdexcept>
#include <utility>

namespace Elements::Types {

    Pixel::Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a)
    : r(r), g(g), b(b), a(a) {}

    PixelData::PixelData(size_t width,
                         size_t height,
                         const void *rawData,
                         std::function<Types::Pixel(const void *, size_t, size_t, size_t, size_t)> dataAdapter)
                         : width(width), height(height), rawData(rawData), adapter(std::move(dataAdapter)) {}

    Pixel PixelData::getPixel(size_t x, size_t y) const{

        if( x + 1 > width ||
            y + 1 > height
        ) {
            throw std::invalid_argument("Pixel position out of bounds.");
        }

        return adapter(rawData, x, y, width, height);
    }

    size_t PixelData::getWidth() const {
        return width;
    }

    size_t PixelData::getHeight() const {
        return height;
    }

    Pixel PixelData::ByteArrayRGBAToPixel(const void *rawData, size_t x, size_t y, size_t width, size_t height) {

        auto *pRawData = static_cast<const unsigned char*>(rawData);
        const size_t pixelPos = x * 4 + width * 4;

        return {
            pRawData[pixelPos],
            pRawData[pixelPos + 1],
            pRawData[pixelPos + 2],
            pRawData[pixelPos + 3]
        };
    }

    Pixel PixelData::ByteVectorRGBAToPixel(const void *rawData, size_t x, size_t y, size_t width, size_t height) {

        auto *pRawData = static_cast<const unsigned char *const *>(rawData);
        const size_t xPos = x * 4;
        const size_t yPos = y * 4;

        return {
            pRawData[xPos    ][yPos],
            pRawData[xPos + 1][yPos],
            pRawData[xPos + 2][yPos],
            pRawData[xPos + 3][yPos],
        };
    }
}

