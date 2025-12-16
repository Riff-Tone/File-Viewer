//
// Created by Diego Gayosso Hernandez on 12/14/25.
//

#ifndef FILE_VIWER_FILE_H
#define FILE_VIWER_FILE_H
#include <filesystem>
#include <string>


class File {
    public:
    void populate(const std::string &path);

    File();
    void printAllPaths() const;

    void printAllFiles() const;

    void printOnlyDirectories() const;

    void printOnlyFiles();

private:
    const std::string rootPath = "/Users/riff/Documents";
    std::vector<std::filesystem::directory_entry> list;
};


#endif //FILE_VIWER_FILE_H