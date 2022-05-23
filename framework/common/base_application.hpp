#pragma once

#include "i_application.hpp"

namespace TEngine
{
    class BaseApplication: impl IApplication
    {
        public:
        virtual int initialize();
        virtual void finalize();

        virtual void tick();

        virtual bool is_quit();

        protected:
        bool m_b_quit;
    };
}
