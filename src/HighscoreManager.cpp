#include "HighscoreManager.hpp"
#include <fstream>
#include <sstream>

void HighScoreManager::writeToFile(const std::string& name, int score)
{
    std::fstream stream("Highscores.txt", std::ios::app);

    if (stream.is_open())
    {
        std::stringstream returnString;
        returnString << name << ": " << score << "\n";
        stream << returnString.str();
    }
}

std::string HighScoreManager::readFromFile()
{
    std::fstream stream("Highscores.txt");
    std::string returnString;
    std::string newString;
    if (stream.is_open())
    {
        while (std::getline(stream, returnString))
        {
            newString += returnString;
        }
    }


    return newString;


}
