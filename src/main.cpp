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

int main() {
    // Single entry point — Screens handles everything.
    Screens::runApp();
    return 0;
}
