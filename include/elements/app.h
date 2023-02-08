//
// Created by golas on 29.1.23.
//

#ifndef ELEMENTS_APP_H
#define ELEMENTS_APP_H

#include <initializer_list>
#include <memory>
#include <string>
#include "package.h"

namespace Elements {

    class App{
    private:
        class Impl;
        std::unique_ptr<Impl> pImpl;

    public:
        App(const std::string & name = "Elements Application");
        ~App() noexcept;

        void addPackage(Elements::Package && package);
        void addPackage(const Elements::Package & package);

        void run();
    };
};

#endif //ELEMENTS_APP_H
