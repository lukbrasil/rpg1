/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   main.cpp
 * Author: luk
 *
 * Created on November 15, 2017, 9:00 PM
 */

#include <iostream>
#include "Character.h"

using namespace std;

/*
 * 
 */
int main(int argc, char** argv) {
    Character::Factory cf;
    Character::Player * player = cf.createHuman();

    cout << "This human has\n"
        << player->weaponSkill() << " WS\n"
        << player->ballisticSkill() << " BS\n"
        << player->attack() << " attack\n"
        << player->wound() << " wound\n";

    delete player;

    return 0;
}

