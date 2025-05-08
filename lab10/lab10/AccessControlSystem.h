#pragma once

#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <algorithm>
#include <sstream>
#include "Resource.h"
#include "User.h"
#include "Student.h"
#include "Teacher.h"
#include "Administrator.h"

template <typename T>
class AccessControlSystem {
private:
    std::vector<std::shared_ptr<T>> users;
    std::vector<Resource> resources;

    void updateNextUserId() {
        int maxId = 0;
        for (const auto& user : users) {
            if (user->getId() > maxId) maxId = user->getId();
        }
        User::setNextId(maxId + 1);
    }

    void updateNextResourceId() {
        int maxId = 0;
        for (const auto& res : resources) {
            if (res.getId() > maxId) maxId = res.getId();
        }
        Resource::setNextId(maxId + 1);
    }

public:
    void addUser(std::shared_ptr<T> user) {
        users.push_back(user);
    }

    void addResource(const Resource& res) {
        resources.push_back(res);
    }

    void listUsers() const {
        for (const auto& user : users) {
            user->displayInfo();
        }
    }

    void listResources() const {
        for (const auto& r : resources) {
            std::cout << "[Resource] ID: " << r.getId()
                << ", Name: " << r.getName()
                << ", Required Access Level: " << r.getRequiredAccessLevel() << '\n';
        }
    }

    std::shared_ptr<T> findUserById(int id) const {
        for (const auto& user : users) {
            if (user->getId() == id) return user;
        }
        return nullptr;
    }

    std::vector<std::shared_ptr<T>> findUsersByName(const std::string& name) const {
        std::vector<std::shared_ptr<T>> result;
        for (const auto& user : users) {
            if (user->getName().find(name) != std::string::npos) {
                result.push_back(user);
            }
        }
        return result;
    }

    const Resource* findResourceById(int id) const {
        for (const auto& r : resources) {
            if (r.getId() == id) return &r;
        }
        return nullptr;
    }

    void listUsersSorted(const std::string& byField) const {
        std::vector<std::shared_ptr<User>> sortedUsers = users;

        if (byField == "id") {
            std::sort(sortedUsers.begin(), sortedUsers.end(),
                [](const auto& a, const auto& b) { return a->getId() < b->getId(); });
        }
        else if (byField == "name") {
            std::sort(sortedUsers.begin(), sortedUsers.end(),
                [](const auto& a, const auto& b) { return a->getName() < b->getName(); });
        }
        else if (byField == "access") {
            std::sort(sortedUsers.begin(), sortedUsers.end(),
                [](const auto& a, const auto& b) { return a->getAccessLevel() < b->getAccessLevel(); });
        }
        else {
            std::cout << "Invalid sort field.\n";
            return;
        }

        for (const auto& user : sortedUsers) {
            user->displayInfo();
        }
    }

    void saveToFile(const std::string& filename) const {
        std::ofstream out(filename);
        for (const auto& user : users) {
            if (auto s = std::dynamic_pointer_cast<Student>(user)) {
                out << "student," << s->getName() << "," << s->getId() << "," << s->getAccessLevel() << "," << s->getGroup() << "\n";
            }
            else if (auto t = std::dynamic_pointer_cast<Teacher>(user)) {
                out << "teacher," << t->getName() << "," << t->getId() << "," << t->getAccessLevel() << "," << t->getDepartment() << "\n";
            }
            else if (auto a = std::dynamic_pointer_cast<Administrator>(user)) {
                out << "admin," << a->getName() << "," << a->getId() << "," << a->getAccessLevel() << "\n";
            }
        }
    }

    void loadFromFile(const std::string& filename) {
        users.clear();
        std::ifstream in(filename);
        std::string line;
        while (std::getline(in, line)) {
            std::stringstream ss(line);
            std::string type, name, extra;
            int id, level;
            std::getline(ss, type, ',');
            std::getline(ss, name, ',');
            ss >> id;
            ss.ignore();
            ss >> level;
            ss.ignore();

            if (type == "student") {
                std::getline(ss, extra);
                addUser(std::make_shared<Student>(name, level, extra));
            }
            else if (type == "teacher") {
                std::getline(ss, extra);
                addUser(std::make_shared<Teacher>(name, level, extra));
            }
            else if (type == "admin") {
                addUser(std::make_shared<Administrator>(name, level));
            }
        }
        updateNextUserId();

    }

    void saveResourcesToFile(const std::string& filename) const {
        std::ofstream out(filename);
        for (const auto& res : resources) {
            out << res.getId() << "," << res.getName() << "," << res.getRequiredAccessLevel() << "\n";
        }
    }

    void loadResourcesFromFile(const std::string& filename) {
        resources.clear();
        std::ifstream in(filename);
        int id, access;
        std::string name;
        char comma;
        while (in >> id >> comma && std::getline(in, name, ',') && in >> access) {
            resources.emplace_back(name, access);
        }

        updateNextResourceId();
    }
};

