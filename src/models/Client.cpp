/*
 * ============================================================================
 * Client.cpp — Implementation skeleton for Client
 * ============================================================================
 */

#include "Client.h"
#include "../utils/Validation.h"
#include <iostream>

using namespace std;

Client::Client()
{
  this->balance = 1500;
}

Client::Client(int id, const string &name, const string &password, double balance)
    : Person(id, name, password)
{
  setBalance(balance);
}

Client::~Client() {};

double Client::getBalance() const
{
  return balance;
}

void Client::setBalance(double balance)
{
  if (Validation::isValidBalance(balance))
    this->balance = balance;
  else
    cout << "The Minimum Valid Balance Is 1500 $." << endl;
}

void Client::deposit(double amount)
{
  if (Validation::isValidAmount(amount))
    balance += amount;
  else
    cout << "Invalid deposit amount. Must be greater than 0." << endl;
}

bool Client::withdraw(double amount)
{
  if (Validation::isValidAmount(amount) && Validation::isValidBalance(getBalance() - amount))
  {
    balance -= amount;
    return true;
  }
  else
  {
    cout << "Withdraw Is Invalid, Because This Smaller Than Minimum Balance" << endl;
    return false;
  }
}

void Client::transferTo(double amount, Client *recipient)
{
  if (recipient == nullptr)
  {
    cout << "Recipient not found!" << endl;
    return;
  }

  if (withdraw(amount))
    recipient->deposit(amount);
  else
    cout << "Transfer failed: insufficient funds" << endl;
}

void Client::checkBalance() const
{
  cout << "Balance: " << balance << "$" << endl;
}

void Client::display() const
{
  cout << "ID: " << id << " | Name: " << name << " | Balance: " << balance << endl;
}
