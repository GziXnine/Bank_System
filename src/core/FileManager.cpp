/*
 * ============================================================================
 * FileManager.cpp — Implementation skeleton for FileManager
 * ============================================================================
 */

#include "FileManager.h"
#include "FilesHelper.h"
#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"
#include <vector>

using namespace std;

// --- Static file path constants ---
// Define these paths relative to where the executable runs.
// Create a "data/" folder in your project root for these files.
const string FileManager::CLIENTS_FILE        = "data/clients.txt";
const string FileManager::EMPLOYEES_FILE      = "data/employees.txt";
const string FileManager::ADMINS_FILE         = "data/admins.txt";
const string FileManager::LAST_CLIENT_ID_FILE = "data/last_client_id.txt";
const string FileManager::LAST_EMPLOYEE_ID_FILE = "data/last_employee_id.txt";
const string FileManager::LAST_ADMIN_ID_FILE  = "data/last_admin_id.txt";

// --- Constructor ---
FileManager::FileManager() {
    // TODO: Optionally create the data/ directory if it doesn't exist.
    // Or just ensure it exists before running the app.
}

// --- Destructor ---
FileManager::~FileManager() {
    // Nothing to clean up.
}

// --- Client Operations ---
void FileManager::addClient(const Client& client) {
    // TODO: Delegate to FilesHelper::saveClient(client).
}

std::vector<Client> FileManager::getAllClients() {
    // TODO: Call FilesHelper::getClients() which now returns vector<Client>.
    // Return the result.
}

void FileManager::removeAllClients() {
    // TODO: Delegate to FilesHelper::clearFile(CLIENTS_FILE, LAST_CLIENT_ID_FILE).
}

// --- Employee Operations ---
void FileManager::addEmployee(const Employee& employee) {
    // TODO: Delegate to FilesHelper::saveEmployee(...).
}

std::vector<Employee> FileManager::getAllEmployees() {
    // TODO: Call FilesHelper::getEmployees() which now returns vector<Employee>.
    // Return the result.
}

void FileManager::removeAllEmployees() {
    // TODO: Delegate to FilesHelper::clearFile(EMPLOYEES_FILE, LAST_EMPLOYEE_ID_FILE).
}

// --- Admin Operations ---
void FileManager::addAdmin(const Admin& admin) {
    // TODO: Delegate to FilesHelper::saveAdmin(...).
}

std::vector<Admin> FileManager::getAllAdmins() {
    // TODO: Call FilesHelper::getAdmins() which now returns vector<Admin>.
    // Return the result.
}

void FileManager::removeAllAdmins() {
    // TODO: Delegate to FilesHelper::clearFile(ADMINS_FILE, LAST_ADMIN_ID_FILE).
}
