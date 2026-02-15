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

// Static member definition
std::vector<Employee> EmployeeManager::employees;

void EmployeeManager::loadEmployees()
{
  employees = FilesHelper::getEmployees();
}

void EmployeeManager::printEmployeeMenu()
{
  cout << "1. Add New Client" << endl;
  cout << "2. List All Clients" << endl;
  cout << "3. Search Client" << endl;
  cout << "4. Edit Client Info" << endl;
  cout << "5. Display My Info" << endl;
  cout << "6. Logout" << endl;
  cout << endl;

  cout << "Choose an option: ";
}

void EmployeeManager::newClient(Employee *employee)
{
  string name;
  string password;
  string balanceInput;
  double balance;
  int newId = FilesHelper::getLast("data/clients_last_id.txt") + 1;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  while (true)
  {
    cout << "Enter client name: ";
    getline(cin, name);

    if (Validation::isValidName(name))
      break;

    cout << "Invalid name. Must be 5-20 alphabetic characters." << endl;
  }

  while (true)
  {
    cout << "Enter client password: ";
    getline(cin, password);

    if (Validation::isValidPassword(password))
      break;

    cout << "Invalid password. Must be 8-20 characters." << endl;
  }

  while (true)
  {
    cout << "Enter initial balance: ";
    getline(cin, balanceInput);

    try
    {
      balance = stod(balanceInput);

      if (Validation::isValidBalance(balance))
        break;

      cout << "Invalid balance. Must be a positive number." << endl;
    }
    catch (const invalid_argument &)
    {
      cout << "Invalid input. Please enter a valid number." << endl;
    }
  }

  Client newClient(newId, name, password, balance);
  employee->addClient(newClient);
  FilesHelper::saveClient(newClient);
}

void EmployeeManager::listAllClients(Employee *employee)
{
  employee->listClient();
}

void EmployeeManager::searchForClient(Employee *employee)
{
  int id;
  cout << "Enter client ID to search: ";
  cin >> id;

  Client *client = employee->searchClient(id);
  if (client != nullptr)
    client->display();
  else
    cout << "Client with ID " << id << " not found." << endl;
}

void EmployeeManager::editClientInfo(Employee *employee)
{
  int id;
  string name;
  string password;
  string balanceInput;
  double balance;

  cout << "Enter client ID to edit: ";
  cin >> id;

  Client *client = employee->searchClient(id);
  if (client == nullptr)
  {
    cout << "Client with ID " << id << " not found." << endl;
    return;
  }

  cout << "Editing client: " << client->getName() << endl;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Leave field empty to keep current value." << endl;
  while (true)
  {
    cout << "Enter new name: ";
    getline(cin, name);

    if (name.empty())
    {
      name = client->getName();
      break;
    }

    if (Validation::isValidName(name))
      break;

    cout << "Invalid name. Must be 5-20 alphabetic characters." << endl;
  }

  while (true)
  {
    cout << "Enter new password: ";
    getline(cin, password);

    if (password.empty())
    {
      password = client->getPassword();
      break;
    }

    if (Validation::isValidPassword(password))
      break;

    cout << "Invalid password. Must be 8-20 characters." << endl;
  }

  while (true)
  {
    cout << "Enter new balance: ";
    getline(cin, balanceInput);

    if (balanceInput.empty())
    {
      balance = client->getBalance();
      break;
    }

    try
    {
      balance = stod(balanceInput);

      if (Validation::isValidBalance(balance))
        break;

      cout << "Invalid balance. Must be a positive number." << endl;
    }
    catch (const invalid_argument &)
    {
      cout << "Invalid input. Please enter a valid number." << endl;
    }
  }

  employee->editClient(id, name, password, balance);
  FilesHelper::saveClient(*client);
}

Employee *EmployeeManager::login(int id, const string &password)
{
  for (Employee &e : employees)
  {
    if (e.getId() == id && e.getPassword() == password)
      return &e;
  }

  return nullptr;
}

bool EmployeeManager::employeeOptions(Employee *employee)
{
  int choice;
  string input;

  printEmployeeMenu();

  getline(cin, input);

  try
  {
    choice = stoi(input);
  }
  catch (const invalid_argument &)
  {
    cout << "Invalid choice. Please enter a number." << endl;
    return true;
  }

  switch (choice)
  {
  case 1:
  {
    cout << "Add new client: " << endl;
    newClient(employee);
  }
  break;
  case 2:
  {
    cout << "Listing all clients: " << endl;
    listAllClients(employee);
  }
  break;
  case 3:
  {
    cout << "Searching for client: " << endl;
    searchForClient(employee);
  }
  break;
  case 4:
  {
    cout << "Editing client info: " << endl;
    editClientInfo(employee);
  }
  break;
  case 5:
  {
    cout << "Displaying employee info: " << endl;
    employee->display();
  }
  break;
  case 6:
  {
    cout << "Logging out..." << endl;
    return false;
  }

  default:
    cout << "Invalid choice. Please try again." << endl;
    break;
  }

  return true; // Continue the menu loop
}
