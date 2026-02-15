/*
 * ============================================================================
 * ClientManager.h — Handles the Client menu and interactions
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   When a Client logs in, they see a menu with options:
 *     - Deposit, Withdraw, Transfer, Check Balance, Update Password, Logout
 *
 *   ClientManager is the SERVICE that orchestrates these operations.
 *   It doesn't DO the operations itself — it calls methods on Client objects.
 *
 * DESIGN DECISIONS:
 *   - All static methods: ClientManager is a service, not an entity.
 *     It has no state of its own. It receives pointers to objects
 *     and operates on them.
 *
 *   - Takes Person* for updatePassword: Both Client and Employee might
 *     want to update their password. Person* allows polymorphism —
 *     one function works for any Person subclass.
 *     You learned upcasting in Day 6: Creature* c = new Human();
 *     Same principle here: Person* p = &someClient;
 *
 *   - login returns Client*: Either a valid pointer (successful login)
 *     or nullptr (failed login). This is the C++ idiom for "optional
 *     return" that you're familiar with.
 *
 *   - clientOptions returns bool: true = stay logged in, false = logout.
 *     This drives the menu loop.
 *
 * ============================================================================
 */

#ifndef CLIENTMANAGER_H
#define CLIENTMANAGER_H

#include <string>
#include <vector>
#include "../models/Employee.h"

class Client;
class Person;
class Employee;

class ClientManager
{
private:
  ClientManager();
  static std::vector<Client> clients; // Static for caching across calls

public:
  static void loadClients(); // Load Clients For Caching.

  // Print the client menu options to console
  static void printClientMenu();

  // Update password for any Person (polymorphic)
  // Takes Person* so it works for Client, Employee, or Admin.
  static void updatePassword(Person *person);

  // Authenticate a client by id and password
  // Returns pointer to the authenticated Client, or nullptr if failed.
  // This connects to FilesHelper or FileManager for data retrieval.
  static Client *login(int id, const std::string &password);

  // Process a single menu choice for the logged-in client
  // Returns true to continue the menu loop, false to logout.
  static bool clientOptions(Client *client);
};

#endif // CLIENTMANAGER_H
