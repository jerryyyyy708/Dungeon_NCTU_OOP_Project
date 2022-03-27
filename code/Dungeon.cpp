#include "Dungeon.h"
Dungeon::Dungeon(){

}

void Dungeon::runDungeon(){
startGame();
while(checkGameLogic()){
chooseAction(player.getCurrentRoom()->getObjects());
}
}

void Dungeon::createPlayer(){
    string yourname;
    int choose,atak,helt;
    cout<<"YUH¡Awhats your name"<<endl;
    cin>>yourname;
    cout<<"what kind of rapper are you"<<endl<<"1.trap rapper 2.melody rapper 3.Battle MC"<<endl;
    cin>>choose;
    if(choose==1){
        helt=100;
        atak=20;
    }
    else if(choose==2){
        helt=120;
        atak=10;
    }
    else if(choose==3){
        helt=80;
        atak=30;
    }
    Player you(yourname,helt,atak);
    this->player=you;
}

void Dungeon::startGame(){
    int start;
    cout<<"choose 1 to start new game"<<endl<<"choose 2 to load saved data"<<endl;
    cin>>start;
    if(start==1){
    createPlayer();
    createMap();
    player.setCurrentRoom(&rooms[0]);
    }
    else if(start==2){
    Record record;
    createMap();
    record.loadFromFile(&player,rooms);
    }
}

void Dungeon::createMap(){
    //vector<Room> rooms;
    int jegaroom=8,index;
    for(index=0;index<jegaroom;index++){
        Room temp;
        temp.setIsExit(0);
        temp.setRoomNumber(index);
        temp.setLiveornot(1);
        rooms.push_back(temp);
    }
    rooms[5].setIsExit(1);
    rooms[0].setUpRoom(&rooms[1]);
    rooms[1].setDownRoom(&rooms[0]);
    rooms[1].setUpRoom(&rooms[2]);
    rooms[2].setUpRoom(&rooms[4]);
    rooms[2].setDownRoom(&rooms[1]);
    rooms[2].setLeftRoom(&rooms[3]);
    rooms[3].setRightRoom(&rooms[2]);
    rooms[4].setDownRoom(&rooms[2]);
    rooms[4].setRightRoom(&rooms[6]);
    rooms[4].setUpRoom(&rooms[5]);
    rooms[5].setDownRoom(&rooms[4]);
    rooms[6].setLeftRoom(&rooms[4]);
    rooms[6].setUpRoom(&rooms[7]);
    rooms[7].setDownRoom(&rooms[6]);
    //room connect end , start setting items
    Monster *wade=new Monster("Wade to the Yu","Yuh,check",20,5);
    Monster *davi=new Monster("DAVI","You guys are too funny!",50,20);
    Monster *ty=new Monster("TY","I didn't say diss , i said effect",100,30);
    Monster *bowz=new Monster("Boss-BOWZ","Why do you ask a rapper to act as a person who act as a rapper.",300,100);
    //rapper items start
    Item *goldchain=new Item("Gold chain",30,5);
    Item *marzl=new Item("tsaitaogwai",200,40);
    Item *tatoo=new Item("Tatto",300,50);
    //npc
    NPC *marz23=new NPC("Marz23","hi",*marzl);
    //Start set vector
    vector<Object*> *room0obj=new vector<Object*>;
    vector<Object*> *room1obj=new vector<Object*>;
    room1obj->push_back(wade);
    vector<Object*> *room2obj=new vector<Object*>;
    room2obj->push_back(goldchain);
    vector<Object*> *room3obj=new vector<Object*>;
    room3obj->push_back(marz23);
    room3obj->push_back(marzl);
    vector<Object*> *room4obj=new vector<Object*>;
    room4obj->push_back(davi);
    vector<Object*> *room5obj=new vector<Object*>;
    room5obj->push_back(bowz);
    vector<Object*> *room6obj=new vector<Object*>;
    room6obj->push_back(ty);
    vector<Object*> *room7obj=new vector<Object*>;
    room7obj->push_back(tatoo);
    //setup room
    rooms[0].setObjects(*room0obj);
    rooms[1].setObjects(*room1obj);
    rooms[2].setObjects(*room2obj);
    rooms[3].setObjects(*room3obj);
    rooms[4].setObjects(*room4obj);
    rooms[5].setObjects(*room5obj);
    rooms[6].setObjects(*room6obj);
    rooms[7].setObjects(*room7obj);
    //set index
    rooms[0].setIndex(0);
    rooms[1].setIndex(1);
    rooms[2].setIndex(2);
    rooms[3].setIndex(3);
    rooms[4].setIndex(1);
    rooms[5].setIndex(1);
    rooms[6].setIndex(1);
    rooms[7].setIndex(2);
    //this->rooms=rooms;
}

