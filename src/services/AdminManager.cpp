/*
 * ============================================================================
 * AdminManager.cpp — Implementation for AdminManager
 * ============================================================================
 */

#include "AdminManager.h"
#include "../models/Admin.h"
#include "../models/Employee.h"
#include "../models/Client.h"
#include "../core/FilesHelper.h"
#include "../core/Parser.h"
#include "../utils/Validation.h"
#include <iostream>
#include <limits>

using namespace std;

// Static member definition
std::vector<Admin> AdminManager::admins;

void AdminManager::loadAdmins()
{
  admins = FilesHelper::getAdmins();
}

void AdminManager::printAdminMenu()
{
  cout << "1. Add New Client" << endl;
  cout << "2. List All Clients" << endl;
  cout << "3. Search Client" << endl;
  cout << "4. Edit Client Info" << endl;

  cout << "5. Add New Employee" << endl;
  cout << "6. List All Employees" << endl;
  cout << "7. Search Employee" << endl;
  cout << "8. Edit Employee Info" << endl;

  cout << "9. Display My Info" << endl;
  cout << "10. Logout" << endl;
  cout << endl;

  cout << "Choose an option: ";
}

Admin *AdminManager::login(int id, const string &password)
{
  for (Admin &a : admins)
  {
    if (a.getId() == id && a.getPassword() == password)
      return &a;
  }

  return nullptr;
}

bool AdminManager::adminOptions(Admin *admin)
{
  int choice;
  string input;

  printAdminMenu();

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
    // Client Management (Admin inherits from Employee, so has these methods)
  case 1:
  {
    cout << "=== Add New Client ===" << endl;
    string name, password, balanceInput;
    double balance;
    int newId = FilesHelper::getLast("data/last_client_id.txt") + 1;

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
        cout << "Invalid balance. Minimum is 1500." << endl;
      }
      catch (const invalid_argument &)
      {
        cout << "Invalid input. Please enter a valid number." << endl;
      }
    }

    Client newClient(newId, name, password, balance);
    admin->addClient(newClient);
    FilesHelper::saveClient(newClient);

    cout << "Client added successfully with ID: " << newId << endl;
  }
  break;

  case 2:
  {
    cout << "=== All Clients ===" << endl;
    admin->listClient();
  }
  break;

  case 3:
  {
    int id;
    cout << "Enter client ID to search: ";
    cin >> id;

    Client *client = admin->searchClient(id);
    if (client != nullptr)
      client->display();
    else
      cout << "Client with ID " << id << " not found." << endl;
  }
  break;

  case 4:
  {
    int id;
    string name, password, balanceInput;
    double balance;

    cout << "Enter client ID to edit: ";
    cin >> id;

    Client *client = admin->searchClient(id);
    if (client == nullptr)
    {
      cout << "Client with ID " << id << " not found." << endl;
      break;
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
      cout << "Invalid name." << endl;
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
      cout << "Invalid password." << endl;
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
        cout << "Invalid balance." << endl;
      }
      catch (const invalid_argument &)
      {
        cout << "Invalid input." << endl;
      }
    }

    admin->editClient(id, name, password, balance);
    FilesHelper::saveClient(*client);
    cout << "Client updated successfully." << endl;
  }
  break;

    // Employee Management
  case 5:
  {
    cout << "=== Add New Employee ===" << endl;
    string name, password, salaryInput;
    double salary;
    int newId = FilesHelper::getLast("data/last_employee_id.txt") + 1;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    while (true)
    {
      cout << "Enter employee name: ";
      getline(cin, name);
      if (Validation::isValidName(name))
        break;
      cout << "Invalid name. Must be 5-20 alphabetic characters." << endl;
    }

    while (true)
    {
      cout << "Enter employee password: ";
      getline(cin, password);
      if (Validation::isValidPassword(password))
        break;
      cout << "Invalid password. Must be 8-20 characters." << endl;
    }

    while (true)
    {
      cout << "Enter salary: ";
      getline(cin, salaryInput);
      try
      {
        salary = stod(salaryInput);
        if (Validation::isValidSalary(salary))
          break;
        cout << "Invalid salary. Minimum is 5000." << endl;
      }
      catch (const invalid_argument &)
      {
        cout << "Invalid input. Please enter a valid number." << endl;
      }
    }

    Employee newEmployee(newId, name, password, salary);
    admin->addEmployee(newEmployee);
    FilesHelper::saveEmployee("data/employees.txt", "data/last_employee_id.txt", newEmployee);
    cout << "Employee added successfully with ID: " << newId << endl;
  }
  break;

  case 6:
  {
    cout << "=== All Employees ===" << endl;
    admin->listEmployee();
  }
  break;

  case 7:
  {
    int id;
    cout << "Enter employee ID to search: ";
    cin >> id;

    Employee *employee = admin->searchEmployee(id);
    if (employee != nullptr)
      employee->display();
    else
      cout << "Employee with ID " << id << " not found." << endl;
  }
  break;

  case 8:
  {
    int id;
    string name, password, salaryInput;
    double salary;

    cout << "Enter employee ID to edit: ";
    cin >> id;

    Employee *employee = admin->searchEmployee(id);
    if (employee == nullptr)
    {
      cout << "Employee with ID " << id << " not found." << endl;
      break;
    }

    cout << "Editing employee: " << employee->getName() << endl;
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Leave field empty to keep current value." << endl;

    while (true)
    {
      cout << "Enter new name: ";
      getline(cin, name);
      if (name.empty())
      {
        name = employee->getName();
        break;
      }
      if (Validation::isValidName(name))
        break;
      cout << "Invalid name." << endl;
    }

    while (true)
    {
      cout << "Enter new password: ";
      getline(cin, password);
      if (password.empty())
      {
        password = employee->getPassword();
        break;
      }
      if (Validation::isValidPassword(password))
        break;
      cout << "Invalid password." << endl;
    }

    while (true)
    {
      cout << "Enter new salary: ";
      getline(cin, salaryInput);
      if (salaryInput.empty())
      {
        salary = employee->getSalary();
        break;
      }
      try
      {
        salary = stod(salaryInput);
        if (Validation::isValidSalary(salary))
          break;
        cout << "Invalid salary." << endl;
      }
      catch (const invalid_argument &)
      {
        cout << "Invalid input." << endl;
      }
    }

    admin->editEmployee(id, name, password, salary);
    FilesHelper::saveEmployee("data/employees.txt", "data/last_employee_id.txt", *employee);

    cout << "Employee updated successfully." << endl;
  }
  break;

  case 9:
  {
    cout << "=== Admin Info ===" << endl;
    admin->display();
  }
  break;
  case 10:
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
