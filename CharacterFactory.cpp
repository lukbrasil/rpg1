/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

#include <stdlib.h>
#include <time.h>
#include "Character.h"

using namespace Character;

struct Profile {
    // Main profile
    int weaponSkill;
    int ballisticSkill;
    int strenght;
    int toughness;
    int agility;
    int intelligence;
    int willPower;
    int fellowship;

    // Secondary profile
    int attack;
    int wound;
    int movement;
    int magic;
    int insanityPoint;
    int fatePoint;

    Profile(int ws, int bs, int s, int t, int ag, int in, int wp, int fel, int a, int w, int m,
        int mag, int ip, int fp) :
    weaponSkill{ws}, ballisticSkill{bs}, strenght{s}, toughness{t}, agility{ag},
    intelligence{in}, willPower{wp}, fellowship{fel}, attack{a}, wound{w}, movement{m},
    magic{mag}, insanityPoint{ip}, fatePoint{fp}
    {
    };

    int strengthBonus() const {
        return strenght;
    }

    int toughnessBonus() const {
        return toughness;
    }
};

class DefaultPlayer : public Player {
private:
    Profile profile;

public:
    DefaultPlayer(Profile p) : profile{p}
    {
    };

    virtual ~DefaultPlayer() override {
    }

    int agility() const override {
        return profile.agility;
    }

    int attack() const override {
        return profile.attack;
    };

    int ballisticSkill() const override {
        return profile.ballisticSkill;
    };

    int fatePoint() const override {
        return profile.fatePoint;
    }

    int fellowship() const override {
        return profile.fellowship;
    };

    int insanityPoint() const override {
        return profile.insanityPoint;
    };

    int intelligence() const override {
        return profile.intelligence;
    };

    int magic() const override {
        return profile.magic;
    };

    int movement() const override {
        return profile.movement;
    };

    int strenght() const override {
        return profile.strenght;
    }

    int strengthBonus() const override {
        return profile.strengthBonus();
    };

    int toughness() const override {
        return profile.toughness;
    };

    int toughnessBonus() const override {
        return profile.toughnessBonus();
    };

    int weaponSkill() const override {
        return profile.weaponSkill;
    };

    int willPower() const override {
        return profile.willPower;
    };

    int wound() const override {
        return profile.wound;
    };
};

class IntegerGenerator {
public:

    virtual ~IntegerGenerator() {
    }

    virtual int generate(int min, int max) const = 0;
};

class RandomIntegerGenerator : public IntegerGenerator {
public:

    RandomIntegerGenerator() {
        srand(time(0));
    }

    virtual ~RandomIntegerGenerator() override {
    }

    int generate(int min, int max) const override {
        return rand() % max + min;
    }
};

class Roll {
public:

    virtual ~Roll() {
    }

    virtual int roll(IntegerGenerator * generator) const = 0;
};

class FixedRoll : public Roll {
private:
    int number;

public:
    FixedRoll(int n) : number{n}
    {
    }

    ~FixedRoll() override {
    }

    int roll(IntegerGenerator* generator) const override {
        return number;
    }
};

class TenDieRoll : public Roll {
private:
    int base;
    int variable;

public:
    TenDieRoll(int b, int v) : base{b}, variable{v}
    {
    }

    ~TenDieRoll() override {
    }

    int roll(IntegerGenerator* generator) const override {
        int result = base;
        for (int i = 0; i < variable; i++) {
            result += generator->generate(1, 10);
        }
        return result;
    }
};

class StartingWoundRoll : Roll {
public:

    virtual ~StartingWoundRoll() override {
    }

    int roll(IntegerGenerator* generator) const override {
        int result = TenDieRoll{-1, 1}
        .roll(generator);
        return result % 3 + 10;
    };
};

Player * Factory::createHuman() const {
    Profile profile{10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10};

    RandomIntegerGenerator generator;

    profile.weaponSkill = (TenDieRoll{20, 2}).roll(&generator);
    profile.ballisticSkill = (TenDieRoll{20, 2}).roll(&generator);
    profile.attack = (FixedRoll{1}).roll(&generator);
    profile.wound = (StartingWoundRoll{}).roll(&generator);

    return new DefaultPlayer{profile};
}

