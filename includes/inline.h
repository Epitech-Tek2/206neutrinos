/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203neutrinos-clement.muth [WSL: Ubuntu]
** File description:
** inline
*/

#pragma once

#include "neutrinos.h"

noreturn bool help(char const *restrict _filepath, int const _output);

static void (my_free)(int _count, void *_ptr, ...)
{
    va_list list_ptr;

    free(_ptr);
    for (va_start(list_ptr, _ptr); _count > 0; --_count)
        free(va_arg(list_ptr, void *));
    va_end(list_ptr);
}

/**
 * @brief User error handler returning the helper
 *
 */
__always_inline noreturn void raise()
{
    help("./help.txt", 84);
}

__always_inline bool issdigit(char const *restrict string)
{
    for (int i = 0; string[i]; i++)
        if (!isdigit(string[i]) && string[i] != '.' && string[i] != '\n') return false;
    return true;
}

__always_inline double fact(double _a, double _t)
{
    double res = _a * exp(-_t);

    res += (4 - (3 * _a)) * exp(-2 * _t);
    res += (2 * _a - 4) * exp(-4 * _t);
    return (res);
}

__always_inline double derive(double _a, double _t)
{
    double res = -_a * exp(-_t);

    res -= (4 - 3 * _a) / 2 * exp(-2 * _t);
    res -= (2 * _a - 4) / 4 * exp(-4 * _t);
    return res;
}