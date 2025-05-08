#pragma once

#include "AccessControlSystem.h"
#include <memory>

class ConsoleInterface
{
    AccessControlSystem<User> system;

    void showMenu() const;
    void addUser();
    void addResource();
    void checkAccess();
    void searchUserById();
    void searchUsersByName();
    void sortAndListUsers();

public:
    void run();
};

