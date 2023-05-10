/*
** EPITECH PROJECT, 2023
** nts
** File description:
** xor.hpp
*/
#pragma once
#include "../abstract/AComponent.hpp"

namespace nts {
    class Xor : public AComponent {
        public:
            Xor(std::string &name, nts::Type &type);
            ~Xor() override;

            void compute() { this->setExitPins(3, this->getEntryPins()[1][0] ^ this->getEntryPins()[2][0]); };
            //compute
            //setlinks
    };
}