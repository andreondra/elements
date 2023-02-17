//
// Created by golas on 21.12.22.
//

#include "elements/element.h"
#include "elements/number.h"
#include "elements/separator.h"
#include "elements/package.h"
#include "elements/app.h"
#include "elements/types.h"
#include "elements/display.h"
#include "elements/bool.h"
#include "elements/memory.h"
#include "elements/text.h"
#include <array>
#include <cstdlib>

int main(int argc, char** argv) {

    uint8_t number8 = INT8_MAX;
    uint16_t number16 = INT16_MAX;
    uint32_t number32 = INT32_MAX;
    int numberInt = 45644651;
    int64_t number64 = INT64_MAX;
    double numberDbl = 4.20;

    srand(clock());
    std::array<uint8_t, 200 * 200 * 4> rawPixels{};

    uint8_t pal[] = {255, 0, 0, 255};
    int idx = 0;

    for(auto & px : rawPixels) {
        px = pal[idx];
        idx = (idx + 1) % 4;
    }

    uint8_t memory[] = {0x00, 0x01, 0x10, 0x11, 0xaa, 0xff, 0xba, 0xba};

    bool exampleBoolean = false;
    Elements::Types::PixelData pixeldata(200, 200, rawPixels.data(), Elements::Types::PixelData::ByteArrayRGBAToPixel);

    Elements::Package pkg("Test package");
    pkg.addElements({
        new Elements::Text("Example plain text"),
        new Elements::Number("Number 8", &number8),
        new Elements::Number("Number 16", &number16),
        new Elements::Number("Number 32", &number32),
        new Elements::Number("Number Int", &numberInt),
        new Elements::Number("Number 64", &number64),
        new Elements::Separator(),
        new Elements::Number("Number dbl", &numberDbl),
        new Elements::Separator(),
        new Elements::Bool("Check me!", &exampleBoolean),
        new Elements::Separator(),
        new Elements::Memory("Example memory view", memory, sizeof(memory), 0, false),
        new Elements::Separator(),
        new Elements::Display("Display Example", pixeldata, true)
    });

    Elements::App app;
    app.addPackage(pkg);
    app.run();

    return 0;
}