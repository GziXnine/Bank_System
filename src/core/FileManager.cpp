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

const string FileManager::CLIENTS_FILE = "data/clients.txt";
const string FileManager::EMPLOYEES_FILE = "data/employees.txt";
const string FileManager::ADMINS_FILE = "data/admins.txt";
const string FileManager::LAST_CLIENT_ID_FILE = "data/last_client_id.txt";
const string FileManager::LAST_EMPLOYEE_ID_FILE = "data/last_employee_id.txt";
const string FileManager::LAST_ADMIN_ID_FILE = "data/last_admin_id.txt";

FileManager::FileManager() {};

FileManager::~FileManager() {};

void FileManager::addClient(const Client &client)
{
  FilesHelper::saveClient(client);
}

std::vector<Client> FileManager::getAllClients()
{
  return FilesHelper::getClients();
}

void FileManager::removeAllClients()
{
  FilesHelper::clearFile(CLIENTS_FILE, LAST_CLIENT_ID_FILE);
}

// --- Employee Operations ---
void FileManager::addEmployee(const Employee &employee)
{
  FilesHelper::saveEmployee(EMPLOYEES_FILE, LAST_EMPLOYEE_ID_FILE, employee);
}

std::vector<Employee> FileManager::getAllEmployees()
{
  return FilesHelper::getEmployees();
}

void FileManager::removeAllEmployees()
{
  FilesHelper::clearFile(EMPLOYEES_FILE, LAST_EMPLOYEE_ID_FILE);
}

void FileManager::addAdmin(const Admin &admin)
{
  FilesHelper::saveAdmin(ADMINS_FILE, LAST_ADMIN_ID_FILE, admin);
}

std::vector<Admin> FileManager::getAllAdmins()
{
  return FilesHelper::getAdmins();
}

void FileManager::removeAllAdmins()
{
  FilesHelper::clearFile(ADMINS_FILE, LAST_ADMIN_ID_FILE);
}
