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

// --- Print Client Menu ---
void ClientManager::printClientMenu() {
    // TODO: Print menu like:
    //   1. Deposit
    //   2. Withdraw
    //   3. Transfer
    //   4. Check Balance
    //   5. Update Password
    //   6. Logout
}

// --- Update Password ---
void ClientManager::updatePassword(Person* person) {
    // TODO:
    //   1. Ask for current password (verify it matches).
    //   2. Ask for new password.
    //   3. Validate new password with Validation::isValidPassword().
    //   4. Call person->setPassword(newPassword).
    //
    // WHY Person* and not Client*?
    //   Because Employees and Admins also need to update passwords.
    //   By using Person*, this single function works for all three.
    //   This is polymorphism in action.
}

// --- Login ---
Client* ClientManager::login(int id, const string& password) {
    // TODO:
    //   1. Load clients from file (or search in a loaded collection).
    //   2. Find client with matching id AND password.
    //   3. Return pointer if found, nullptr if not.
    //
    // DESIGN NOTE: This function needs access to stored client data.
    // It should work with FileManager/FilesHelper to load clients
    // and search through them.
    //
    // CLARIFICATION NEEDED: Should login read from file every time?
    // Or should there be a cached list? For a file-based system,
    // reading from file is the simplest approach.
}

// --- Client Options ---
bool ClientManager::clientOptions(Client* client) {
    // TODO:
    //   1. Call printClientMenu().
    //   2. Read user choice.
    //   3. Switch on choice:
    //      case 1: deposit → ask amount, call client->deposit(amount)
    //      case 2: withdraw → ask amount, call client->withdraw(amount)
    //      case 3: transfer → ask recipient id + amount, call client->transferTo()
    //      case 4: client->checkBalance()
    //      case 5: updatePassword(client)    ← Note: Person* polymorphism!
    //      case 6: return false (logout)
    //   4. Return true to keep the menu loop going.
}
