/*
** EPITECH PROJECT, 2023
** nts
** File description:
** andGates.cpp
*/

#include "andGates.hpp"
#include "../elementaryComponent/and.hpp"

namespace nts
{

    AndGates::AndGates(std::string &name, nts::Type &type) : AComponent(name, type)
    {
        _type = type;
        _name = name;

        nts::And and1 = nts::And("and1", Type::AND, 1, 2, 3);
        nts::And and2 = nts::And("and2", Type::AND, 6, 5, 4);
        nts::And and3 = nts::And("and3", Type::AND, 8, 9, 10);
        nts::And and4 = nts::And("and4", Type::AND, 13, 12, 11);



        _exit_pins[0] = &and1._exit_pins[0];  //set link exit
        _exit_pins[1] = and2._exit_pins[3];  //set link exit
        _exit_pins[2] = and3._exit_pins[3]; //set link exit
        _exit_pins[3] = and4._exit_pins[3]; //set link exit

        // _andGates.push_back(and1);
        // _andGates.push_back(and2);
        // _andGates.push_back(and3);
        // _andGates.push_back(and4);
    }

    void AndGates::setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin) {
        //if 7 = error("grrrr"  )
        float tempPin = otherPin;
        if (otherPin > 7)
             tempPin = otherPin - 1;
        _andGates[floor(tempPin / 3)].setLink(otherPin, other, pin);
    }

    AndGates::~AndGates() = default;

} // namespace nts