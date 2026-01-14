#pragma once
#include <string>

class HighScoreManager
{
public:
    void WriteToFile(const std::string& name, int score);
    std::string ReadFromFile();
};
