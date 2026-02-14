/*
 * ============================================================================
 * AdminManager.cpp — Implementation skeleton for AdminManager
 * ============================================================================
 */

#include "AdminManager.h"
#include "../models/Admin.h"
#include "../models/Employee.h"
#include "../models/Client.h"
#include "../core/FilesHelper.h"
#include "../core/Parser.h"
#include <iostream>

using namespace std;

// --- Print Admin Menu ---
void AdminManager::printAdminMenu() {
    // TODO: Print menu combining client AND employee management:
    //   --- Client Management ---
    //   1. Add New Client
    //   2. List All Clients
    //   3. Search Client
    //   4. Edit Client
    //   --- Employee Management ---
    //   5. Add New Employee
    //   6. List All Employees
    //   7. Search Employee
    //   8. Edit Employee
    //   --- Account ---
    //   9. Display My Info
    //   10. Logout
}

// --- Login ---
Admin* AdminManager::login(int id, const string& password) {
    // TODO: Same pattern as other login methods.
    // Read from admins.txt, parse, match id+password.
}

// --- Admin Options ---
bool AdminManager::adminOptions(Admin* admin) {
    // TODO:
    //   1. Call printAdminMenu().
    //   2. Read choice.
    //   3. Switch:
    //      Cases 1-4: Client operations (reuse Employee methods on admin)
    //        admin->addClient(), admin->searchClient(), etc.
    //      Cases 5-8: Employee operations
    //        admin->addEmployee(), admin->searchEmployee(), etc.
    //      Case 9: admin->display()
    //      Case 10: return false (logout)
    //   4. Return true.
    //
    // MENTOR NOTE: Since Admin inherits from Employee, you can call
    // all client management methods directly on admin. This is the
    // payoff of the inheritance chain Person → Employee → Admin.
}
