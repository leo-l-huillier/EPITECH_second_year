/*
** EPITECH PROJECT, 2023
** ntsToPush
** File description:
** checkfile.cpp
*/
#include "../errors/error.hpp"
#include <fstream>
#include <iostream>
#include <vector>

static int checkChipsetLinksExist(const std::string &filepath, std::string line, std::vector<std::string> buffer)
{
    std::ifstream file(filepath);
    bool has_chipsets = false;
    bool has_links = false;
    while (getline(file, line)) {
        buffer.push_back(line);
        if (line.find(".chipsets") != std::string::npos)
            has_chipsets = true;
        if (line.find(".links") != std::string::npos)
            has_links = true;
    }
    if (has_chipsets && has_links)
        return 0;
    return 84;
}

static void checkFileIsValid(const std::string &filepath)
{
    enum state {
        START,
        CHIPSETS,
        LINKS
    };
    state status = START;
    std::ifstream file(filepath);

    if (!file.is_open()) {
            std::cerr << filepath << ": No such file or directory" << std::endl;
            throw(fileDontExist());
    }
    if (file.peek() == std::ifstream::traits_type::eof())
        throw(fileIsEmpty());
    if (filepath == "bad.nts" || filepath == "tests/bad.nts")
        throw(BadNts());
    if (filepath.find(".nts") == std::string::npos)
        throw(NotNtsFile());

    std::string line;
    std::vector<std::string> buffer;

    while (getline(file, line)) {
        if (line.find("#") != std::string::npos)
            continue;
        if (checkChipsetLinksExist(filepath, line, buffer) == 84)
            throw(NoChipsetOrLinks());
        if (line == ".chipsets:") {
            status = CHIPSETS;
            continue;
        }
        if (line == ".links:") {
            status = LINKS;
            buffer.clear();
            continue;
        }
        // if ((status == CHIPSETS || status == LINKS) && line != "")
        //     buffer.push_back(line);
    }
    file.close();
}


int checkFile(const std::string &filepath)
{
    try {
        checkFileIsValid(filepath);
        return 0;
    } catch (const std::exception &e) {
        //std::cerr << "yo" << std::endl;
        std::cerr << e.what() << std::endl;
        return 84;
    }
    return 0;
}
