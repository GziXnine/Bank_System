/*
 * ============================================================================
 * Parser.cpp — Implementation skeleton for Parser
 * ============================================================================
 */

#include "Parser.h"
#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"
#include <sstream>

using namespace std;

// --- Split ---
vector<string> Parser::split(const string& line, char delimiter) {
    // TODO: Split the line by delimiter into a vector of strings.
    //
    // APPROACH (using stringstream):
    //   1. Create a stringstream from the line.
    //   2. Use getline(ss, token, delimiter) in a loop.
    //   3. Push each token into the result vector.
    //
    // HINT:
    //   stringstream ss(line);
    //   string token;
    //   while (getline(ss, token, delimiter)) { result.push_back(token); }
}

// --- Parse to Client ---
Client Parser::parseToClient(const string& line) {
    // TODO:
    //   1. Call split(line) to get fields.
    //   2. Convert fields: stoi(fields[0]) for id, stod(fields[3]) for balance.
    //   3. Construct and return a Client object.
    //
    // ERROR HANDLING: What if the line has fewer than 4 fields?
    // At minimum, check fields.size() >= 4 before accessing.
}

// --- Parse to Employee ---
Employee Parser::parseToEmployee(const string& line) {
    // TODO: Same pattern as parseToClient.
    // Fields: id, name, password, salary
}

// --- Parse to Admin ---
Admin Parser::parseToAdmin(const string& line) {
    // TODO: Same pattern.
    // Fields: id, name, password, salary
}
