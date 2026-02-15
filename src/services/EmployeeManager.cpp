/*
 * ============================================================================
 * EmployeeManager.cpp — Implementation skeleton for EmployeeManager
 * ============================================================================
 */

#include "EmployeeManager.h"
#include "ClientManager.h"
#include "../models/Employee.h"
#include "../models/Client.h"
#include "../core/FilesHelper.h"
#include "../core/Parser.h"
#include "../utils/Validation.h"
#include <iostream>
#include <iomanip>

using namespace std;

// Static member definition
std::vector<Employee> EmployeeManager::employees;

void EmployeeManager::loadEmployees()
{
  employees = FilesHelper::getEmployees();
}

std::vector<Employee> &EmployeeManager::getAllEmployees()
{
  return employees;
}

void EmployeeManager::saveAllEmployees()
{
  FilesHelper::updateAllEmployees(employees);
}

Employee *EmployeeManager::findEmployeeById(int id)
{
  for (auto &e : employees)
  {
    if (e.getId() == id)
      return &e;
  }
  return nullptr;
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
  (void)employee; // Parameter unused - using shared cache instead

  string name;
  string password;
  string balanceInput;
  double balance;
  int newId = FilesHelper::getLast("data/last_client_id.txt") + 1;

  cout << "\n=== Add New Client ===\n"
       << endl;

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

      cout << "Invalid balance. Must be a positive number." << endl;
    }
    catch (const invalid_argument &)
    {
      cout << "Invalid input. Please enter a valid number." << endl;
    }
  }

  Client newClient(newId, name, password, balance);

  // Add to shared client cache
  ClientManager::getAllClients().push_back(newClient);

  // Save to file and update last ID
  FilesHelper::saveClient(newClient);

  cout << "Client added successfully with ID: " << newId << endl;
}

void EmployeeManager::listAllClients(Employee *employee)
{
  (void)employee; // Parameter unused - using shared cache instead

  vector<Client> &allClients = ClientManager::getAllClients();

  if (allClients.empty())
  {
    cout << "\nNo clients found.\n"
         << endl;
    return;
  }

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

void EmployeeManager::searchForClient(Employee *employee)
{
  (void)employee; // Parameter unused - using shared cache instead

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

void EmployeeManager::editClientInfo(Employee *employee)
{
  (void)employee; // Parameter unused - using shared cache instead

  int id;
  string name;
  string password;
  string balanceInput;
  double balance;

  cout << "\nEnter client ID to edit: ";
  cin >> id;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

  Client *client = ClientManager::findClientById(id);
  if (client == nullptr)
  {
    cout << "\nClient with ID " << id << " not found.\n"
         << endl;
    return;
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

      cout << "Invalid balance. Must be at least 1500." << endl;
    }
    catch (const invalid_argument &)
    {
      cout << "Invalid input. Please enter a valid number." << endl;
    }
  }

  // Update client in cache
  client->setName(name);
  client->setPassword(password);
  client->setBalance(balance);

  // Save all clients to file
  ClientManager::saveAllClients();

  cout << "Client updated successfully!" << endl;
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
    cout << "\n=== Employee Info ===" << endl;
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
