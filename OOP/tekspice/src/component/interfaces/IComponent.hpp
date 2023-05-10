/*
** EPITECH PROJECT, 2022
** nts
** File description:
** IComponent
*/
#ifndef NTS_ICOMPONENT_HPP
#define NTS_ICOMPONENT_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <cmath>
namespace nts {
    class IComponent {
        public :
        virtual ~IComponent () = default;
        virtual void simulate (std::size_t tick) = 0;
        //virtual nts::Tristate compute (std::size_t pin) = 0;
        //virtual void setLink (std::size_t pin, nts::IComponent &other, std::size_t otherPin ) = 0;
    };
}

#endif //NTS_ICOMPONENT_HPP