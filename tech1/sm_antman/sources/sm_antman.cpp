/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_antman
*/

#include "sm_antman.hpp"
#include <sstream>

sm_antman::sm_antman(std::string path, int type)
{
    _path = path;
    if (type == 1)
        read_file();
    if (type == 0)
        read_file2();
}

sm_antman::~sm_antman()
{
    
}

/**
 * @brief Compress .ppm files
 *
*/
void sm_antman::read_file()
{
    std::ifstream file(_path);
    std::string line;
    int i = -1;
    int bcp = 0;
    int nb = 0;
    bool tape = false;
    std::string tmp = "";
    bool isNew = true;
    if (file.is_open()) {
        while (getline(file, line)) {
            if (line[0] == '#') {
                std::cout << line << std::endl;
                continue;
            }
            i++;
            if (i < 2) {
                std::cout << line << std::endl;
                continue;
            }
            try {  
                if (isNew) {
                    tmp = std::to_string(i - 1);
                    isNew = false;
                }
                nb = std::stoi(line);
                if (nb < 0 || nb > 255)
                    throw std::invalid_argument("Invalid argument");
                if (i == 3)
                    bcp = nb;
                if (nb != bcp) {
                    if (tmp == std::to_string(i - 1))
                        tmp += "/";
                    else
                        tmp += "-" + std::to_string(i - 1) + "/";
                    isNew = true;
                    _dictionary[std::to_string(bcp)] += tmp;
                    bcp = nb;
                }
            } catch (std::invalid_argument) {
                continue;
            }
            if (tape == false) {
                tape = true;
            }
        }
        if (isNew)
            tmp = std::to_string(i);
        if (tmp == std::to_string(i))
            tmp += "/";
        else
            tmp += "-" + std::to_string(i) + "/";
        _dictionary[std::to_string(bcp)] += tmp;
        file.close();
    }
    for (auto it = _dictionary.begin(); it != _dictionary.end(); it++) {
        std::cout << it->first << " " << it->second << std::endl;
    }
}

void sm_antman::read_file2()
{
    std::string line;
    std::string data;
    std::ifstream file(_path);
    if (file.is_open()) {
        while (getline(file, line)) {
            data += line;
        }
        file.close();
    }
    std::cout << compress(data) << std::endl;
}

std::string sm_antman::compress(const std::string& input)
{
    std::stringstream output;
    char last_char = input[0];
    int count = 1;
    
    for (size_t i = 1; i < input.length(); i++)
    {
        if (input[i] == last_char)
        {
            count++;
        }
        else
        {
            output << count << last_char;
            last_char = input[i];
            count = 1;
        }
    }
    
    output << count << last_char;
    
    return output.str();
}