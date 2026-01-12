#include "GameState.hpp"

void GameState::SetNewHighscore()
{
     highscoreManager.writeToFile(GetDateTime(), currentScore);

}

std::string GameState::GetDateTime()
{
    auto now = std::chrono::system_clock::now();
    std::time_t t = std::chrono::system_clock::to_time_t(now);

    std::tm tm{};
    localtime_s(&tm, &t);

    std::ostringstream oss;
    oss << std::put_time(&tm, "%Y-%m-%d %H:%M:%S");
    return oss.str();
}

std::string GameState::GetAllHighscores()
{
    return highscoreManager.readFromFile();
}
