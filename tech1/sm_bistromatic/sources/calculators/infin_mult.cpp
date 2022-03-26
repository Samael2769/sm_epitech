/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** infin_mult
*/

#include "sm_bistromatic.hpp"
#include <iostream>

void addZeros(std::string &nb, int size)
{
    for (int i = 0; i < size; ++i)
        nb += "0";
}

std::string infin_mult(std::string s1, std::string s2)
{
    std::vector<std::string> vec;
    std::string res = "0";
    vec.push_back(s1);
    vec.push_back(s2);
    bool pow = findBiggest(vec[0], vec[1]);
    std::reverse(vec[0].begin(), vec[0].end());
    std::reverse(vec[1].begin(), vec[1].end());
    size_t rec = 0;
    int b_i_res;
    if (s1 == "0" || s2 == "0")
        return "0";
    for (size_t i = 0; i < vec[!pow].size(); ++i) {
        std::string b_res;
        for (size_t j = 0; j < vec[pow].size(); ++j) {
            b_i_res = (vec[!pow][i] - '0') * (vec[pow][j] - '0') + rec;
            if (b_i_res > 9) {
                rec = b_i_res / 10;
                b_i_res %= 10;
            } else 
                rec = 0;
            b_res += b_i_res + '0';
        }
        b_res += rec + '0';
        std::reverse(b_res.begin(), b_res.end());
        addZeros(b_res, i);
        res = infin_add(res, b_res);
    }
    deleteZeros(res);
    return res;
}