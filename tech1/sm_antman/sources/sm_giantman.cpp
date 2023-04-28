/**
 * @ Author: Samael
 * @ Create Time: 2023-04-11 07:09:12
 * @ Modified by: Samael
 * @ Modified time: 2023-04-28 05:48:46
 * @ Description:
 */

#include "sm_giantman.hpp"
#include <sstream>


sm_giantman::sm_giantman(std::string path, int type) {
    this->path = path;
    this->type = type;
    if (type == 1) {
        read_file();
        int i = 0;
        for (auto it = dict.begin(); it != dict.end(); it++) {
            if (i == 0) {
                i++;
                continue;
            }
            std::cout << it->second << std::endl;
        }
    }
    if (type == 0)
        read_file2();
}

sm_giantman::~sm_giantman() {
}

std::vector<std::string> split(std::string str, char c)
{
    std::vector<std::string> result;
    std::string tmp;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == c) {
            result.push_back(tmp);
            tmp = "";
        } else {
            tmp += str[i];
        }
    }
    result.push_back(tmp);
    return result;
}

void sm_giantman::mapping(std::string pattern, int key)
{
    int value = 0;
    std::vector<std::string> tmp = split(pattern, '/');
    for (int i = 0; i < tmp.size(); i++) {
        if (tmp[i] == "")
            continue;
        if (tmp[i].find('-') != std::string::npos) {
            std::vector<std::string> tmp2 = split(tmp[i], '-');
            for (int j = std::stoi(tmp2[0]); j <= std::stoi(tmp2[1]); j++) {
                dict[j] = key;
            }
        } else {
            dict[std::stoi(tmp[i])] = key;
        }
    }

}

void sm_giantman::read_file() {
    std::ifstream file;
    int i = 0;
    file.open(this->path);
    if (!file.is_open()) {
        std::cout << "File open failed!" << std::endl;
        return;
    }
    std::string line;
    while (std::getline(file, line)) {
        if (i < 3) {
            i++;
            std::cout << line << std::endl;
            continue;
        }
        if (line[0] == '#') {
            std::cout << line << std::endl;
            continue;
        }
        std::string key = line.substr(0, line.find(' '));
        std::string value = line.substr(line.find(' ') + 1, line.size());
        mapping(value, std::stoi(key));
    }
    file.close();
}

void sm_giantman::read_file2() {
    std::string line;
    std::string decompressed;
    std::ifstream file;
    file.open(this->path);
    if (!file.is_open()) {
        std::cout << "File open failed!" << std::endl;
        return;
    }
    while (std::getline(file, line)) {
        decompressed += line;
    }
    file.close();
    std::cout << decompress(decompressed) << std::endl;
}

std::string sm_giantman::decompress(const std::string& input)
{
    std::stringstream output;
    int count = 0;
    
    for (size_t i = 0; i < input.length(); i++)
    {
        if (isdigit(input[i]))
        {
            count = count * 10 + (input[i] - '0');
        }
        else
        {
            for (int j = 0; j < count; j++)
            {
                output << input[i];
            }
            
            count = 0;
        }
    }
    
    return output.str();
}