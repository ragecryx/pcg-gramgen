#include <iostream>
#include <cstdlib>

using namespace std;

#include <PCGGram/Ruleset.hpp>
#include <PCGGram/Generator.hpp>

#include "Demo.hpp"
#include "DemoQuests.hpp"
#include "DemoWeapons.hpp"

using namespace PCGGrammar;


/// General usage steps
// 1. create ruleset object
// 2. enter ruleset data
// 3. create generator
// 4. give ruleset to generator
// 5. ask generator to make stuff, dont forget to say "please".


int main() {

    Demo* currentDemo = 0;
    bool isRunning = true;
    char choice;
    
    do {
        cout << "** Procedural Content Generation using Generative Grammars **\n\n";
        cout << "Select demo:\n";
        cout << "   Demo 1: Quest Generation (Description)\n";
        cout << "   Demo 2: Weapon Generation\n";
        cout << "   'q' to quit\n\n";
        cout << "(Number)> ";
        choice = cin.get();
        
        if( currentDemo != 0 ) {
            delete currentDemo;
            currentDemo = 0;
        }
        
        switch (choice) {
            case '1':
                currentDemo = new DemoQuests();
                break;
            case '2':
                currentDemo = new DemoWeapons();
                break;
            case 'q':
                isRunning = false;
                break;
        }
        
        if( currentDemo!= 0 ) {
            
            currentDemo->Initialize();
            currentDemo->Run();
            
            cin.get(); // registers 2 enters for some reason :/
            
            #ifdef WINDOWS_PLATFORM
                system("cls");
            #else
                system("clear");
            #endif
        }
        
        
    } while ( isRunning );

    delete currentDemo;

    return 0;
}

