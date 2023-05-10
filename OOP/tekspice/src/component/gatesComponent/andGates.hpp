/*
** EPITECH PROJECT, 2023
** nts
** File description:
** andGates.hpp
*/

#pragma once

#include "../abstract/AComponent.hpp"
#include "../elementaryComponent/and.hpp"

namespace nts {
    class AndGates : public AComponent {
        std::vector<AComponent &> _andGates;
        public:
            AndGates(std::string &name, nts::Type &type);
            ~AndGates() override;

            void setLink(std::size_t pin, nts::AComponent &other, std::size_t otherPin);
        //faudra voir pour les compute set links tout ca si on le met ici aussi
        //ou si on e redefinie dans chaque classe simple component
    };

} //namespace nts