/*
 * ============================================================================
 * Client.cpp — Implementation skeleton for Client
 * ============================================================================
 */

#include "Client.h"
#include "../utils/Validation.h"
#include <iostream>

using namespace std;

// --- Default Constructor ---
Client::Client() {
    // TODO: Initialize balance to minimum (1500).
    // Person's default constructor handles id, name, password.
}

// --- Parameterized Constructor ---
Client::Client(int id, const string& name, const string& password, double balance)
    : Person(id, name, password) {
    // TODO: Use setBalance() to apply validation.
    // IMPORTANT: Call the PARENT constructor via initializer list (shown above).
    // This is how you chain constructors in inheritance — you learned this in Day 5.
}

// --- Destructor ---
Client::~Client() {
    // No dynamic memory to clean up in Client.
    // Person's virtual destructor handles the chain.
}

// --- Getter ---
double Client::getBalance() const {
    // TODO: Return balance.
}

// --- Setter ---
void Client::setBalance(double balance) {
    // TODO: Validate minimum balance (1500).
    // If invalid, print error and do NOT update.
}

// --- Business Operations ---
void Client::deposit(double amount) {
    // TODO: Validate amount > 0, then add to balance.
}

bool Client::withdraw(double amount) {
    // TODO: Validate amount > 0.
    // Ensure (balance - amount) >= minimum balance.
    // If successful, subtract and return true.
    // If not possible, print error and return false.
}

void Client::transferTo(double amount, Client& recipient) {
    // TODO: Withdraw from this client, deposit to recipient.
    // Reuse withdraw() and recipient.deposit() — don't duplicate logic.
    //
    // CORRECTED: withdraw() now returns bool.
    // Only deposit if withdraw succeeds:
    //   if (withdraw(amount)) { recipient.deposit(amount); }
    //   else { print "Transfer failed: insufficient funds" }
}

void Client::checkBalance() const {
    // TODO: Print balance to console.
}

// --- Display ---
void Client::display() const {
    // TODO: Print id, name, balance (NOT password — security!).
    //
    // CLARIFICATION NEEDED: The requirements say "Display function"
    // but don't specify format. Decide on a consistent format like:
    //   "ID: 1 | Name: Ahmed | Balance: 5000.00"
}
