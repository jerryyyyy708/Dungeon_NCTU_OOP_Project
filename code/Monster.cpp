#include "Monster.h"
Monster::Monster(){

}
Monster::Monster(string name,string cry,int heal,int atk):GameCharacter(name,cry,heal,atk){

}

bool Monster::triggerEvent(Object* guy){
    Player *me=dynamic_cast<Player*>(guy);
    string rap;
    int choose;
    cout<<endl<<"Welcome to Diss RBL. "<<endl;
    while(this->checkIsDead()&&me->checkIsDead()){
        cout<<"your enemy is "<<this->getName()<<" . His current health:"<<this->getCurrentHealth()<<endl;
        cout<<"what to do 1.see status 2.battle 3.retreat"<<endl;
        cin>>choose;
        switch(choose){
case 1:
    me->triggerEvent(me);
    break;
case 2:

    cout<<"enter your freestyle rap:"<<endl;
    getchar();
    getline(cin,rap);
    cout<<endl<<"You said:"<<rap<<endl<<this->getName()<<" said : "<<this->getTag()<<endl;
    cout<<"you dealt "<<me->getAttack()<<" damages to enemy"<<endl;
    cout<<"enemy dealt "<<this->getAttack()<<" damages to you"<<endl<<endl;
    me->takeDamage(this->getAttack());
    this->takeDamage(me->getAttack());
    if(!(this->checkIsDead())){
        cout<<"You beat "<<this->getName()<<endl;
        me->getCurrentRoom()->setLiveornot(0);
    }
    break;

case 3:
    me->changeRoom(me->getPreviousRoom());
    return 1;
    break;
    }
    }
}

