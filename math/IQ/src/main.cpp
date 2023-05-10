/*
** EPITECH PROJECT, 2023
** 205
** File description:
** main.cpp
*/
#include "205IQ.hpp"

void help()
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./205IQ u s [IQ1] [IQ2]" << std::endl;
    std::cout << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tu\tmean" << std::endl;
    std::cout << "\ts\tstandard deviation" << std::endl;
    std::cout << "\tIQ1\tminimum IQ" << std::endl;
    std::cout << "\tIQ2\tmaximum IQ" << std::endl;
}

int errorHandling(int argc, char **argv)
{
    if (argc == 2 && std::string(argv[1]) == "-h") {
        help();
        return 0;
    }
    if (argc < 3 || argc > 5) {
        std::cerr << "USAGE: " << argv[0] << " u s [IQ1] [IQ2]" << std::endl;
        return 84;
    }
    if (argc >= 4) {
        if (std::atoi(argv[3]) > 200 || std::atoi(argv[3]) < 0) { // IQ1 out of range
            std::cerr << "IQ1 must be between 0 and 200" << std::endl;
            return 84;
        }
        for (int i = 0; argv[3][i] != '\0'; i++) {
            if (argv[3][i] < '0' || argv[3][i] > '9') {
                std::cerr << "invalid iq1" << std::endl;
                return 84;
            }
        }
    }
    if (argc == 5) {
        if (std::atoi(argv[4]) <= std::atoi(argv[3])) { // IQ2 smaller than IQ1
            std::cerr << "IQ2 must be greater than IQ1" << std::endl;
            return 84;
        }
        if (std::atoi(argv[4]) > 200 || std::atoi(argv[4]) < 0) { // IQ2 out of range
            std::cerr << "IQ2 must be between 0 and 200" << std::endl;
            return 84;
        }
        for (int i = 0; argv[4][i] != '\0'; i++) {
            if (argv[4][i] < '0' || argv[4][i] > '9') {
                std::cerr << "invalid iq2" << std::endl;
                return 84;
            }
        }
    }
    if (std::atoi(argv[1]) <= 0 || std::atoi(argv[1]) > 200) {
        std::cerr << "invalid u" << std::endl;
        return 84;
    }
    if (std::atoi(argv[2]) <= 0 || std::atoi(argv[1]) > 200) { // voir si ca passe parce que je crois qu'on doit pouvoir avoir des valuers negatifs
        std::cerr << "invalid s" << std::endl;
        return 84;
    }

    return 0;
}

int main(int argc, char* argv[])
{
    if (errorHandling(argc, argv) == 84)
        return 84;
    IQ205::IQ Iq = IQ205::IQ(argc, argv);

    Iq.run();
    return 0;
}