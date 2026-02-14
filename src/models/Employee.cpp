/*
 * ============================================================================
 * Employee.cpp — Implementation skeleton for Employee
 * ============================================================================
 */

#include "Employee.h"
#include "Client.h"        // Full definition needed here for method bodies
#include "../utils/Validation.h"
#include <iostream>

using namespace std;

// --- Default Constructor ---
Employee::Employee() {
    // TODO: Initialize salary to minimum (5000).
}

// --- Parameterized Constructor ---
Employee::Employee(int id, const string& name, const string& password, double salary)
    : Person(id, name, password) {
    // TODO: Use setSalary() to apply validation.
}

// --- Destructor ---
Employee::~Employee() {
    // vector<Client> cleans itself up automatically (RAII).
    // No manual delete needed — this is a benefit of using
    // std::vector over raw arrays with new/delete.
}

// --- Getters ---
double Employee::getSalary() const {
    // TODO: Return salary.
}

// --- Setters ---
void Employee::setSalary(double salary) {
    // TODO: Validate minimum salary (5000).
}

// --- Client Management ---
void Employee::addClient(Client& client) {
    // TODO: Add client to the clients vector.
    // Consider: Should you check for duplicate IDs first?
}

Client* Employee::searchClient(int id) {
    // TODO: Loop through clients vector, find by id.
    // Return pointer to the found client, or nullptr if not found.
    //
    // HINT: Use a range-based for loop with reference:
    //   for (auto& c : clients) { ... return &c; }
    // The & is critical — without it, you'd search a copy.
}

void Employee::listClient() const {
    // TODO: Loop through clients, call display() on each.
}

void Employee::editClient(int id, const string& name,
                          const string& password, double balance) {
    // TODO: Find client by id (reuse searchClient).
    // If found, update their fields using setters.
    // If not found, print error.
}

// --- Display ---
void Employee::display() const {
    // TODO: Print id, name, salary (NOT password).
}
