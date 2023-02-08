//
// Created by golas on 21.12.22.
//

#ifndef ELEMENTS_NUMBER_H
#define ELEMENTS_NUMBER_H

#include "element.h"
#include <string>
#include <cstdint>
#include <memory>

namespace Elements{

    template<typename T>
    class Number : public Element {

    private:
        class Impl;
        // Only for cloning purposes.
        Number(const Number & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Number(T *pTarget, std::string const& name = "");
        ~Number();

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_NUMBER_H
