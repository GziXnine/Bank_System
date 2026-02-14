/*
 * ============================================================================
 * Admin.cpp — Implementation skeleton for Admin
 * ============================================================================
 */

#include "Admin.h"
#include <iostream>

using namespace std;

// --- Default Constructor ---
Admin::Admin() {
    // TODO: Employee default constructor handles salary.
    // Nothing extra to initialize.
}

// --- Parameterized Constructor ---
Admin::Admin(int id, const string& name, const string& password, double salary)
    : Employee(id, name, password, salary) {
    // TODO: Everything handled by Employee's constructor.
    // This is constructor chaining — Person → Employee → Admin.
}

// --- Destructor ---
Admin::~Admin() {
    // vector<Employee> self-destructs (RAII).
}

// --- Employee Management ---
void Admin::addEmployee(Employee& employee) {
    // TODO: Add employee to employees vector.
    // Consider: Check for duplicate IDs?
}

Employee* Admin::searchEmployee(int id) {
    // TODO: Loop through employees, find by id.
    // Return pointer or nullptr.
}

void Admin::listEmployee() const {
    // TODO: Loop through employees, call display() on each.
}

void Admin::editEmployee(int id, const string& name,
                         const string& password, double salary) {
    // TODO: Find employee by id (reuse searchEmployee).
    // If found, update fields. If not, print error.
}

// --- Display ---
void Admin::display() const {
    // TODO: Print admin info (id, name, salary).
    // Could prefix with "[Admin]" to distinguish from regular employees.
}
