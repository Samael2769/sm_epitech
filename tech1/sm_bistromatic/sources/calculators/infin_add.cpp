/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** infin_add
*/

#include "sm_bistromatic.hpp"

static void makeFill(std::string &nb, int size)
{
    for (int i = 0; i < size; ++i)
        nb += "0";
}

void fillZeros(std::string &nb1, std::string &nb2)
{
    if (nb1.size() >= nb2.size())
        makeFill(nb2, nb1.size() - nb2.size());
    else
        makeFill(nb1, nb2.size() - nb1.size());
}

std::string infin_add(std::string n1, std::string n2)
{
    std::string nb1 = n1;
    std::string nb2 = n2;
    std::reverse(nb1.begin(), nb1.end());
    std::reverse(nb2.begin(), nb2.end());
    std::string result;
    fillZeros(nb1, nb2);
    for (int i = 0; i < nb1.size(); ++i) {
        int ret = 0;
        int res = (nb1.at(i) - '0') + (nb2.at(i) - '0');
        if (res > 9) {
            res = 0;
            ret = 1;
        }
        result += (res + ret) + '0';
    }
    std::reverse(result.begin(), result.end());
    return result;
}