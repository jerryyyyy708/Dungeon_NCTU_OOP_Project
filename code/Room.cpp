#include "Room.h"
Room::Room(){
this->downRoom=NULL;
this->leftRoom=NULL;
this->upRoom=NULL;
this->rightRoom=NULL;
}

Room::Room(bool yesorno, int ondex, vector<Object*> object){
isExit=yesorno;
index=ondex;
objects=object;
}

void Room::setIndex(int number){
index=number;
}

void Room::setUpRoom(Room* beset){
    upRoom=beset;
}
void Room::setDownRoom(Room* beset){
    downRoom=beset;
}
void Room::setLeftRoom(Room* beset){
    leftRoom=beset;
}
void Room::setRightRoom(Room* beset){
    rightRoom=beset;
}

void Room::setObjects(vector<Object*> newobject){
objects=newobject;
}

void Room::setIsExit(bool yon){
isExit=yon;
}

bool Room::getIsExit(){
return isExit;
}

vector<Object*> Room::getObjects(){
return objects;
}

int Room::getIndex(){
return index;
}

void Room::setRoomNumber(int num){
    number=num;
}

int Room::getRoomNumber(){
return number;
}

Room* Room::getUpRoom(){
return upRoom;
}

Room* Room::getDownRoom(){
return downRoom;
}

Room* Room::getLeftRoom(){
return leftRoom;
}

Room* Room::getRightRoom(){
return rightRoom;
}

void Room::setLiveornot(bool yon){
liveornot=yon;
}

bool Room::getLiveornot(){
return liveornot;
}

Object* Room::getFirstobj(){
return objects[0];
}

Object* Room::getSecobj(){
return objects[1];
}
