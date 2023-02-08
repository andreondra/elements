//
// Created by golas on 29.1.23.
//

#include <memory>
#include <initializer_list>
#include <cstdio>
#include <iostream>
#include "imgui.h"
#include "elements/element.h"
#include "elements/package.h"

class Elements::Package::Impl{

private:
    // The Package will be an owner of the Elements, so it should be a unique pointer.
    std::vector<std::unique_ptr<Elements::Element>> mElements;
    std::string mName;

public:
    Impl(const std::string & name);
    Impl(const Impl & src);
    Impl(Impl && src) noexcept;
    Impl & operator=(Impl src) noexcept;
    ~Impl() noexcept;

    void addElements(std::initializer_list<Elements::Element*> elementList);
    void render();
};

Elements::Package::Impl::Impl(const std::string & name) : mName(name) {
    if(name.length() < 1) throw std::invalid_argument("Package name is empty.");
}

Elements::Package::Impl::Impl(const Impl & src)
 : mName(src.mName) {

    for(auto & pEl : src.mElements) {
        mElements.push_back(std::unique_ptr<Elements::Element>(pEl->clone()));
    }
}

Elements::Package::Impl::Impl(Elements::Package::Impl &&src) noexcept
 : mElements(std::move(src.mElements)),
   mName(std::move(src.mName)) {

}

Elements::Package::Impl & Elements::Package::Impl::operator=(Impl src) noexcept {
    std::swap(mElements, src.mElements);
    return *this;
}

Elements::Package::Impl::~Impl() noexcept = default;

void Elements::Package::Impl::addElements(std::initializer_list<Elements::Element *> elementList) {

    for(auto & el : elementList) {
        mElements.emplace_back(el);
    }
};

void Elements::Package::Impl::render() {

    ImGui::Begin(mName.c_str());
    for (auto & x : mElements) {
        x->render();
    }
    ImGui::End();
}

Elements::Package::Package(const std::string & name)
 : pImpl(std::make_unique<Impl>(name)) { }

Elements::Package::Package(const Elements::Package & src)
 : pImpl(std::make_unique<Impl>(*src.pImpl)) { }

Elements::Package::Package(Elements::Package && src) noexcept
 : pImpl(std::move(src.pImpl)) {

}

Elements::Package &Elements::Package::operator=(Elements::Package src) noexcept {
    std::swap(pImpl, src.pImpl);
    return *this;
}

Elements::Package::~Package() noexcept {}

void Elements::Package::addElements(std::initializer_list<Elements::Element*> elementList) {
    pImpl->addElements(elementList);
}

void Elements::Package::render() {
    pImpl->render();
}
