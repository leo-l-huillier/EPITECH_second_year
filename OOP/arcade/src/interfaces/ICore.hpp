
/*
** EPITECH PROJECT, 2022
** InterfaceArcade
** File description:
** ICore.hpp
*/

#pragma once

#include <string>

namespace arcade
{
    class ICore {
        public:
            /**
            ** Set the username
            */
            virtual void setName(const std::string &name) = 0;

            /**
            ** Get the username
            */
            virtual const std::string &getName() const = 0;
        };
}