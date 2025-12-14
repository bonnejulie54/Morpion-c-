Je n’ai utilisé aucune librairie externe, le projet contient uniquement des librairies standard vue en cours comme : iostream, array, string, cstdlib, ctime.

Mon code est organisé de cette façon (comme vu en cours) : 
Morpion/
├── src/
│ ├── main.cpp
│ ├── Player.cpp
│ ├── GameBoard.cpp
│ ├── Menu.cpp
│ └── Victoire.cpp
│
├── include/
│ ├── Player.hpp
│ ├── GameBoard.hpp
│ ├── Menu.hpp
│ └── Victoire.hpp
│
├── CMakeLists.txt

Player.hpp / Player.cpp
Contient la structure Player (comme demandé dans le sujet) avec le nom et symbol du joueur. Contient aussi la fonction Create_player qui permet de créer un joueur via une saisie utilisateur.

GameBoard.cpp / GameBoard.hpp
Gère l’affichage du plateau de jeu. Le plateau est représenté par un std::array<char, 9>

Menu.hpp / Menu.cpp
Affiche le menu principal qui permet de choisir entre les deux modes de jeu ( contre un autre joueur ou contre une ia) 

Victoire.hpp/Victoire.cpp : 
Permet de vérifier la victoire avec la fonction check_win qui vérifie toutes les combinaisons possibles pour gagner. 
J’ai choisi de mettre l’ia ici et pas dans player car player contient uniquement les informations du joueur, tandis que la logique du jeu, incluant l’IA et la détection des conditions de victoire, est regroupée ici dans Victoire.cpp.
La fonction play_ai permet tout simplement a l’ia de jouer aléatoirement grâce a ca : srand(time(0));
rand() % 9;

Enfin main.cpp : 
Le fichier main.cpp fait  le déroulement du jeu :
1.	Initialisation du générateur aléatoire
2.	Affichage du menu
3.	Création des joueurs
4.	Boucle de jeu (9 tours maximum)
5.	Gestion des tours joueurs / IA
6.	Vérification de la victoire ou du match nul
Le main ne contient pas de logique complexe mais appelle les fonctions définies dans les autres fichiers.

Problèmes rencontré : 
1)	Certaines erreurs venaient des warnings transformés en erreurs avec l’option -Werror. Par exemple, certaines variables étaient déclarées mais jamais utilisées, ou il y avait des comparaisons entre des types int et size_t.
J’ai commencé par utiliser size_t pour toutes les boucles, ce qui est plus adapté aux indices et tailles de conteneurs. Ensuite, j’ai soit supprimé les variables inutilisées, soit trouvé un moyen de les utiliser, pour que le code compile proprement.
2)	Il y avait aussi des incompatibilités entre char et std::string, notamment dans la fonction check_win. Cela empêchait le code de fonctionner correctement.
J’ai harmonisé tous les symboles en utilisant char partout dans le projet, ce qui a simplifié le code et évité les erreurs de type.
3)	Enfin, la structure du projet posait problème : certaines inclusions de fichiers .hpp ne fonctionnaient pas correctement. J’ai utilisé le fichier CMake transmis, mais il m’a fallu un certain temps avant de bien comprendre son fonctionnement. Une fois compris, j’ai séparé clairement les dossiers src/ et include/ et ajusté target_include_directories pour que tous les fichiers soient correctement pris en compte lors de la compilation.
