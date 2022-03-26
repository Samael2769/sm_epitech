/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** infin_sub
*/

#include "sm_bistromatic.hpp"
#include <iostream>
#include <string.h>

int findBiggest(std::string &nb1, std::string &nb2)
{
    if (nb1.size() > nb2.size())
        return 0;
    if (nb1.size() < nb2.size())
        return 1;
    if (strcmp(nb1.c_str(), nb2.c_str()) > 0)
        return 0;
    if (strcmp(nb1.c_str(), nb2.c_str()) < 0)
        return 1;
    return 2;
}

void deleteZeros(std::string &nb)
{
    for (int i = 0; i < nb.size(); ++i) {
        if (nb.at(i) == '0') {
            nb.erase(nb.begin() + i);
        } else {
            break;
        }
    }
}

std::string infin_sub(std::string nb1, std::string nb2)
{
    if (nb1 == nb2)
        return "0";
    std::vector<std::string> vec;
    vec.push_back(nb1);
    vec.push_back(nb2);
    int pow = findBiggest(nb1, nb2);
    std::reverse(vec[pow].begin(), vec[pow].end());
    std::reverse(vec[!pow].begin(), vec[!pow].end());
    std::string result;
    fillZeros(vec[pow], vec[!pow]);
    int ret = 0;
    for (int i = 0; i < vec[pow].size(); ++i) {
        size_t nb1 = (vec[pow].at(i) - '0') - ret;
        size_t nb2 = (vec[!pow].at(i) - '0');
        if (nb1 < nb2)
            ret = 1;
        else
            ret = 0;
        int res = (nb1 + (ret * 10)) - nb2;
        result += (res + '0');
    }
    std::reverse(result.begin(), result.end());
    deleteZeros(result);
    return result;
}