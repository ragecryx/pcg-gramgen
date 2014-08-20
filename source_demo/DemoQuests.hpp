#ifndef DEMOQUESTS_H
#define DEMOQUESTS_H

#include <iostream>

#include <PCGGram/Ruleset.hpp>
#include <PCGGram/Generator.hpp>

using namespace std;
using namespace PCGGrammar;


#include "Demo.hpp"


class DemoQuests : public Demo {
	public:
		DemoQuests();
		~DemoQuests();
	public:
		virtual void Initialize();
		virtual void Run();
	private:
        Ruleset     quests;
        Generator   contentGenerator;
};


#endif
