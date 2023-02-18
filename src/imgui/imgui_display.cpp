//
// Created by golas on 12.2.23.
//

#include <stdexcept>
#include "elements/display.h"
#include "elements/types.h"
#include "imgui.h"

class Elements::Display::Impl{

private:
    std::string name;
    Types::PixelData image;
    bool scalable;
    float scale = 1.0f;

public:
    Impl(const std::string & name, const Types::PixelData & data, bool scalable);
    ~Impl() = default;
    void render();
};

Elements::Display::Impl::Impl(const std::string & name, const Types::PixelData & data, bool scalable)
 : name(name), image(data), scalable(scalable) {

    if(name.empty()) throw std::invalid_argument("Name length is zero.");
}

void Elements::Display::Impl::render() {

    ImGui::Text("%s", name.c_str());

    if(scalable) {
        ImGui::SliderFloat("Scale", &scale, 1.0, 10.0);
    }

    ImDrawList * dl = ImGui::GetWindowDrawList();
    const ImVec2 defaultScreenPos = ImGui::GetCursorScreenPos();

    for(size_t imageX = 0; imageX < image.getWidth(); imageX++) {
        for(size_t imageY = 0; imageY < image.getHeight(); imageY++) {

            ImColor color = ImColor(
                image.getPixel(imageX, imageY).r,
                image.getPixel(imageX, imageY).g,
                image.getPixel(imageX, imageY).b,
                image.getPixel(imageX, imageY).a
            );

            float screenX = defaultScreenPos.x + scale * static_cast<float>(imageX);
            float screenY = defaultScreenPos.y + scale * static_cast<float>(imageY);
            dl->AddRectFilled({screenX, screenY}, {screenX + scale, screenY + scale}, color);
        }
    }

    float dummyWidth = scale * static_cast<float>(image.getWidth());
    float dummyHeight = scale * static_cast<float>(image.getHeight());
    // Dummy widget is needed for scrollbars to work and to allow to place more elements below correctly.
    ImGui::Dummy({dummyWidth, dummyHeight});
}

Elements::Display::Display(const std::string & name, const Types::PixelData & data, bool scalable)
        : mpImpl(std::make_unique<Impl>(name, data, scalable)) { }

Elements::Display::Display(const Display &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) { }

void Elements::Display::render() {
    mpImpl->render();
}

Elements::Element * Elements::Display::clone() const {
    return new Elements::Display(*this);
}