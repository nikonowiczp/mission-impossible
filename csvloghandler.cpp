#include "csvloghandler.h"
#include <iostream>
#include <fstream>

CSVLogHandler::CSVLogHandler()
{

}

void CSVLogHandler::SaveGame(int _points)
{
    std::ofstream _file(this->filePath, std::ios::app);
    if (_file)
    {
        _file << _points << std::endl;
    }
    _file.close();
}

std::vector<int> CSVLogHandler::ReadGames()
{
    std::ifstream _file(this->filePath);
    std::vector<int> _games = {};
    if (_file)
    {
        std::string _line;
        int _points;
        while (std::getline(_file, _line))
        {
            try
            {
               _points = std::stoi(_line);
               _games.push_back(_points);
            }
            catch (...) {}
        }
    }
    _file.close();
    sort(_games.begin(), _games.end(), std::greater<int>());
    return _games;
}

CSVLogHandler::~CSVLogHandler()
{

}
