#ifndef PCGGRAM_RULESET_H
#define PCGGRAM_RULESET_H

#include <string>
#include <map>
#include <vector>


using namespace std;

namespace PCGGrammar {

    class __RulesetWork;
    
    class Ruleset {
        public:
            Ruleset();
            ~Ruleset();
        private:
            map<string, vector<vector<string>>> mRules;
        public:
            __RulesetWork* Rule(string sym);
            void AddRule(string rule, vector<string> components);
            bool IsTerminal(string sym);
            vector<vector<string>> GetRulesFor(string sym);
    };

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
