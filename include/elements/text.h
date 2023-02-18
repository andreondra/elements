//
// Created by golas on 13.2.23.
//

#ifndef ELEMENTS_TEXT_H
#define ELEMENTS_TEXT_H

#include <memory>
#include <functional>
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
        explicit Text(const std::string & text);
        explicit Text(const std::function<std::string (void)> & getter);
        ~Text() override = default;

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_TEXT_H
