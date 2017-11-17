/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   Character.h
 * Author: luk
 *
 * Created on November 15, 2017, 9:07 PM
 */

#ifndef CHARACTER_H
#define CHARACTER_H

namespace Character {

    class Player {
    public:

        virtual ~Player() {
        };

        // Primary profile
        virtual int weaponSkill() const = 0;
        virtual int ballisticSkill() const = 0;
        virtual int strenght() const = 0;
        virtual int toughness() const = 0;
        virtual int agility() const = 0;
        virtual int intelligence() const = 0;
        virtual int willPower() const = 0;
        virtual int fellowship() const = 0;

        // Secondary profile
        virtual int attack() const = 0;
        virtual int wound() const = 0;
        virtual int strengthBonus() const = 0;
        virtual int toughnessBonus() const = 0;
        virtual int movement() const = 0;
        virtual int magic() const = 0;
        virtual int insanityPoint() const = 0;
        virtual int fatePoint() const = 0;
    };

    class Factory {
    public:
        Player * createHuman() const;
    };
}

#endif /* CHARACTER_H */

