/*
** EPITECH PROJECT, 2022
** nts
** File description:
** parcing.cpp
*/
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "../namespace/nts.hpp"

namespace nts {
    void parseFile(std::string filename, std::vector<std::string>& chipsets, std::vector<std::string>& links) {
        std::ifstream file(filename);
        if (file.is_open()) {
            std::string line;
            bool parsingChipsets = true;
            while (getline(file, line)) {
                if (line.empty()) continue; // skip empty lines
                if (line.substr(0, 9) == ".chipsets") {
                    parsingChipsets = true;
                } else if (line.substr(0, 7) == ".links") {
                    parsingChipsets = false;
                } else {
                    if (line.substr(0, 1) == ".") {
                        continue;
                    } else if (parsingChipsets) {
                        chipsets.push_back(line);
                    } else {
                        links.push_back(line);
                    }
                }
            }
            file.close();
        } else {
            std::cout << "Unable to open file: " << filename << std::endl;
        }
    }

    void open_file(std::string File_Name, nts::glb &gl)
    {
        parseFile(File_Name, gl.chipsets, gl.links);
    }
}
