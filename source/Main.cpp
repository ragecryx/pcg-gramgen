#include <iostream>

#include <cstdio>
#include <cstdlib>
#include <ctime>

using namespace std;


#include <PCGGram\Ruleset.h>
#include <PCGGram\Generator.h>

using namespace PCGGrammar;


int main() {

    srand(time(NULL));

	// 1. create ruleset object
    Ruleset questRuleset;

	// 2. enter ruleset data
    questRuleset.Rule("Quest")->Sym("Objective")->Sym("Reward")->End();
    questRuleset.Rule("Objective")->Sym("KillMonsters")->End();
    questRuleset.Rule("Objective")->Sym("GatherItems")->End();
    questRuleset.Rule("Objective")->Sym("HuntForFood")->Sym("CookFood")->End();
    questRuleset.Rule("CookFood")->Sym("GatherWood")->Sym("LightFire")->Sym("GrillTheMeat")->End();
    questRuleset.Rule("GrillTheMeat")->Sym("EatFood")->End();
    questRuleset.Rule("GrillTheMeat")->Sym("DeliverFood")->End();

	// 3. create generator
    Generator contentGenerator;

	// 4. give ruleset to generator
    contentGenerator.SetRuleset(&questRuleset);

	// 5. ask generator to make stuff, dont forget to say "please".
    vector<string> generatedQuest;
    generatedQuest = contentGenerator.Generate("Quest"); // pleaaaaaaaase :)

	return 0;
}

