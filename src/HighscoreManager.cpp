#include "HighscoreManager.hpp"
#include <fstream>
#include <sstream>

void HighScoreManager::writeToFile(const std::string& time, int score)
{
    std::fstream stream("Highscores.txt", std::ios::app);

    if (stream.is_open())
    {
        std::stringstream returnString;
        returnString << "Time of playing: " << time << " Score: " << score << "\n";
        stream << returnString.str();
    }
}

std::string HighScoreManager::readFromFile()
{
    std::ifstream file("Highscores.txt");

    std::string line;
    std::string full;
    if (file.is_open())
    {
        while (std::getline(file, line))
        {
            full += line + "\n";
        }
    }


    return full;


}
