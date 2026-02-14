/*
 * ============================================================================
 * Client.h — Represents a bank client/customer
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   A Client is a person who has a bank account. They can:
 *     - Log in with id + password
 *     - Deposit money
 *     - Withdraw money
 *     - Transfer money to another client
 *     - Check their balance
 *
 *   A Client IS-A Person (inheritance), plus they have a balance.
 *
 * DESIGN DECISIONS:
 *   - Inherits from Person: Gets id, name, password for free.
 *   - balance is private: Only accessible through controlled methods
 *     (deposit, withdraw, transferTo). This is encapsulation at its best —
 *     nobody can set balance to -9999 by accident.
 *   - Min balance is 1500: Enforced in the setter / constructor.
 *   - transferTo takes Client& (reference): The recipient's balance
 *     must actually change. A copy wouldn't work here.
 *   - display() overrides Person's pure virtual: Now Client is concrete
 *     (you can create Client objects).
 *
 * MENTOR NOTE:
 *   The requirements say Client has its own id, name, password, balance.
 *   Since we use Person as base, Client only ADDS balance.
 *   This is the power of inheritance — no code duplication.
 *
 * ============================================================================
 */

#ifndef CLIENT_H
#define CLIENT_H

#include "Person.h"
#include <string>

class Client : public Person {
private:
    double balance;

public:
    // --- Constructors ---
    Client();
    Client(int id, const std::string& name, const std::string& password, double balance);

    // --- Destructor ---
    // Virtual inherited from Person. Override is optional but good practice.
    ~Client() override;

    // --- Getter ---
    double getBalance() const;

    // --- Setter (with min balance validation: 1500) ---
    void setBalance(double balance);

    // --- Business Operations ---
    // deposit: Adds amount to balance. Amount must be positive.
    void deposit(double amount);

    // withdraw: Subtracts amount from balance.
    // Must ensure balance doesn't go below minimum (1500).
    // Returns true if successful, false if insufficient funds.
    bool withdraw(double amount);

    // transferTo: Withdraws from this client, deposits to recipient.
    // recipient is passed by reference — their balance must change too.
    void transferTo(double amount, Client& recipient);

    // checkBalance: Displays the current balance to the console.
    void checkBalance() const;

    // --- Display (overrides Person's pure virtual) ---
    void display() const override;
};

#endif // CLIENT_H
