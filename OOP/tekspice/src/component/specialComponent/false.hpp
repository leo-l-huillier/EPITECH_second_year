/*
** EPITECH PROJECT, 2023
** nts
** File description:
** output.hpp
*/
#pragma once

#include "../abstract/AComponent.hpp"

namespace  nts {
    class  False :  public  AComponent {
        public :
        False(std::string &name, nts::Type &type) : AComponent(name, type) {};
        ~False() override = default;

        void compute() { if (this->getExitPins()[1][0] != Tristate::False) setExitPins(1, Tristate::False); };
    };
}