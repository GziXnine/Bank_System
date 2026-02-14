/*
 * ============================================================================
 * Person.cpp — Implementation skeleton for Person base class
 * ============================================================================
 *
 * NOTE TO STUDENT:
 *   This is where you write the BODIES of the functions declared in Person.h.
 *   Separation of .h and .cpp is a professional practice:
 *     - .h = WHAT the class can do (interface / contract)
 *     - .cpp = HOW it does it (implementation / logic)
 *
 *   Benefits:
 *     1. Faster compilation (only recompile changed .cpp files)
 *     2. Cleaner headers that are easy to read
 *     3. Hides implementation details from other files
 *
 * ============================================================================
 */

#include "Person.h"
#include "../utils/Validation.h"

using namespace std;

Person::Person()
{
  this->id = 0;
  this->name = "";
  this->password = "";
}

Person::Person(int id, const string &name, const string &password)
{
  this->id = id;
  setName(name);
  setPassword(password);
}

// --- Virtual Destructor ---
Person::~Person()
{
  // Nothing to clean up — no dynamic memory in this class.
  // But the virtual destructor MUST exist so derived class
  // destructors are called correctly through base pointers.
}

int Person::getId() const
{
  return id;
}

const string &Person::getName() const
{
  return name;
}

// In a real application, you would NEVER return the password like this.
const string &Person::getPassword() const
{
  return password;
}

void Person::setName(const string &name)
{
  if (Validation::isValidName(name))
    this->name = name;
  else
    cout << "Invalid name. Must be alphabetic only, 5-20 characters." << endl;
}

void Person::setPassword(const string &password)
{
  if (Validation::isValidPassword(password))
    this->password = password;
  else
    cout << "Invalid password. Must be 8-20 characters." << endl;
}
