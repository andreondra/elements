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
    T *mpTarget;
    std::string mName;

public:
    Impl(T *pTarget, const std::string &name);
    ~Impl();
    void render();
};

template<typename T>
Elements::Number<T>::Impl::Impl(T *pTarget, const std::string &name)
        : mpTarget(pTarget), mName(name) { }

template<typename T>
Elements::Number<T>::Impl::~Impl() = default;

template<>
void Elements::Number<unsigned char>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_U8, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<signed char>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_S8, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<short int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_S16, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned short int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_U16, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_S32, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_U32, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<long int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_S32, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned long int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_U32, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<long long int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_S64, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<unsigned long long int>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_U64, mpTarget, NULL, NULL, "%x", ImGuiInputTextFlags_CharsHexadecimal);
}
template<>
void Elements::Number<float>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_Float, mpTarget, NULL, NULL);
}
template<>
void Elements::Number<double>::Impl::render() {
    ImGui::InputScalar(mName.c_str(), ImGuiDataType_Double, mpTarget, NULL, NULL);
}

template<typename T>
Elements::Number<T>::Number(T *pTarget, const std::string &name)
        : mpImpl(std::make_unique<Impl>(pTarget, name)) { }

template<typename T>
Elements::Number<T>::Number(const Number &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) {

}

template<typename T>
Elements::Number<T>::~Number() {
};

template<typename T>
void Elements::Number<T>::render() {
    mpImpl->render();
}

template<typename T>
Elements::Element * Elements::Number<T>::clone() const {
    return new Elements::Number(*this);
}

