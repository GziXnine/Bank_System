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
#include <stdexcept>

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

  if (fields.size() < 4)
    throw std::runtime_error("Malformed client line: expected 4 fields");

  try
  {
    int id = stoi(fields[0]);
    double balance = stod(fields[3]);

    return Client(id, fields[1], fields[2], balance);
  }
  catch (const std::invalid_argument &ex)
  {
    throw std::runtime_error(string("Invalid numeric value in client fields: ") + ex.what());
  }
  catch (const std::out_of_range &ex)
  {
    throw std::runtime_error(string("Numeric value out of range in client fields: ") + ex.what());
  }
  catch (const std::exception &ex)
  {
    throw std::runtime_error(string("Failed to parse client fields: ") + ex.what());
  }
}

Employee Parser::parseToEmployee(const string &line)
{
  vector<string> fields = split(line, ',');

  if (fields.size() < 4)
    throw std::runtime_error("Malformed employee line: expected 4 fields");

  try
  {
    int id = stoi(fields[0]);
    double salary = stod(fields[3]);

    return Employee(id, fields[1], fields[2], salary);
  }
  catch (const std::invalid_argument &ex)
  {
    throw std::runtime_error(string("Invalid numeric value in employee fields: ") + ex.what());
  }
  catch (const std::out_of_range &ex)
  {
    throw std::runtime_error(string("Numeric value out of range in employee fields: ") + ex.what());
  }
  catch (const std::exception &ex)
  {
    throw std::runtime_error(string("Failed to parse employee fields: ") + ex.what());
  }
}

Admin Parser::parseToAdmin(const string &line)
{
  vector<string> fields = split(line, ',');

  if (fields.size() < 4)
    throw std::runtime_error("Malformed admin line: expected 4 fields");

  try
  {
    int id = stoi(fields[0]);
    double salary = stod(fields[3]);

    return Admin(id, fields[1], fields[2], salary);
  }
  catch (const std::invalid_argument &ex)
  {
    throw std::runtime_error(string("Invalid numeric value in admin fields: ") + ex.what());
  }
  catch (const std::out_of_range &ex)
  {
    throw std::runtime_error(string("Numeric value out of range in admin fields: ") + ex.what());
  }
  catch (const std::exception &ex)
  {
    throw std::runtime_error(string("Failed to parse admin fields: ") + ex.what());
  }
}
