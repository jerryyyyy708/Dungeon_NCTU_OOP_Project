#include "GameCharacter.h"

GameCharacter::GameCharacter(){}

GameCharacter::GameCharacter(string chname,string chtag,int heal,int atk):Object(chname,chtag){
name=chname;
currentHealth=heal;
attack=atk;
}

bool GameCharacter::checkIsDead(){
if(this->currentHealth>0){
    return 1;
}
else{
    return 0;
}
}

void GameCharacter::setCurrentHealth(int currentHealth){
this->currentHealth=currentHealth;
}
void GameCharacter::setAttack(int attack){
this->attack=attack;
}


int GameCharacter::getCurrentHealth(){
return currentHealth;
}

int GameCharacter::getAttack(){
return attack;
}

void GameCharacter::takeDamage(int damage){
currentHealth=currentHealth-damage;
}
