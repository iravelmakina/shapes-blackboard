#pragma once
#include "Blackboard.h"


class CLI {
public:
    CLI();

    void run();

private:
    Blackboard blackboard;

    void executeCommand(const std::string &command);

    static void showMenu();

    static std::pair<int, int> getBlackboardSize();

    static std::string getString();

    static std::string getFilePath() ;

    void handleAddCommand();

    static bool isValidMeasurement(const std::string &parameterStr);

    static bool getCoordinates(int &x, int &y);

    static bool getParameters(int &param1, int &param2);

    static bool getParameters(int &param1);

    static bool getParameters(int &param1, int &param2, int &param3, int &param4);
};
