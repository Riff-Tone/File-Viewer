#include <ftxui/dom/elements.hpp>
#include <ftxui/screen/screen.hpp>
#include <iostream>

#include <string>
#include <iostream>
#include <filesystem>
#include <File.h>
namespace fs = std::filesystem;
File fileManager;
std::string menu[] = {"All Files","all directories","Non-directories"};

void printMenu() {
    for (int i = 0; i < std::size(menu); i++) {
        std::printf("%d: %s\n", i, menu[i].c_str());
    }
}
void clearScreen() {
    std::cout << "\033[2J\033[H";
}

void action(const std::string& input,bool& run) {
    clearScreen();
    switch (stoi(input)) {
        case 0:
            fileManager.printAllFiles();
            break;
        case 1:
            fileManager.printOnlyDirectories();
            break;
        case 2:
            fileManager.printOnlyFiles();
            break;
        case 113:
            run = false;
            break;
        default:
            std::cout << "enter a valid input " << std::endl;
    }
}
void app() {
    bool run = true;
    std::string input;

    while(run) {
        std::cout << "Press Q to quit or selected"<< std::endl;
        printMenu();
        std::cin >> input;
        action(input,run);
        std::cout << std::endl;
    }
}
int main(){
    app();


    return 0;
}
