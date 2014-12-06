#ifndef PCGGRAM_RULESET_H
#define PCGGRAM_RULESET_H

#include <string>
#include <map>
#include <vector>


using namespace std;


namespace PCGGrammar {
    
    typedef vector<string> ComponentVector;
    typedef multimap< string, ComponentVector > RuleMap;
    typedef multimap< string, float > DistributionMap;

    class __RuleInjector;
    
    // Ruleset class
    //
    // Instantiate and use instance.Rule("COMPOSITE_SYMBOL")->Sym("COMPONENT_SYMBOL")->Sym("terminal symbol")->Sym("ANOTHER_COMPONENT_SYMBOL")->End();
    // Dont forget calling End(), it saves the changes back to the ruleset.
    //
    // Instantiate and use instance.AddRule("COMPOSITE_SYMBOL", VECTOR_OF_STRINGS_WITH_THE_DECOMPOSITION)
    // if you already have the data (like if you are reading production rules from a file).

    class Ruleset {
        public:
            Ruleset();
            ~Ruleset();
        private:
            RuleMap mRules;
            DistributionMap mRuleWeights;
        public:
            __RuleInjector* Rule(string sym);
            void AddRule(string rule, ComponentVector components, float weight);
            bool IsTerminal(string sym) const;
            vector<string> GetNonTerminals(void) const;
            pair< RuleMap::const_iterator, RuleMap::const_iterator > GetRulesFor(string sym) const;
            pair< DistributionMap::const_iterator, DistributionMap::const_iterator > GetWeightsFor(string sym) const;
    };




    // __RuleInjector class, do not instantiate manually.

    class __RuleInjector {
        public:
            __RuleInjector(Ruleset* parentObject, string parentRule);
        private:
            Ruleset* mpParent;
            string mParentRule;
            vector<string> mRule;
        public:
            __RuleInjector* Sym(string sym);
            void End();
            void End(float weight);
    };


}


#endif
