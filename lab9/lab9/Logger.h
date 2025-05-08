#pragma once

#include <fstream>
#include <string>

template <typename T>
class Logger {
public:
    static void log(const T& message) {
        std::ofstream file("log.txt", std::ios::app);
        if (file) {
            file << message << "\n";
        }
    }
};

