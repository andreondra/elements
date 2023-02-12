//
// Created by golas on 8.2.23.
//

#ifndef ELEMENTS_SEPARATOR_H
#define ELEMENTS_SEPARATOR_H

#include <memory>
#include "element.h"

namespace Elements{

    class Separator : public Element{
    private:
        class Impl;
        // Only for cloning purposes.
        Separator(const Separator & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Separator();
        ~Separator();

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_SEPARATOR_H
