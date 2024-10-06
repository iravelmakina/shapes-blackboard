#include "CLI.h"
#include <iostream>


CLI::CLI() : blackboard(0, 0) {
    std::pair<int, int> size = getBlackboardSize();
    const int width = size.first;
    const int height = size.second;
    blackboard = Blackboard(width, height);
}


void CLI::run() {
    std::string command;
    showMenu();
    do {
        std::cout << "Command: ";
        command = getString();
        executeCommand(command);
    } while (command != "exit");
}


void CLI::executeCommand(const std::string &command) {
    if (command == "draw") {
        blackboard.draw();
    } else if (command == "list") {
        blackboard.list();
    } else if (command == "shapes") {
        Blackboard::shapes();
    } else if (command == "add") {
        handleAddCommand();
    } else if (command == "undo") {
        blackboard.undo();
    } else if (command == "clear") {
        blackboard.clear();
    } else if (command == "save") {
        const std::string filepath = getFilePath();
        blackboard.save(filepath);
    } else if (command == "load") {
        const std::string filepath = getFilePath();
        blackboard.load(filepath);
    } else if (command == "menu") {
        showMenu();
    } else if (command == "exit") {
        std::cout << "Exiting ..." << std::endl;
    } else {
        std::cout << "Invalid command. Please, try again." << std::endl;
    }
}


void CLI::showMenu() {
    std::cout << "Enter command:\n"
            << "draw: Draw blackboard\n"
            << "list: Print all added shapes with their IDs and parameters\n"
            << "shapes: Print a list of all available shapes and parameters for add call\n"
            << "add: Add shape to the blackboard\n"
            << "undo: Remove the last added shape from the blackboard\n"
            << "clear: Remove all shapes from blackboard\n"
            << "save: Save the blackboard to the file\n"
            << "load: Load a blackboard from the file\n"
            << "menu: Show menu\n"
            << "exit: Exit\n";
}


std::pair<int, int> CLI::getBlackboardSize() {
    std::string widthStr, heightStr;
    do {
        std::cout << "Enter blackboard width: ";
        widthStr = getString();
        std::cout << "Enter blackboard height: ";
        heightStr = getString();

        if (!isValidMeasurement(widthStr) || !isValidMeasurement(heightStr)) {
            std::cout << "Invalid dimensions. Please, try again." << std::endl;
        }
    } while (!isValidMeasurement(widthStr) || !isValidMeasurement(heightStr));

    int width = std::stoi(widthStr);
    int height = std::stoi(heightStr);

    return {width, height};
}


std::string CLI::getString() {
    std::string input;
    do {
        std::getline(std::cin, input);
        std::transform(input.begin(), input.end(), input.begin(), ::tolower);
        if (input.empty()) {
            std::cout << "Error: Input cannot be empty. Please, try again." << std::endl;
        }
    } while (input.empty());
    return input;
}


std::string CLI::getFilePath() {
    std::string filePath;
    do {
        std::cout << "File path: ";
        std::getline(std::cin, filePath);
        if (filePath.empty()) {
            std::cout << "Error: File path cannot be empty. Please, try again." << std::endl;
        }
    } while (filePath.empty());
    return filePath;
}


void CLI::handleAddCommand() {
    int x, y, param1, param2;
    std::string figureName;

    do {
        std::cout << "Figure: ";
        figureName = getString();
        if (figureName != "line" && figureName != "circle" && figureName != "rectangle" && figureName != "triangle") {
            std::cout << "Invalid figure type. Please, try again." << std::endl;
        }
    } while (figureName != "line" && figureName != "circle" && figureName != "rectangle" && figureName != "triangle");

    getCoordinates(x, y);

    if (figureName == "line") {
        do {
            if (getParameters(param1, param2)) {
                blackboard.add(0, x, y, param1, param2);
                break;
            }
        } while (true);
    } else if (figureName == "circle") {
        do {
            if (getParameters(param1)) {
                blackboard.add(1, x, y, param1);
                break;
            }
        } while (true);
    } else if (figureName == "rectangle") {
        do {
            if (getParameters(param1, param2)) {
                blackboard.add(2, x, y, param1, param2);
                break;
            }
        } while (true);
    } else if (figureName == "triangle") {
        int param4;
        int param3;
        do {
            if (getParameters(param1, param2, param3, param4)) {
                blackboard.add(3, x, y, param1, param2, param3, param4);
                break;
            }
        } while (true);
    }
}


bool CLI::isValidMeasurement(const std::string &parameterStr) {
    if (std::all_of(parameterStr.begin(), parameterStr.end(), ::isdigit)) {
        const int parameter = std::stoi(parameterStr);
        return parameter > 0;
    }
    return false;
}


bool CLI::getCoordinates(int &x, int &y) {
    while (true) {
        std::cout << "x1: ";
        const std::string xStr = getString();
        std::cout << "y1: ";
        const std::string yStr = getString();

        if (isValidMeasurement(xStr) && isValidMeasurement(yStr)) {
            x = std::stoi(xStr);
            y = std::stoi(yStr);
            return true;
        }
        std::cout << "Invalid coordinates. Please, try again." << std::endl;
    }
}


bool CLI::getParameters(int &param1, int &param2) {
    std::cout << "x2: ";
    const std::string param1Str = getString();
    std::cout << "y2: ";
    const std::string param2Str = getString();

    if (!isValidMeasurement(param1Str) || !isValidMeasurement(param2Str)) {
        std::cout << "Invalid parameters. Please, try again." << std::endl;
        return false;
    }

    param1 = std::stoi(param1Str);
    param2 = std::stoi(param2Str);
    return true;
}


bool CLI::getParameters(int &param1) {
    std::cout << "radius: ";
    std::string param1Str = getString();

    if (!isValidMeasurement(param1Str)) {
        std::cout << "Invalid parameter. Please, try again." << std::endl;
        return false;
    }

    param1 = std::stoi(param1Str);
    return true;
}


bool CLI::getParameters(int &param1, int &param2, int &param3, int &param4) {
    std::cout << "x2: ";
    const std::string param1Str = getString();
    std::cout << "y2: ";
    const std::string param2Str = getString();
    std::cout << "x3: ";
    const std::string param3Str = getString();
    std::cout << "y3: ";
    const std::string param4Str = getString();

    if (!isValidMeasurement(param1Str) || !isValidMeasurement(param2Str) ||
        !isValidMeasurement(param3Str) || !isValidMeasurement(param4Str)) {
        std::cout << "Invalid parameters. Please, try again." << std::endl;
        return false;
    }

    param1 = std::stoi(param1Str);
    param2 = std::stoi(param2Str);
    param3 = std::stoi(param3Str);
    param4 = std::stoi(param4Str);
    return true;
}
