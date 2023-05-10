/*
** EPITECH PROJECT, 2023
** nts
** File description:
** output.hpp
*/
#pragma once

#include "../abstract/AComponent.hpp"

namespace  nts {
    class  True :  public  AComponent {
        public :
        True(std::string &name, nts::Type &type) : AComponent(name, type) {};
        ~True() override = default;

        void compute() { if (this->getExitPins()[1][0] != Tristate::True) setExitPins(1, Tristate::True); };
    };
}