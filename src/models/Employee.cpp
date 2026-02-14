/*
 * ============================================================================
 * Employee.cpp — Implementation skeleton for Employee
 * ============================================================================
 */

#include "Employee.h"
#include "Client.h"
#include "../utils/Validation.h"
#include <iostream>

using namespace std;

Employee::Employee()
{
  this->salary = 5000.00;
}

Employee::Employee(int id, const string &name, const string &password, double salary)
    : Person(id, name, password)
{
  setSalary(salary);
}

// vector<Client> cleans itself up automatically (RAII).
// No manual delete needed — this is a benefit of using
Employee::~Employee() {};

double Employee::getSalary() const
{
  return salary;
}

void Employee::setSalary(double salary)
{
  if(Validation::isValidSalary(salary))
    this->salary = salary;
}

// Client Management
void Employee::addClient(Client &client)
{
  // TODO: Add client to the clients vector.
  // Consider: Should you check for duplicate IDs first?
}

Client *Employee::searchClient(int id)
{
  // TODO: Loop through clients vector, find by id.
  // Return pointer to the found client, or nullptr if not found.
  //
  // HINT: Use a range-based for loop with reference:
  //   for (auto& c : clients) { ... return &c; }
  // The & is critical — without it, you'd search a copy.
}

void Employee::listClient() const
{
  // TODO: Loop through clients, call display() on each.
}

void Employee::editClient(int id, const string &name,
                          const string &password, double balance)
{
  // TODO: Find client by id (reuse searchClient).
  // If found, update their fields using setters.
  // If not found, print error.
}

void Employee::display() const
{
  cout << "ID: " << id << " | Name: " << name << " | Salary: " << salary << endl;
}
