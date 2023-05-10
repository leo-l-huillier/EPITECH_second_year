/*
** EPITECH PROJECT, 2022
** nts
** File description:
** Main.cpp
*/

// #include "namespace/nts.hpp"
#include "parsing/parsing.hpp"
#include <iostream>
#include <string>

int main(int argc, char **argv)
{
    // nts::glb gl;
    std::string filepath = argv[1];
    checkFile(filepath);

    return 0;
}