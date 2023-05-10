/*
** EPITECH PROJECT, 2022
** nts
** File description:
** AComponent.cpp
*/

#include "AComponent.hpp"

//       d888888b                         d888888b
//    d888    8888b                    d888888   888b
//  d88    88  898888b               d8888  888     88b
// d8P        88888888b             d88888888888     b8b
// 88        8888888888             88888888888       88
// 88       88888888888             8888888888        88
// 98b     88888888888P             988888888        d8P
//  988     888  8888P      _=_      9888898  88    88P
//    9888   888888P      q(-_-)p       98888    888P
//       9888888P         '_) (_`         9888888P
//          88            /__/  \            88
//          88          _(<_   / )_          88
//         d88b        (__\_\_|_/__)        d88b

namespace nts
{
    void AComponent::setName(std::string &name)
    {
        _name = name;
    }

    void AComponent::setType(nts::Type &type)
    {
        _type = type;
    }

    const std::string &AComponent::getName() const
    {
        return _name;
    }

    const nts::Type &AComponent::getType() const
    {
        return _type;
    }

    void AComponent::setLinkPin(size_t pin_num_this, nts::AComponent &component, size_t pin_num_target)
    {
        (*_link_pins[pin_num_this].first) = component;
        _link_pins[pin_num_this].second = component._exit_pins[pin_num_target][0];
    }
    //setlink
    void AComponent::SetLink(glb gl, size_t pin_num_this, nts::AComponent &component, size_t pin_num_target)
    {
        setLinkPin(pin_num_this, component, pin_num_target);
        component.setLinkPin(pin_num_target, *this, pin_num_this);
    }

    // void AComponent::Add_entry(int nb)
    // {
    //     pins pin();
    //     _entry_pins.push_back(pin);
    // }

    // void AComponent::Add_exit(int nb)
    // {
    //     pins pin();
    //     _exit_pins.push_back(pin);
    // }

    // AComponent *AComponent::Add_Component(std::string &name, nts::Type type, std::vector<int> entry, std::vector<int> nb_exit)
    // {
    //     this->Add_Component(name, type);
    //     AComponent component(name, type);
    //     for (auto pin : entry)
    //         component.Add_entry(pin)
    //     for (auto pin : exit)
    //         component.Add_exit(pin);
    //     return this;
    // }

        void operator+(Tristate &left)
    {
        if (left == Tristate::True)
            left = Tristate::False;
        else if (left == Tristate::False)
            left = Tristate::True;
        else
            left = Tristate::Undefined;
    }

    Tristate operator&(const Tristate &left, const Tristate &right)
    {
        if (left == Tristate::False || right == Tristate::False)
            return Tristate::False;
        else if (left == Tristate::Undefined || right == Tristate::Undefined)
            return Tristate::Undefined;
        else
            return Tristate::True;
    }

    Tristate operator|(const Tristate &left, const Tristate &right)
    {
        if (left == Tristate::True || right == Tristate::True)
            return Tristate::True;
        else if (left == Tristate::Undefined || right == Tristate::Undefined)
            return Tristate::Undefined;
        else
            return Tristate::False;
    }

    Tristate operator^(const Tristate &left, const Tristate &right)
    {
        if (left == Tristate::Undefined || right == Tristate::Undefined)
            return Tristate::Undefined;
        else if (left == right)
            return Tristate::False;
        else
            return Tristate::True;
    }

    Tristate operator!(const Tristate &left)
    {
        if (left == Tristate::True)
            return Tristate::False;
        else if (left == Tristate::False)
            return Tristate::True;
        else
            return Tristate::Undefined;
    }
}