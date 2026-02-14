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

Employee::~Employee() {
  // vector<Client> cleans itself up automatically (RAII).
  // No manual delete needed — this is a benefit of using
};

double Employee::getSalary() const
{
  return salary;
}

void Employee::setSalary(double salary)
{
  if (Validation::isValidSalary(salary))
    this->salary = salary;
  else
    cout << "Invalid salary. Must be at least 5000." << endl;
}

void Employee::addClient(Client &client)
{
  clients.push_back(client);
}

Client *Employee::searchClient(int id)
{
  for (auto &c : clients)
  {
    if (c.getId() == id)
      return &c;
  }

  return nullptr;
}

void Employee::listClient() const
{
  for (const auto &c : clients)
    c.display();
}

void Employee::editClient(int id, const string &name, const string &password, double balance)
{
  Client *client = searchClient(id);
  if (client != nullptr)
  {
    client->setName(name);
    client->setPassword(password);
    client->setBalance(balance);
  }
  else
    cout << "Client with ID " << id << " not found." << endl;
}

void Employee::display() const
{
  cout << "ID: " << id << " | Name: " << name << " | Salary: " << salary << endl;
}
