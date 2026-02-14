/*
 * ============================================================================
 * Validation.h — Centralized validation utility
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   Multiple classes need the SAME validation logic:
 *     - Client, Employee, Admin all validate name (alpha, 5-20 chars)
 *     - Client, Employee, Admin all validate password (8-20 chars)
 *     - Client validates balance (min 1500)
 *     - Employee, Admin validate salary (min 5000)
 *
 *   Instead of copy-pasting this logic into every class, we extract
 *   it into a single utility class with static methods.
 *
 * DESIGN DECISIONS:
 *   - All static methods: Validation has no state. It doesn't need
 *     to be instantiated. It's a collection of pure utility functions.
 *     You learned static methods in Day 3 (Math class).
 *
 *   - Returns bool: Each method returns true/false. The CALLER decides
 *     what to do (print error, throw exception, retry, etc.).
 *     This is separation of concerns — Validation validates, it doesn't
 *     print messages or handle UI.
 *
 *   - Private constructor: Prevents anyone from creating a Validation
 *     object. This is a common pattern for utility classes in C++.
 *
 * WHY a separate class and not free functions?
 *   Both are valid. A class groups related functions under a namespace-like
 *   structure (Validation::isValidName). At your current level, this
 *   pattern is clearer. In modern C++, you could also use a namespace.
 *
 * ============================================================================
 */

#ifndef VALIDATION_H
#define VALIDATION_H

#include <string>

class Validation {
private:
    // Private constructor — nobody should create a Validation object.
    Validation();

public:
    // --- Name Validation ---
    // Rules: Alphabetic characters only, min 5, max 20 characters.
    // Returns true if valid, false otherwise.
    static bool isValidName(const std::string& name);

    // --- Password Validation ---
    // Rules: Min 8, max 20 characters.
    // Returns true if valid, false otherwise.
    static bool isValidPassword(const std::string& password);

    // --- Balance Validation ---
    // Rules: Must be >= 1500.
    static bool isValidBalance(double balance);

    // --- Salary Validation ---
    // Rules: Must be >= 5000.
    static bool isValidSalary(double salary);

    // --- Amount Validation (for deposit/withdraw) ---
    // Rules: Must be > 0.
    static bool isValidAmount(double amount);

    // --- Helper: Check if string is all alphabetic (including spaces) ---
    // Used internally by isValidName.
    // Public so you can reuse it if needed.
    static bool isAlphabetic(const std::string& str);
};

#endif // VALIDATION_H
