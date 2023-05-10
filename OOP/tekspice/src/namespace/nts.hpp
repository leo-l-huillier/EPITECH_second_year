/*
** EPITECH PROJECT, 2023
** nts
** File description:
** nts.hpp
*/

#ifndef NTS_NTS_HPP
#define NTS_NTS_HPP

#include <iostream>
#include <unordered_map>
#include <vector>
#include <memory>
#include "../component/abstract/AComponent.hpp"

namespace nts
{
    class glb
    {
    public:
        // AComponent test;
        static inline unsigned int tick = 0;
        std::unordered_map<std::string, std::shared_ptr<IComponent>> componentList;
        static inline std::vector<std::string> chipsets;
        static inline std::vector<std::string> links;
    };

    enum class Tristate
    {
        Undefined = -1,
        True = 0,
        False = 1
    };

    enum class Type
    {
        UNDEFINED, // for initialisation purpose -> see if it's really useful

        TRUE,
        FALSE,
        CLOCK,
        AND,
        OR,
        XOR,
        LOGGER,
        NOT,
        INPUT,
        OUTPUT,

        AND_gates,  // 4081
        NOT_gates,  // 4069
        OR_gates,   // 4071
        NOR_gates,  // 4001
        XOR_gates,  // 4030
        NAND_gates, // 4011

        CHAN_DATA_SELECT,      // 4512
        BYTE_DECODER,          // 4514
        BYTE_BINARY_COUNTER,   // 4040
        DUAL_D_TYPE_FLIP_FLOP, // 4013
        BYTE_RAM,              // 4801
        BYTE_ROM,              // 2716
        BYTE_SHIFT_REGISTER,   // 4094
        BYTE_COUNTER,          // 4017
        BYTE_ADDER             // 4008
    };
}

#endif // NTS_NTS_HPP