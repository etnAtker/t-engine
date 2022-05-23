#pragma once

#include "interface.hpp"
#include "i_runtime_module.hpp"

namespace TEngine
{
    interface IApplication : impl IRuntimeModule
    {
    public:
        int initialize() override = 0;
        void finalize() override = 0;

        void tick() override = 0;
        virtual bool is_quit() = 0;
    };
}
