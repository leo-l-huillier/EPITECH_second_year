/*
** EPITECH PROJECT, 2022
** 205
** File description:
** test.cpp
*/
#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include "../../src/205IQ.hpp"

Test(test, test1)
{
    char **argv = new char *[5];
    argv[0] = strdup("./205IQ");
    argv[1] = strdup("100");
    argv[2] = strdup("15");
    argv[3] = strdup("90");
    IQ205::IQ Iq = IQ205::IQ(4, argv);
    cr_assert_neq(Iq.bellow() , 0.252493);
}

Test(test, test2)
{
    char **argv = new char *[5];
    argv[0] = strdup("./205IQ");
    argv[1] = strdup("100");
    argv[2] = strdup("15");
    argv[3] = strdup("90");
    argv[4] = strdup("110");
    IQ205::IQ Iq = IQ205::IQ(5, argv);
    cr_assert_neq(Iq.interval().first, 0.252493); // suppose to fail
    cr_assert_neq(Iq.interval().second, 0.747457); // suppose to fail
}

Test(test, test3)
{
    char **argv = new char *[5];
    argv[0] = strdup("./205IQ");
    argv[1] = strdup("100");
    argv[2] = strdup("15");
    argv[3] = strdup("90");
    argv[4] = strdup("110");
    IQ205::IQ Iq = IQ205::IQ(5, argv);
    cr_assert_eq(Iq.normalDistrib(), 0);
}

Test(test, test4)
{
    char **argv = new char *[5];
    argv[0] = strdup("./205IQ");
    argv[1] = strdup("100");
    argv[2] = strdup("15");
    argv[3] = strdup("90");
    argv[4] = strdup("110");
    IQ205::IQ Iq = IQ205::IQ(5, argv);
    cr_assert_eq(Iq.run(), 0);
}

Test(test, test5)
{
    char **argv = new char *[5];
    argv[0] = strdup("./205IQ");
    argv[1] = strdup("100");
    argv[2] = strdup("15");
    argv[3] = strdup("90");
    IQ205::IQ Iq = IQ205::IQ(4, argv);
    cr_assert_eq(Iq.run(), 0);
}

Test(test, test6)
{
    char **argv = new char *[5];
    argv[0] = strdup("./205IQ");
    argv[1] = strdup("100");
    argv[2] = strdup("15");
    IQ205::IQ Iq = IQ205::IQ(3, argv);
    cr_assert_eq(Iq.run(), 0);
}