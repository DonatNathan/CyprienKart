/*
** EPITECH PROJECT, 2021
** MY_PUTSTR
** File description:
** It's a program that display the caracters of a string
*/

#include "my.h"

void my_putstr(char const *str)
{
    while (*str != '\0') {
        my_putchar(*str);
        str += 1;
    }
}
