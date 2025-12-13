cmake_minimum_required(VERSION 3.20)

project(TicTacToe)

# On crée l'exécutable
add_executable(${PROJECT_NAME})

# On définit la norme C++
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)

# Dossier de sortie du binaire
set_target_properties(${PROJECT_NAME} PROPERTIES
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin/${CMAKE_BUILD_TYPE})

# On récupère tous les fichiers .cpp dans src/
file(GLOB_RECURSE MY_SOURCES CONFIGURE_DEPENDS src/*.cpp)

# On ajoute ces fichiers à l'exécutable
target_sources(${PROJECT_NAME} PRIVATE ${MY_SOURCES})

# On indique le dossier des headers
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_SOURCE_DIR}/include)

# Warnings stricts selon le compilateur
if(MSVC)
    target_compile_options(${PROJECT_NAME} PRIVATE /WX /W4)
else()
    target_compile_options(${PROJECT_NAME} PRIVATE -Werror -Wall -Wextra -Wpedantic -pedantic-errors -Wimplicit-fallthrough)
endif()

