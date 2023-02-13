//
// Created by golas on 13.2.23.
//

#ifndef ELEMENTS_BOOL_H
#define ELEMENTS_BOOL_H

#include <memory>
#include "elements/element.h"

namespace Elements{

    /**
     * An element representing a boolean value. Usually presented as a checkbox.
     */
    class Bool : public Element{
    private:
        class Impl;
        // Only for cloning purposes.
        Bool(const Bool & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Bool(const std::string & name, bool *target);
        ~Bool() override = default;

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_BOOL_H
