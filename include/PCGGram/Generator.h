#ifndef PCGGRAM_GENERATOR_H
#define PCGGRAM_GENERATOR_H

#include <iostream>
#include <vector>
#include <stack>

using namespace std;


#include "Ruleset.h"


namespace PCGGrammar {
    
    class Generator {
        public:
            Generator();
            ~Generator();
        private:
            Ruleset* mpRuleset;
        public:
            void SetRuleset(Ruleset* ruleset);
            vector<string> Generate(string baseRule);
    };

}


#endif
