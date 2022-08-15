/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_printf
*/

#include "sm_printf.hpp"

std::string getArgs(std::string str, int i)
{
    std::string s;
    for (int j = i; str.size(); j++) {
        if (flags_tab.find(str[j]) == flags_tab.end())
            break;
        s += str[j];
    }
    return s;
}

char getFormat(std::string str, int j)
{
    for (int i = j; i < str.size(); i++) {
        if (formats_tab.find(str[i]) != formats_tab.end())
            return str[i];
    }
    return '\0';
}


void sm_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            std::string left;
            std::string right;
            std::pair<int, std::string> flag;
            std::pair<int, std::string> ret;
            char c = getFormat(format, i);
            bool isLeft = false;
            bool isFlag = true;
            std::string retur = formats_tab[c](ap);
            int size = retur.size();
            while (isFlag) {
                if (flags_tab.find(format[i]) != flags_tab.end()) {
                    size += flag.second.size();
                    ret = make_pair(size, retur);
                    flag = flags_tab[format[i]](format, ap, i, ret);
                    if (flag.first == 1)
                        isLeft = 1;
                    if ((isLeft == 1 && flag.first != 2) || flag.first == 3) {
                        right += flag.second;
                    } else {
                        left += flag.second;
                    }
                } else {
                    isFlag = false;
                }
            }
            std::cout << left;
            std::cout << retur;
            std::cout << right;
        } else {
            std::cout << format[i];
        }
    }
    va_end(ap);
}