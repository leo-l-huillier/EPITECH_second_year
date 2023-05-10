/*
** EPITECH PROJECT, 2023
** nts
** File description:
** input.hpp
*/
#pragma once

#include "../abstract/AComponent.hpp"

namespace nts {
    class Input : public AComponent {
        public:
            Input(std::string &name, nts::Type &type);
            ~Input() override;

            void compute() { this->setExitPins(1, this->getEntryPins()[1][0]); };
            //compute
            //setlinks
    };
}