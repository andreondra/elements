//
// Created by golas on 10.2.23.
//

#ifndef ELEMENTS_TYPES_H
#define ELEMENTS_TYPES_H

#include <functional>
#include <cstddef>

namespace Elements::Types{

    struct Pixel{

        Pixel() = default;
        Pixel(unsigned char r, unsigned char g, unsigned char b, unsigned char a);

        unsigned char r = 0;
        unsigned char g = 0;
        unsigned char b = 0;
        unsigned char a = 0;
    };

    /**
     * An interface for accessing raw image data in various representations in a C++ type-safe way.
     * Reasons for implementing separate class:
     * - there could be a lot of representations (RGBA, RGB, GBRA...) stored in a lot of ways,
     * - not all image data are stored in a raw form that could be easily retrieved,
     * - it is not possible to force users to convert their data to one supported format,
     * - the class can be reused in different elements.
     */
    class PixelData{
    private:
        size_t width;
        size_t height;
        const void *rawData;
        std::function<Types::Pixel(const void *rawData, size_t x, size_t y, size_t width, size_t height)> adapter;

    public:
        PixelData(size_t width,
                  size_t height,
                  const void *rawData,
                  std::function<Types::Pixel(const void *rawData, size_t x, size_t y, size_t width, size_t height)> dataAdapter);

        static Types::Pixel ByteArrayRGBAToPixel(const void *rawData, size_t x, size_t y, size_t width, size_t height);
        static Types::Pixel ByteVectorRGBAToPixel(const void *rawData, size_t x, size_t y, size_t width, size_t height);

        [[nodiscard]] Pixel getPixel(size_t x, size_t y) const;
    };
}

#endif //ELEMENTS_TYPES_H
