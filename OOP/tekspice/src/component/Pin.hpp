/*
** EPITECH PROJECT, 2023
** nts
** File description:
** Pin.hpp
*/

#ifndef NTS_PINS_HPP
#define NTS_PINS_HPP

#include "../namespace/nts.hpp"
#include "abstract/AComponent.hpp"
#include <unordered_map>

namespace nts {
    class pins {

        Tristate _value;
        std::vector<IComponent &> _link; //always 1 element init but a vector to evoid compiler errors
        int _PN; //pin number
        int _CPN; //connexion pin number

        public:
        pins() : _value(Tristate::Undefined), _PN(-1), _CPN(-1) {};
        pins(int pn) : _value(Tristate::Undefined), _PN(pn), _CPN(-1) {};

        void setPin(Tristate value, int pn, int cpn) { setValue(value); setPN(pn); setCPN(cpn);};
        void setPin(int pn, int cpn) { setPN(pn); setCPN(cpn);};
        void setPin(Tristate value) { setValue(value); };

        void setPin(IComponent &component, int cpn) { setLink(component); setCPN(cpn); };

        void setValue(Tristate value) { this->_value = value;};
        void setLink(IComponent &link) { this->_link.push_back(link);};
        void setPN(int pin) { this->_PN = pin;};
        void setCPN(int pin) { this->_CPN = pin;};
        Tristate getValue() { return this->_value;};
        IComponent &getLink() { return this->_link[0];};
        int getPN() { return this->_PN;};
        int getCPN() { return this->_CPN;};
    };
}

#endif //NTS_PINS_HPP