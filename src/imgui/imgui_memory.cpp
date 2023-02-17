//
// Created by golas on 13.2.23.
//

#include <string>
#include "imgui.h"
#include "imgui_memory_editor.h"
#include "elements/memory.h"

class Elements::Memory::Impl{

private:
    std::string name;
    unsigned char *target;
    size_t size;
    size_t offset;
    bool readOnly;
    MemoryEditor memEdit;

public:
    Impl(const std::string & name, unsigned char *target, size_t size, size_t offset, bool readOnly);
    ~Impl() = default;
    void render();
};

Elements::Memory::Impl::Impl(const std::string & name, unsigned char *target, size_t size, size_t offset, bool readOnly)
        : name(name), target(target), size(size), offset(offset), readOnly(readOnly) {

    if(name.empty()) throw std::invalid_argument("Name is empty.");
}

void Elements::Memory::Impl::render() {
    memEdit.DrawContents(target, size, offset);
}

Elements::Memory::Memory(const std::string & name, unsigned char *target, size_t size, size_t offset, bool readOnly)
        : mpImpl(std::make_unique<Impl>(name, target, size, offset, readOnly)) { }

Elements::Memory::Memory(const Memory &src)
        : mpImpl(std::make_unique<Impl>(*src.mpImpl)) { }

void Elements::Memory::render() {
    mpImpl->render();
}

Elements::Element * Elements::Memory::clone() const {
    return new Elements::Memory(*this);
}