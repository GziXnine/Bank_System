/*
 * ============================================================================
 * Admin.h — Represents a bank administrator
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   An Admin has ALL the powers of an Employee, PLUS:
 *     - Can add/search/edit/list Employees
 *     - Can manage clients (inherited from Employee)
 *
 *   The requirement hint says: "Admin could inherit from Employee."
 *   This is MULTILEVEL INHERITANCE: Person → Employee → Admin
 *   You practiced this in Day 7 (Creature → Human → Employee chain).
 *
 * DESIGN DECISIONS:
 *   - Inherits from Employee: Gets id, name, password, salary, AND
 *     all client management methods for free.
 *   - Adds employee management: vector<Employee> for employees it manages.
 *
 *   MENTOR NOTE — IS THIS GOOD DESIGN?
 *     Inheriting Admin from Employee is what the requirements ask.
 *     In a real system, this is debatable — an Admin IS NOT really
 *     "a kind of Employee" in all business contexts. But for this
 *     project scope and your current learning level, it's appropriate.
 *     It lets you practice multilevel inheritance.
 *
 *     The alternative (better in production) would be:
 *       - Person as base
 *       - Client, Employee, Admin all inherit from Person directly
 *       - Use INTERFACES (abstract classes) for capabilities
 *     But that's beyond the current requirements.
 *
 *   - Admin has the same salary field (inherited) and same validation
 *     rules as Employee. No duplication needed.
 *
 * ============================================================================
 */

#ifndef ADMIN_H
#define ADMIN_H

#include "Employee.h"
#include <vector>
#include <string>

class Admin : public Employee {
private:
    std::vector<Employee> employees;  // Employees managed by this admin

public:
    // --- Constructors ---
    Admin();
    Admin(int id, const std::string& name, const std::string& password, double salary);

    // --- Destructor ---
    ~Admin() override;

    // --- Client Management (inherited from Employee, listed for clarity) ---
    // addClient, searchClient, listClient, editClient — all inherited.
    // No need to redeclare unless behavior differs.

    // --- Employee Management (Phase 2, requirement 7) ---
    void addEmployee(Employee& employee);
    Employee* searchEmployee(int id);
    void listEmployee() const;
    void editEmployee(int id, const std::string& name,
                      const std::string& password, double salary);

    // --- Display ---
    void display() const override;
};

#endif // ADMIN_H
