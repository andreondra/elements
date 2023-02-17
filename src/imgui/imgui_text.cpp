//
// Created by golas on 13.2.23.
//

#include <string>
#include "imgui.h"
#include "elements/text.h"

class Elements::Text::Impl{

private:
    std::string text;

public:
    Impl(const std::string & text);
    ~Impl() = default;
    void render();
};

Elements::Text::Impl::Impl(const std::string & text)
        : text(text) {

    if(text.empty()) throw std::invalid_argument("Text is empty.");
}

void Elements::Text::Impl::render() {
    ImGui::Text(text.c_str());
}

Elements::Text::Text(const std::string & text)
        : mpImpl(std::make_unique<Impl>(text)) { }

Elements::Text::Text(const Text &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) { }

void Elements::Text::render() {
    mpImpl->render();
}

Elements::Element * Elements::Text::clone() const {
    return new Elements::Text(*this);
}