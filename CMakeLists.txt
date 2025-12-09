cmake_minimum_required(VERSION 3.20)
set(CMAKE_CXX_STANDARD 17)

project(morpion)

# On indique que l'on veut créer un exécutable "ex01" compilé à partir du fichier td01_ex01.cpp
add_executable(morpion "src/player.cpp" "src/main.cpp")
