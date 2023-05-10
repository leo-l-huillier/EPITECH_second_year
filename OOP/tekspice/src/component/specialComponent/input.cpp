/*
** EPITECH PROJECT, 2023
** nts
** File description:
** input.cpp
*/
#include "input.hpp"

namespace nts
{
    Input::Input(std::string &name, nts::Type &type) : AComponent(name, type)
    {
        _type = type;
        _name = name;
        std::vector<AComponent> component;
        component.push_back(Add_Component(name, type, {}, {1}));
        componentList.insert(std::pair<std::string, std::vector<AComponent>>(name, component));
    }
    Input::~Input() = default;

} // namesapce nts