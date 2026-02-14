/*
 * ============================================================================
 * FileManager.h — Concrete implementation of DataSourceInterface
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   FileManager is the CONCRETE class that actually saves/loads data
 *   to/from text files. It implements the DataSourceInterface.
 *
 *   This is POLYMORPHISM applied to architecture:
 *     - DataSourceInterface defines WHAT operations are available
 *     - FileManager defines HOW they work (using text files)
 *
 *   If you later want a DatabaseManager, you implement
 *   DataSourceInterface again with SQL logic. The rest of the system
 *   doesn't change — it only talks to DataSourceInterface*.
 *
 * DESIGN DECISIONS:
 *   - Inherits from DataSourceInterface (public).
 *   - Delegates actual file I/O to FilesHelper (composition pattern).
 *     FileManager orchestrates, FilesHelper does raw I/O.
 *
 *   - This is the "Strategy Pattern" in simplified form:
 *     DataSourceInterface = Strategy interface
 *     FileManager = Concrete strategy (file-based)
 *
 *   - You learned this pattern conceptually in Day 6 with Shape*
 *     pointing to Circle or Rectangle. Same concept, bigger scale.
 *
 * ============================================================================
 */

#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include <string>
#include <vector>

class FileManager : public DataSourceInterface
{
private:
  static const std::string CLIENTS_FILE;
  static const std::string EMPLOYEES_FILE;
  static const std::string ADMINS_FILE;
  static const std::string LAST_CLIENT_ID_FILE;
  static const std::string LAST_EMPLOYEE_ID_FILE;
  static const std::string LAST_ADMIN_ID_FILE;

public:
  // Constructor / Destructor
  FileManager();
  ~FileManager() override;

  // DataSourceInterface Implementation
  void addClient(const Client &client) override;
  void addEmployee(const Employee &employee) override;
  void addAdmin(const Admin &admin) override;

  std::vector<Client> getAllClients() override;
  std::vector<Employee> getAllEmployees() override;
  std::vector<Admin> getAllAdmins() override;

  void removeAllClients() override;
  void removeAllEmployees() override;
  void removeAllAdmins() override;
};

#endif // FILEMANAGER_H
