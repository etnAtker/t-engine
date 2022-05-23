#pragma once

#include "i_runtime_module.hpp"

namespace TEngine
{
    class GraphicsManager: impl IRuntimeModule
    {
    public:
        ~GraphicsManager() override = default;
    };
}
