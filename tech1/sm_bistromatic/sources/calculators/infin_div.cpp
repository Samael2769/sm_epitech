/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** infin_div
*/

#include <sm_bistromatic.hpp>
#include <iostream>

//return the division between num and quo
std::string infin_div(std::string num, std::string den)
{
    std::string quotient;
    std::string str;
    std::string tmp;
    std::string index = "0";
    if (findBiggest(num, den) == 1) {
        quotient = "0";
        return quotient;
    }
    if (num == den) {
        quotient = "1";
        return quotient;
    }
    for (int i = 0; i < num.size(); ++i) {
        str = "";
        index = "0";
        tmp += num.at(i);
        while (findBiggest(str, tmp) != 0) {
            str = infin_mult(den, index);
            index = infin_add(index, "1");
        }
        index = infin_sub(index, "2");
        quotient = quotient + index;
        str = infin_mult(den, index);
        tmp = infin_sub(tmp, str);
    }
    deleteZeros(quotient);
    return quotient;
}