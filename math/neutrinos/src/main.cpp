/*
** EPITECH PROJECT, 2023
** 206
** File description:
** main.cpp
*/
#include <iostream>
#include <cmath>
#include <string>
#include <cstdlib>
#include <iomanip>

bool is_num(std::string str)
{
   for( int i = 0; i < str.length(); i++ ) {
        if(!isdigit(str[i]) && str[i] != '.' && str[i] != '-') {
           return false;
        }
    }
    return true;
}

void help(void)
{
    std::cout << "USAGE" << std::endl;
    std::cout << "\t./205IQ n a h sd" << std::endl;
    std::cout << std::endl;
    std::cout << "DESCRIPTION" << std::endl;
    std::cout << "\tn\tnumber of values" << std::endl;
    std::cout << "\ta\taritmetic mean" << std::endl;
    std::cout << "\th\tharmonic mean" << std::endl;
    std::cout << "\tsd\tstandar deviation" << std::endl;
}

int errorHandling(int argc, char **argv)
{
    if (argc == 2 && argv[1][0] == '-' && argv[1][1] == 'h') {
        help();
        return 1;
    }
    if (argc != 5) {
        help();
        return 84;
    }
    for (int i = 1; i < 5; i++)
        if (!is_num(argv[i])) {
            help();
            return 84;
        }
    return 0;
}

void printResults(int new_n, double new_sd, double new_a, double new_rms, double new_h)
{
    std::cout << "\tNumber of values:\t" << new_n << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\tStandard deviation:\t" << new_sd << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\tArithmetic mean:\t" << new_a << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\tRoot mean square:\t" << new_rms << std::endl;
    std::cout << std::fixed << std::setprecision(2) << "\tHarmonic mean:\t\t" << new_h << "\n" << std::endl;
}

int main(int argc, char *argv[])
{
    if (errorHandling(argc, argv) == 1) return 0;
    if (errorHandling(argc, argv) == 84) return 84;
    double n = std::atof(argv[1]);
    double a = std::atof(argv[2]);
    double h = std::atof(argv[3]);
    double sd = std::atof(argv[4]);

    double sum_sq = n * sd * sd + n * a * a;
    double sum = n * a;

    while (true) {
        std::string input;
        std::cout << "Enter next value: ";
        std::cin >> input;
        if (input == "END")
            break;
        if (!is_num(input)) {
            std::cerr << "input is not a correct number" << std::endl;
            return 84;
        }
        double value = std::atof(input.c_str());

        int new_n = n + 1;
        if (new_n == 0 || value == 0 || h == 0) {
            std::cerr << "cannot divide by 0" << std::endl;
            return 84;
        }
        double delta = value - a;
        double new_a = a + delta / new_n;
        double new_sd = std::sqrt((n * sd * sd + delta * delta + 2 * delta * (new_a - a)) / new_n);
        sum_sq += value * value;
        sum += value;
        double new_rms = std::sqrt((sum_sq + sum*sum/new_n) / new_n - new_a*new_a);
        double new_h = (n + 1) / (((1 / h) * n) + (1 / value));

        printResults(new_n, new_sd, new_a, new_rms, new_h);

        n = new_n;
        a = new_a;
        h = new_h;
        sd = new_sd;
    }

    return 0;
}
