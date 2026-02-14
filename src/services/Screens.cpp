/*
 * ============================================================================
 * Screens.cpp — Implementation skeleton for Screens
 * ============================================================================
 */

#include "Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include <iostream>

using namespace std;

// --- Bank Name ---
void Screens::bankName() {
    // TODO: Print a styled bank name. Example:
    //   "==============================="
    //   "     ★  FIFTH STEP BANK  ★     "
    //   "==============================="
}

// --- Welcome ---
void Screens::welcome() {
    // TODO: Print welcome message.
    //   "Welcome to Fifth Step Bank System"
}

// --- Login Options ---
void Screens::loginOptions() {
    // TODO: Print:
    //   "Login as:"
    //   "  1. Client"
    //   "  2. Employee"
    //   "  3. Admin"
    //   "  0. Exit"
}

// --- Login As ---
int Screens::loginAs() {
    // TODO:
    //   1. Call loginOptions().
    //   2. Read user input.
    //   3. Validate input (must be 0, 1, 2, or 3).
    //   4. Return the choice.
}

// --- Invalid ---
void Screens::invalid(int c) {
    // TODO: Print "Invalid choice: <c>. Please try again."
}

// --- Logout ---
void Screens::logout() {
    // TODO: Print "Logged out successfully. Goodbye!"
}

// --- Login Screen ---
void Screens::loginScreen(int c) {
    // TODO:
    //   1. Prompt for id and password.
    //   2. Based on c:
    //      c == 1: Call ClientManager::login(id, password)
    //              If successful, loop ClientManager::clientOptions(client)
    //      c == 2: Call EmployeeManager::login(id, password)
    //              If successful, loop EmployeeManager::employeeOptions(employee)
    //      c == 3: Call AdminManager::login(id, password)
    //              If successful, loop AdminManager::adminOptions(admin)
    //   3. If login fails, print error and return to main menu.
    //
    // PATTERN: The manager loop looks like:
    //   while (ManagerClass::options(ptr)) { }
    //   // When options() returns false, the user chose logout.
}

// --- Run App (Main Loop) ---
void Screens::runApp() {
    // TODO:
    //   1. Call bankName() and welcome().
    //   2. Loop:
    //      a. int choice = loginAs();
    //      b. if (choice == 0) break;  // Exit app
    //      c. loginScreen(choice);
    //      d. logout();
    //   3. Print "Thank you for using Fifth Step Bank!"
    //
    // This is the ENTRY POINT of the entire application.
    // main() only calls Screens::runApp() and nothing else.
}
