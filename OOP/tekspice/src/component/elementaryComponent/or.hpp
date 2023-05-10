/*
** EPITECH PROJECT, 2023
** nts
** File description:
** or.hpp
*/
#pragma once

#include "../abstract/AComponent.hpp"

namespace nts {
    class Or : public AComponent {
        public:
            Or(std::string &name, nts::Type &type);
            ~Or() override;

            void compute() { this->setExitPins(3, this->getEntryPins()[1][0] | this->getEntryPins()[2][0]); };
            //compute
            //setlinks
    };
}