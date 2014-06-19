#include "PCGGram/Generator.h"

#include <cstdio>
#include <cstdlib>
#include <random>
#include <iterator>
#include <functional>

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

template<typename Iter>
vector< float > iterator_to_vector(Iter start, Iter end) {
	vector< float > data;
    while(start != end) {
        data.push_back(start->second);
        ++start;
    }
	return data;
}


Generator::Generator() : mpRuleset(0) { }
Generator::~Generator() { }


void Generator::SetRuleset(Ruleset* ruleset) {
    mpRuleset = ruleset;
}

vector<string> Generator::Generate(string baseRule) const {
    ComponentVector mainList;
    ComponentVector tempList;
    
    static std::random_device rd;
    static std::mt19937 gen(rd());
	
	{
		const pair< RuleMap::const_iterator, RuleMap::const_iterator > &range = mpRuleset->GetRulesFor(baseRule);
		std::pair< DistributionMap::const_iterator, DistributionMap::const_iterator > weightData = mpRuleset->GetWeightsFor(baseRule);
		
		vector< float > weights = iterator_to_vector(weightData.first, weightData.second);
		std::discrete_distribution<int> dist(weights.begin(), weights.end());
		
		RuleMap::const_iterator it = range.first;
		std::advance(it, dist(gen));
		ComponentVector initial = it->second;
		mainList = initial;
	}

    bool run;
    do {
        run = false;
        tempList.clear();
        
        for(ComponentVector::const_iterator it = mainList.begin(); it != mainList.end(); ++it) {
            if(mpRuleset->IsTerminal(*it))
                tempList.push_back(*it);
            else {
                run = true;
                const pair< RuleMap::const_iterator, RuleMap::const_iterator > &rules = mpRuleset->GetRulesFor(*it);
                
                if ( rules.first != rules.second ) {
					// Fetch weights for the current to-be-decomposed rules
					std::pair< DistributionMap::const_iterator, DistributionMap::const_iterator > ruleWeightData = mpRuleset->GetWeightsFor(*it);
					vector< float > ruleWeights = iterator_to_vector(ruleWeightData.first, ruleWeightData.second);
					// Setup distribution with the weights and choose a random rule to apply
					std::discrete_distribution<int> dist(ruleWeights.begin(), ruleWeights.end());
					RuleMap::const_iterator it = rules.first;
					std::advance(it, dist(gen));
					
                    const ComponentVector &tobeadded = it->second;
                    tempList.insert(tempList.end(), tobeadded.begin(), tobeadded.end());
                }
				
            }
        }
        
        mainList = tempList;
        
    } while(run);

    return mainList;
}
