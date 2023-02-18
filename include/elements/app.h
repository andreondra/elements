//
// Created by golas on 29.1.23.
//

#ifndef ELEMENTS_APP_H
#define ELEMENTS_APP_H

#include <initializer_list>
#include <memory>
#include <string>
#include "package.h"
#include "types.h"

namespace Elements {

    class App{
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        explicit App();
        ~App() noexcept;

        App & setName(const std::string & name);
        App & setWindowSize(Types::Size size);
        App & setDocking(bool enabled);
        App & setLeftDock(bool enabled);
        App & setBottomDock(bool enabled);
        App & setRightDock(bool enabled);

        App & addPackage(Elements::Package && package);
        App & addPackage(const Elements::Package & package);

        void run();
    };
};

#endif //ELEMENTS_APP_H
