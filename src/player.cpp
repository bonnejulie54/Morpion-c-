#include <iostream>
#include "player.hpp"

Player create_player (){
    Player player;
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> player.name;
    std::cout << "Choisissez un symbole (X ou O) : ";
    std::cin >> player.symbol;

    return player;
}