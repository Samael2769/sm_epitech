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

void print_char(va_list ap);
void print_string(va_list ap);
void print_int(va_list ap);
void print_float(va_list ap);
void print_pointer(va_list ap);
void print_binary(va_list ap);
void print_octal(va_list ap);
void print_hex(va_list ap);
void print_hex_maj(va_list ap);
void print_unsigned(va_list ap);
void print_percent(va_list ap);
void print_float(va_list ap);
void print_float_exp(va_list ap);
void print_float_exp_maj(va_list ap);
void print_float_dec(va_list ap);
void print_float_dec_maj(va_list ap);
void print_argSize(va_list ap);


std::map<char, void (*)(va_list)> formats_tab = {
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
