/*
** EPITECH PROJECT, 2023
** ntsToPush
** File description:
** testParcing.cpp
*/

#include <criterion/criterion.h>
#include <criterion/redirect.h>
#include <criterion/assert.h>

#include "../../src/parsing/parsing.hpp"
#include <iostream>

Test(parsing, badNts)
{
    cr_assert_eq(checkFile("tests/bad.nts"), 84);
}

Test(parsing, empty)
{
    cr_assert_eq(checkFile("tests/empty.nts"), 84);
}

Test(parsing, notNts)
{
    cr_assert_eq(checkFile("tests/file.notnts"), 84);
}

Test(parsing, noChipset)
{
    cr_assert_eq(checkFile("tests/noChipset.nts"), 84);
}

Test(parsing, noLinks)
{
    cr_assert_eq(checkFile("tests/noLinks.nts"), 84);
}

Test(parsing, doNotExist)
{
    cr_assert_eq(checkFile("tests/doNotExist.nts"), 84);
}

Test(parsing, good)
{
    cr_assert_eq(checkFile("tests/example.nts"), 0);
}
