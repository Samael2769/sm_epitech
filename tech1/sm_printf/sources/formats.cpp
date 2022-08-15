/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** flags
*/

#include <stdarg.h>
#include <string>
#include <iostream>
#include <bitset>
#include <sstream>

std::string print_char(va_list ap)
{
    char c = va_arg(ap, int);
    return std::string(1, c);
}

std::string print_string(va_list ap)
{
    std::string s = va_arg(ap, char*);
    return s;
}

std::string print_int(va_list ap)
{
    int i = va_arg(ap, int);
    return std::to_string(i);
}

std::string print_float(va_list ap)
{
    float f = va_arg(ap, double);
    return std::to_string(f);
}

std::string print_pointer(va_list ap)
{
    void *p = va_arg(ap, void*);
    return std::to_string((long)p);
}

std::string print_binary(va_list ap)
{
    int i = va_arg(ap, int);
    return std::bitset<32>(i).to_string();
}

std::string print_octal(va_list ap)
{
    int i = va_arg(ap, int);
    std::stringstream ss;
    ss << std::oct << i;
    return ss.str();
}

std::string print_hex(va_list ap)
{
    int i = va_arg(ap, int);
    std::stringstream ss;
    ss << std::hex << i;
    return ss.str();
}

std::string print_hex_maj(va_list ap)
{
    int i = va_arg(ap, int);
    std::stringstream s;
    s << std::hex << i << std::uppercase;
    return s.str();
}

std::string print_unsigned(va_list ap)
{
    unsigned int i = va_arg(ap, unsigned int);
    return std::to_string(i);
}

std::string print_percent(va_list ap)
{
    return "%";
}

std::string print_float_exp(va_list ap)
{
    float f = va_arg(ap, double);
    std::stringstream ss;
    ss << std::scientific << f;
    return ss.str();
}

std::string print_float_exp_maj(va_list ap)
{
    float f = va_arg(ap, double);
    std::stringstream ss;
    ss << std::scientific << f << std::uppercase;
    return ss.str();
}

std::string print_float_dec(va_list ap)
{
    float f = va_arg(ap, double);
    std::stringstream ss;
    ss << std::fixed << f;
    return ss.str();
}

std::string print_float_dec_maj(va_list ap)
{
    float f = va_arg(ap, double);
    std::stringstream ss;
    ss << std::fixed << f << std::uppercase;
    return ss.str();
}

std::string print_argSize(va_list ap)
{
    int i = va_arg(ap, int);
    return std::to_string(i);
}