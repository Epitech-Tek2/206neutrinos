/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203neutrinos-clement.muth [WSL: Ubuntu]
** File description:
** neutrinos
*/

#pragma once

#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <math.h>
#include <stdnoreturn.h>
#include "../library/includes/assert.h"

typedef struct calc_s calc_t;
typedef struct pair_s pair;
typedef struct getline_s getline_t;

typedef char const *restrict const *restrict arr_const_restrict;
typedef char const *restrict str_const_restrict;

#define MIN(a,b) (((a)<(b))?(a):(b))
#define MAX(a,b) (((a)>(b))?(a):(b))

#define my_free(ptr, ...) my_free(_N__ARG(__VA_ARGS__), ptr, ##__VA_ARGS__)

#define cOut(messsage) printf("%s\n", message)
#define cErr(message) fprintf(stderr, "%s\n", message)

/**
 * @brief Internal error handler
 *
 */
#define eraise(...) ({ \
    cErr(strerror(errno)); \
    my_free(NULL, ##__VA_ARGS__); \
    exit(84); \
})

/**
 * @brief User error handler
 *
 */
#define uraise(error, ...) ({ \
    cErr(error); \
    my_free(NULL, ##__VA_ARGS__); \
    exit(84); \
})

void main_for_test(int const _ac, arr_const_restrict _av);

void quadratique(double const _stock, double const _root);

void harmonic(double const _value);

void sd(double const _value, double const _stock);

void aritmetic(double const _value);

void arg_handling(int _ac, arr_const_restrict _av);

struct calc_s
{
    double _nb;
    double _aritmetic;
    double _harmonic;
    double _sd;
};

struct pair_s
{
    double first;
    double second;
};

struct getline_s
{
    size_t _size;
    char *_line;
};

#include "inline.h"

void neutrinos();