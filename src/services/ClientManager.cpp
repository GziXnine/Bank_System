/*
 * ============================================================================
 * ClientManager.cpp — Implementation skeleton for ClientManager
 * ============================================================================
 */

#include "ClientManager.h"
#include "../models/Client.h"
#include "../models/Person.h"
#include "../core/FilesHelper.h"
#include "../core/Parser.h"
#include "../utils/Validation.h"
#include <iostream>

using namespace std;

void ClientManager::loadClients()
{
  clients = FilesHelper::getClients();
}

void ClientManager::printClientMenu()
{
  cout << "1. Deposit" << endl;
  cout << "2. Withdraw" << endl;
  cout << "3. Transfer" << endl;
  cout << "4. Check Balance" << endl;
  cout << "5. Update Password" << endl;
  cout << "6. Logout" << endl;
  cout << endl;

  cout << "Choose an option: ";
}

void ClientManager::updatePassword(Person *person)
{
  string currentPassword;
  string newPassword;

  cout << "Enter current password: ";
  cin >> currentPassword;

  if (currentPassword != person->getPassword())
  {
    cout << "Incorrect current password. Password update failed." << endl;
    return;
  }

  cout << "Enter new password: ";
  cin >> newPassword;

  if (!Validation::isValidPassword(newPassword))
  {
    cout << "Invalid password. Must be 8-20 characters." << endl;
    return;
  }

  person->setPassword(newPassword);
  cout << "Password updated successfully." << endl;
}

Client *ClientManager::login(int id, const string &password)
{
  for (Client &c : clients)
  {
    if (c.getId() == id && c.getPassword() == password)
      return &c; // Return pointer to the authenticated client
  }

  return nullptr; // Authentication failed
}

bool ClientManager::clientOptions(Client *client)
{
  int choice;

  printClientMenu();

  cin >> choice;
  switch (choice)
  {
  case 1:
  {
    double amount;

    cout << "Enter deposit amount: ";
    cin >> amount;
    client->deposit(amount);
  }
  break;
  case 2:
  {
    double amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;
    client->withdraw(amount);
  }
  break;
  case 3:
  {
    int recipientId;
    double amount;
    Employee emp;

    cout << "Enter recipient ID: ";
    cin >> recipientId;
    cout << "Enter transfer amount: ";
    cin >> amount;

    Client *recipient = emp.searchClient(recipientId);
    if (recipient != nullptr)
      client->transferTo(amount, recipient);
    else
      cout << "Recipient with ID " << recipientId << " not found." << endl;
  }
  break;
  case 4:
    client->checkBalance();
    break;
  case 5:
    updatePassword(client); // ← Note: Person* polymorphism!
    break;

  default:
    cout << "Invalid choice. Please try again." << endl;
    break;
  }

  if (choice == 6)
    return false; // Logout

  return true; // Continue the menu loop
}
