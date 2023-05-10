/*
** EPITECH PROJECT, 2023
** nts
** File description:
** not.hpp
*/
#pragma once
#include "../abstract/AComponent.hpp"

namespace nts
{
    class Not : public AComponent
    {
    public:
        Not(std::string &name, nts::Type &type) : AComponent(name, type){};
        ~Not() override;

        void compute() { this->setExitPins(2, !this->getEntryPins()[1][0]); };
    };

} // namespace nts