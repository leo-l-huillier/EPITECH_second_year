/*
** EPITECH PROJECT, 2023
** nts
** File description:
** command.cpp
*/

#include "command.hpp"

namespace nts {
    command::command() {
    }

    command::~command() {
    }

    void command::display(std::unordered_map<std::string, std::vector<AComponent>> componentList) {
        std::cout << "tick: " << tick << std::endl;
        std::cout << "input(s):" << std::endl;
        for (auto &it : componentList) {
            for (auto &it2 : it.second) {
                if (it2.getType() == "input") {
                    std::cout << it2.getName() << "=";
                    if (it2.getEntryPins()[0].getValue() == Tristate::True)
                        std::cout << "1" << std::endl;
                    else if (it2.getEntryPins()[0].getValue() == Tristate::False)
                        std::cout << "0" << std::endl;
                    else
                        std::cout << "U" << std::endl;
                }
            }
        }
    }

    void command::simulate(std::unordered_map<std::string, std::vector<AComponent>> componentList) {
        compute::computeComponent(componentList);
    }

    void command::loop(std::unordered_map<std::string, std::vector<AComponent>> componentList) {
        std::string input;
        std::string name;
        std::string value;

        while (1) {
            std::cout << "> ";
            std::getline(std::cin, input);
            if (input == "exit")
                break;
            else if (input == "display")
                display(componentList);
            else if (input == "simulate")
                simulate(componentList);
            else if (input.find("input") != std::string::npos) {
                name = input.substr(6, input.find(" ") - 6);
                value = input.substr(input.find(" ") + 1, input.size() - input.find(" "));
                input(componentList, name, value);
            }
        }
    }

    void command::dump(std::unordered_map<std::string, std::vector<AComponent>> componentList) {
        for (auto &it : component + it.second) {
            std::cout << it2.getName() << "=";
            if (it2.getPin(1).getValue() == Tristate::True)
                std::cout << "1" << std::endl;
            else if (it2.getPin(1).getValue() == Tristate::False)
                std::cout << "0" << std::endl;
            else
                std::cout << "U" << std::endl;
        }

    }

    void command::input(std::unordered_map<std::string, std::vector<AComponent>> componentList, std::string name, std::string value) {
        for (auto &it : componentList) {
            for (auto &it2 : it.second) {
                if (it2.getName() == name) {
                    if (value == "1")
                        it2.getPin(1).setValue(Tristate::True);
                    else if (value == "0")
                        it2.getPin(1).setValue(Tristate::False);
                    else
                        it2.getPin(1).setValue(Tristate::Undefined);
                }
            }
        }
    }

    void command::exit(std::unordered_map<std::string, std::vector<AComponent>> componentList) {
        exit(0);
    }

}