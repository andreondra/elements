//
// Created by golas on 13.2.23.
//

#include <string>
#include <utility>
#include "imgui.h"
#include "elements/text.h"
#include <iostream>

class Elements::Text::Impl{

private:
    std::function<std::string (void)> getter;

public:
    explicit Impl(const std::string & text);
    explicit Impl(std::function<std::string (void)> getter);
    ~Impl() = default;
    void render();
};

Elements::Text::Impl::Impl(const std::string & text)
        : getter([text](){
            return text;
        }) {

    if(text.empty()) throw std::invalid_argument("Text is empty.");
}

Elements::Text::Impl::Impl(std::function<std::string (void)> getter)
    : getter(std::move(getter)) { }

void Elements::Text::Impl::render() {
    ImGui::Text("%s", getter().c_str());
}

Elements::Text::Text(const std::string & text)
        : mpImpl(std::make_unique<Impl>(text)) { }

Elements::Text::Text(const std::function<std::string (void)> & getter)
        : mpImpl(std::make_unique<Impl>(getter)) { }

Elements::Text::Text(const Text &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) { }

void Elements::Text::render() {
    mpImpl->render();
}

Elements::Element * Elements::Text::clone() const {
    return new Elements::Text(*this);
}