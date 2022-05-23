#pragma once

#include "interface.hpp"

namespace TEngine
{
    interface IRuntimeModule
    {
        public:
        virtual ~IRuntimeModule() {}

        virtual int initialize() = 0;
        virtual void finalize() = 0;

        virtual void tick() = 0;
    };
}
