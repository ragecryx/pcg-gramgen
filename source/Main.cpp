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
    Ruleset story;

	// 2. enter ruleset data
    questRuleset.Rule("Quest")->Sym("Objective")->Sym("Reward")->End();
    questRuleset.Rule("Objective")->Sym("KillMonsters")->End();
    questRuleset.Rule("Objective")->Sym("GatherItems")->End();
    questRuleset.Rule("Objective")->Sym("HuntForFood")->Sym("CookFood")->End();
    questRuleset.Rule("CookFood")->Sym("GatherWood")->Sym("LightFire")->Sym("GrillTheMeat")->End();
    questRuleset.Rule("GrillTheMeat")->Sym("EatFood")->End();
    questRuleset.Rule("GrillTheMeat")->Sym("DeliverFood")->End();



    story.Rule("STORY")->Sym("Itan mia fora")->Sym("ATOMO")->Sym("pou forouse")->Sym("ROUXO")->Sym("kai pige")->Sym("MEROS")->End();
    
    story.Rule("ATOMO")->Sym("mia Prigkipisa")->End();
    story.Rule("ATOMO")->Sym("enas polemistis")->End();
    story.Rule("ATOMO")->Sym("o Antonis Samaras")->End();
    story.Rule("ATOMO")->Sym("o Papas")->End();
    story.Rule("ATOMO")->Sym("o Dante apo to DMC")->End();
    story.Rule("ATOMO")->Sym("mia gria")->End();
    
    story.Rule("ROUXO")->Sym("foustani")->End();
    story.Rule("ROUXO")->Sym("panoplia")->End();
    story.Rule("ROUXO")->Sym("kostoumi")->End();
    story.Rule("ROUXO")->Sym("vraka")->End();
    story.Rule("ROUXO")->Sym("sexy esorouxo")->End();
    story.Rule("ROUXO")->Sym("perikefalea")->End();
    story.Rule("ROUXO")->Sym("dantela")->End();
    story.Rule("ROUXO")->Sym("magio kai psa8ino kapelo")->End();
    
    story.Rule("MEROS")->Sym("ekdromi.")->End();
    story.Rule("MEROS")->Sym("na polemisei ton drako.")->End();
    story.Rule("MEROS")->Sym("sto diaolo!!!")->End();
    story.Rule("MEROS")->Sym("stin Alabama.")->End();
    story.Rule("MEROS")->Sym("stin toualeta.")->End();
    story.Rule("MEROS")->Sym("ston Vorio Polo.")->End();
    story.Rule("MEROS")->Sym("gamiontas...")->End();
    story.Rule("MEROS")->Sym("ston paradeiso.")->End();
    story.Rule("MEROS")->Sym("spiti...")->End();

	// 3. create generator
    Generator contentGenerator;

	// 4. give ruleset to generator
    contentGenerator.SetRuleset(&story);

	// 5. ask generator to make stuff, dont forget to say "please".
    vector<string> gen;

    for(int i=0; i<10; i++) {
        gen = contentGenerator.Generate("STORY");
        for(vector<string>::iterator it = gen.begin(); it!=gen.end(); it++) {
            cout << *it << " ";
        }
        cout << endl << endl;
    }

    cin.get();

	return 0;
}

