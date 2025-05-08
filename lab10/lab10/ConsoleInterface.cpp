#include "ConsoleInterface.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"
#include <iostream>
#include <limits>

void ConsoleInterface::showMenu() const {
    std::cout << "\n--- Access Control Menu ---\n"
        << "1. Add User\n"
        << "2. Add Resource\n"
        << "3. Show All Users\n"
        << "4. Show All Resources\n"
        << "5. Check Access\n"
        << "6. Save Data\n"
        << "7. Load Data\n"
        << "8. Find User by ID\n"
        << "9. Find Users by Name\n"
        << "10. List Users Sorted\n"
        << "0. Exit\n"
        << "Choice: ";
}

void ConsoleInterface::addUser() {
    std::string name, type;
    int level;
    std::cout << "Enter user type (student/teacher/admin): ";
    std::cin >> type;

    if (type != "student" && type != "teacher" && type != "admin")
        throw std::invalid_argument("Invalid type.");

    std::cout << "Enter name: ";
    std::cin >> name;
    std::cout << "Enter access level: ";
    std::cin >> level;

    if (type == "student") {
        std::string group;
        std::cout << "Enter group: ";
        std::cin >> group;
        system.addUser(std::make_shared<Student>(name, level, group));
    }
    else if (type == "teacher") {
        std::string department;
        std::cout << "Enter department: ";
        std::cin >> department;
        system.addUser(std::make_shared<Teacher>(name, level, department));
    }
    else if (type == "admin") {
        system.addUser(std::make_shared<Administrator>(name, level));
    }
}

void ConsoleInterface::addResource() {
    int access;
    std::string name;
    std::cout << "Enter resource name: ";
    std::cin >> name;
    std::cout << "Enter required access level: ";
    std::cin >> access;
    system.addResource(Resource(name, access));
}

void ConsoleInterface::checkAccess() {
    int uid, rid;
    std::cout << "Enter User ID: ";
    std::cin >> uid;
    std::cout << "Enter Resource ID: ";
    std::cin >> rid;
    auto user = system.findUserById(uid);
    auto res = system.findResourceById(rid);
    if (!user || !res) {
        std::cout << "User or resource not found.\n";
    }
    else {
        std::cout << "Access: " << (res->checkAccess(*user) ? "Allowed" : "Denied") << "\n";
    }
}

void ConsoleInterface::searchUserById() {
    int id;
    std::cout << "Enter ID to search: ";
    std::cin >> id;
    auto user = system.findUserById(id);
    if (user) user->displayInfo();
    else std::cout << "User not found.\n";
}

void ConsoleInterface::searchUsersByName() {
    std::string name;
    std::cout << "Enter name (partial match): ";
    std::cin >> name;
    auto results = system.findUsersByName(name);
    if (results.empty()) {
        std::cout << "No users found.\n";
    }
    else {
        for (const auto& user : results) {
            user->displayInfo();
        }
    }
}

void ConsoleInterface::sortAndListUsers() {
    std::string field;
    std::cout << "Sort by (id/name/access): ";
    std::cin >> field;
    system.listUsersSorted(field);
}

void ConsoleInterface::run() {
    system.loadFromFile("users.txt");
    system.loadResourcesFromFile("resources.txt");

    int choice;
    while (true) {
        showMenu();
        std::cin >> choice;
        try {
            switch (choice) {
            case 0: return;
            case 1: addUser(); break;
            case 2: addResource(); break;
            case 3: system.listUsers(); break;
            case 4: system.listResources(); break;
            case 5: checkAccess(); break;
            case 6:
                system.saveToFile("users.txt");
                system.saveResourcesToFile("resources.txt");
                std::cout << "Data saved.\n";
                break;
            case 7:
                system.loadFromFile("users.txt");
                system.loadResourcesFromFile("resources.txt");
                std::cout << "Data loaded.\n";
                break;
            case 8: searchUserById(); break;
            case 9: searchUsersByName(); break;
            case 10: sortAndListUsers(); break;
            default:
                std::cout << "Invalid option.\n";
            }
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << '\n';
            std::cin.clear();
            std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        }
    }
}
