#include <iostream>   
#include <string>     
#include <random>
#include <ranges>
#include <SFML/Graphics.hpp>
#include <fstream>
using namespace std;
#include "Battle.h"
#include "Chest.h"
#include "Enemy.h"
#include "Inventory.h"
#include "Item.h"
#include "Money.h"
#include "Player.h"
#include "Weapons.h"
#include "World.h" // optional world header; comment out if missing

using namespace std;

int main() {
    int age;
    std::string player_name;

    std::cout << "Welcome to the game\n";

    cout << "Enter your age: ";
    while (!(cin >> age)) {  
        cout << "Invalid input. Try again: ";
        cin.clear(); 
        cin.ignore(10000, '\n'); 
    }
    cout << "You are: " << age;


    // consume leftover newline from previous input then read player name
    cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    do {
        cout << "Enter your name: ";
        getline(cin, player_name);
    } while (player_name.empty());

    cout << "Hello, " << player_name;

    // Create the player now that we know their name (constructor needs it up front)
    Player hero(player_name, "Warrior", 120, 15, 5);
    hero.setAge(age);

    std::cout << "Hello, " << hero.getName() << "\n";
    std::cout << "You are " << hero.getAge() << " years old\n";
    hero.displayStatus();

    Inventory player_inventory;
    Money player_gold;

    Chest treasure_chest;
    treasure_chest.lock();
    treasure_chest.setLoot("chest_key"); // just for testing the flow below

    bool hasKey = player_inventory.hasItem("chest_key");
    treasure_chest.tryUnlock(hasKey);

    if (!treasure_chest.isLocked() && !treasure_chest.isOpen()) {
        treasure_chest.open();
        player_gold.addGold(50);

        if (treasure_chest.hasItems()) {
            player_inventory.addItem(treasure_chest.getItemName());
        }
    }

    std::cout << "Chest open? " << std::boolalpha << treasure_chest.isOpen() << "\n";

    sf::RenderWindow window(sf::VideoMode(800, 600), "My C++ Window");

    while (window.isOpen()) {
        sf::Event event;

        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::Black);
        window.display();
    }

    return 0;
}