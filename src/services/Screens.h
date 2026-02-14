/*
 * ============================================================================
 * Screens.h — UI/Console display and main application loop
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   Screens is the TOP-LEVEL entry point for the user interface.
 *   It handles:
 *     - Welcome screen and bank branding
 *     - Login selection (Client / Employee / Admin)
 *     - Login form display
 *     - Invalid input messages
 *     - Logout screen
 *     - The main application loop (runApp)
 *
 *   This is the PRESENTATION LAYER — it only deals with what the user
 *   sees on the console. It delegates all business logic to the
 *   Manager classes.
 *
 * DESIGN DECISIONS:
 *   - All static: No state. Pure display and routing functions.
 *
 *   - runApp() is the main loop: Called from main() once.
 *     It loops: show welcome → login → route to manager → repeat.
 *
 *   - loginAs() returns int: 1 = Client, 2 = Employee, 3 = Admin.
 *     This drives which Manager handles the session.
 *
 *   - loginScreen(int c) delegates to the right Manager::login().
 *
 * LAYER ARCHITECTURE (simple but clear):
 *
 *   main.cpp
 *     └── Screens (UI / presentation)
 *           ├── ClientManager (client workflow)
 *           ├── EmployeeManager (employee workflow)
 *           └── AdminManager (admin workflow)
 *                 ├── Models (Person, Client, Employee, Admin)
 *                 └── Core (FileManager, FilesHelper, Parser)
 *                       └── data/*.txt (persistence)
 *
 *   Dependencies flow DOWNWARD only. Models never depend on Services.
 *   Services never depend on Screens. This is clean architecture.
 *
 * ============================================================================
 */

#ifndef SCREENS_H
#define SCREENS_H

class Screens {
private:
    Screens();

public:
    // --- Display bank name / logo ---
    static void bankName();

    // --- Display welcome message ---
    static void welcome();

    // --- Display login type options (Client/Employee/Admin) ---
    static void loginOptions();

    // --- Get the user's login type choice ---
    // Returns: 1 = Client, 2 = Employee, 3 = Admin
    static int loginAs();

    // --- Display invalid input message ---
    // c = the invalid value entered
    static void invalid(int c);

    // --- Display logout message ---
    static void logout();

    // --- Route to the correct login screen based on user type ---
    // c: 1 = Client login, 2 = Employee login, 3 = Admin login
    static void loginScreen(int c);

    // --- Main application loop ---
    // This is where everything starts. Called from main().
    // Loop: welcome → loginAs → loginScreen → manager loop → repeat
    static void runApp();
};

#endif // SCREENS_H
