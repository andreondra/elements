//
// Created by golas on 21.12.22.
//

#include "elements/element.h"
#include "elements/number.h"
#include "elements/separator.h"
#include "elements/package.h"
#include "elements/app.h"

int main(int argc, char** argv) {

    uint8_t number8 = INT8_MAX;
    uint16_t number16 = INT16_MAX;
    uint32_t number32 = INT32_MAX;
    int numberInt = 45644651;
    int64_t number64 = INT64_MAX;
    double numberDbl = 4.20;

    Elements::Package pkg("Test package");
    pkg.addElements({
        new Elements::Number(&number8, "Number 8"),
        new Elements::Number(&number16, "Number 16"),
        new Elements::Number(&number32, "Number 32"),
        new Elements::Separator(),
        new Elements::Number(&numberInt, "Number Int"),
        new Elements::Number(&number64, "Number 64"),
        new Elements::Separator(),
        new Elements::Number(&numberDbl, "Number dbl")
    });

    Elements::App app;
    app.addPackage(pkg);
    app.run();

    return 0;
}