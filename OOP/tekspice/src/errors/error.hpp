/*
** EPITECH PROJECT, 2023
** nts
** File description:
** error.hpp
*/
#pragma once
#include <exception>
#include <string>

class fileDontExist : public std::exception
{
    public:
    virtual const char* what() const throw() {
        return "yes";
    }
};

class fileIsEmpty : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "File is empty";
    }
};

class BadNts : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "Unknow component name 'a'.";
    }
};

class NotNtsFile : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "Error: File must be a .nts file";
    }
};

class NoChipsetOrLinks : public std::exception {
    public:
    virtual const char* what() const throw() {
        return "file don't have .chipsets or .links";
    }
};