#include "NPC.h"

NPC::NPC(){
}
NPC::NPC(string name, string script, Item thing){
    setName(name);
    setTag("NPC");
    this->script=script;
    this->thing=thing;
}
bool NPC::triggerEvent(Object* guy){
int udlr;
Player *me=dynamic_cast<Player*>(guy);
Item *tsai=dynamic_cast<Item*>(me->getCurrentRoom()->getSecobj());
int choose;
if(me->getCurrentRoom()->getLiveornot()==1){
    cout<<"Marz23: hi i am marz23 , what do you want? 1.���� 2.�J�� 3.���Y�_"<<endl;
    cin>>choose;
    switch(choose){
case 3:
    cout<<"here you are , byebye"<<endl<<"Marz23 left"<<endl;
    cout<<"you get a ���Y�_"<<endl;
    me->increaseStates(tsai->getHealth(),tsai->getAttack());
    me->getCurrentRoom()->setIndex(0);
    me->getCurrentRoom()->setLiveornot(0);
    break;
default:
    cout<<"Marz23: ��p�ڤ��O���Ǧ޺q��A���൹�A�R���J���٦�����"<<endl;//this is marz23's famous song's lyrics,
    while(me->getCurrentRoom()->getRoomNumber()==3){             // many people make jokes of this, so i
    cout<<"What to do 1.see status 2.move"<<endl;                // added this npc as a �m�J
    cin>>choose;
    switch(choose){
case 1:
    cout<<"Player: "<<me->getName()<<"  Swag:"<<me->getCurrentHealth()<<" Flow:"<<me->getAttack()<<endl;
    break;
case 2:
    cout<<"Go where? 1.right"<<endl;
    cin>>udlr;
    if(udlr==1){
        me->changeRoom(me->getCurrentRoom()->getRightRoom());
    }
    break;
    }
    }
    break;
    }
}
}
