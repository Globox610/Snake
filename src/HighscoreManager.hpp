#pragma once
#include <string>

class HighScoreManager
{
public:
    void writeToFile(const std::string& name, int score);
    std::string readFromFile();
};
