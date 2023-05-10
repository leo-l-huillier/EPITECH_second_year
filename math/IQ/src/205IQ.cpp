/*
** EPITECH PROJECT, 2022
** 205IQ
** File description:
** 205IQ.cpp
*/

#include "205IQ.hpp"

IQ205::IQ::IQ(int argc, char **argv) : _nbArgs(argc), _argv(argv)
{
    _mean = std::atof(_argv[1]);
    _stddev = std::atof(_argv[2]);
    _iq1 = 0;
    _iq2 = 0;
    if (_nbArgs >= 4)
        _iq1 = std::atof(_argv[3]);
    if (_nbArgs == 5)
        _iq2 = std::atof(_argv[4]);
}

IQ205::IQ::~IQ()
{}

/**
 * @brief Calculates the normal probability density
 * for a given value x using the standardized normal probability density
 * formula and adjusting for the mean and standard deviation specified in the
 * IQ object. This function is used to display the normal distribution curve.
 * @param x
 * @return double
 */
double IQ205::IQ::normalPdf(double x)
{
    return (1 / (_stddev * std::sqrt(2 * M_PI))) * std::exp(-(x - _mean) * (x - _mean) / (2 * _stddev * _stddev));
}

/**
 * @brief displays the normal distribution curve
 * @return int
 */
int IQ205::IQ::normalDistrib()
{
    for (int i = 0; i <= 200; i++) {
        std::cout << i << " " << std::fixed << std::setprecision(5) << normalPdf(i) << std::endl;
    }
    return 0;
}

/**
 * @brief displays the proportion of people with an IQ below the designated IQ value
 */
double IQ205::IQ::bellow()
{
    double cdf = 0.5 * (1 + std::erf((_iq1 - _mean) / (_stddev * std::sqrt(2))));
    std::cout << std::fixed << std::setprecision(1) << cdf * 100 << "% of people have an IQ inferior to " << (int)_iq1 << std::endl;
    return cdf;
}

/**
 * @brief displays the proportion of people with an IQ between the two designated IQ values
 * @return std::pair<double, double>
 */
std::pair<double, double> IQ205::IQ::interval()
{
    double cdf1 = 0.5 * (1 + std::erf((_iq1 - _mean) / (_stddev * std::sqrt(2))));
    double cdf2 = 0.5 * (1 + std::erf((_iq2 - _mean) / (_stddev * std::sqrt(2))));
    std::cout << std::fixed << std::setprecision(1) << (cdf2 - cdf1) * 100 << "% of people have an IQ between " << (int)_iq1 << " and " << (int)_iq2 << std::endl;
    return std::make_pair(cdf1, cdf2);
}

/**
 * @brief runs the program
 */
int IQ205::IQ::run()
{
    if (_nbArgs == 3)
        normalDistrib();
    if (_nbArgs == 4)
        bellow();
    if (_nbArgs == 5)
        interval();
    return 0;
}