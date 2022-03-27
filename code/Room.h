#ifndef ROOM_H_INCLUDED
#define ROOM_H_INCLUDED

#include <iostream>
#include <string>
#include <vector>
#include "Object.h"

using namespace std;

class Room
{
private:
    Room* upRoom;
    Room* downRoom;
    Room* leftRoom;
    Room* rightRoom;
    bool isExit;
    bool liveornot;//only monster use
    int index;
    int number;
    vector<Object*> objects; /*contain 1 or multiple objects, including monster, npc, etc*/
public:
    Room();
    Room(bool, int, vector<Object*>);
    bool popObject(Object*); /*pop out the specific object, used when the interaction is done*/

    /* Set & Get function*/
    void setRoomNumber(int);
    void setUpRoom(Room*);
    void setDownRoom(Room*);
    void setLeftRoom(Room*);
    void setRightRoom(Room*);
    void setIsExit(bool);
    void setIndex(int);
    void setObjects(vector<Object*>);
    void setLiveornot(bool);
    bool getLiveornot();
    bool getIsExit();
    int getIndex();
    int getRoomNumber();
    vector<Object*> getObjects();
    Room* getUpRoom();
    Room* getDownRoom();
    Room* getLeftRoom();
    Room* getRightRoom();
    Object* getFirstobj();
    Object* getSecobj();
};

#endif // ROOM_H_INCLUDED
