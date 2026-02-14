/*
 * ============================================================================
 * Person.h — Base class for all people in the Bank System
 * ============================================================================
 *
 * BUSINESS CONTEXT:
 *   Every user in the system (Client, Employee, Admin) shares a common
 *   identity: id, name, and password. Instead of duplicating these in
 *   every class, we extract them into a base class.
 *
 * DESIGN DECISIONS:
 *   - Abstract base class: Person alone has no business meaning.
 *     You never create "just a Person". You create a Client, Employee,
 *     or Admin. The pure virtual display() enforces this.
 *
 *   - Virtual destructor: MANDATORY. We will store Person* pointers
 *     (for polymorphism in login, password update, etc.). Without a
 *     virtual destructor, deleting through a base pointer causes
 *     undefined behavior — the derived destructor never runs.
 *
 *   - Protected members: id, name, password are protected so derived
 *     classes can access them directly. Setters are public because
 *     they carry validation logic that must be enforced everywhere.
 *
 *   - const correctness: All getters are const. They do not modify
 *     the object. This is a habit you must build — it tells the
 *     compiler AND the reader "this function is safe to call on
 *     const objects."
 *
 * WHY NOT just put everything in Client?
 *   Because Employee and Admin share the SAME fields (id, name, password).
 *   The hint in your requirements says: "create Person which contains
 *   name, id, password and let Client, Employee inherit from Person,
 *   Admin inherits from Employee."
 *
 * ============================================================================
 */

#ifndef PERSON_H
#define PERSON_H

#include <string>

// NOTE: We do NOT use "using namespace std;" in headers.
// Reason: Any file that #includes this header would get the entire
// std namespace injected — that causes name collisions in large projects.
// Always use std:: prefix in headers. In .cpp files, "using namespace std;"
// is acceptable if you prefer.

class Person {
protected:
    int id;
    std::string name;
    std::string password;

public:
    // --- Constructors ---
    Person();
    Person(int id, const std::string& name, const std::string& password);

    // --- Virtual Destructor ---
    // WHY virtual? Because we will use Person* pointers polymorphically.
    // Rule: If a class has ANY virtual function, its destructor must be virtual.
    virtual ~Person();

    // --- Getters (const — they don't modify the object) ---
    int getId() const;
    const std::string& getName() const;
    const std::string& getPassword() const;

    // --- Setters (with validation — see Validation utility) ---
    // These call Validation methods internally.
    // The validation rules are:
    //   name: alphabetic only, min 5, max 20 characters
    //   password: min 8, max 20 characters
    void setName(const std::string& name);
    void setPassword(const std::string& password);

    // --- Pure Virtual: Forces every derived class to implement display ---
    // WHY pure virtual? A "Person" has no meaningful display format.
    // A Client shows balance. An Employee shows salary. They differ.
    virtual void display() const = 0;
};

#endif // PERSON_H
