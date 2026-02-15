/*
 * ============================================================================
 * AdminManager.cpp — Implementation for AdminManager
 * ============================================================================
 */

#include "AdminManager.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "../models/Admin.h"
#include "../models/Employee.h"
#include "../models/Client.h"
#include "../core/FilesHelper.h"
#include "../core/Parser.h"
#include "../utils/Validation.h"
#include <iostream>
#include <iomanip>
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
    cout << "\n=== Add New Client ===\n"
         << endl;
    string name, password, balanceInput;
    double balance;
    int newId = FilesHelper::getLast("data/last_client_id.txt") + 1;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

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
    ClientManager::getAllClients().push_back(newClient);
    FilesHelper::saveClient(newClient);

    cout << "Client added successfully with ID: " << newId << endl;
  }
  break;

  case 2:
  {
    vector<Client> &allClients = ClientManager::getAllClients();

    if (allClients.empty())
    {
      cout << "\nNo clients found.\n"
           << endl;
    }
    else
    {
      cout << "\n";
      cout << "╔════════╦══════════════════════╦═══════════════╗" << endl;
      cout << "║   ID   ║        Name          ║    Balance    ║" << endl;
      cout << "╠════════╬══════════════════════╬═══════════════╣" << endl;

      for (const auto &c : allClients)
      {
        cout << "║ " << setw(6) << left << c.getId()
             << " ║ " << setw(20) << left << c.getName()
             << " ║ " << setw(13) << fixed << setprecision(2) << c.getBalance() << " ║" << endl;
      }

      cout << "╚════════╩══════════════════════╩═══════════════╝" << endl;
      cout << endl;
    }
  }
  break;

  case 3:
  {
    int id;
    cout << "\nEnter client ID to search: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    Client *client = ClientManager::findClientById(id);
    if (client != nullptr)
    {
      cout << "\n";
      cout << "╔════════╦══════════════════════╦═══════════════╗" << endl;
      cout << "║   ID   ║        Name          ║    Balance    ║" << endl;
      cout << "╠════════╬══════════════════════╬═══════════════╣" << endl;
      cout << "║ " << setw(6) << left << client->getId()
           << " ║ " << setw(20) << left << client->getName()
           << " ║ " << setw(13) << fixed << setprecision(2) << client->getBalance() << " ║" << endl;
      cout << "╚════════╩══════════════════════╩═══════════════╝" << endl;
      cout << endl;
    }
    else
      cout << "\nClient with ID " << id << " not found.\n"
           << endl;
  }
  break;

  case 4:
  {
    int id;
    string name, password, balanceInput;
    double balance;

    cout << "\nEnter client ID to edit: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    Client *client = ClientManager::findClientById(id);
    if (client == nullptr)
    {
      cout << "\nClient with ID " << id << " not found.\n"
           << endl;
      break;
    }

    cout << "\nEditing client: " << client->getName() << endl;
    cout << "Leave field empty to keep current value.\n"
         << endl;

    while (true)
    {
      cout << "Enter new name (current: " << client->getName() << "): ";
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
      cout << "Enter new balance (current: " << client->getBalance() << "): ";
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

    client->setName(name);
    client->setPassword(password);
    client->setBalance(balance);
    ClientManager::saveAllClients();
    cout << "Client updated successfully." << endl;
  }
  break;

    // Employee Management
  case 5:
  {
    cout << "\n=== Add New Employee ===\n"
         << endl;
    string name, password, salaryInput;
    double salary;
    int newId = FilesHelper::getLast("data/last_employee_id.txt") + 1;

    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

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
    EmployeeManager::getAllEmployees().push_back(newEmployee);
    FilesHelper::saveEmployee("data/employees.txt", "data/last_employee_id.txt", newEmployee);
    cout << "Employee added successfully with ID: " << newId << endl;
  }
  break;

  case 6:
  {
    vector<Employee> &allEmployees = EmployeeManager::getAllEmployees();

    if (allEmployees.empty())
    {
      cout << "\nNo employees found.\n"
           << endl;
    }
    else
    {
      cout << "\n";
      cout << "╔════════╦══════════════════════╦═══════════════╗" << endl;
      cout << "║   ID   ║        Name          ║     Salary    ║" << endl;
      cout << "╠════════╬══════════════════════╬═══════════════╣" << endl;

      for (const auto &e : allEmployees)
      {
        cout << "║ " << setw(6) << left << e.getId()
             << " ║ " << setw(20) << left << e.getName()
             << " ║ " << setw(13) << fixed << setprecision(2) << e.getSalary() << " ║" << endl;
      }

      cout << "╚════════╩══════════════════════╩═══════════════╝" << endl;
      cout << endl;
    }
  }
  break;

  case 7:
  {
    int id;
    cout << "\nEnter employee ID to search: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    Employee *employee = EmployeeManager::findEmployeeById(id);
    if (employee != nullptr)
    {
      cout << "\n";
      cout << "╔════════╦══════════════════════╦═══════════════╗" << endl;
      cout << "║   ID   ║        Name          ║     Salary    ║" << endl;
      cout << "╠════════╬══════════════════════╬═══════════════╣" << endl;
      cout << "║ " << setw(6) << left << employee->getId()
           << " ║ " << setw(20) << left << employee->getName()
           << " ║ " << setw(13) << fixed << setprecision(2) << employee->getSalary() << " ║" << endl;
      cout << "╚════════╩══════════════════════╩═══════════════╝" << endl;
      cout << endl;
    }
    else
      cout << "\nEmployee with ID " << id << " not found.\n"
           << endl;
  }
  break;

  case 8:
  {
    int id;
    string name, password, salaryInput;
    double salary;

    cout << "\nEnter employee ID to edit: ";
    cin >> id;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    Employee *employee = EmployeeManager::findEmployeeById(id);
    if (employee == nullptr)
    {
      cout << "\nEmployee with ID " << id << " not found.\n"
           << endl;
      break;
    }

    cout << "\nEditing employee: " << employee->getName() << endl;
    cout << "Leave field empty to keep current value.\n"
         << endl;

    while (true)
    {
      cout << "Enter new name (current: " << employee->getName() << "): ";
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
      cout << "Enter new salary (current: " << employee->getSalary() << "): ";
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

    employee->setName(name);
    employee->setPassword(password);
    employee->setSalary(salary);
    EmployeeManager::saveAllEmployees();

    cout << "Employee updated successfully." << endl;
  }
  break;

  case 9:
  {
    cout << "\n=== Admin Info ===" << endl;
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
