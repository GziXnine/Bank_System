/*
 * ============================================================================
 * Employee.h — Represents a bank employee
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   An Employee works at the bank. They can:
 *     - Log in with id + password
 *     - Add new clients
 *     - Search for clients by id
 *     - List all clients
 *     - Edit client information
 *
 *   An Employee IS-A Person (has id, name, password) plus a salary.
 *
 * DESIGN DECISIONS:
 *   - Inherits from Person: Same reasoning as Client.
 *   - salary is private with min 5000 validation.
 *   - Employee manages clients through a vector<Client>.
 *     This is COMPOSITION — Employee HAS clients it manages.
 *
 *   MENTOR NOTE ON PHASE 2 REQUIREMENTS:
 *     The requirements say to add client management methods directly
 *     to Employee. This is acceptable for this project scope, but in
 *     a real system, you'd separate "user data" from "user actions"
 *     (Single Responsibility Principle). For now, follow the requirements.
 *
 *   - searchClient returns Client*: A pointer allows returning nullptr
 *     when not found. This is the C++ way before std::optional.
 *     In your course (Day 6), you used raw pointers for polymorphism.
 *     Same idea here but for "nullable return."
 *
 * ============================================================================
 */

#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "Person.h"
#include <string>
#include <vector>

// Forward declaration — avoids circular dependency.
// We only need Client* (pointer) in the header, not the full definition.
// The full #include "Client.h" goes in Employee.cpp.
class Client;

class Employee : public Person {
private:
    double salary;
    std::vector<Client> clients;  // Clients managed by this employee

public:
    // --- Constructors ---
    Employee();
    Employee(int id, const std::string& name, const std::string& password, double salary);

    // --- Destructor ---
    ~Employee() override;

    // --- Getters ---
    double getSalary() const;

    // --- Setters (min salary: 5000) ---
    void setSalary(double salary);

    // --- Client Management (Phase 2, requirement 6) ---
    void addClient(Client& client);

    // Returns pointer to found client, or nullptr if not found.
    // IMPORTANT: Returns pointer to element in the vector — do NOT
    // store this pointer long-term, it invalidates if vector resizes.
    Client* searchClient(int id);

    void listClient() const;

    void editClient(int id, const std::string& name,
                    const std::string& password, double balance);

    // --- Display ---
    void display() const override;
};

#endif // EMPLOYEE_H
