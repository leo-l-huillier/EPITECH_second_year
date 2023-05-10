/*
** EPITECH PROJECT, 2023
** 204Ducks
** File description:
** 204ducks.cpp
*/

#include <iostream>
#include <cmath>
#include <cstdlib>
#include <string>
#include <iomanip>

void print_help() {
    std::cout << "USAGE\n    ./204ducks a\n\nDESCRIPTION\n    a constant (between 0 and 2.5)" << std::endl;
}

void check_args(int argc, char *argv[]) {
    if (argc == 2 && std::string(argv[1]) == "-h") {
        print_help();
        exit(0);
    }
    if (argc != 2) {
        std::cout << "USAGE: ./204ducks a" << std::endl;
        exit(84);
    }
    if (argc == 2) {
        try {
            float a = std::stof(argv[1]);
            if (a < 0 || a > 2.5) {
                std::cout << "ERROR: a must be between 0 and 2.5" << std::endl;
                exit(84);
            }
        } catch (const std::invalid_argument &e) {
            std::cout << "ERROR: Invalid argument, a must be a number" << std::endl;
            exit(84);
        }
    }
}

double f(double t, double a) {
    return a * exp(-t) + (4 - 3 * a) * exp(-2 * t) + (2 * a - 4) * exp(-4 * t);
}

double avg_return_time(double a) {
    double sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        double t = 1
         * i;
        sum += f(t, a) * t;
    }
    return sum;
}

double standard_deviation(double a) {
    double mean = avg_return_time(a);
    double sum = 0;
    for (int i = 0; i < 1000000; ++i) {
        double t = 0.001 * i;
        sum += f(t, a) * pow(t - mean, 2);
    }
    return sqrt(sum);
}

double time_for_50_percent(double a) {
    double total_prob = 0;
    for (int i = 0; i < 1000000; ++i) {
        double t = 0.001 * i;
        total_prob += f(t, a) * 0.001;
        if (total_prob >= 0.5) {
            return t;
        }
    }
    return 0;
}

double time_for_99_percent(double a) {
    double total_prob = 0;
    for (int i = 0; i < 1000000; ++i) {
        double t = 0.001 * i;
        total_prob += f(t, a) * 0.001;
        if (total_prob >= 0.99) {
            return t;
        }
    }
    return 0;
}

double percent_back_after_time(double time, double a) {
    double total_prob = 0;
    for (int i = 0; i < static_cast<int>(time * 1000); ++i) {
        double t = 0.001 * i;
        total_prob += f(t, a) * 0.001;
    }
    return total_prob * 100;
}

int main(int argc, char *argv[])
{
    check_args(argc, argv);

    double a = std::stod(argv[1]);

    double avg_time = avg_return_time(a);
    int avg_time_m = static_cast<int>(avg_time);
    int avg_time_s = static_cast<int>((avg_time - avg_time_m) * 60);
    std::cout << "Average return time: " << avg_time_m << "m " << avg_time_s << "s" << std::endl;

    double std_dev = standard_deviation(a);
    std::cout << "Standard deviation: " << std::fixed << std::setprecision(3) << std_dev << std::endl;

    double time_50 = time_for_50_percent(a);
    int time_50_m = static_cast<int>(time_50);
    int time_50_s = static_cast<int>((time_50 - time_50_m) * 60);
    std::cout << "Time after which 50% of the ducks are back: " << time_50_m << "m " << time_50_s << "s" << std::endl;

    double time_99 = time_for_99_percent(a);
    int time_99_m = static_cast<int>(time_99);
    int time_99_s = static_cast<int>((time_99 - time_99_m) * 60);
    std::cout << "Time after which 99% of the ducks are back: " << time_99_m << "m " << time_99_s << "s" << std::endl;

    double percent_1 = percent_back_after_time(1, a);
    std::cout << "Percentage of ducks back after 1 minute: " << std::fixed << std::setprecision(1) << percent_1 << "%" << std::endl;

    double percent_2 = percent_back_after_time(2, a);
    std::cout << "Percentage of ducks back after 2 minutes : " << std::fixed << std::setprecision(1) << percent_2 << "%" << std::endl;

    return 0;
}
