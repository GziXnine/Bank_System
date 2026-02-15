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
#include <iomanip>
#include <limits>

using namespace std;

// Static member definition
std::vector<Client> ClientManager::clients;

void ClientManager::loadClients()
{
  clients = FilesHelper::getClients();
}

std::vector<Client> &ClientManager::getAllClients()
{
  return clients;
}

void ClientManager::saveAllClients()
{
  FilesHelper::updateAllClients(clients);
}

Client *ClientManager::findClientById(int id)
{
  for (auto &c : clients)
  {
    if (c.getId() == id)
      return &c;
  }
  return nullptr;
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
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

  if (currentPassword != person->getPassword())
  {
    cout << "Incorrect current password. Password update failed." << endl;
    return;
  }

  cout << "Enter new password: ";
  cin >> newPassword;
  cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

  if (!Validation::isValidPassword(newPassword))
  {
    cout << "Invalid password. Must be 8-20 characters." << endl;
    return;
  }

  person->setPassword(newPassword);
  cout << "Password updated successfully." << endl;

  // Save changes to file
  if (dynamic_cast<Client *>(person))
  {
    saveAllClients();
  }
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
  string input;

  printClientMenu();

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
    double amount;

    cout << "Enter deposit amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    client->deposit(amount);
    saveAllClients(); // Save changes to file
  }
  break;
  case 2:
  {
    double amount;

    cout << "Enter withdrawal amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer
    if (client->withdraw(amount))
    {
      saveAllClients(); // Save changes to file
    }
  }
  break;
  case 3:
  {
    int recipientId;
    double amount;

    cout << "Enter recipient ID: ";
    cin >> recipientId;
    cout << "Enter transfer amount: ";
    cin >> amount;
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear buffer

    Client *recipient = nullptr;
    for (auto &c : clients)
    {
      if (c.getId() == recipientId)
      {
        recipient = &c;
        break;
      }
    }

    if (recipient != nullptr && recipient != client)
    {
      client->transferTo(amount, recipient);
      saveAllClients(); // Save changes to file
    }
    else if (recipient == client)
      cout << "Cannot transfer to yourself!" << endl;
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
