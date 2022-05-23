#include "base_application.hpp"

// Parse command line, read configuration, initialize all sub modules.
int TEngine::BaseApplication::initialize()
{
    m_b_quit = false;
    return 0;
}

// Finalize all sub modules and clean up all runtime temporary files.
void TEngine::BaseApplication::finalize()
{
}

// Run one cycle.
void TEngine::BaseApplication::tick()
{
}

bool TEngine::BaseApplication::is_quit()
{
    return m_b_quit;
}
