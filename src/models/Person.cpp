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

// In .cpp files, "using namespace std;" is acceptable.
using namespace std;

// --- Default Constructor ---
Person::Person() {
    // TODO: Initialize id to 0, name and password to empty strings.
}

// --- Parameterized Constructor ---
Person::Person(int id, const string& name, const string& password) {
    // TODO: Use setters to assign values (so validation runs).
    // Set id directly since it has no validation.
}

// --- Virtual Destructor ---
Person::~Person() {
    // Nothing to clean up — no dynamic memory in this class.
    // But the virtual destructor MUST exist so derived class
    // destructors are called correctly through base pointers.
}

// --- Getters ---
int Person::getId() const {
    // TODO: Return id.
}

const string& Person::getName() const {
    // TODO: Return name.
}

const string& Person::getPassword() const {
    // TODO: Return password.
}

// --- Setters ---
void Person::setName(const string& name) {
    // TODO: Use Validation::isValidName(name) before assigning.
    // If invalid, print an error message and do NOT update the field.
}

void Person::setPassword(const string& password) {
    // TODO: Use Validation::isValidPassword(password) before assigning.
    // If invalid, print an error message and do NOT update the field.
}

// NOTE: display() is pure virtual — no implementation here.
// Each derived class (Client, Employee, Admin) provides its own.
