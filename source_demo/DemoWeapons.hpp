#ifndef DEMOWEAPONS_H
#define DEMOWEAPONS_H

#include <iostream>

#include <PCGGram/Ruleset.hpp>
#include <PCGGram/Generator.hpp>

using namespace std;
using namespace PCGGrammar;


#include "Demo.hpp"


class DemoWeapons : public Demo {
    public:
        DemoWeapons();
        ~DemoWeapons();
    public:
        virtual void Initialize();
        virtual void Run();
    private:
        Ruleset     weapons;
        Generator   contentGenerator;
};


#endif
