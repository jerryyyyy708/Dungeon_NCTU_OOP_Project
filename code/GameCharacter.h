#ifndef GAMECHARACTER_H_INCLUDED
#define GAMECHARACTER_H_INCLUDED

#include <iostream>
#include <string>
#include "Object.h"
using namespace std;

class GameCharacter: public Object
{
private:
    string name;
    int currentHealth;
    int attack;
public:
    GameCharacter();
    GameCharacter(string,string,int,int);
    bool checkIsDead();
    void takeDamage(int);

    /* Set & Get function*/
    void setCurrentHealth(int);
    void setAttack(int);
    int getCurrentHealth();
    int getAttack();

};
#endif // GAMECHARACTER_H_INCLUDED
