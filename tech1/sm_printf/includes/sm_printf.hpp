/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_printf
*/

#ifndef SM_PRINTF_HPP_
#define SM_PRINTF_HPP_

#include <map>
#include <stdarg.h>
#include <string>
#include <iostream>
#include <utility>

std::string print_char(va_list ap);
std::string print_string(va_list ap);
std::string print_int(va_list ap);
std::string print_float(va_list ap);
std::string print_pointer(va_list ap);
std::string print_binary(va_list ap);
std::string print_octal(va_list ap);
std::string print_hex(va_list ap);
std::string print_hex_maj(va_list ap);
std::string print_unsigned(va_list ap);
std::string print_percent(va_list ap);
std::string print_float(va_list ap);
std::string print_float_exp(va_list ap);
std::string print_float_exp_maj(va_list ap);
std::string print_float_dec(va_list ap);
std::string print_float_dec_maj(va_list ap);
std::string print_argSize(va_list ap);

std::pair<int, std::string> flag_numbers(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);
std::pair<int, std::string> flag_zero(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);
std::pair<int, std::string> flag_minus(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);
std::pair<int, std::string> flag_plus(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);
std::pair<int, std::string> flag_space(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);
std::pair<int, std::string> flag_hash(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);
std::pair<int, std::string> flag_precision(std::string arg, va_list ap, int &i, std::pair<int, std::string> &ret);

std::map<char, std::pair<int, std::string> (*)(std::string, va_list, int &, std::pair<int, std::string> &)> flags_tab = {
    {'#', &flag_hash},
    {'0', &flag_zero},
    {'-', &flag_minus},
    {'+', &flag_plus},
    {'1', &flag_numbers},
    {'2', &flag_numbers},
    {'3', &flag_numbers},
    {'4', &flag_numbers},
    {'5', &flag_numbers},
    {'6', &flag_numbers},
    {'7', &flag_numbers},
    {'8', &flag_numbers},
    {'9', &flag_numbers},
    {'.', &flag_precision},
};


std::map<char, std::string (*)(va_list)> formats_tab = {
    {'c', &print_char},
    {'s', &print_string},
    {'d', &print_int},
    {'i', &print_int},
    {'u', &print_unsigned},
    {'x', &print_hex},
    {'X', &print_hex_maj},
    {'b', &print_binary},
    {'o', &print_octal},
    {'p', &print_pointer},
    {'%', &print_percent},
    {'f', &print_float},
    {'e', &print_float_exp},
    {'E', &print_float_exp_maj},
    {'g', &print_float_dec},
    {'G', &print_float_dec_maj},
    {'n', &print_argSize}
};

#endif /* !SM_PRINTF_HPP_ */
