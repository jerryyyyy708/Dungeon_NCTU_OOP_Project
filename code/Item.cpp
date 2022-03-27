#include "Item.h"

Item::Item(){

}

Item::Item(string name,int heal,int atk):Object(name,"Item"){
this->health=heal;
this->attack=atk;
}

int Item::getHealth(){
return health;
}

int Item::getAttack(){
return attack;
}


void Item::setHealth(int health){
this->health=health;
}

void Item::setAttack(int attack){
this->attack=attack;
}

bool Item::triggerEvent(Object* guy){
Player *me=dynamic_cast<Player*>(guy);
int choose;
cout<<"wow there's a "<<me->getCurrentRoom()->getFirstobj()->getName()<<" !"<<endl;
cout<<"What to do 1.see status 2.wear"<<endl;
cin>>choose;
switch(choose){
case 1:
    me->triggerEvent(me);
    break;
case 2:
    cout<<"great , i got a "<<me->getCurrentRoom()->getFirstobj()->getName()<<endl;
    me->increaseStates(this->getHealth(),this->getAttack());
    me->getCurrentRoom()->setLiveornot(0);
    break;
}

}
