/*
** EPITECH PROJECT, 2023
** nts
** File description:
** output.cpp
*/

#include "output.hpp"

namespace nts {
    Output::Output(std::string &name, nts::Type &type) : AComponent(name, type) {
        _type = type;
        _name = name;
        std::vector<AComponent> component;
        component.push_back(Add_Component(name, type, {1}, {2}));
        componentList.insert(std::pair<std::string, std::vector<AComponent>>(name, component));
    }
    Output::~Output() = default;

} //namespace nts