#include "PCGGram\Ruleset.h"

using namespace PCGGrammar;

Ruleset::Ruleset() { }

Ruleset::~Ruleset() { }


__RulesetWork* Ruleset::Rule(string sym) {
    __RulesetWork* work = new __RulesetWork(this, sym);
    return work;
}

void Ruleset::AddRule(string rule, vector<string> components) {
    mRules[rule].push_back(components);
}


bool Ruleset::IsTerminal(string sym) {
    if(mRules.find(sym) != mRules.end())
        return false;
    else
        return true;
}


vector<vector<string>> Ruleset::GetRulesFor(string sym) {
    if(mRules.find(sym) != mRules.end())
        return mRules[sym];
    else
        return vector<vector<string>>();
}






__RulesetWork::__RulesetWork(Ruleset* parentObject, string parentRule) {
    mpParent = parentObject;
    mParentRule = parentRule;
    mRule.clear();
}

__RulesetWork* __RulesetWork::Sym(string sym) {
    mRule.push_back(sym);
    return this;
}


void __RulesetWork::End() {
    mpParent->AddRule(mParentRule, mRule);
    delete this;
}
