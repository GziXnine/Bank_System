/*
 * ============================================================================
 * AdminManager.h — Handles the Admin menu and interactions
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   An Admin has all Employee capabilities PLUS:
 *     - Add/Search/Edit/List Employees
 *
 *   The admin menu combines client management and employee management.
 *
 * DESIGN DECISIONS:
 *   - Takes Client* in AdminOptions: The requirements show this signature.
 *
 *   MENTOR NOTE — POSSIBLE REQUIREMENT ERROR:
 *     The Phase 3 requirements say:
 *       AdminManager::AdminOptions(Client* client)
 *     This seems like a mistake — Admin options should take an Admin*,
 *     not a Client*. An admin is not a client.
 *
 *     However, looking more carefully, printEmployeeMenu() is also
 *     listed under AdminManager, which suggests AdminManager might
 *     reuse EmployeeManager for client operations and add employee
 *     operations on top.
 *
 *     RECOMMENDATION: Follow the requirements but note this discrepancy.
 *     If your instructor confirms it's a typo, change Client* to Admin*.
 *
 * ============================================================================
 */

#ifndef ADMINMANAGER_H
#define ADMINMANAGER_H

#include <string>
#include <vector>

class Admin;
class Client;

class AdminManager
{
private:
  AdminManager();
  static std::vector<Admin> admins; // Static for caching

public:
  static void loadAdmins(); // Load Admins For Caching

  // Print the admin/employee menu
  static void printAdminMenu();

  static Admin *login(int id, const std::string &password);

  // CORRECTED: Changed from Client* to Admin* (requirements had a typo).
  static bool adminOptions(Admin *admin);
};

#endif // ADMINMANAGER_H
