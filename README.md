# Bank System — OOP Project

## Architecture Overview

A console-based bank system with 3 user roles: **Client**, **Employee**, **Admin**.
Built with clean OOP principles: inheritance, polymorphism, encapsulation, abstraction.

## Folder Structure

```
Bank_System/
├── data/                          # Runtime data files (auto-generated)
│   ├── clients.txt
│   ├── employees.txt
│   ├── admins.txt
│   ├── last_client_id.txt
│   ├── last_employee_id.txt
│   └── last_admin_id.txt
│
├── src/
│   ├── main.cpp                   # Entry point — calls Screens::runApp()
│   │
│   ├── models/                    # Domain entities (WHAT things ARE)
│   │   ├── Person.h / .cpp        # Abstract base: id, name, password
│   │   ├── Client.h / .cpp        # Person + balance + banking operations
│   │   ├── Employee.h / .cpp      # Person + salary + client management
│   │   └── Admin.h / .cpp         # Employee + employee management
│   │
│   ├── core/                      # Data layer (HOW data is stored/loaded)
│   │   ├── DataSourceInterface.h  # Abstract interface for persistence
│   │   ├── FileManager.h / .cpp   # Implements DataSourceInterface (files)
│   │   ├── FilesHelper.h / .cpp   # Low-level file I/O operations
│   │   └── Parser.h / .cpp        # String ↔ Object conversion
│   │
│   ├── services/                  # Business logic layer (WHAT happens)
│   │   ├── ClientManager.h / .cpp     # Client login + menu workflow
│   │   ├── EmployeeManager.h / .cpp   # Employee login + menu workflow
│   │   ├── AdminManager.h / .cpp      # Admin login + menu workflow
│   │   └── Screens.h / .cpp           # UI screens + main app loop
│   │
│   └── utils/                     # Shared utilities
│       └── Validation.h / .cpp    # Input validation (name, password, etc.)
│
├── Business Model/                # Requirements documentation (images)
└── README.md
```

## Class Hierarchy

```
Person (abstract)
  ├── Client        (has balance, banking operations)
  └── Employee      (has salary, manages clients)
        └── Admin   (manages employees + inherits client management)
```

## Dependency Direction

```
Screens → Managers → Models
                  → Core (FileManager, Parser, FilesHelper)
                  → Utils (Validation)
```

Dependencies flow **downward only**. Models never depend on Services.

## Compilation

All `.cpp` files must be compiled together:

```bash
g++ -o bank_system src/main.cpp \
    src/models/Person.cpp src/models/Client.cpp \
    src/models/Employee.cpp src/models/Admin.cpp \
    src/core/FileManager.cpp src/core/FilesHelper.cpp src/core/Parser.cpp \
    src/services/ClientManager.cpp src/services/EmployeeManager.cpp \
    src/services/AdminManager.cpp src/services/Screens.cpp \
    src/utils/Validation.cpp
```

## Phases

- **Phase 1**: Model classes (Person, Client, Employee, Admin, Validation)
- **Phase 2**: Data layer (DataSourceInterface, FileManager, FilesHelper, Parser)
- **Phase 3**: Service layer (ClientManager, EmployeeManager, AdminManager, Screens)
