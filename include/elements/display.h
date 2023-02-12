//
// Created by golas on 10.2.23.
//

#ifndef ELEMENTS_DISPLAY_H
#define ELEMENTS_DISPLAY_H

#include <string>
#include <memory>
#include <functional>
#include "element.h"

namespace Elements{



    /**
     * An element for rendering raw RGBA pixel data. Usable for textures, small video outputs etc.
     * Read-only.
     */
    class Display : public Element{
    private:
        class Impl;
        // Only for cloning purposes.
        Display(const Separator & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Display(const std::string & name, PixelData data);
        ~Display();

        void render() override;
        Element *clone() const override;
    };
}

#endif //ELEMENTS_DISPLAY_H
