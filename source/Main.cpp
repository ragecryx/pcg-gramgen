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

    quests.Rule("Quest")->Sym("Objective")->Sym("\nComplete:")->Sym("Reward")->End();
	
	quests.Rule("Reward")->Sym("XP")->End();
	quests.Rule("Reward")->Sym("RewardItem")->Sym("XP")->End();
	quests.Rule("RewardItem")->Sym("A weapon of your choice.")->End();
	quests.Rule("RewardItem")->Sym("A weapon of your choice.")->End();
	
	quests.Rule("XP")->Sym("100XP")->End();
	quests.Rule("XP")->Sym("250XP")->End();
	quests.Rule("XP")->Sym("600XP")->End();
	quests.Rule("XP")->Sym("1100XP")->End();
	quests.Rule("XP")->Sym("1800XP")->End();
	quests.Rule("XP")->Sym("2500XP")->End();
	quests.Rule("XP")->Sym("3600XP")->End();
	quests.Rule("XP")->Sym("4200XP")->End();
	quests.Rule("XP")->Sym("5000XP")->End();
	
	
    quests.Rule("Objective")->Sym("Kill")->Sym("KillMonsters")->End();
	quests.Rule("KillMonsters")->Sym("MonsterType")->Sym("Count")->End();
	quests.Rule("MonsterType")->Sym("Goblin")->End();
	quests.Rule("MonsterType")->Sym("Ogre")->End();
	quests.Rule("MonsterType")->Sym("Undead")->End();
	quests.Rule("MonsterType")->Sym("Lizardfolk")->End();
	quests.Rule("MonsterType")->Sym("Gargoyle")->End();
	quests.Rule("MonsterType")->Sym("Wraith")->End();
	quests.Rule("MonsterType")->Sym("Hellhound")->End();
	
	
	quests.Rule("KillMonsters")->Sym("KillBoss")->End();
	quests.Rule("KillBoss")->Sym("MonsterBoss")->Sym("BossDifficulty")->End();
	quests.Rule("MonsterBoss")->Sym("The Lich King")->End();
	quests.Rule("MonsterBoss")->Sym("The Red Dragon")->End();
	quests.Rule("MonsterBoss")->Sym("The Kraken")->End();
	quests.Rule("MonsterBoss")->Sym("The Pirate Lord")->End();
	quests.Rule("MonsterBoss")->Sym("The Witch of the Seven Realms")->End();
	quests.Rule("BossDifficulty")->Sym("Normal")->End(0.7f);
	quests.Rule("BossDifficulty")->Sym("Hard")->End(0.16f);
	quests.Rule("BossDifficulty")->Sym("Harder")->End(0.1f);
	quests.Rule("BossDifficulty")->Sym("Insane")->End(0.02f);
	quests.Rule("BossDifficulty")->Sym("Nightmare")->End(0.015f);
	quests.Rule("BossDifficulty")->Sym("MonoGiaTonLeuteri")->End(0.005f);
	
	
    quests.Rule("Objective")->Sym("CollectItems")->Sym("Count")->End();
	quests.Rule("CollectItems")->Sym("GatherHerbs")->End();
	quests.Rule("CollectItems")->Sym("GatherOre")->End();
	quests.Rule("CollectItems")->Sym("GatherWood")->End();
	quests.Rule("CollectItems")->Sym("CollectMetalScraps")->End();
	quests.Rule("CollectItems")->Sym("CollectMobLoot")->End();
	
	quests.Rule("Objective")->Sym("Deliver")->Sym("DeliverItems")->End();
	quests.Rule("DeliverItems")->Sym("ItemType")->Sym("Count")->Sym("to")->Sym("NPC")->End();
	quests.Rule("ItemType")->Sym("Weapons")->End();
	quests.Rule("ItemType")->Sym("Food")->End();
	quests.Rule("ItemType")->Sym("Crafting Materials")->End();
	quests.Rule("ItemType")->Sym("Precious gems")->End();
	quests.Rule("ItemType")->Sym("Letters")->End();
	quests.Rule("ItemType")->Sym("Rare Pendant")->End(0.01f);
	quests.Rule("ItemType")->Sym("Armor")->End();
	quests.Rule("ItemType")->Sym("Spellbook")->End();
	quests.Rule("NPC")->Sym("Greg the traveling merchant")->End();
	quests.Rule("NPC")->Sym("Laura, Priestess of Cutethulhu")->End();
	quests.Rule("NPC")->Sym("Kidd, the fearsome thief lord")->End();
	quests.Rule("NPC")->Sym("Heine, cleric of the Sun-god")->End();
	quests.Rule("NPC")->Sym("Dranzer the mighty warrior")->End();
	
	
	quests.Rule("Count")->Sym("x 2")->End();
	quests.Rule("Count")->Sym("x 3")->End();
	quests.Rule("Count")->Sym("x 4")->End();
	quests.Rule("Count")->Sym("x 5")->End();
	quests.Rule("Count")->Sym("x 6")->End();
	quests.Rule("Count")->Sym("x 7")->End();
	quests.Rule("Count")->Sym("x 8")->End();
	quests.Rule("Count")->Sym("x 9")->End();
	quests.Rule("Count")->Sym("x 10")->End();
	
	
	

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
        gen = contentGenerator.Generate("Quest");
        for(vector<string>::iterator it = gen.begin(); it!=gen.end(); it++) {
            cout << *it << " ";
        }
        cout << endl << endl;
    } while(cin.get());

	return 0;
}

