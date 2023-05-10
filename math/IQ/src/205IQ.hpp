/*
** EPITECH PROJECT, 2022
** 205IQ
** File description:
** 205IQ.hpp
*/

#pragma once

#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <list>

namespace IQ205 {
    class IQ {
            int _nbArgs;
            char **_argv;
            double _mean; // mean
            double _stddev; // standard deviation
            double _iq1;
            double _iq2;
        public:
            IQ(int argc, char **argv);
            ~IQ();
            double normalPdf(double x);
            int run();
            int normalDistrib();
            double bellow();
            std::pair<double, double> interval();
    };
}