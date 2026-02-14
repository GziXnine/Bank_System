/*
 * ============================================================================
 * FilesHelper.cpp — Implementation skeleton for FilesHelper
 * ============================================================================
 *
 * FILE I/O HINTS:
 *   You'll need these headers:
 *     #include <fstream>   — for ifstream (read) and ofstream (write)
 *     #include <iostream>   — for error messages
 *
 *   Key patterns:
 *     READING:
 *       ifstream file(fileName);
 *       if (file.is_open()) { string line; while(getline(file, line)) { ... } }
 *       file.close();
 *
 *     WRITING (append):
 *       ofstream file(fileName, ios::app);
 *       file << data << endl;
 *       file.close();
 *
 *     WRITING (overwrite):
 *       ofstream file(fileName, ios::trunc);
 *       file << data;
 *       file.close();
 *
 * ============================================================================
 */

#include "FilesHelper.h"
#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

// --- Save Last ID ---
void FilesHelper::saveLast(const string& fileName, int id) {
    // TODO: Write the id to the file (overwrite mode, not append).
    // This file always contains a single number.
}

// --- Get Last ID ---
int FilesHelper::getLast(const string& fileName) {
    // TODO: Read the single number from the file.
    // If file doesn't exist or is empty, return 0.
}

// --- Save Client ---
void FilesHelper::saveClient(const Client& c) {
    // TODO: Format client as "id,name,password,balance"
    // Append to the clients file.
    // Also update the last-ID file.
}

// --- Save Employee ---
void FilesHelper::saveEmployee(const string& fileName,
                               const string& lastIdFile,
                               const Employee& e) {
    // TODO: Format employee as "id,name,password,salary"
    // Append to fileName.
    // Update lastIdFile with the employee's id.
}

// --- Save Admin ---
void FilesHelper::saveAdmin(const string& fileName,
                            const string& lastIdFile,
                            const Admin& a) {
    // TODO: Same pattern as saveEmployee.
}

// --- Get Clients ---
std::vector<Client> FilesHelper::getClients() {
    // TODO: Read all lines from clients.txt.
    // Parse each line into a Client using Parser::parseToClient().
    // Push each Client into a vector and return it.
}

// --- Get Employees ---
std::vector<Employee> FilesHelper::getEmployees() {
    // TODO: Same pattern for employees.txt.
    // Return vector<Employee>.
}

// --- Get Admins ---
std::vector<Admin> FilesHelper::getAdmins() {
    // TODO: Same pattern for admins.txt.
    // Return vector<Admin>.
}

// --- Clear File ---
void FilesHelper::clearFile(const string& fileName, const string& lastIdFile) {
    // TODO: Open fileName in trunc mode (erases contents).
    // Reset lastIdFile to 0.
}
