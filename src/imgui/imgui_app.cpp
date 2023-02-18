//
// Created by golas on 29.1.23.
//

#include <memory>
#include <vector>
#include <string>
#include <array>
#include "immapp/immapp.h"
#include "imgui.h"
#include "elements/app.h"
#include "elements/types.h"

namespace Elements {

    class App::Impl {

    private:
        std::string name = "Elements Application";
        Types::Size size = {640, 480};
        struct {
            bool docking    = false;
            bool left       = false;
            bool right      = false;
            bool bottom     = false;
        } dockParams;

        std::vector<Package> mPackages;
        std::array<std::string, 4> dockNames = {
            "MainDockSpace",
            "LeftSpace",
            "BottomSpace",
            "RightSpace"
        };

        void mainLoop();

    public:
        Impl();
        ~Impl() noexcept;

        void setName(const std::string & name);
        void setWindowSize(Types::Size size);
        void setDocking(bool enabled);
        void setLeftDock(bool enabled);
        void setRightDock(bool enabled);
        void setBottomDock(bool enabled);

        void addPackage(Package && package);
        void addPackage(const Package & package);

        void run();
    };

    App::Impl::Impl() { }

    App::Impl::~Impl() noexcept {}

    void App::Impl::addPackage(Package && package) {
        mPackages.push_back(std::move(package));
    }

    void App::Impl::addPackage(const Package & package) {
        mPackages.push_back(package);
    }

    void App::Impl::run() {

        HelloImGui::RunnerParams par;
        par.appWindowParams.windowTitle = name;
        par.appWindowParams.windowGeometry.size = {size.width, size.height};
        par.imGuiWindowParams.showMenuBar = false;
        par.appWindowParams.restorePreviousGeometry = false;

        if (dockParams.docking) {

            par.imGuiWindowParams.defaultImGuiWindowType = HelloImGui::DefaultImGuiWindowType::ProvideFullScreenDockSpace;
            par.imGuiWindowParams.enableViewports = false;
            par.dockingParams.layoutCondition = HelloImGui::DockingLayoutCondition::ApplicationStart;

            if(dockParams.left) {
                HelloImGui::DockingSplit splitLeft;
                splitLeft.initialDock = dockNames[static_cast<int>(Types::Dock::DEFAULT)];
                splitLeft.newDock = dockNames[static_cast<int>(Types::Dock::LEFT)];
                splitLeft.direction = ImGuiDir_Left;
                splitLeft.ratio = 0.25f;

                par.dockingParams.dockingSplits.push_back(splitLeft);
            }

            if(dockParams.bottom) {
                HelloImGui::DockingSplit splitBottom;
                splitBottom.initialDock = dockNames[static_cast<int>(Types::Dock::DEFAULT)];
                splitBottom.newDock = dockNames[static_cast<int>(Types::Dock::BOTTOM)];
                splitBottom.direction = ImGuiDir_Down;
                splitBottom.ratio = 0.25f;

                par.dockingParams.dockingSplits.push_back(splitBottom);
            }

            if(dockParams.right) {
                HelloImGui::DockingSplit splitRight;
                splitRight.initialDock = dockNames[static_cast<int>(Types::Dock::DEFAULT)];
                splitRight.newDock = dockNames[static_cast<int>(Types::Dock::RIGHT)];
                splitRight.direction = ImGuiDir_Right;
                splitRight.ratio = 0.25f;

                par.dockingParams.dockingSplits.push_back(splitRight);
            }

            for(auto & pkg : mPackages) {

                HelloImGui::DockableWindow window;
                window.label = pkg.getName();
                window.dockSpaceName = dockNames[static_cast<int>(pkg.getDefaultDock())];
                window.GuiFunction = [&](){pkg.render();};

                par.dockingParams.dockableWindows.push_back(window);
            }

        } else {
            par.callbacks.ShowGui = [&](){mainLoop();};
        }

        ImmApp::Run(par);
    }

    void App::Impl::mainLoop() {

        for(auto & package : mPackages) {
            package.render();
        }
    }

    void App::Impl::setName(const std::string & name) {
        this->name = name;
    }

    void App::Impl::setWindowSize(Types::Size size) {
        this->size = size;
    }

    void App::Impl::setDocking(bool enabled) {
        dockParams.docking = enabled;
    }

    void App::Impl::setLeftDock(bool enabled) {
        dockParams.left = enabled;
    }

    void App::Impl::setRightDock(bool enabled) {
        dockParams.right = enabled;
    }

    void App::Impl::setBottomDock(bool enabled) {
        dockParams.bottom = enabled;
    }

    App::App()
     : pImpl(std::make_unique<Impl>()) { }

    App::~App() noexcept { }

    App & App::setName(const std::string &name) {
        pImpl->setName(name);
        return *this;
    }

    App & App::setWindowSize(Types::Size size) {
        pImpl->setWindowSize(size);
        return *this;
    }

    App & App::setDocking(bool enabled) {
        pImpl->setDocking(enabled);
        return *this;
    }

    App & App::setLeftDock(bool enabled) {
        pImpl->setLeftDock(enabled);
        return *this;
    }

    App & App::setBottomDock(bool enabled) {
        pImpl->setBottomDock(enabled);
        return *this;
    }

    App & App::setRightDock(bool enabled) {
        pImpl->setRightDock(enabled);
        return *this;
    }

    App & App::addPackage(Package && package) {
        pImpl->addPackage(std::move(package));
        return *this;
    }

    App & App::addPackage(const Package & package) {
        pImpl->addPackage(package);
        return *this;
    }

    void App::run() {
        pImpl->run();
    }

}