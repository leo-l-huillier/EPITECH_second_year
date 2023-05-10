/*
** EPITECH PROJECT, 2023
** ntsToPush
** File description:
** createLinks.cpp
*/
#include "createLinks.hpp"

namespace nts {
    //on s'en fou vrm de l'ordre dest / src ?

    //link = name1:pin1 name2:pin2
    void createLinks(nts::glb gl)
    {
        for (std::string &s : gl.links) {
            size_t pos = s.find(" ");

            std::string src = s.substr(0, pos - 1);
            size_t posPin1 = src.find(":");
            size_t pin = std::stoi(s.substr(posPin1 + 1));

            std::string dst = s.substr(pos + 1);
            size_t posPin2 = dst.find(":");
            size_t pin2 = std::stoi(s.substr(posPin2 + 1));

            gl.componentList[src]->SetLink(gl, pin, *gl.componentList[dst], pin2);
        }
    }
} // namespace nts
