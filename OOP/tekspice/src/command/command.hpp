/*
** EPITECH PROJECT, 2023
** nts
** File description:
** command.hpp
*/

#ifndef NTS_COMMAND_HPP
#define NTS_COMMAND_HPP

#include "../classes/abstract/AComponent.hpp"
#include "../componentAplication/componentApplication.hpp"
#include "../componentAplication/compute/compute.hpp"

namespace nts {
    class command {
        public:
        command();
        ~command();
        void display(std::unordered_map<std::string, std::vector<AComponent>> componentList);
        void simulate(std::unordered_map<std::string, std::vector<AComponent>> componentList);
        void loop(std::unordered_map<std::string, std::vector<AComponent>> componentList);
        void dump(std::unordered_map<std::string, std::vector<AComponent>> componentList);
        void input(std::unordered_map<std::string, std::vector<AComponent>> componentList, std::string name, std::string value);
        void exit(std::unordered_map<std::string, std::vector<AComponent>> componentList);
    };
}

#endif //NTS_COMMAND_HPP