/*
 * ============================================================================
 * DataSourceInterface.h — Abstract interface for data persistence
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   The system needs to SAVE and LOAD data (clients, employees, admins).
 *   Right now, we save to text files. But tomorrow, we might use:
 *     - A database (SQLite, MySQL)
 *     - JSON files
 *     - A web API
 *
 *   By defining an ABSTRACT INTERFACE, we decouple the business logic
 *   from the storage mechanism. The rest of the system talks to
 *   DataSourceInterface, not to "files" directly.
 *
 * DESIGN DECISIONS:
 *   - Pure abstract class (all pure virtual methods): This is an
 *     INTERFACE in C++ (like Java's interface). You cannot create
 *     a DataSourceInterface object — you create a FileManager object
 *     that IMPLEMENTS this interface.
 *
 *   - You learned abstract classes in Day 6 (Shape, Creature).
 *     This is the same concept but applied to ARCHITECTURE, not
 *     just shapes. This is a key step in your growth as a developer.
 *
 *   - Virtual destructor: Required because we might hold a pointer
 *     DataSourceInterface* ds = new FileManager();
 *     and delete through the base pointer.
 *
 * DEPENDENCY DIRECTION:
 *   FileManager → implements → DataSourceInterface
 *   Services (managers) → depend on → DataSourceInterface (not FileManager)
 *   This is called "Dependency Inversion" — depend on abstractions,
 *   not on concrete classes.
 *
 * ============================================================================
 */

#ifndef DATASOURCEINTERFACE_H
#define DATASOURCEINTERFACE_H

#include <vector>

// Forward declarations — we only need these as parameter/return types.
// Full includes go in the .cpp files of classes that implement this.
class Client;
class Employee;
class Admin;

class DataSourceInterface {
public:
    // --- Virtual Destructor (MANDATORY for abstract base classes) ---
    virtual ~DataSourceInterface() = default;

    // --- Client Operations ---
    virtual void addClient(const Client& client) = 0;
    virtual std::vector<Client> getAllClients() = 0;
    virtual void removeAllClients() = 0;

    // --- Employee Operations ---
    virtual void addEmployee(const Employee& employee) = 0;
    virtual std::vector<Employee> getAllEmployees() = 0;
    virtual void removeAllEmployees() = 0;

    // --- Admin Operations ---
    virtual void addAdmin(const Admin& admin) = 0;
    virtual std::vector<Admin> getAllAdmins() = 0;
    virtual void removeAllAdmins() = 0;

    /*
     * CORRECTED: Changed void to vector<T> return types.
     * This allows managers to process the results (search, display, etc.)
     * instead of just printing directly from the data layer.
     */
};

#endif // DATASOURCEINTERFACE_H
