/*
** EPITECH PROJECT, 2023
** nts
** File description:
** clock.cpp
*/

#include "clock.hpp"

namespace nts
{
    Clock::Clock(std::string &name, nts::Type &type) : AComponent(name, type)
    {
        _name = name;
        _type = type;
        // faire d'autre chose ici genre feur
    }

    Clock::~Clock() = default;

    Tristate Clock::compute(std::vector<pins> entryPins)
    {
        if (entryPins[0].getValue() == Tristate::True)
        {
            entryPins[0].setLink(Tristate::False);
            return Tristate::False;
        }
        else if (entryPins[0].getValue() == Tristate::False)
        {
            entryPins[0].setLink(Tristate::False);
            return Tristate::True;
        }
        return Tristate::Undefined;
    }

} // namespace nts