#pragma once

#include <vector>
#include <memory>
#include <algorithm>
#include <fstream>
#include <iostream>
#include "User.h"
#include "Resource.h"

template <typename T>
class AccessControlSystem {
private:
    std::vector<std::shared_ptr<User>> users;
    std::vector<Resource> resources;

public:
    void addUser(std::shared_ptr<User> user) {
        users.push_back(user);
    }
    void addResource(const Resource& resource) {
        resources.push_back(resource);
    }
    void checkAllAccess() {
        for (const auto& user : users) {
            std::cout << "Access for " << user->getName() << ":\n";
            for (const auto& res : resources) {
                std::cout << " - " << res.getName() << ": "
                    << (res.checkAccess(*user) ? "Allowed" : "Denied") << "\n";
            }
        }
    }
    void listUsers() const {
        for (const auto& user : users) {
            user->displayInfo();
        }
    }
    void saveToFile(const std::string& filename) const {
        std::ofstream out(filename);
        for (const auto& user : users) {
            out << user->getName() << "," << user->getId() << "," << user->getAccessLevel() << "\n";
        }
    }
    void loadFromFile(const std::string& filename) {
        std::ifstream in(filename);
        std::string name;
        int id, level;
        while (in >> name >> id >> level) {
            users.push_back(std::make_shared<Administrator>(name, id, level));
        }
    }
    std::shared_ptr<User> findUserById(int id) const {
        for (const auto& user : users) {
            if (user->getId() == id)
                return user;
        }
        return nullptr;
    }
    void sortUsersByAccess() {
        std::sort(users.begin(), users.end(), [](const auto& a, const auto& b) {
            return a->getAccessLevel() > b->getAccessLevel();
        });
    }
};



