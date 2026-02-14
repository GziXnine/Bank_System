/*
 * ============================================================================
 * EmployeeManager.cpp — Implementation skeleton for EmployeeManager
 * ============================================================================
 */

#include "EmployeeManager.h"
#include "../models/Employee.h"
#include "../models/Client.h"
#include "../core/FilesHelper.h"
#include "../core/Parser.h"
#include "../utils/Validation.h"
#include <iostream>

using namespace std;

// --- Print Employee Menu ---
void EmployeeManager::printEmployeeMenu() {
    // TODO: Print menu:
    //   1. Add New Client
    //   2. List All Clients
    //   3. Search Client
    //   4. Edit Client
    //   5. Display My Info
    //   6. Logout
}

// --- New Client ---
void EmployeeManager::newClient(Employee* employee) {
    // TODO:
    //   1. Prompt for client name, password, initial balance.
    //   2. Validate all inputs using Validation.
    //   3. Generate new ID (using FilesHelper::getLast + 1).
    //   4. Create Client object.
    //   5. Add to employee's client list via employee->addClient().
    //   6. Save to file via FileManager or FilesHelper.
}

// --- List All Clients ---
void EmployeeManager::listAllClients(Employee* employee) {
    // TODO: Call employee->listClient().
}

// --- Search For Client ---
void EmployeeManager::searchForClient(Employee* employee) {
    // TODO:
    //   1. Prompt for client id.
    //   2. Call employee->searchClient(id).
    //   3. If found, display client info.
    //   4. If not, print "Client not found."
}

// --- Edit Client Info ---
void EmployeeManager::editClientInfo(Employee* employee) {
    // TODO:
    //   1. Prompt for client id to edit.
    //   2. Search for client.
    //   3. If found, prompt for new name, password, balance.
    //   4. Call employee->editClient(id, name, password, balance).
    //   5. Update the file (save changes).
}

// --- Login ---
Employee* EmployeeManager::login(int id, const string& password) {
    // TODO: Same pattern as ClientManager::login but for employees.
    // Read from employees.txt, parse, match id+password.
}

// --- Employee Options ---
bool EmployeeManager::employeeOptions(Employee* employee) {
    // TODO:
    //   1. Call printEmployeeMenu().
    //   2. Read choice.
    //   3. Switch:
    //      case 1: newClient(employee)
    //      case 2: listAllClients(employee)
    //      case 3: searchForClient(employee)
    //      case 4: editClientInfo(employee)
    //      case 5: employee->display()
    //      case 6: return false (logout)
    //   4. Return true.
}
