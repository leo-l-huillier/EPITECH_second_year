/*
** EPITECH PROJECT, 2023
** nts
** File description:
** output.hpp
*/
#pragma once

#include "../abstract/AComponent.hpp"

namespace  nts {
    class  Output :  public  AComponent {
        public :
        Output(std::string &name, nts::Type &type);
        ~Output() override;

        void compute() { this->setExitPins(1, this->getEntryPins()[1][0]); };
            //compute
            //setlinks
    };
}