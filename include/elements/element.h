//
// Created by golas on 21.12.22.
//

#ifndef ELEMENTS_ELEMENT_H
#define ELEMENTS_ELEMENT_H

namespace Elements{

    class Element{
    public:
        Element() = default;
        virtual ~Element() = default;

        virtual void render() = 0;
        virtual Element * clone() const = 0;
    };
}

#endif //ELEMENTS_ELEMENT_H