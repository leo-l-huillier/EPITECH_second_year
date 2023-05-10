/*
** EPITECH PROJECT, 2023
** nts
** File description:
** clock.hpp
*/

#pragma once

#include "../abstract/AComponent.hpp"

namespace nts {
    class Clock : public AComponent {
        public:
            Clock(std::string &name, nts::Type &type);
            ~Clock() override;

            void compute() { +this->getExitPins()[1][0]; };
    };

} //namespace nts