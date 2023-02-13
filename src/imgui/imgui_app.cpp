//
// Created by golas on 29.1.23.
//

#include <memory>
#include <vector>
#include <string>
#include "immapp/immapp.h"
#include "imgui.h"
#include "elements/app.h"


class Elements::App::Impl {

private:
    std::string mName;
    int width, height;
    std::vector<Elements::Package> mPackages;

    void mainLoop();

public:
    Impl(const std::string & name, int width, int height);
    ~Impl() noexcept;

    void addPackage(Elements::Package && package);
    void addPackage(const Elements::Package & package);

    void run();
};

Elements::App::Impl::Impl(const std::string &name, int width, int height)
 : mName(name), width(width), height(height) {

}

Elements::App::Impl::~Impl() noexcept {}

void Elements::App::Impl::addPackage(Elements::Package && package) {
    mPackages.push_back(std::move(package));
}

void Elements::App::Impl::addPackage(const Elements::Package & package) {
    mPackages.push_back(package);
}

void Elements::App::Impl::run() {

    ImmApp::Run(
        [&](){
            mainLoop();
        },
        mName,
        false,
        true,
        {width, height}
    );
}

void Elements::App::Impl::mainLoop() {

    for(auto & package : mPackages) {
        package.render();
    }
}

Elements::App::App(const std::string &name, int width, int height)
 : pImpl(std::make_unique<Impl>(name, width, height)) { }

Elements::App::~App() noexcept { }

void Elements::App::addPackage(Elements::Package && package) {
    pImpl->addPackage(std::move(package));
}

void Elements::App::addPackage(const Elements::Package & package) {
    pImpl->addPackage(package);
}

void Elements::App::run() {
    pImpl->run();
}