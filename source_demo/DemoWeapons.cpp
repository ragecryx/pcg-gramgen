#include "DemoWeapons.hpp"


DemoWeapons::DemoWeapons () { }


DemoWeapons::~DemoWeapons () { }


void DemoWeapons::Initialize () {

    // ==============================================
    // Weapon generation rules
    // ==============================================

    weapons.Rule("WEAPON")->Sym("UNNAMED_WEAPON")->End(0.9f);
    weapons.Rule("WEAPON")->Sym("NAMED_WEAPON")->End(0.1f);

    weapons.Rule("NAMED_WEAPON")->Sym("The")->Sym("PREFIX")->Sym("UNNAMED_WEAPON")->End();
    weapons.Rule("UNNAMED_WEAPON")->Sym("TYPE")->Sym("STATS")->End(0.8f);
    weapons.Rule("UNNAMED_WEAPON")->Sym("TYPE")->Sym("ENCHANT")->Sym("STATS")->End(0.2f);
    

    weapons.Rule("TYPE")->Sym("SWORD")->End();
    weapons.Rule("TYPE")->Sym("STAFF")->End();
    weapons.Rule("TYPE")->Sym("MACE")->End();
    weapons.Rule("TYPE")->Sym("BOW")->End();
    weapons.Rule("TYPE")->Sym("AXE")->End();
    weapons.Rule("TYPE")->Sym("SPEAR")->End();

    weapons.Rule("SWORD")->Sym("Longsword")->End();
    weapons.Rule("SWORD")->Sym("Shortsword")->End();
    weapons.Rule("SWORD")->Sym("Greatsword")->End();
    weapons.Rule("SWORD")->Sym("Rapier")->End();

    weapons.Rule("STAFF")->Sym("Wooden Staff")->End();
    weapons.Rule("STAFF")->Sym("Magic Staff")->End();
    weapons.Rule("STAFF")->Sym("Holy Staff")->End();
    weapons.Rule("STAFF")->Sym("Royal Staff")->End();

    weapons.Rule("MACE")->Sym("Mace")->End();
    weapons.Rule("MACE")->Sym("Royal Mace")->End();

    weapons.Rule("BOW")->Sym("Longbow")->End(0.5f);
    weapons.Rule("BOW")->Sym("Shortbow")->End(0.3f);
    weapons.Rule("BOW")->Sym("Crossbow")->End(0.2f);

    weapons.Rule("AXE")->Sym("Greataxe")->End(0.3f);
    weapons.Rule("AXE")->Sym("Axe")->End(0.6f);
    weapons.Rule("AXE")->Sym("Throwing Axe")->End(0.1f);

    weapons.Rule("SPEAR")->Sym("Spear")->End();
    weapons.Rule("SPEAR")->Sym("Giant Spear")->End();


    weapons.Rule("STATS")->Sym("PRIMARYSTAT")->Sym("SECONDARYSTAT")->End();

    weapons.Rule("PRIMARYSTAT")->Sym("\n Primary Stat:")->Sym("STATTYPE")->End(); // Added a fake Sym(bol) for printing purposes ->Sym("\n Primary Stat:")->
    weapons.Rule("SECONDARYSTAT")->Sym("\n Secondary Stat:")->Sym("STATTYPE")->End();

    weapons.Rule("STATTYPE")->Sym("Offence")->End();
    weapons.Rule("STATTYPE")->Sym("Defence")->End();
    weapons.Rule("STATTYPE")->Sym("Agility")->End();
    weapons.Rule("STATTYPE")->Sym("Health")->End();
    weapons.Rule("STATTYPE")->Sym("Magic")->End();
    weapons.Rule("STATTYPE")->Sym("Stamina")->End();
    weapons.Rule("STATTYPE")->Sym("Intelligence")->End();
    weapons.Rule("STATTYPE")->Sym("Wisdom")->End();


    weapons.Rule("ENCHANT")->Sym("of the Dragon")->End();
    weapons.Rule("ENCHANT")->Sym("of Mount Doom")->End();
    weapons.Rule("ENCHANT")->Sym("of the Fire")->End();
    weapons.Rule("ENCHANT")->Sym("of the Forgotten Nightmares")->End();
    weapons.Rule("ENCHANT")->Sym("of the Angry Joe")->End();
    weapons.Rule("ENCHANT")->Sym("of the N00B")->End();
    weapons.Rule("ENCHANT")->Sym("of the Great Wizard")->End();
    weapons.Rule("ENCHANT")->Sym("of the Water")->End();
    weapons.Rule("ENCHANT")->Sym("of the Thunder")->End();
    weapons.Rule("ENCHANT")->Sym("of the Deep Sea")->End();
    weapons.Rule("ENCHANT")->Sym("of the Undeath")->End();
    weapons.Rule("ENCHANT")->Sym("of the Stone")->End();
    weapons.Rule("ENCHANT")->Sym("of Death")->End();
    weapons.Rule("ENCHANT")->Sym("of the Dream")->End();
    weapons.Rule("ENCHANT")->Sym("of the Munchkin")->End();
    weapons.Rule("ENCHANT")->Sym("of the Seven Ravens")->End();
    weapons.Rule("ENCHANT")->Sym("of the Infinity")->End();
    weapons.Rule("ENCHANT")->Sym("of the Thousand Souls")->End();
    weapons.Rule("ENCHANT")->Sym("of Bessy")->End();
    weapons.Rule("ENCHANT")->Sym("of the Unicorn")->End();


    weapons.Rule("PREFIX")->Sym("Cursed")->End();
    weapons.Rule("PREFIX")->Sym("Uber")->End();
    weapons.Rule("PREFIX")->Sym("Excelsior")->End();
    weapons.Rule("PREFIX")->Sym("Dominant")->End();
    weapons.Rule("PREFIX")->Sym("Fabulous")->End();
    weapons.Rule("PREFIX")->Sym("Uber")->End();
    weapons.Rule("PREFIX")->Sym("Ascendent")->End();
    weapons.Rule("PREFIX")->Sym("Cardinal")->End();
    weapons.Rule("PREFIX")->Sym("Sovereign")->End();
    weapons.Rule("PREFIX")->Sym("Over-Powered")->End();
    weapons.Rule("PREFIX")->Sym("Enchanted")->End();
    weapons.Rule("PREFIX")->Sym("Bewitched")->End();
    weapons.Rule("PREFIX")->Sym("Mesmerizing")->End();
    weapons.Rule("PREFIX")->Sym("Ravishing")->End();
    weapons.Rule("PREFIX")->Sym("Savage")->End();

    // ============================= WEAPON RULESET ENDS HERE

    contentGenerator.SetRuleset(&weapons);
}



void DemoWeapons::Run () {
    vector<string> gen;

    cout << "Press enter to generate more...\n===============================\nPress q and enter to quit demo...\n===============================\n\n";
    do{
        gen = contentGenerator.Generate("WEAPON");
        for(vector<string>::iterator it = gen.begin(); it!=gen.end(); it++) {
            cout << *it << " ";
        }
        cout << endl << endl << "= = = = = = = = = = = =" << endl;
    } while(cin.get() != 'q');
    
}

