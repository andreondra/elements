//
// Created by golas on 21.12.22.
//


#include <memory>
#include <cstdio>
#include "imgui.h"

#include "elements/number.h"

template class Elements::Number<signed char>;
template class Elements::Number<unsigned char>;
template class Elements::Number<short int>;
template class Elements::Number<unsigned short int>;
template class Elements::Number<int>;
template class Elements::Number<unsigned int>;
template class Elements::Number<long int>;
template class Elements::Number<unsigned long int>;
template class Elements::Number<long long int>;
template class Elements::Number<unsigned long long int>;
template class Elements::Number<float>;
template class Elements::Number<double>;

template<typename T>
class Elements::Number<T>::Impl{

private:
    std::string name;
    T *target;

public:
    Impl(const std::string &name, T *target);
    ~Impl();
    void render();
};

template<typename T>
Elements::Number<T>::Impl::Impl(const std::string &name, T *target)
        : name(name), target(target) { }

template<typename T>
Elements::Number<T>::Impl::~Impl() = default;

template<>
void Elements::Number<unsigned char>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_U8, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<signed char>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_S8, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<short int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_S16, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned short int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_U16, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_S32, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_U32, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<long int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_S32, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned long int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_U32, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<long long int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_S64, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned long long int>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_U64, target, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<float>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_Float, target, NULL, NULL);
}
template<>
void Elements::Number<double>::Impl::render() {
    ImGui::InputScalar(name.c_str(), ImGuiDataType_Double, target, NULL, NULL);
}

template<typename T>
Elements::Number<T>::Number(const std::string &name, T *target)
        : mpImpl(std::make_unique<Impl>(name, target)) { }

template<typename T>
Elements::Number<T>::Number(const Number &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) {

}

template<typename T>
Elements::Number<T>::~Number() = default;

template<typename T>
void Elements::Number<T>::render() {
    mpImpl->render();
}

template<typename T>
Elements::Element * Elements::Number<T>::clone() const {
    return new Elements::Number(*this);
}
