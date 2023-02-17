//
// Created by golas on 13.2.23.
//

#ifndef ELEMENTS_TEXT_H
#define ELEMENTS_TEXT_H

#include <memory>
#include "element.h"

namespace Elements{

    /**
     * An element representing a plain text.
     */
    class Text : public Element{
    private:
        class Impl;
        // Only for cloning purposes.
        Text(const Text & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Text(const std::string & text);
        ~Text() override = default;

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_TEXT_H
