#pragma once
#include <iostream>
#include <vector>

template <typename T>
class GameManager {
private:
    std::vector<T> entities;

public:
    void addEntity(const T& entity) {
        if (entity->getHealth() <= 0) {
            throw std::invalid_argument("Entity has invalid health");
        }
        entities.push_back(entity);
    }

    void displayAll() const {
        for (const auto& entity : entities) {
            entity->displayInfo(); 
        }
    }

    const std::vector<T>& getEntities() const {
        return entities;
    }
};