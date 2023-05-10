/*
** EPITECH PROJECT, 2023
** nts
** File description:
** or.cpp
*/
#include "or.hpp"

namespace nts {
    Or::Or(std::string &name, nts::Type &type) : AComponent(name, type) {
        _type = type;
        _name = name;
        std::vector<AComponent> component;
        component.push_back(Add_Component(name, type, {1, 2}, {3}));
        componentList.insert(std::pair<std::string, std::vector<AComponent>>(name, component));
    }

    Or::~Or() = default;

    Tristate Or::compute(std::vector<pins> entryPins) {
        Tristate value = Tristate::False;

        for (auto &it : entryPins) {
            if (it.getValue() == Tristate::True)
                return Tristate::True;
            else if (it.getValue() == Tristate::Undefined)
                value = Tristate::Undefined;
        }
        return value;
    }

} //namesapce nts