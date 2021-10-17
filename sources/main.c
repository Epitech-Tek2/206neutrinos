/*
** EPITECH PROJECT, 2021
** B-MAT-400-STG-4-1-203hotline-clement.muth [WSL: Ubuntu]
** File description:
** main
*/

#include <ctype.h>
#include <math.h>
#include <time.h>
#include <errno.h>
#include "neutrinos.h"
#include "../library/utils/includes/index.h"

calc_t *calc = NULL;

noreturn bool help(str_const_restrict _filepath, int const _output)
{
    char *lineptr = NULL;
    size_t i = 500;
    FILE *stream = GET(FILE *, {
        my_assert(_filepath, PROTO_DATA, ASSERT_INFO("Cannot read property '_filepath' of undefined", ERR_TYPE, FAIL_EXEC), NULL);
        return (fopen(_filepath, "r"));
    });

    while (-1 != getline(&lineptr, &i, stream) && (printf("%s", lineptr)));
    free(lineptr);
    fclose(stream);
    exit(_output);
}

static void arg_handling(int _ac, arr_const_restrict _av)
{
    if (4 != _ac) raise();
    for (int i = 0; i < _ac; i++)
        if (!issdigit(_av[i])) uraise("Arguments must be an integer", calc);
}

static void aritmetic(double const _value)
{
    calc->_aritmetic = ((calc->_aritmetic * (calc->_nb - 1)) + _value) / calc->_nb;
}

static void sd(double const _value, double const _stock)
{
    double tmp = ((pow(calc->_sd, 2) + pow(_stock, 2)) * (calc->_nb - 1)) + pow(_value, 2);

    calc->_sd = sqrt(tmp / calc->_nb - pow(calc->_aritmetic, 2));
    printf("    Standard deviation: %.2lf\n", calc->_sd);
}

static void harmonic(double const _value)
{
    calc->_harmonic = calc->_nb / ((1 / _value) + ((calc->_nb - 1) / calc->_harmonic));
    printf("    Harmonic mean:\t%.2lf\n", calc->_harmonic);
}

static void quadratique(double const _stock, double const _root)
{
    double ret = sqrt((((pow(calc->_sd, 2) + pow(_stock, 2)) * (calc->_nb - 1.0)) + pow(_root, 2)) / calc->_nb);
    printf("    Root mean square:\t%.2lf\n", ret);
}

void neutrinos()
{
    getline_t *stdcin = malloc(sizeof(getline_t));
    double value = 0;
    double stock = 0;

    my_assert(calc != NULL, PROTO_DATA, ASSERT_INFO(strerror(errno), ERR_ALC84, FAIL_EXEC), NULL);
    stdcin->_line = NULL;
    stdcin->_size = 500;
    printf("Enter next value: ");
    while (getline(&stdcin->_line, &stdcin->_size, stdin) && strcmp(stdcin->_line, "END\n") != 0) {
        calc->_nb++;
        if (!issdigit(stdcin->_line)) uraise("value must be an integer", stdcin->_line);
        value = atof(stdcin->_line);
        printf("    Number of values:\t%0.lf\n", calc->_nb);
        stock = calc->_aritmetic;
        aritmetic(value);
        sd(value, stock);
        printf("    Arithmetic mean:\t%.2lf\n", calc->_aritmetic);
        quadratique(stock, atof(stdcin->_line));
        harmonic(value);
        printf("\nEnter next value: ");
    }
    my_free(stdcin->_line, stdcin);
}

int main(int const _ac, arr_const_restrict _av)
{
    errno = 0;
    calc = malloc(sizeof(calc_t));
    my_assert(calc != NULL, PROTO_DATA, ASSERT_INFO(strerror(errno), ERR_ALC84, FAIL_EXEC), NULL);
    if (2 == _ac && !strcmp(_av[1], "-h")) help("./help.txt", 0);
    _av++;
    arg_handling(_ac - 1, _av);
    calc->_nb = atof(_av[0]);
    calc->_aritmetic = atof(_av[1]);
    calc->_harmonic = atof(_av[2]);
    calc->_sd = atof(_av[3]);
    neutrinos();
    my_free(calc);
    return (0);
}