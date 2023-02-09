//
// Created by golas on 9.2.2023
//


#include <memory>
#include <cstdio>
#include "imgui.h"

#include "elements/separator.h"

class Elements::Separator::Impl{

public:
    Impl();
    ~Impl();
    void render();
};

Elements::Separator::Impl::Impl() { }

Elements::Separator::Impl::~Impl() = default;

void Elements::Separator::Impl::render() {
    ImGui::Separator();
}

Elements::Separator::Separator()
 : mpImpl(std::make_unique<Impl>()) { }

Elements::Separator::Separator(const Separator &src)
 : mpImpl(std::make_unique<Impl>(*src.mpImpl)) { }

Elements::Separator::~Separator() {}

void Elements::Separator::render() {
    mpImpl->render();
}

Elements::Element * Elements::Separator::clone() const {
    return new Elements::Separator(*this);
}