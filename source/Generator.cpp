#include "PCGGram/Generator.h"

#include <cstdio>
#include <cstdlib>
#include <random>
#include <iterator>

using namespace PCGGrammar;

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter random_element(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}

Generator::Generator() : mpRuleset(0) { }
Generator::~Generator() { }


void Generator::SetRuleset(Ruleset* ruleset) {
    mpRuleset = ruleset;
}

vector<string> Generator::Generate(string baseRule) {
    ComponentVector mainList;
    ComponentVector tempList;
    mainList.clear();
    tempList.clear();

    const pair< RuleMap::const_iterator, RuleMap::const_iterator > &range = mpRuleset->GetRulesFor(baseRule);
    ComponentVector initial = random_element(range.first, range.second)->second;
    
    mainList = initial;

    bool run;
    do {
        run = false;
        for(vector<string>::iterator it = mainList.begin(); it != mainList.end(); ++it) {
            if(mpRuleset->IsTerminal(*it))
                tempList.push_back(*it);
            else {
                run = true;
                const pair< RuleMap::const_iterator, RuleMap::const_iterator > &rules = mpRuleset->GetRulesFor(*it);
                
                if ( rules.first != rules.second ) {
                    const ComponentVector &tobeadded = random_element(rules.first, rules.second)->second;
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
