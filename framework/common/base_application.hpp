#pragma once

#include "i_application.hpp"

namespace TEngine
{
    class BaseApplication : impl IApplication
    {
    public:
        int initialize() override;
        void finalize() override;

        void tick() override;
        bool is_quit() override;

    protected:
        bool m_b_quit{};
    };
}
