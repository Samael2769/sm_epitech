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

void print_char(va_list ap)
{
    char c = va_arg(ap, int);
    std::cout << c;
}

void print_string(va_list ap)
{
    std::string s = va_arg(ap, char*);
    std::cout << s;
}

void print_int(va_list ap)
{
    int i = va_arg(ap, int);
    std::cout << i;
}

void print_float(va_list ap)
{
    float f = va_arg(ap, double);
    std::cout << f;
}

void print_pointer(va_list ap)
{
    void *p = va_arg(ap, void*);
    std::cout << p;
}

void print_binary(va_list ap)
{
    int i = va_arg(ap, int);
    std::cout << std::bitset<sizeof(int) * 8>(i);
}

void print_octal(va_list ap)
{
    int i = va_arg(ap, int);
    std::cout << std::oct << i;
}

void print_hex(va_list ap)
{
    int i = va_arg(ap, int);
    std::cout << std::hex << i;
}

void print_hex_maj(va_list ap)
{
    int i = va_arg(ap, int);
    std::cout << std::hex << std::uppercase << i;
}

void print_unsigned(va_list ap)
{
    unsigned int i = va_arg(ap, unsigned int);
    std::cout << i;
}

void print_percent(va_list ap)
{
    std::cout << '%';
}

void print_float_exp(va_list ap)
{
    float f = va_arg(ap, double);
    std::cout << std::scientific << f;
}

void print_float_exp_maj(va_list ap)
{
    float f = va_arg(ap, double);
    std::cout << std::scientific << std::uppercase << f;
}

void print_float_dec(va_list ap)
{
    float f = va_arg(ap, double);
    std::cout << std::fixed << f;
}

void print_float_dec_maj(va_list ap)
{
    float f = va_arg(ap, double);
    std::cout << std::fixed << std::uppercase << f;
}

void print_argSize(va_list ap)
{
    int i = va_arg(ap, int);
    std::cout << i;
}