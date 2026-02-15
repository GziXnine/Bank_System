/*
 * ============================================================================
 * Screens.cpp — Full implementation of Screens UI
 * ============================================================================
 */

#include "Screens.h"
#include "ClientManager.h"
#include "EmployeeManager.h"
#include "AdminManager.h"
#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"
#include <iostream>
#include <limits>

using namespace std;

void Screens::bankName()
{
  cout << "======================================" << endl;
  cout << "          ★  BANK SYSTEM  ★          " << endl;
  cout << "======================================" << endl;
}

void Screens::welcome()
{
  cout << "\nWelcome to Bank System!" << endl;
  cout << "Your trusted financial partner.\n"
       << endl;
}

void Screens::loginOptions()
{
  cout << "\n--- Login Menu ---" << endl;
  cout << "1. Client" << endl;
  cout << "2. Employee" << endl;
  cout << "3. Admin" << endl;
  cout << "0. Exit" << endl;
  cout << "\nChoice: ";
}

int Screens::loginAs()
{
  int choice;
  string input;

  loginOptions();
  getline(cin, input);

  try
  {
    choice = stoi(input);

    if (choice < 0 || choice > 3)
    {
      invalid(choice);
      return -1; // Invalid choice marker
    }

    return choice;
  }
  catch (const invalid_argument &)
  {
    cout << "Invalid input. Please enter a number (0-3)." << endl;
    return -1;
  }
}

void Screens::invalid(int c)
{
  cout << "Invalid choice: " << c << ". Please try again." << endl;
}

void Screens::logout()
{
  cout << "\n--- Logged out successfully. Goodbye! ---\n"
       << endl;
}

void Screens::loginScreen(int c)
{
  int id;
  string password;

  cout << "\n=== Login ===" << endl;
  cout << "Enter ID: ";
  cin >> id;

  cin.ignore(numeric_limits<streamsize>::max(), '\n');

  cout << "Enter Password: ";
  getline(cin, password);

  switch (c)
  {
  case 1:
  {
    Client *client = ClientManager::login(id, password);
    if (client != nullptr)
    {
      cout << "\nLogin successful! Welcome, " << client->getName() << "!\n"
           << endl;
      while (ClientManager::clientOptions(client))
      {
        // Keep showing menu until logout (returns false)
      }
    }
    else
    {
      cout << "\nLogin failed! Invalid ID or password.\n"
           << endl;
    }
  }
  break;

  case 2:
  {
    // Employee Login
    Employee *employee = EmployeeManager::login(id, password);
    if (employee != nullptr)
    {
      cout << "\nLogin successful! Welcome, " << employee->getName() << "!\n"
           << endl;
      while (EmployeeManager::employeeOptions(employee))
      {
        // Keep showing menu until logout
      }
    }
    else
    {
      cout << "\nLogin failed! Invalid ID or password.\n"
           << endl;
    }
  }
  break;

  case 3:
  {
    // Admin Login
    Admin *admin = AdminManager::login(id, password);
    if (admin != nullptr)
    {
      cout << "\nLogin successful! Welcome, Admin " << admin->getName() << "!\n"
           << endl;
      while (AdminManager::adminOptions(admin))
      {
        // Keep showing menu until logout
      }
    }
    else
    {
      cout << "\nLogin failed! Invalid ID or password.\n"
           << endl;
    }
  }
  break;

  default:
    cout << "Unknown user type." << endl;
    break;
  }
}

void Screens::runApp()
{
  ClientManager::loadClients();
  EmployeeManager::loadEmployees();
  AdminManager::loadAdmins();

  bankName();
  welcome();

  bool running = true;

  while (running)
  {
    int choice = loginAs();

    if (choice == -1)
    {
      // Invalid input, loop again
      continue;
    }

    if (choice == 0)
    {
      cout << "\nThank you for using Bank!" << endl;
      cout << "Have a great day!\n"
           << endl;

      running = false;
    }
    else
    {
      loginScreen(choice);
      logout();
    }
  }
}
