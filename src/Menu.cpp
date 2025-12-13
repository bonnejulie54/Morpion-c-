#include <iostream>
#include "player.hpp"

int display_menu() {
    std::cout << "Bienvenue dans le jeu du Morpion\n";
    std::cout << "Veuillez choisir un mode de jeu :\n";
    std::cout << "1. Deux joueurs\n";
    std::cout << "2. Un joueur contre l'IA\n";

    int choice;
    std::cin >> choice;
    return choice;
}