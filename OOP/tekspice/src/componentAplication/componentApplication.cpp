/*
** EPITECH PROJECT, 2023
** nts
** File description:
** componentApplication.cpp
*/

#include "componentApplication.hpp"

namespace nts {
    void addChipset(glb gl) {
        
        }
    }

    void addLink(std::vector<std::string>& links)
    {
        AComponent CP;
        for (std::string &s : links) {
            size_t pos = s.find(":");
            std::string src = s.substr(0, pos - 1);
            std::string dst = s.substr(pos, pos + 2);
            std::string rst = s.substr(pos + 2);

            CP.LinkCP(src, dst, rst);
        }
    }

    void processLink(const std::string& src, const std::string& dst, const std::string& rst) {
        size_t pos = rst.find(":");
        std::string rst1 = rst.substr(0, pos - 1);
        std::string rst2 = rst.substr(pos, pos + 2);
        std::vector<pins> exit_pin = componentList[src];
    }
}
