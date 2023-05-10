/*
** EPITECH PROJECT, 2023
** nts
** File description:
** xor.cpp
*/
#include "xor.hpp"

namespace nts
{
    Xor::Xor(std::string &name, nts::Type &type) : AComponent(name, type)
    {
        _type = type;
        _name = name;
        std::vector<AComponent> component;
        component.push_back(Add_Component(name, type, {1, 2}, {3}));
        componentList.insert(std::pair<std::string, std::vector<AComponent>>(name, component));
    }

    Xor::~Xor() = default;

    Tristate Xor::compute(std::vector<pins> entryPins)
    {
        Tristate value = Tristate::False;
        int nbTrue = 0;

        for (auto &it : entryPins)
        {
            if (it.getValue() == Tristate::True)
                nbTrue++;
            else if (it.getValue() == Tristate::Undefined)
                value = Tristate::Undefined;
        }
        if (nbTrue % 2 == 1)
            return Tristate::True;
        return value;
    }

} // namesapce nts
