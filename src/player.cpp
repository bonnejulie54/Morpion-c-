#include <iostream>
#include "player.hpp"

player create_player (){
    player p;
    std::cout << "Entrez le nom du joueur : ";
    std::cin >> p.name;
    std::cout << "Choisissez un symbole (X ou O) : ";
    std::cin >> p.symbol;
    
    return p;
}