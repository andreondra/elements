//
// Created by golas on 29.1.23.
//

#ifndef ELEMENTS_PACKAGE_H
#define ELEMENTS_PACKAGE_H

#include <vector>
#include <memory>
#include <initializer_list>
#include "element.h"
#include "types.h"

namespace Elements{

    class Package{
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        Package(const std::string & name = "Default package", Types::Dock defaultDock = Types::Dock::DEFAULT);
        Package(const Package & src);
        Package(Package && src) noexcept;
        Package & operator=(Package src) noexcept;
        ~Package() noexcept;

        void addElements(std::initializer_list<Elements::Element*> elementList);
        [[nodiscard]] std::string getName() const;
        [[nodiscard]] Types::Dock getDefaultDock() const;

        void render();
    };
}

#endif //ELEMENTS_PACKAGE_H
