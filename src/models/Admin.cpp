/*
 * ============================================================================
 * Admin.cpp — Implementation skeleton for Admin
 * ============================================================================
 */

#include "Admin.h"
#include <iostream>
#include <iomanip>

using namespace std;

Admin::Admin() {};

Admin::Admin(int id, const string &name, const string &password, double salary)
    : Employee(id, name, password, salary) {};

Admin::~Admin() {};

void Admin::addEmployee(Employee &employee)
{
  employees.push_back(employee);
}

Employee *Admin::searchEmployee(int id)
{
  for (auto &e : employees)
  {
    if (e.getId() == id)
      return &e;
  }

  return nullptr;
}

void Admin::listEmployee() const
{
  for (const auto &e : employees)
    e.display();
}

void Admin::editEmployee(int id, const string &name, const string &password, double salary)
{
  Employee *employee = searchEmployee(id);
  if (employee != nullptr)
  {
    employee->setName(name);
    employee->setPassword(password);
    employee->setSalary(salary);
  }
  else
    cout << "Employee with ID " << id << " not found." << endl;
}

void Admin::display() const
{
  cout << "╔════════╦══════════════════════╦═══════════════╗" << endl;
  cout << "║   ID   ║        Name          ║     Salary    ║" << endl;
  cout << "╠════════╬══════════════════════╬═══════════════╣" << endl;
  cout << "║ " << setw(6) << left << id
       << " ║ " << setw(20) << left << name
       << " ║ " << setw(13) << fixed << setprecision(2) << getSalary() << " ║" << endl;
  cout << "╚════════╩══════════════════════╩═══════════════╝" << endl;
}
