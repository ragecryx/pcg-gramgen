#include "PCGGram/Generator.h"

#include <cstdio>
#include <cstdlib>

using namespace PCGGrammar;


Generator::Generator() : mpRuleset(0) { }
Generator::~Generator() { }


void Generator::SetRuleset(Ruleset* ruleset) {
    mpRuleset = ruleset;
}

vector<string> Generator::Generate(string baseRule) {
    vector<string> mainList;
    vector<string> tempList;
    mainList.clear();
    tempList.clear();

    vector< vector<string> > initRule = mpRuleset->GetRulesFor(baseRule);
    vector<string> initial = initRule[rand() % initRule.size()];
    mainList = initial;

    bool run;
    do {
        run = false;
        for(vector<string>::iterator it = mainList.begin(); it != mainList.end(); it++) {
            if(mpRuleset->IsTerminal(*it))
                tempList.push_back(*it);
            else {
                run = true;
                vector< vector<string> > rules = mpRuleset->GetRulesFor(*it);
                if(rules.size() > 0) {
                    vector<string> tobeadded = rules[rand() % rules.size()];
                    tempList.insert(tempList.end(), tobeadded.begin(), tobeadded.end());
                }
            }
        }
        mainList.clear();
        mainList = tempList;
        tempList.clear();
    } while(run);

    return mainList;
}
