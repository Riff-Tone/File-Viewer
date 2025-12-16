//
// Created by Diego Gayosso Hernandez on 12/14/25.
//

#include "File.h"

#include <string>
#include <iostream>
#include <filesystem>
namespace fs = std::filesystem;

File::File() {
    populate(rootPath);

}

void File::populate(const std::string& path) {
    for (auto & entry : fs::directory_iterator(path)){
        list.push_back(entry);
    }

}

void File::printAllPaths() const {
    for (const auto & arg : list) {
        std::cout << arg.path().string() << std::endl;
    }
}

void File::printAllFiles() const {
    for (const auto & arg : list) {
        std::cout << arg.path().filename() << std::endl;
    }
}

void File::printOnlyDirectories() const {
    for (const auto & arg : list) {
        if (arg.is_directory()) {
            std::cout << arg.path().filename() << std::endl;
        }
    }
}

void File::printOnlyFiles() {
    for (const auto & arg : list) {
        if (arg.is_regular_file()) {
            std::cout << arg.path().filename() << std::endl;
        }
    }
}
void ChangePath() {
    std::cout << "Implement" << std::endl;
}





