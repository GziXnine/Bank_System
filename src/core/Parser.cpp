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

vector<string> Parser::split(const string &line, char delimiter)
{
  vector<string> result;

  size_t start = 0;
  size_t end = line.find(delimiter);

  while (end != string::npos)
  {
    result.push_back(line.substr(start, end - start));
    start = end + 1;
    end = line.find(delimiter, start);
  }

  result.push_back(line.substr(start));

  return result;
}

Client Parser::parseToClient(const string &line)
{
  vector<string> fields = split(line, ',');

  int id = stoi(fields[0]);
  double balance = stod(fields[3]);

  if (fields.size() >= 4)
    return Client(id, fields[1], fields[2], balance);
  else
    return Client();
}

Employee Parser::parseToEmployee(const string &line)
{
  vector<string> fields = split(line, ',');

  int id = stoi(fields[0]);
  double salary = stod(fields[3]);

  if (fields.size() >= 4)
    return Employee(id, fields[1], fields[2], salary);
  else
    return Employee();
}

Admin Parser::parseToAdmin(const string &line)
{
  vector<string> fields = split(line, ',');

  int id = stoi(fields[0]);
  double salary = stod(fields[3]);

  if (fields.size() >= 4)
    return Admin(id, fields[1], fields[2], salary);
  else
    return Admin();
}
