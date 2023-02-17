//
// Created by golas on 13.2.23.
//

#ifndef ELEMENTS_MEMORY_H
#define ELEMENTS_MEMORY_H

#include <memory>
#include "element.h"

namespace Elements{

    /**
     * An element representing a boolean value. Usually presented as a checkbox.
     */
    class Memory : public Element{
    private:
        class Impl;
        // Only for cloning purposes.
        Memory(const Memory & src);
        std::unique_ptr<Impl> mpImpl;

    public:
        Memory(const std::string & name, unsigned char *target, size_t size, size_t offset, bool readOnly = false);
        ~Memory() override = default;

        void render() override;
        [[nodiscard]] Element *clone() const override;
    };
}

#endif //ELEMENTS_MEMORY_H
