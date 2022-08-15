/*
** EPITECH PROJECT, 2022
** Untitled (Workspace)
** File description:
** sm_printf
*/

#include "sm_printf.hpp"


void sm_printf(const char *format, ...)
{
    va_list ap;
    va_start(ap, format);
    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            i++;
            std::string flag = flags_tab[format[i]](format + i, ap);
            formats_tab[format[i]](ap);
        } else {
            std::cout << format[i];
        }
    }
    va_end(ap);
}