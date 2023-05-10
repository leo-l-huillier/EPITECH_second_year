/*
** EPITECH PROJECT, 2023
** nts
** File description:
** compute.hpp
*/

#ifndef NTS_COMPUTE_HPP
#define NTS_COMPUTE_HPP

#include "../../classes/interfaces/IComponent.hpp"
#include "../../classes/abstract/AComponent.hpp"
#include <unordered_map>


namespace nts {
    class compute {
        public:
        compute();
        ~compute();
        Tristate compute(std::unordered_map<std::string, std::vector<AComponent>> componentList, std::string name);
    };
}

#endif //NTS_COMPUTE_HPP