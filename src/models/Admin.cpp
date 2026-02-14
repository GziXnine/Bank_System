/*
 * ============================================================================
 * Admin.cpp — Implementation skeleton for Admin
 * ============================================================================
 */

#include "Admin.h"
#include <iostream>

using namespace std;

Admin::Admin() {};

Admin::Admin(int id, const string &name, const string &password, double salary)
    : Employee(id, name, password, salary) {};

Admin::~Admin() {};

// Employee Management
void Admin::addEmployee(Employee &employee)
{
  // TODO: Add employee to employees vector.
  // Consider: Check for duplicate IDs?
}

Employee *Admin::searchEmployee(int id)
{
  // TODO: Loop through employees, find by id.
  // Return pointer or nullptr.
}

void Admin::listEmployee() const
{
  // TODO: Loop through employees, call display() on each.
}

void Admin::editEmployee(int id, const string &name,
                         const string &password, double salary)
{
  // TODO: Find employee by id (reuse searchEmployee).
  // If found, update fields. If not, print error.
}

void Admin::display() const
{
  cout << "ID: " << Admin::id << " | Name: " << Admin::name << " | Salary: " << Admin::getSalary() << endl;
}
