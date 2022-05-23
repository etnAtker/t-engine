#pragma once

#include "interface.hpp"
#include "i_runtime_module.hpp"

namespace TEngine{
    interface IApplication: impl IRuntimeModule
    {
        public:
        virtual int initialize() = 0;
        virtual void finalize() = 0;

        virtual void tick() = 0;
        
        virtual bool is_quit() = 0;
    };
}
