#include <iostream>

using namespace std;


#include <PCGGram/Ruleset.h>
#include <PCGGram/Generator.h>

using namespace PCGGrammar;


int main() {

	// 1. create ruleset object
    Ruleset quests;
    Ruleset weapons;


	// 2. enter ruleset data

    // ==============================================
    // Quest generation rules
    // ==============================================

    quests.Rule("QUEST")->Sym("OBJECTIVES")->End();
	quests.Rule("OBJECTIVES")->Sym("OBJECTIVE")->End(0.6);
	// quests.Rule("OBJECTIVES")->Sym("OBJECTIVE")->Sym("\n\n")->Sym("OBJECTIVES")->End(0.4);
	// ^ quests with multiple objectives seem very difficult
	// TODO: split OBJECTIVES so we have one BIG objective or a group of SMALLER ones.
	
	// NPC Names ===
	
	quests.Rule("NPC")->Sym("NAME")->Sym("of")->Sym("PLACE")->End();
	quests.Rule("NPC")->Sym("NAME")->Sym("SURNAME")->End();
	
	quests.Rule("NPC")->Sym("MALE_TITLE")->Sym("MALE_NAME")->End();
	quests.Rule("NPC")->Sym("MALE_TITLE")->Sym("MALE_NAME")->Sym("of")->Sym("PLACE")->End();
	quests.Rule("NPC")->Sym("FEMALE_TITLE")->Sym("FEMALE_NAME")->End();
	quests.Rule("NPC")->Sym("FEMALE_TITLE")->Sym("FEMALE_NAME")->Sym("of")->Sym("PLACE")->End();
	
	quests.Rule("NAME")->Sym("MALE_NAME")->End();
	quests.Rule("NAME")->Sym("FEMALE_NAME")->End();
	
	quests.Rule("MALE_TITLE")->Sym("Sir")->End(0.5);
	quests.Rule("MALE_TITLE")->Sym("Baron")->End(0.2);
	quests.Rule("MALE_TITLE")->Sym("Count")->End(0.15);
	quests.Rule("MALE_TITLE")->Sym("Duke")->End(0.1);
	quests.Rule("MALE_TITLE")->Sym("Prince")->End(0.05);
	
	quests.Rule("MALE_NAME")->Sym("Ron")->End();
	quests.Rule("MALE_NAME")->Sym("Edgar")->End();
	quests.Rule("MALE_NAME")->Sym("Gregor")->End();
	quests.Rule("MALE_NAME")->Sym("John")->End();
	quests.Rule("MALE_NAME")->Sym("Bran")->End();
	quests.Rule("MALE_NAME")->Sym("Jake")->End();
	quests.Rule("MALE_NAME")->Sym("Alan")->End();
	quests.Rule("MALE_NAME")->Sym("William")->End();
	
	
	quests.Rule("FEMALE_TITLE")->Sym("Lady")->End(0.5);
	quests.Rule("FEMALE_TITLE")->Sym("Baroness")->End(0.2);
	quests.Rule("FEMALE_TITLE")->Sym("Countess")->End(0.15);
	quests.Rule("FEMALE_TITLE")->Sym("Duchess")->End(0.1);
	quests.Rule("FEMALE_TITLE")->Sym("Princess")->End(0.05);
	
	quests.Rule("FEMALE_NAME")->Sym("Ravene")->End();
	quests.Rule("FEMALE_NAME")->Sym("Lucia")->End();
	quests.Rule("FEMALE_NAME")->Sym("Brienne")->End();
	quests.Rule("FEMALE_NAME")->Sym("Lyda")->End();
	quests.Rule("FEMALE_NAME")->Sym("Jasmine")->End();
	quests.Rule("FEMALE_NAME")->Sym("Lenore")->End();
	quests.Rule("FEMALE_NAME")->Sym("Olivia")->End();
	quests.Rule("FEMALE_NAME")->Sym("Henriette")->End();
	
	quests.Rule("SURNAME")->Sym("Addinell")->End();
	quests.Rule("SURNAME")->Sym("Ashdown")->End();
	quests.Rule("SURNAME")->Sym("Arundel")->End();
	quests.Rule("SURNAME")->Sym("Bainard")->End();
	quests.Rule("SURNAME")->Sym("Baudry")->End();
	quests.Rule("SURNAME")->Sym("Bertran")->End();
	quests.Rule("SURNAME")->Sym("Cardon")->End();
	quests.Rule("SURNAME")->Sym("Cooper")->End();
	quests.Rule("SURNAME")->Sym("Clarke")->End();
	quests.Rule("SURNAME")->Sym("Durerie")->End();
	quests.Rule("SURNAME")->Sym("Digby")->End();
	quests.Rule("SURNAME")->Sym("Durandhal")->End();
	quests.Rule("SURNAME")->Sym("Esteney")->End();
	quests.Rule("SURNAME")->Sym("Elers")->End();
	quests.Rule("SURNAME")->Sym("Eustace")->End();
	quests.Rule("SURNAME")->Sym("Fletcher")->End();
	quests.Rule("SURNAME")->Sym("Fergant")->End();
	quests.Rule("SURNAME")->Sym("Fossard")->End();
	quests.Rule("SURNAME")->Sym("Godfrey")->End();
	quests.Rule("SURNAME")->Sym("Gillain")->End();
	quests.Rule("SURNAME")->Sym("Griffin")->End();
	quests.Rule("SURNAME")->Sym("Hendry")->End();
	quests.Rule("SURNAME")->Sym("Hughes")->End();
	quests.Rule("SURNAME")->Sym("Herbard")->End();
	quests.Rule("SURNAME")->Sym("Lovet")->End();
	quests.Rule("SURNAME")->Sym("Ludel")->End();
	quests.Rule("SURNAME")->Sym("Leigh")->End();
	quests.Rule("SURNAME")->Sym("Maignart")->End();
	quests.Rule("SURNAME")->Sym("Mallory")->End();
	quests.Rule("SURNAME")->Sym("Montgomery")->End();
	quests.Rule("SURNAME")->Sym("Nelond")->End();
	quests.Rule("SURNAME")->Sym("Nesdin")->End();
	quests.Rule("SURNAME")->Sym("Neville")->End();
	quests.Rule("SURNAME")->Sym("Owens")->End();
	quests.Rule("SURNAME")->Sym("Orlebar")->End();
	quests.Rule("SURNAME")->Sym("Osmond")->End();
	quests.Rule("SURNAME")->Sym("Rainecourt")->End();
	quests.Rule("SURNAME")->Sym("Rolfe")->End();
	quests.Rule("SURNAME")->Sym("Roard")->End();
	quests.Rule("SURNAME")->Sym("Somneri")->End();
	quests.Rule("SURNAME")->Sym("Strivelyn")->End();
	quests.Rule("SURNAME")->Sym("Shaw")->End();
	quests.Rule("SURNAME")->Sym("Talvace")->End();
	quests.Rule("SURNAME")->Sym("Thaon")->End();
	quests.Rule("SURNAME")->Sym("Taylor")->End();
	quests.Rule("SURNAME")->Sym("Ventris")->End();
	quests.Rule("SURNAME")->Sym("Wilde")->End();
	quests.Rule("SURNAME")->Sym("Wissant")->End();
	quests.Rule("SURNAME")->Sym("Wells")->End();
	
	// Names end ===
	// Places ===
	
	quests.Rule("PLACE")->Sym("Castle Frostford")->End();
	quests.Rule("PLACE")->Sym("Town of Pontybridge")->End();
	quests.Rule("PLACE")->Sym("Berxley")->End();
	quests.Rule("PLACE")->Sym("City of Blackpool")->End();
	quests.Rule("PLACE")->Sym("Marren's Eve Crossroads")->End();
	quests.Rule("PLACE")->Sym("Wakefield")->End();
	quests.Rule("PLACE")->Sym("Orrenshire")->End();
	quests.Rule("PLACE")->Sym("City of Aysgarth")->End();
	quests.Rule("PLACE")->Sym("Wolfden Village")->End();
	quests.Rule("PLACE")->Sym("Lockinge")->End();
	quests.Rule("PLACE")->Sym("Longdale Town")->End();
	quests.Rule("PLACE")->Sym("Auchendale")->End();
	quests.Rule("PLACE")->Sym("Bellmoral Falls")->End();
	quests.Rule("PLACE")->Sym("Wealdstone")->End();
	quests.Rule("PLACE")->Sym("Erith Castle")->End();
	
	// Places end ===
	// Adverb of place 
	
	quests.Rule("ADVERB_OF_PLACE")->Sym("near")->End();
	quests.Rule("ADVERB_OF_PLACE")->Sym("outside")->End();
	quests.Rule("ADVERB_OF_PLACE")->Sym("around")->End();
	quests.Rule("ADVERB_OF_PLACE")->Sym("east of the")->End();
	quests.Rule("ADVERB_OF_PLACE")->Sym("west of the")->End();
	quests.Rule("ADVERB_OF_PLACE")->Sym("north of the")->End();
	quests.Rule("ADVERB_OF_PLACE")->Sym("south of the")->End();
	
	// Adverb of place end ===
	// Items
	
	quests.Rule("ITEM")->Sym("a brand new armor")->End();
	quests.Rule("ITEM")->Sym("a carrot")->End();
	quests.Rule("ITEM")->Sym("a forbidden alcoholic beverage")->End();
	quests.Rule("ITEM")->Sym("a forbidden tobacco")->End();
	quests.Rule("ITEM")->Sym("a book")->End();
	quests.Rule("ITEM")->Sym("a quil")->End();
	quests.Rule("ITEM")->Sym("a garment")->End();
	quests.Rule("ITEM")->Sym("a piece of armor")->End();
	quests.Rule("ITEM")->Sym("a shield")->End();
	quests.Rule("ITEM")->Sym("a mysterious dust")->End();
	quests.Rule("ITEM")->Sym("a suspicious barrel")->End();
	
	quests.Rule("ITEMS")->Sym("vegetables")->End();
	quests.Rule("ITEMS")->Sym("books")->End();
	quests.Rule("ITEMS")->Sym("quils")->End();
	quests.Rule("ITEMS")->Sym("garments")->End();
	quests.Rule("ITEMS")->Sym("weapons")->End();
	quests.Rule("ITEMS")->Sym("forbidden weapons")->End();
	quests.Rule("ITEMS")->Sym("suspicious barrels")->End();
	quests.Rule("ITEMS")->Sym("rare runestones")->End();
	
	// Items end ===
	// Relics
	
	quests.Rule("RELIC")->Sym("An ancient amulet")->End();
	quests.Rule("RELIC")->Sym("A very rare tome of magic")->End();
	quests.Rule("RELIC")->Sym("An enchanted crystal orb")->End();
	quests.Rule("RELIC")->Sym("The Ring of Memories")->End();
	quests.Rule("RELIC")->Sym("A noble's legacy jewelry box")->End();
	quests.Rule("RELIC")->Sym("The Stick of Truth")->End();
	quests.Rule("RELIC")->Sym("A golden hairpin")->End();
	quests.Rule("RELIC")->Sym("A pair of handcrafted dragon boots")->End();
	quests.Rule("RELIC")->Sym("Krulgath's Great-Axe")->End();
	quests.Rule("RELIC")->Sym("An ancient coin")->End();
	quests.Rule("RELIC")->Sym("The mythic Dragon-tooth of Ulthar")->End();
	quests.Rule("RELIC")->Sym("Hellmare the Greatsword")->End();
	quests.Rule("RELIC")->Sym("The Chain of the Martyr")->End();
	quests.Rule("RELIC")->Sym("Lyath the Longbow")->End();
	quests.Rule("RELIC")->Sym("A small inscribed bell")->End();
	quests.Rule("RELIC")->Sym("The Staff of Eternal Fire")->End();
	quests.Rule("RELIC")->Sym("The Scepter of Nimble Water")->End();
	quests.Rule("RELIC")->Sym("A key of the Grand Keymaster")->End();
	quests.Rule("RELIC")->Sym("The Unshakable Shield")->End();
	
	// Relics end ===
	// Groups
	
	quests.Rule("GROUP")->Sym("a group of peasants")->End();
	quests.Rule("GROUP")->Sym("a group of farmers")->End();
	quests.Rule("GROUP")->Sym("a group of adventurers")->End();
	quests.Rule("GROUP")->Sym("a group of nobles")->End();
	
	quests.Rule("GROUP")->Sym("a caravan from the")->Sym("PLACE")->End();
	quests.Rule("GROUP")->Sym("a group of citizens from")->Sym("PLACE")->End();
	
	quests.Rule("GROUP")->Sym("a squad of")->Sym("FACTION")->End();
	quests.Rule("GROUP")->Sym("a battalion of")->Sym("FACTION")->End();
	quests.Rule("GROUP")->Sym("a brigade of")->Sym("FACTION")->End();
	
	// Groups end ===
	// Factions
	
	quests.Rule("FACTION")->Sym("Pirates of the West Seas")->End();
	quests.Rule("FACTION")->Sym("Knights of the Grey-Skies")->End();
	quests.Rule("FACTION")->Sym("Warriors of Berxley")->End();
	quests.Rule("FACTION")->Sym("The Empire")->End();
	
	// Factions end ===
	// The Quests
	
	quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("lost")->Sym("RELIC")->Sym("!  Find it and bring it back.")->End();
	quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to steal")->Sym("RELIC")->End();
	quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to smuggle")->Sym("ITEM")->Sym("from")->Sym("PLACE")->Sym("to")->Sym("PLACE")->End();
	quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to smuggle some")->Sym("ITEMS")->Sym("from")->Sym("PLACE")->Sym("to")->Sym("PLACE")->End();
	quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to assasinate")->Sym("NPC")->End();
	quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to deliver a package to")->Sym("NPC")->End();
	quests.Rule("OBJECTIVE")->Sym("FACTION")->Sym("attacked")->Sym("GROUP")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym(".\nHelp the defenders.")->End();
	quests.Rule("OBJECTIVE")->Sym("FACTION")->Sym("attacked")->Sym("GROUP")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym(".\nHelp the attackers.")->End();
	quests.Rule("OBJECTIVE")->Sym("A mysterious monster appeared")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym("!  Your task is to kill it.")->End();
	
	// The Quests end ===
	// ============================= QUEST RULESET ENDS HERE



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



	// 3. create generator
    Generator contentGenerator;

	// 4. give ruleset to generator
    contentGenerator.SetRuleset(&quests);

	// 5. ask generator to make stuff, dont forget to say "please".
    vector<string> gen;

    cout << "Press enter to generate more...\n===============================\n\n";
    do{
        gen = contentGenerator.Generate("QUEST");
        for(vector<string>::iterator it = gen.begin(); it!=gen.end(); it++) {
            cout << *it << " ";
        }
        cout << endl << endl << "= = = = = = = = = = = =" << endl;
    } while(cin.get());

	return 0;
}

