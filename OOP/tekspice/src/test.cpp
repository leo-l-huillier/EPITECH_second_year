
#include "component/abstract/AComponent.hpp"
#include "namespace/nts.hpp"
#include "component/Factory/factory.hpp"

int main()
{
    nts::glb gl;
    gl.chipsets.push_back("input a1");
    gl.chipsets.push_back("input a2");
    gl.chipsets.push_back("output o1");
    gl.chipsets.push_back("and and1");
    gl.chipsets.push_back("and and2");
    gl.chipsets.push_back("or or1");

    nts::Factory factor;
    factor.create(gl);

    for (auto test : gl.componentList)
        printf("%s\n", test.first);

    return 0;
}
