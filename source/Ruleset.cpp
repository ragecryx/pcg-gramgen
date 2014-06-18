#include <PCGGram/Ruleset.h>

using namespace PCGGrammar;


// Ruleset class = = = = = = =

Ruleset::Ruleset() { }

Ruleset::~Ruleset() { }


__RulesetWork* Ruleset::Rule(string sym) {
    __RulesetWork* work = new __RulesetWork(this, sym);
    return work;
}


void Ruleset::AddRule(string rule, ComponentVector components) {
    mRules.insert( pair<string, ComponentVector>(rule, components) );
}


bool Ruleset::IsTerminal(string sym) const {
    if(mRules.find(sym) != mRules.end())
        return false;
    else
        return true;
}


pair< RuleMap::const_iterator, RuleMap::const_iterator > Ruleset::GetRulesFor(string sym) const {
    return mRules.equal_range(sym);
}


// __RulesetWork class = = = = = = =

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
