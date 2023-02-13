//
// Created by golas on 13.2.23.
//

#include <string>
#include "imgui.h"
#include "elements/bool.h"

class Elements::Bool::Impl{

private:
    std::string name;
    bool *target;

public:
    Impl(const std::string & name, bool *target);
    ~Impl() = default;
    void render();
};

Elements::Bool::Impl::Impl(const std::string & name, bool *target)
        : name(name), target(target) {

    if(name.empty()) throw std::invalid_argument("Name is empty.");
}

void Elements::Bool::Impl::render() {
    ImGui::Checkbox(name.c_str(), target);
}

Elements::Bool::Bool(const std::string & name, bool * target)
        : mpImpl(std::make_unique<Impl>(name, target)) { }

Elements::Bool::Bool(const Bool &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) { }

void Elements::Bool::render() {
    mpImpl->render();
}

Elements::Element * Elements::Bool::clone() const {
    return new Elements::Bool(*this);
}