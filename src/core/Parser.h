/*
 * ============================================================================
 * Parser.h — Converts between string lines and model objects
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   Data is stored in text files as lines like:
 *     "1,Ahmed,password123,5000.0"
 *
 *   We need to:
 *     1. SPLIT a line into fields (id, name, password, balance/salary)
 *     2. CONVERT those fields into a Client, Employee, or Admin object
 *
 *   This is the PARSING layer — it translates between the file format
 *   and the in-memory objects.
 *
 * DESIGN DECISIONS:
 *   - All static methods: Parser has no state. It's a utility class,
 *     like Validation. Same pattern — private constructor, all static.
 *
 *   - Returns objects by value: parseToClient returns a Client object.
 *     This is fine — modern C++ compilers apply Return Value Optimization
 *     (RVO), so no unnecessary copies are made.
 *
 *   - split() returns vector<string>: This is a general-purpose string
 *     splitting function. The other methods call split() internally.
 *
 * MENTOR NOTE:
 *   You haven't used std::vector<std::string> in your course yet
 *   (you built custom List<T> templates). This is a good time to
 *   learn the STL — std::vector is what professionals use.
 *
 *   For splitting strings, look into:
 *     - std::stringstream with std::getline (delimiter version)
 *     - std::string::find + std::string::substr
 *
 * ============================================================================
 */

#ifndef PARSER_H
#define PARSER_H

#include <string>
#include <vector>

// Forward declarations
class Client;
class Employee;
class Admin;

class Parser {
private:
    Parser();  // Prevent instantiation

public:
    // --- Split a line by delimiter (default: comma) ---
    // Input:  "1,Ahmed,pass123,5000"
    // Output: {"1", "Ahmed", "pass123", "5000"}
    static std::vector<std::string> split(const std::string& line, char delimiter = ',');

    // --- Parse a line into a Client object ---
    // Expected format: "id,name,password,balance"
    static Client parseToClient(const std::string& line);

    // --- Parse a line into an Employee object ---
    // Expected format: "id,name,password,salary"
    static Employee parseToEmployee(const std::string& line);

    // --- Parse a line into an Admin object ---
    // Expected format: "id,name,password,salary"
    static Admin parseToAdmin(const std::string& line);

    /*
     * CONFIRMED: Comma delimiter is used throughout.
     * File format: "id,name,password,balance" or "id,name,password,salary"
     */
};

#endif // PARSER_H
