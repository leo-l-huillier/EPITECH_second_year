/*
** EPITECH PROJECT, 2023
** nts
** File description:
** and.cpp
*/

#include "and.hpp"

namespace nts
{
    // And(std::string name, nts::Type type, int entry_one, int entry_two, int exit);
    And::And(std::string name, nts::Type type, int entry_one, int entry_two, int exitPin) : AComponent(name, type)
    {

    }

    And::~And() = default;

} // namesapce nts