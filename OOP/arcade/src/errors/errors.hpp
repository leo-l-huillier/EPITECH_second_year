/*
** EPITECH PROJECT, 2023
** arcade
** File description:
** errors.hpp
*/
#pragma once
#include <exception>
#include <string>

class cannotOpenLibrary : public std::exception
{
    public:
    virtual const char* what() const throw() {
        return "Cannot open library: ";
    }
};

class cannotCloseLibrary : public std::exception
{
    public:
    virtual const char* what() const throw() {
        return "Cannot close library: ";
    }
};

class cannotCreateModule : public std::exception
{
    public:
    virtual const char* what() const throw() {
        return "Cannot create module: ";
    }
};

class cannotCloseModule : public std::exception
{
    public:
    virtual const char* what() const throw() {
        return "Cannot close module: ";
    }
};