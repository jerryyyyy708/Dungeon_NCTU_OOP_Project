#include "Player.h"
Player::Player():GameCharacter(){

}

Player::Player(string name,int heal,int atk):GameCharacter(name,"yuh",heal,atk){
previousRoom=currentRoom;
}

void Player::setCurrentRoom(Room* setroom){
currentRoom=setroom;
}

void Player::setPreviousRoom(Room* setroom){
previousRoom=setroom;
}

Room* Player::getCurrentRoom(){
return currentRoom;
}

Room* Player::getPreviousRoom(){
return previousRoom;
}

void Player::changeRoom(Room* newe3){
previousRoom=currentRoom;
currentRoom=newe3;
}

bool Player::triggerEvent(Object* guy){
Player* me=dynamic_cast<Player*>(guy);
cout<<"Player: "<<me->getName()<<"  Swag:"<<me->getCurrentHealth()<<"  Flow:"<<me->getAttack()<<endl<<endl;
return 0;
}

void Player::addItem(Item newitem){
inventory.push_back(newitem);
}

void Player::increaseStates(int health,int attack){
this->setCurrentHealth((this->getCurrentHealth())+health);
this->setAttack((this->getAttack())+attack);
}
