/*
** EPITECH PROJECT, 2021
** 206neutrinos [WSL: Ubuntu]
** File description:
** test_neutrinos
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "neutrinos.h"

extern calc_t *calc;

Test(basic_test, neutrinos_exit, .exit_code=0)
{
    calc = malloc(sizeof(calc_t));
    calc->_aritmetic = 0;
    calc->_harmonic = 0;
    calc->_nb = 0;
    calc->_sd = 0;

    quadratique(333, 333);
}

Test(basic_test_harmonic, neutrinos_exit, .exit_code=0)
{
    calc = malloc(sizeof(calc_t));
    calc->_aritmetic = 0;
    calc->_harmonic = 0;
    calc->_nb = 0;
    calc->_sd = 0;

    harmonic(333);
}

Test(basic_test_aritmetic, neutrinos_exit, .exit_code=0)
{
    calc = malloc(sizeof(calc_t));
    calc->_aritmetic = 0;
    calc->_harmonic = 0;
    calc->_nb = 0;
    calc->_sd = 0;

    aritmetic(333);
}

Test(basic_test_sd, neutrinos_exit, .exit_code=0)
{
    calc = malloc(sizeof(calc_t));
    calc->_aritmetic = 0;
    calc->_harmonic = 0;
    calc->_nb = 0;
    calc->_sd = 0;

    sd(333, 333);
}