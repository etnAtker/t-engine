#include <iostream>
#include "i_application.hpp"

using namespace TEngine;

namespace TEngine
{
    extern IApplication* g_p_app;
}

int main()
{
    int ret = 0;

    // Initialize.
    if ((ret = g_p_app->initialize()) != 0) {
        std::cout << "Application initialize failed." << std::endl;
    }

    // Enter main loop.
    while (!g_p_app->is_quit()) {
        g_p_app->tick();
    }

    // Clean and quit.
    g_p_app->finalize();
    return 0;
}
