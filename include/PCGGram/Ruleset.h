#ifndef PCGGRAM_RULESET_H
#define PCGGRAM_RULESET_H

#include <string>
#include <map>
#include <vector>


using namespace std;

namespace PCGGrammar {

    class __RulesetWork;
    
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
            map< string, vector< vector<string> > > mRules;
        public:
            __RulesetWork* Rule(string sym);
            void AddRule(string rule, vector<string> components);
            bool IsTerminal(string sym);
            vector< vector<string> > GetRulesFor(string sym);
    };




    // __RulesetWork class, do not instantiate manually.

    class __RulesetWork {
        public:
            __RulesetWork(Ruleset* parentObject, string parentRule);
        private:
            Ruleset* mpParent;
            string mParentRule;
            vector<string> mRule;
        public:
            __RulesetWork* Sym(string sym);
            void End();
    };


}


#endif
