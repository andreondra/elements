//
// Created by golas on 10.2.23.
//

#ifndef ELEMENTS_DISPLAY_H
#define ELEMENTS_DISPLAY_H

#include <string>
#include <memory>
#include <functional>
#include "element.h"
#include "elements/types.h"

namespace Elements{

    /**
     * An element for rendering raw RGBA pixel data. Usable for textures, small video outputs etc.
     * Read-only.
     */
    class Display : public Element{
    private:
        class Impl;
        // Only for cloning purposes.
        Display(const Display & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Display(const std::string & name, const Types::PixelData & data, bool scalable = false);
        ~Display() override = default;

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_DISPLAY_H
