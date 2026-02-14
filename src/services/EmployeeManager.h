/*
 * ============================================================================
 * EmployeeManager.h — Handles the Employee menu and interactions
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   When an Employee logs in, they see a menu with options:
 *     - Add new client
 *     - List all clients
 *     - Search for client
 *     - Edit client info
 *     - Display own info
 *     - Logout
 *
 *   EmployeeManager orchestrates the employee workflow.
 *
 * DESIGN DECISIONS:
 *   - All methods take Employee* parameter: The logged-in employee
 *     is passed around so methods can access their client list
 *     and personal info.
 *
 *   - Separated from Employee class: Employee is a DATA MODEL.
 *     EmployeeManager is a SERVICE. Mixing both in one class
 *     violates Single Responsibility Principle.
 *     Employee knows WHAT it is. EmployeeManager knows WHAT TO DO with it.
 *
 *   - login returns Employee*: Same pattern as ClientManager.
 *
 * ============================================================================
 */

#ifndef EMPLOYEEMANAGER_H
#define EMPLOYEEMANAGER_H

#include <string>

class Employee;

class EmployeeManager {
private:
    EmployeeManager();

public:
    // --- Print the employee menu ---
    static void printEmployeeMenu();

    // --- Add a new client (prompts for input) ---
    static void newClient(Employee* employee);

    // --- List all clients managed by this employee ---
    static void listAllClients(Employee* employee);

    // --- Search for a client by id ---
    static void searchForClient(Employee* employee);

    // --- Edit a client's information ---
    static void editClientInfo(Employee* employee);

    // --- Authenticate an employee ---
    static Employee* login(int id, const std::string& password);

    // --- Process a single menu choice ---
    // Returns true to continue, false to logout.
    static bool employeeOptions(Employee* employee);
};

#endif // EMPLOYEEMANAGER_H
