/*
 * ============================================================================
 * Validation.cpp — Implementation skeleton for Validation utility
 * ============================================================================
 *
 * HINT: For isAlphabetic, you can use std::isalpha() from <cctype>
 * to check each character. Remember to handle spaces — a name like
 * "Ahmed Ali" has a space, which is technically not alphabetic.
 * Decide: Allow spaces in names or not? The requirements say
 * "alphabetic chars" — clarify with your instructor.
 *
 * ============================================================================
 */

#include "Validation.h"
#include <cctype>

using namespace std;

// --- Name Validation ---
bool Validation::isValidName(const string& name) {
    // TODO: Check length (5-20) AND isAlphabetic().
    // Return true only if BOTH conditions pass.
}

// --- Password Validation ---
bool Validation::isValidPassword(const string& password) {
    // TODO: Check length (8-20).
}

// --- Balance Validation ---
bool Validation::isValidBalance(double balance) {
    // TODO: Return balance >= 1500.
}

// --- Salary Validation ---
bool Validation::isValidSalary(double salary) {
    // TODO: Return salary >= 5000.
}

// --- Amount Validation ---
bool Validation::isValidAmount(double amount) {
    // TODO: Return amount > 0.
}

// --- Alphabetic Check ---
bool Validation::isAlphabetic(const string& str) {
    // TODO: Loop through each character.
    // Return false if any char is not alphabetic AND not space.
    // Return true if all pass.
    //
    // CORRECTED: Spaces are ALLOWED in names ("Ahmed Ali").
    // HINT: for (char c : str) { if (!isalpha(c) && c != ' ') return false; }
}
