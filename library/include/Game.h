//
// Created by student on 04.06.2020.
//

#ifndef GAMEBAJA_GAME_H
#define GAMEBAJA_GAME_H

#include "typedefs.h"

class MenuException : public std::logic_error
{
public:
    explicit MenuException(const std::string& what_arg) : std::logic_error(what_arg) {}
};

enum Option
{
    LOAD, NEW, EXIT
};
class Menu
{
public:
    Option choice_from_menu(GamePtr);
};
class Game : public std::enable_shared_from_this<Game>{
private:
    MenuPtr menu;
public:
    virtual ~Game();

    Game();

    Play* load_game();
    Play* new_play();
    void choice_from_menu();

};


#endif //GAMEBAJA_GAME_H