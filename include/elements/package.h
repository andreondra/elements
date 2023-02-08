//
// Created by golas on 29.1.23.
//

#ifndef ELEMENTS_PACKAGE_H
#define ELEMENTS_PACKAGE_H

#include <vector>
#include <memory>
#include <initializer_list>
#include "element.h"

namespace Elements{

    class Package{
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        Package(const std::string & name = "Default package");
        Package(const Package & src);
        Package(Package && src) noexcept;
        Package & operator=(Package src) noexcept;
        ~Package() noexcept;

        void addElements(std::initializer_list<Elements::Element*> elementList);
        void render();
    };
}

#endif //ELEMENTS_PACKAGE_H
