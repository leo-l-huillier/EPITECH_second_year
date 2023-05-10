/*
** EPITECH PROJECT, 2023
** nts
** File description:
** compute.cpp
*/

#include "compute.hpp"

namespace nts {

    Tristate selectComponent(std::unordered_map<std::string, std::vector<AComponent>> componentList, std::string name)
    {
        for (auto &it : componentList) {
            if (it.first == name) {
                for (auto &it2 : it.second) {
                    if (it2.getType() == "input")
                        return it2.getEntryPins()[0].getValue();
                    else if (it2.getType() == "output")
                        return it2.getExitPins()[0].getValue();
                    else if (it2.getType() == "and")
                        return compAnd(it2.getEntryPins());
                    else if (it2.getType() == "or")
                        return compOr(it2.getEntryPins());
                    else if (it2.getType() == "xor")
                        return compXor(it2.getEntryPins());
                    else if (it2.getType() == "not")
                        return compNot(it2.getEntryPins());
                    else if (it2.getType() == "clock")
                        return compClock(it2.getEntryPins());
                }
            }
        }
        return Tristate::Undefined;
    }

    void compute(std::unordered_map<std::string, std::vector<AComponent>> componentList)
    {

    }
}