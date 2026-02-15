/*
 * ============================================================================
 * FilesHelper.h — Low-level file I/O operations
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   This class handles the RAW file operations:
 *     - Read lines from a file
 *     - Write lines to a file
 *     - Get the last used ID (for auto-incrementing IDs)
 *     - Save the last ID
 *     - Clear a file
 *
 *   It does NOT know about Client, Employee, or Admin objects.
 *   It only knows about files and strings. The Parser converts
 *   between strings and objects.
 *
 * DESIGN DECISIONS:
 *   - All static: No state needed. Pure file operations.
 *
 *   - saveLast / getLast: Requirements say to save the last ID to a file.
 *     This is for auto-incrementing IDs when creating new records.
 *     Each entity type (Client, Employee, Admin) has its own last-ID file.
 *
 *   - saveClient/saveEmployee: The requirements list these as methods of
 *     FilesHelper. They format the object as a string line and append it
 *     to the appropriate file. This couples FilesHelper to the models,
 *     which breaks our separation slightly.
 *
 *   MENTOR NOTE ON DESIGN TENSION:
 *     Ideally, FilesHelper would ONLY deal with strings and files,
 *     and the FileManager would handle object-to-string conversion
 *     (using Parser). But the requirements explicitly put saveClient()
 *     in FilesHelper. Follow the requirements, but understand that
 *     in a cleaner design, this would be in FileManager.
 *
 * FILE STRUCTURE:
 *   data/clients.txt     — One client per line: "id,name,password,balance"
 *   data/employees.txt   — One employee per line: "id,name,password,salary"
 *   data/admins.txt      — One admin per line: "id,name,password,salary"
 *   data/last_client_id.txt    — Single number: last used client ID
 *   data/last_employee_id.txt  — Single number: last used employee ID
 *   data/last_admin_id.txt     — Single number: last used admin ID
 *
 * ============================================================================
 */

#ifndef FILESHELPER_H
#define FILESHELPER_H

#include <string>
#include <vector>

class Client;
class Employee;
class Admin;

class FilesHelper
{
private:
  FilesHelper();

public:
  // Save the last used ID to a file (for auto-increment).
  static void saveLast(const std::string &fileName, int id);

  // Get the last used ID from a file. Returns 0 if file doesn't exist.
  static int getLast(const std::string &fileName);

  // Append a client record as a line to the clients file.
  static void saveClient(const Client &c);

  // Append an employee record to the employees file.
  static void saveEmployee(const std::string &fileName, const std::string &lastIdFile, const Employee &e);

  // Append an admin record to the admins file.
  static void saveAdmin(const std::string &fileName, const std::string &lastIdFile, const Admin &a);

  // Load All Records (returns vectors)
  static std::vector<Client> getClients();
  static std::vector<Employee> getEmployees();
  static std::vector<Admin> getAdmins();

  // Update existing records (rewrites entire file)
  static void updateAllClients(const std::vector<Client> &clients);
  static void updateAllEmployees(const std::vector<Employee> &employees);
  static void updateAllAdmins(const std::vector<Admin> &admins);

  // Clear file contents and reset the last ID
  static void clearFile(const std::string &fileName, const std::string &lastIdFile);
};

#endif // FILESHELPER_H
