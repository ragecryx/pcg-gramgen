#ifndef PCGGRAM_GENERATOR_H
#define PCGGRAM_GENERATOR_H

#include <string>

using namespace std;


#include "Ruleset.h"


namespace PCGGrammar {


    // Generator class
    //
    // Instantiate and set the ruleset to be used with instance.SetRuleset(&rulesetinstance)
    // then call instance.Generate("COMPOSITE_SYMBOL_YOU_WANT_TO_GENERATE") to generate the
    // stuff you want.
    
    class Generator {
        public:
            Generator();
			Generator(string seed);
            ~Generator();
        private:
            Ruleset* mpRuleset;
			string mSeedString;
        public:
            void SetRuleset(Ruleset* ruleset);
            ComponentVector Generate(string baseRule) const;
    };


}


#endif
