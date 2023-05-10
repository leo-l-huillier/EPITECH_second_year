/*
** EPITECH PROJECT, 2023
** nts
** File description:
** Pin.hpp
*/

#pragma once

#include "../abstract/AComponent.hpp"
#include "../../namespace/nts.hpp"
#include "../specialComponent/input.hpp"
#include "../specialComponent/output.hpp"
#include "../specialComponent/true.hpp"
#include "../specialComponent/false.hpp"
#include "../specialComponent/clock.hpp"
#include "../elementaryComponent/and.hpp"
#include "../elementaryComponent/not.hpp"
#include "../elementaryComponent/or.hpp"
#include "../elementaryComponent/xor.hpp"

#include <memory>

namespace nts
{
    class Factory
    {
    public:
        void create(glb &gl)
        {
            for (std::string &s : gl.chipsets)
            {
                if (s.substr(0, 5) == "input")
                {
                    auto name = s.substr(6);
                    std::shared_ptr<Input> input = std::make_shared<Input>(name, Type::INPUT);
                    gl.componentList[name] = std::move(input);
                }
                else if (s.substr(0, 6) == "output")
                {
                    auto name = s.substr(7);
                    std::shared_ptr<Output> output = std::make_shared<Output>(name, Type::OUTPUT);
                    gl.componentList[name] = std::move(output);
                }
                else if (s.substr(0, 4) == "true")
                {
                    auto name = s.substr(6);
                    std::shared_ptr<True> true_object = std::make_shared<True>(name, Type::TRUE);
                    gl.componentList[name] = std::move(true_object);
                }
                else if (s.substr(0, 5) == "false")
                {
                    auto name = s.substr(6);
                    std::shared_ptr<False> false_object = std::make_shared<False>(name, Type::TRUE);
                    gl.componentList[name] = std::move(false_object);
                }
                else if (s.substr(0, 5) == "clock")
                {
                    auto name = s.substr(6);
                    std::shared_ptr<Clock> clock_object = std::make_shared<Clock>(name, Type::OR);
                    gl.componentList[name] = std::move(clock_object);
                }
                else if (s.substr(0, 3) == "and")
                {
                    auto name = s.substr(4);
                    std::shared_ptr<And> and_object = std::make_shared<And>(name, Type::AND);
                    gl.componentList[name] = std::move(and_object);
                }
                else if (s.substr(0, 2) == "or")
                {
                    auto name = s.substr(3);
                    std::shared_ptr<Or> or_object = std::make_shared<Or>(name, Type::OR);
                    gl.componentList[name] = std::move(or_object);
                }
                else if (s.substr(0, 3) == "xor")
                {
                    auto name = s.substr(4);
                    std::shared_ptr<Xor> xor_object = std::make_shared<Xor>(name, Type::XOR);
                    gl.componentList[name] = std::move(xor_object);
                }
                else if (s.substr(0, 3) == "not")
                {
                    auto name = s.substr(4);
                    std::shared_ptr<Not> not_object = std::make_shared<Not>(name, Type::NOT);
                    gl.componentList[name] = std::move(not_object);
                }
            }
        }
    };
} // namespace nts```