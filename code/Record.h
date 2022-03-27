#ifndef RECORD_H_INCLUDED
#define RECORD_H_INCLUDED

#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "Item.h"
#include "Monster.h"
#include "NPC.h"
#include "Player.h"

using namespace std;

/* This is the record system. Get the information of the  */
/* player and rooms then save them to (a) file(s). Notice */
/* that using pass by reference can prevent sending the   */
/* whole vector to the function.                          */

class Record
{
private:
public:
    Record();
    void savePlayer(Player*, ofstream&);
    void saveRooms(vector<Room>&, ofstream&);
    void saveToFile(Player*, vector<Room>&);
    void loadFromFile(Player*, vector<Room>&);
    void loadPlayer(Player*, ifstream&);
    void loadRooms(vector<Room>&, ifstream&);
    string readtxt(string,int);
    int readtxtnum(string,int);
};

#endif // RECORD_H_INCLUDED
