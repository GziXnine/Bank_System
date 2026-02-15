/*
 * ============================================================================
 * main.cpp — Application entry point
 * ============================================================================
 *
 * This file should be MINIMAL. Its only job is to start the application.
 * All logic lives in the classes.
 *
 * WHY so minimal?
 *   In your Day 6 main1.cpp, you had 50+ lines creating objects and
 *   calling methods. That's fine for learning. In a real project,
 *   main() is a single function call. Everything is organized in classes.
 *
 * ============================================================================
 */

#include "services/Screens.h"
#ifdef _WIN32
#include <windows.h>
#endif

int main()
{
#ifdef _WIN32
    // Set Windows console to UTF-8 for proper box-drawing characters
    SetConsoleOutputCP(65001);
#endif

    // Single entry point — Screens handles everything.
    Screens::runApp();
    return 0;
}