bool Dungeon::checkGameLogic(){
    if(player.getCurrentHealth()<=0){
            cout<<"you lose , you suck"<<endl;
        return 0;
    }
    else if(player.getCurrentRoom()->getIsExit()==1&&player.getCurrentRoom()->getLiveornot()==0){
        cout<<"you win , you handsome"<<endl;
        return 0;
    }
    return 1;
}

void Dungeon::handleMovement(){
    int udlr;
switch(player.getCurrentRoom()->getRoomNumber()){
case 0:
    cout<<"Go where? 1.up"<<endl;
    cin>>udlr;
    if(udlr==1){
        player.changeRoom(player.getCurrentRoom()->getUpRoom());
    }
    break;
case 1:
    cout<<"Go where? 1.up 2.down"<<endl;
    cin>>udlr;
    switch(udlr){
    case 1:
    player.changeRoom(player.getCurrentRoom()->getUpRoom());
    break;
    case 2:
    player.changeRoom(player.getCurrentRoom()->getDownRoom());
    break;
    }
    break;
case 2:
    cout<<"Go where? 1.up 2.down 3.left"<<endl;
    cin>>udlr;
    switch(udlr){
    case 1:
    player.changeRoom(player.getCurrentRoom()->getUpRoom());
    break;
    case 2:
    player.changeRoom(player.getCurrentRoom()->getDownRoom());
    break;
    case 3:
    player.changeRoom(player.getCurrentRoom()->getLeftRoom());
    break;
    }
    break;
case 4:
    cout<<"Go where? 1.up 2.down 3.right"<<endl;
    cin>>udlr;
    switch(udlr){
    case 1:
    player.changeRoom(player.getCurrentRoom()->getUpRoom());
    break;
    case 2:
    player.changeRoom(player.getCurrentRoom()->getDownRoom());
    break;
    case 3:
    player.changeRoom(player.getCurrentRoom()->getRightRoom());
    break;
    }
    break;
case 7:
    cout<<"Go where? 1.down"<<endl;
    cin>>udlr;
    if(udlr==1){
        player.changeRoom(player.getCurrentRoom()->getDownRoom());
    }
    break;
case 3:
    cout<<"Go where? 1.right"<<endl;
    cin>>udlr;
    if(udlr==1){
        player.changeRoom(player.getCurrentRoom()->getRightRoom());
    }
    break;
case 6:
    cout<<"Go where? 1.left 2.up"<<endl;
    cin>>udlr;
    if(udlr==1){
        player.changeRoom(player.getCurrentRoom()->getLeftRoom());
    }
    else if(udlr==2){
        player.changeRoom(player.getCurrentRoom()->getUpRoom());
    }
    break;
}
}
void Dungeon::chooseAction(vector<Object*> roomitem){
    Record record;
    int choose;//need to set when choose !=1234
    if(player.getCurrentRoom()->getIndex()==0){
    cout<<"What to do 1.see status 2.move 3.save"<<endl;
    cin>>choose;
    switch(choose){
case 1:
    //cout<<"Swag:"<<player.getCurrentHealth()<<" Flow:"<<player.getAttack()<<endl;
    handleEvent(&player);
    break;
case 2:
    handleMovement();
    break;
case 3:
    record.saveToFile(&player,rooms);
    cout<<"Saved"<<endl<<endl;
    break;
    }
}
    else if(player.getCurrentRoom()->getIndex()==1){//this else if needs to check monster die or not------------------------------------index1start
        if(player.getCurrentRoom()->getLiveornot()){
            handleEvent(roomitem[0]);
        }
        else{//
            player.getCurrentRoom()->setIndex(0);
        }//
        }//-------------------------------------------------------------------------------------------------------------------------------index1end
    else if(player.getCurrentRoom()->getIndex()==2){//-------------------------------------------------------index2start
        if(player.getCurrentRoom()->getLiveornot()){
            handleEvent(roomitem[0]);
        }
        else{
            player.getCurrentRoom()->setIndex(0);
        }

}//-------------------------------------------------------------------------------------------------------------index2end
    else if(player.getCurrentRoom()->getIndex()==3){//--------------------------------------------------------------------3
    if(player.getCurrentRoom()->getLiveornot()){
            handleEvent(roomitem[0]);
        }
        else{
            player.getCurrentRoom()->setIndex(0);
        };
    }//--------------------------------------------------------------------------------------------------------------------3
    else if(player.getCurrentRoom()->getIndex()==4){

    }
}

void Dungeon::handleEvent(Object* roomthing){
    Player* roomyer=dynamic_cast<Player*>(roomthing);
    Monster* roomster=dynamic_cast<Monster*>(roomthing);
    Item* roomtem=dynamic_cast<Item*>(roomthing);
    NPC * roompc=dynamic_cast<NPC*>(roomthing);
    if(roomyer!=NULL){
        player.triggerEvent(roomyer);
    }
    else if(roomster!=NULL){
        roomster->triggerEvent(&player);
    }
    else if(roomtem!=NULL){
        roomtem->triggerEvent(&player);
    }
    else if(roompc!=NULL){
        roompc->triggerEvent(&player);
    }
}
