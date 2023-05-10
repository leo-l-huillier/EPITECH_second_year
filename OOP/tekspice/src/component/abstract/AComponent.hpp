/*
** EPITECH PROJECT, 2023
** nts
** File description:
** AComponent.hpp
*/

#ifndef NTS_ACOMPONENT_HPP
#define NTS_ACOMPONENT_HPP

#include "../interfaces/IComponent.hpp"
#include "../Pin.hpp"
#include "../../namespace/nts.hpp"
#include "../../componentAplication/componentApplication.hpp"
#include <unordered_map>
#include <memory>

namespace nts
{
    class AComponent : public virtual IComponent
    {
    protected:
        nts::Type _type;
        std::string _name;

        std::unordered_map<int, std::vector<Tristate>> _entry_pins;
        std::unordered_map<int, std::vector<Tristate>> _exit_pins;

        std::unordered_map<int, std::pair<std::shared_ptr<AComponent>, Tristate &>> _link_pins;
        std::unordered_map<int, std::pair<std::shared_ptr<AComponent>, Tristate &>> output_link_pins; // pas sur qu'on va l'utiliser mais je le créé ds le doute

    public:
        AComponent(std::string name, nts::Type type) : _name(name), _type(type){};
        ~AComponent() override = default;

        virtual void simulate(std::size_t tick){};
        virtual Tristate compute(std::vector<pins> entryPins) { return Tristate::Undefined; };
        void SetLink(glb gl, size_t pin_num_this, nts::AComponent &component, size_t pin_num_target);
        void setLinkPin(size_t pin_num_this, nts::AComponent &component, size_t pin_num_target);
        virtual void setExitPins(int pin, Tristate state){_exit_pins[pin][0] = state;};

        void setName(std::string &name);
        void setType(nts::Type &type);
        const std::string &getName() const;
        const nts::Type &getType() const;

        // void Add_entry(int nb);
        // void Add_exit(int nb);
        std::unordered_map<int, std::vector<Tristate>> getEntryPins() { return _entry_pins; };
        std::unordered_map<int, std::vector<Tristate>> getExitPins() { return _exit_pins; };
        std::unordered_map<int, std::pair<std::shared_ptr<AComponent>, Tristate &>> getLinkPins() { return _link_pins; };

        // AComponent *AComponent::Add_Component(std::string &name, nts::Type type, int nb_entry, int nb_exit, int pin);
    };
    void operator+(Tristate &left); //clock
    Tristate operator&(const Tristate &left, const Tristate &right); //and
    Tristate operator|(const Tristate &left, const Tristate &right); //or
    Tristate operator^(const Tristate &left, const Tristate &right); //xor
    Tristate operator!(const Tristate &left); //not
} // namespace nts

#endif // NTS_ACOMPONENT_HPP