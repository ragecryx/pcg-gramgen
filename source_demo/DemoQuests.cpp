#include "DemoQuests.hpp"


DemoQuests::DemoQuests () { }


DemoQuests::~DemoQuests () { }


void DemoQuests::Initialize () {
    
    // ==============================================
    // Quest generation rules
    // ==============================================

    quests.Rule("QUEST")->Sym("OBJECTIVES")->End();
    quests.Rule("OBJECTIVES")->Sym("OBJECTIVE")->End(0.6);
    // quests.Rule("OBJECTIVES")->Sym("OBJECTIVE")->Sym("\n\n")->Sym("OBJECTIVES")->End(0.4);
    // ^ quests with multiple objectives seem very difficult
    // TODO: split OBJECTIVES so we have one BIG objective or a group of SMALLER ones.
    
    // NPC Names ===
    
    quests.Rule("NPC")->Sym("NPC_NORMAL")->End();
    quests.Rule("NPC")->Sym("NPC_TITLED")->End();
    quests.Rule("NPC_NORMAL")->Sym("NAME")->Sym("of")->Sym("PLACE")->End();
    quests.Rule("NPC_NORMAL")->Sym("NAME")->Sym("SURNAME")->End();
    
    quests.Rule("NPC_TITLED")->Sym("MALE_TITLE")->Sym("MALE_NAME")->End();
    quests.Rule("NPC_TITLED")->Sym("MALE_TITLE")->Sym("MALE_NAME")->Sym("of")->Sym("PLACE")->End();
    quests.Rule("NPC_TITLED")->Sym("FEMALE_TITLE")->Sym("FEMALE_NAME")->End();
    quests.Rule("NPC_TITLED")->Sym("FEMALE_TITLE")->Sym("FEMALE_NAME")->Sym("of")->Sym("PLACE")->End();
    
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
    quests.Rule("MALE_NAME")->Sym("Henry")->End();
    quests.Rule("MALE_NAME")->Sym("Drustan")->End();
    quests.Rule("MALE_NAME")->Sym("Judoc")->End();
    
    
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
    quests.Rule("FEMALE_NAME")->Sym("Adelaine")->End();
    quests.Rule("FEMALE_NAME")->Sym("Bertha")->End();
    quests.Rule("FEMALE_NAME")->Sym("Odilia")->End();
    
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
    // Buildings
    
    quests.Rule("BUILDING")->Sym("house")->End();
    quests.Rule("BUILDING")->Sym("mansion")->End();
    quests.Rule("BUILDING")->Sym("shop")->End();
    quests.Rule("BUILDING")->Sym("tavern")->End();
    quests.Rule("BUILDING")->Sym("inn")->End();
    quests.Rule("BUILDING")->Sym("barn")->End();
    quests.Rule("BUILDING")->Sym("church")->End();
    quests.Rule("BUILDING")->Sym("mausoleum")->End();
    quests.Rule("BUILDING")->Sym("graveyard")->End();
    quests.Rule("BUILDING")->Sym("stable")->End();
    quests.Rule("BUILDING")->Sym("water-mill")->End();
    quests.Rule("BUILDING")->Sym("lighthouse")->End();
    quests.Rule("BUILDING")->Sym("watchtower")->End();
    quests.Rule("BUILDING")->Sym("wizards tower")->End();
    quests.Rule("BUILDING")->Sym("bridge")->End();
    quests.Rule("BUILDING")->Sym("castle")->End();
    quests.Rule("BUILDING")->Sym("quarry")->End();
    quests.Rule("BUILDING")->Sym("dungeon")->End();
    
    // Buildings end ===
    // Point-Of-Interest
    
    quests.Rule("POINT_OF_INTEREST")->Sym("a forest")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("some ancient ruins")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("a cave")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("an abandoned dungeon")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("a magical forest")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("a deserted city")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("a swamp")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("a huge grassland")->End();
    quests.Rule("POINT_OF_INTEREST")->Sym("a hidden underwater cavern")->End(0.01);
    
    // Point-Of-Interest end ===
    // Relics
    
    quests.Rule("RELIC")->Sym("A map to a hidden artifact")->End();
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
    // Religious, Political, Philosophical Groups
    
    quests.Rule("RPP_GROUP")->Sym("religion")->End();
    quests.Rule("RPP_GROUP")->Sym("cult")->End();
    quests.Rule("RPP_GROUP")->Sym("sect")->End();
    quests.Rule("RPP_GROUP")->Sym("secret society")->End();
    
    // Religious, Political, Philosophical Groups end ===
    // Factions
    
    quests.Rule("FACTION")->Sym("Pirates of the Withered Sea")->End();
    quests.Rule("FACTION")->Sym("Red-fang Knights")->End();
    quests.Rule("FACTION")->Sym("Noble Swordsmen of Berxley")->End();
    quests.Rule("FACTION")->Sym("The Empire")->End();
    
    // Factions end ===
    // Classes
    
    quests.Rule("CLASS")->Sym("Warrior")->End();
    quests.Rule("CLASS")->Sym("Wizard")->End();
    quests.Rule("CLASS")->Sym("Thief")->End();
    quests.Rule("CLASS")->Sym("Paladin")->End();
    quests.Rule("CLASS")->Sym("Cleric")->End();
    quests.Rule("CLASS")->Sym("Sorcerer")->End();
    quests.Rule("CLASS")->Sym("Barbarian")->End();
    quests.Rule("CLASS")->Sym("Ranger")->End();
    quests.Rule("CLASS")->Sym("Bard")->End();
    quests.Rule("CLASS")->Sym("Necromancer")->End();
    quests.Rule("CLASS")->Sym("Druid")->End();
    
    // Classes end ===
    // Jobs
    
    quests.Rule("JOB")->Sym("farmer")->End();
    quests.Rule("JOB")->Sym("stockman")->End();
    quests.Rule("JOB")->Sym("merchant")->End();
    quests.Rule("JOB")->Sym("blacksmith")->End();
    quests.Rule("JOB")->Sym("tailor")->End();
    quests.Rule("JOB")->Sym("innkeeper")->End();
    quests.Rule("JOB")->Sym("guard")->End();
    quests.Rule("JOB")->Sym("armorsmith")->End();
    quests.Rule("JOB")->Sym("adventurer")->End();
    
    // Jobs end ===
    // The Quests
    
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("lost")->Sym("RELIC")->Sym("!  Find it and bring it back.")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to steal")->Sym("RELIC")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to smuggle")->Sym("ITEM")->Sym("from")->Sym("PLACE")->Sym("to")->Sym("PLACE")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to smuggle some")->Sym("ITEMS")->Sym("from")->Sym("PLACE")->Sym("to")->Sym("PLACE")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to assasinate")->Sym("NPC")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to deliver a package to")->Sym("NPC")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to deliver a message to")->Sym("NPC")->End();
    quests.Rule("OBJECTIVE")->Sym("FACTION")->Sym("attacked")->Sym("GROUP")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym(".\nYour task is to help the defenders.")->End();
    quests.Rule("OBJECTIVE")->Sym("FACTION")->Sym("attacked")->Sym("GROUP")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym(".\nYour task is to help the attackers.")->End();
    quests.Rule("OBJECTIVE")->Sym("A mysterious monster appeared")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym("!  Your task is to kill it.")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("needs you as a champion to fight in a duel of honor. Your opponent is")->Sym("NPC")->End();
    quests.Rule("OBJECTIVE")->Sym("Thieves are stealing the people of")->Sym("PLACE")->Sym(".  A wealthy ")->Sym("JOB")->Sym(" that goes by the name of")->Sym("NPC_NORMAL")->Sym("wants to sponsor you in order to stop them.")->End();
    quests.Rule("OBJECTIVE")->Sym("A dead")->Sym("CLASS")->Sym("named")->Sym("NPC")->Sym("is haunting a")->Sym("BUILDING")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym(". Your task is to help the ghost find peace.")->End();
    quests.Rule("OBJECTIVE")->Sym("NPC")->Sym("wants you to destroy a")->Sym("BUILDING")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->End();
    quests.Rule("OBJECTIVE")->Sym("A little girl named")->Sym("FEMALE_NAME")->Sym("has dark visions about a noble named")->Sym("MALE_TITLE")->Sym("MALE_NAME")->Sym(".\nFind and deal with the source of the kid's nightmares!")->End();
    quests.Rule("OBJECTIVE")->Sym("A little boy named")->Sym("MALE_NAME")->Sym("was kidnapped by an evil")->Sym("CLASS")->Sym("named")->Sym("MALE_NAME")->Sym(".\nRescue the kid!")->End();
    quests.Rule("OBJECTIVE")->Sym("Recently")->Sym("GROUP")->Sym("in")->Sym("POINT_OF_INTEREST")->Sym("ADVERB_OF_PLACE")->Sym("PLACE")->Sym("created a dangerous")->Sym("RPP_GROUP")->Sym("! You are commanded to end their heinous acts.")->End();
    
    // The Quests end ===
    // ============================= QUEST RULESET ENDS HERE

    contentGenerator.SetRuleset(&quests);
}



void DemoQuests::Run () {
    vector<string> gen;

    cout << "Press enter to generate more...\n===============================\nPress q and enter to quit demo...\n===============================\n\n";
    do{
        gen = contentGenerator.Generate("QUEST");
        for(vector<string>::iterator it = gen.begin(); it!=gen.end(); it++) {
            cout << *it << " ";
        }
        cout << endl << endl << "= = = = = = = = = = = =" << endl;
    } while(cin.get() != 'q');

}

