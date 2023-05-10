/*
** EPITECH PROJECT, 2023
** nts
** File description:
** and.hpp
*/

#pragma once

#include "../abstract/AComponent.hpp"
#include <unordered_map>
#include <vector>

namespace nts
{
    class And : public AComponent
    {
    public:
        And(std::string name, nts::Type type, int entry_one, int entry_two, int exit);
        ~And() override;

        void compute() { this->setExitPins(3, this->getEntryPins()[1][0] & this->getEntryPins()[2][0]); };

        // setlinks
    };
}