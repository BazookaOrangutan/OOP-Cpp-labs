#pragma once
#include <iostream>


template <typename T>
class Queue {
private:
    std::unique_ptr<T[]> data = std::make_unique<T[]>(1);
    int size = 0;
    int capacity = 1;

    void resize() {
        capacity *= 2;
        std::unique_ptr<T[]> buf = std::make_unique<T[]>(capacity);

        for (int i = 0; i < size; ++i) {
            buf[i] = data[i];
        }

        data = std::move(buf);
    }

public:
    void push(const T& entity) {
        if (size >= capacity) {
            resize();
        }
        data[size++] = entity;
    }

    void pop() {
        try {
            if (size <= 0) {
                throw std::exception("Queue is empty");
            }
            std::unique_ptr<T[]> buf = std::make_unique<T[]>(capacity);
            for (int i = 1; i < size; ++i) {
                buf[i - 1] = data[i];
            }
            size--;
            data = std::move(buf);
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << std::endl;
        }
    }

    void displayAll() const {
        for (int i = 0; i < size; ++i) {
            std::cout << data[i] << ", ";
        }
        std::cout << std::endl;
    }
};