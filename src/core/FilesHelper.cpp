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
#include "Parser.h"
#include "../models/Client.h"
#include "../models/Employee.h"
#include "../models/Admin.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

void FilesHelper::saveLast(const string &fileName, int id)
{
  ofstream file(fileName, ios::trunc);
  if (file.is_open())
  {
    file << id;
    file.close();
  }
}

int FilesHelper::getLast(const string &fileName)
{
  ifstream file(fileName);
  if (file.is_open())
  {
    int id;
    file >> id;
    file.close();
    return id;
  }

  return 0; // File doesn't exist or is empty
}

void FilesHelper::saveClient(const Client &c)
{
  ofstream file("data/clients.txt", ios::app);
  if (file.is_open())
  {
    file << c.getId() << "," << c.getName() << "," << c.getPassword() << "," << c.getBalance() << endl;
    file.close();
  }

  saveLast("data/last_client_id.txt", c.getId());
}

void FilesHelper::saveEmployee(const string &fileName, const string &lastIdFile, const Employee &e)
{
  ofstream file(fileName, ios::app);
  if (file.is_open())
  {
    file << e.getId() << "," << e.getName() << "," << e.getPassword() << "," << e.getSalary() << endl;
    file.close();
  }

  saveLast(lastIdFile, e.getId());
}

void FilesHelper::saveAdmin(const string &fileName, const string &lastIdFile, const Admin &a)
{
  ofstream file(fileName, ios::app);
  if (file.is_open())
  {
    file << a.getId() << "," << a.getName() << "," << a.getPassword() << "," << a.getSalary() << endl;
    file.close();
  }

  saveLast(lastIdFile, a.getId());
}

std::vector<Client> FilesHelper::getClients()
{
  vector<Client> clients;
  ifstream file("data/clients.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      clients.push_back(Parser::parseToClient(line));
    }

    file.close();
  }

  return clients;
}

std::vector<Employee> FilesHelper::getEmployees()
{
  vector<Employee> employees;
  ifstream file("data/employees.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      employees.push_back(Parser::parseToEmployee(line));
    }

    file.close();
  }

  return employees;
}

std::vector<Admin> FilesHelper::getAdmins()
{
  vector<Admin> admins;
  ifstream file("data/admins.txt");
  if (file.is_open())
  {
    string line;
    while (getline(file, line))
    {
      admins.push_back(Parser::parseToAdmin(line));
    }

    file.close();
  }

  return admins;
}

void FilesHelper::clearFile(const string &fileName, const string &lastIdFile)
{
  ofstream file(fileName, ios::trunc);
  if (file.is_open())
  {
    file.close();
  }

  saveLast(lastIdFile, 0);
}
