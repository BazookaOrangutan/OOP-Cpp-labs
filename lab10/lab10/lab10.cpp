#include <iostream>
#include "AccessControlSystem.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

int main() {
    AccessControlSystem<User> system;

    system.addUser(std::make_shared<Student>("Alice", 1, 2, "CS-101"));
    system.addUser(std::make_shared<Teacher>("Bob", 2, 4, "Math"));
    system.addUser(std::make_shared<Administrator>("Eve", 3, 5));

    system.addResource(Resource("Library", 1));
    system.addResource(Resource("Lab", 3));
    system.addResource(Resource("Admin Room", 5));

    std::cout << "\n--- User List ---\n";
    system.listUsers();

    std::cout << "\n--- Access Check ---\n";
    system.checkAllAccess();

    std::cout << "\n--- Sorted Users by Access Level ---\n";
    system.sortUsersByAccess();
    system.listUsers();
}
