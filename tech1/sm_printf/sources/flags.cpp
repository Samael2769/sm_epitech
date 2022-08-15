/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** flags
*/

#include <string>
#include <iostream>
#include <stdarg.h>
#include <utility>

#include "usefull.hpp"

std::pair<int, std::string> flag_numbers(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret)
{
    std::string args = getArgs(arg, i);
    i += args.size();
    std::string s;
    for (int j = 0; j < std::stoi(args) - ret.first; j++) {
        s += " ";
    }
    return std::make_pair(0, s);
}

std::pair<int, std::string> flag_minus(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret)
{
    i++;
    return std::make_pair(1, "");
}

std::pair<int, std::string> flag_plus(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret)
{
    char c = getFormat(arg, i + 1);
    i++;
    std::string s = "dioxXufeEgGn";
    if (s.find(c) != std::string::npos)
        return std::make_pair(2, "+");
    return std::make_pair(0, "");
}

std::pair<int, std::string> flag_space(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret)
{
    char c = getFormat(arg, i + 1);
    i++;
    std::string s = "dioxXufeEgGn";
    if (s.find(c) != std::string::npos)
        return std::make_pair(2, " ");
    return std::make_pair(0, "");
}

std::pair<int, std::string> flag_hash(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret)
{
    char c = getFormat(arg, i + 1);
    i++;
    switch(c) {
        case 'o':
            return std::make_pair(2, "0");
        case 'x':
            return std::make_pair(2, "0x");
        case 'X':
            return std::make_pair(2, "0X");
        case 'p':
            return std::make_pair(2, "0x");
        case 'b':
            return std::make_pair(2, "0b");
        case 'e':
            if (ret.second.find(".") == std::string::npos)
                return std::make_pair(3, ".");
        case 'E':
            if (ret.second.find(".") == std::string::npos)
                return std::make_pair(3, ".");
        case 'f':
            if (ret.second.find(".") == std::string::npos)
                return std::make_pair(3, ".");
        case 'g':
            if (ret.second.find(".") == std::string::npos)
                return std::make_pair(3, ".");
        case 'G':
            if (ret.second.find(".") == std::string::npos)
                return std::make_pair(3, ".");
        default:
            return std::make_pair(0, "");
    }
}

std::pair<int, std::string> flag_zero(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret)
{
    std::string args = getArgs(arg, i + 1);
    i += args.size() + 1;
    std::string s;
    for (int j = 0; j < std::stoi(args) - ret.first; j++) {
        s += "0";
    }
    return std::make_pair(0, s);
}