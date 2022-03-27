#include "Record.h"

Record::Record(){
}

void Record::saveToFile(Player* you,vector<Room> &allrooms){
ofstream foutp("saveplayer.txt");
ofstream foutr("saveroom.txt");
savePlayer(you,foutp);
saveRooms(allrooms,foutr);
}

void Record::savePlayer(Player* you,ofstream &file){
file<<you->getName()<<endl<<you->getCurrentHealth()<<endl<<you->getAttack()<<endl<<you->getCurrentRoom()->getRoomNumber()<<endl<<you->getPreviousRoom()->getRoomNumber()<<endl;
}

void Record::saveRooms(vector<Room> &allrooms,ofstream &file){
file<<allrooms[0].getLiveornot()<<endl<<allrooms[1].getLiveornot()<<endl<<allrooms[2].getLiveornot()<<endl;
file<<allrooms[3].getLiveornot()<<endl<<allrooms[4].getLiveornot()<<endl<<allrooms[5].getLiveornot()<<endl<<allrooms[6].getLiveornot()<<endl<<allrooms[7].getLiveornot()<<endl;
Monster* room1mon=dynamic_cast<Monster*>(allrooms[1].getFirstobj());
Monster* room4mon=dynamic_cast<Monster*>(allrooms[4].getFirstobj());
Monster* room5mon=dynamic_cast<Monster*>(allrooms[5].getFirstobj());
Monster* room6mon=dynamic_cast<Monster*>(allrooms[6].getFirstobj());
file<<room1mon->getCurrentHealth()<<endl<<room4mon->getCurrentHealth()<<endl<<room5mon->getCurrentHealth()<<endl<<room6mon->getCurrentHealth();
}

void Record::loadPlayer(Player* old, ifstream& file){
string savepname="saveplayer.txt",temp;
int statnum;
old->setName(readtxt(savepname,1));
temp=readtxt(savepname,2);
istringstream(temp) >> statnum;
old->setCurrentHealth(statnum);
temp=readtxt(savepname,3);
istringstream(temp) >> statnum;
old->setAttack(statnum);
}

void Record::loadRooms(vector<Room>& oldroom, ifstream& file){
int i,num;
string temp;
Monster *room1mon=dynamic_cast<Monster*>(oldroom[1].getFirstobj());
Monster *room4mon=dynamic_cast<Monster*>(oldroom[4].getFirstobj());
Monster *room5mon=dynamic_cast<Monster*>(oldroom[5].getFirstobj());
Monster *room6mon=dynamic_cast<Monster*>(oldroom[6].getFirstobj());
for(i=0;i<8;i++){
    temp=readtxt("saveroom.txt",(i+1));
    istringstream(temp) >> num;
    oldroom[i].setLiveornot(num);
}
temp=readtxt("saveroom.txt",9);
istringstream(temp) >> num;
room1mon->setCurrentHealth(num);
temp=readtxt("saveroom.txt",10);
istringstream(temp) >> num;
room4mon->setCurrentHealth(num);
temp=readtxt("saveroom.txt",11);
istringstream(temp) >> num;
room5mon->setCurrentHealth(num);
temp=readtxt("saveroom.txt",12);
istringstream(temp) >> num;
room6mon->setCurrentHealth(num);
}

void Record::loadFromFile(Player* old, vector<Room> &oldroom){
ifstream fintp,fintr;
string temp;
int num;
fintp.open("saveplayer.txt",ios::in);
fintr.open("saveroom.txt",ios::in);
loadRooms(oldroom,fintr);
loadPlayer(old,fintp);
temp=readtxt("saveplayer.txt",4);
istringstream(temp) >> num;
old->setCurrentRoom(&oldroom[num]);
temp=readtxt("saveplayer.txt",5);
istringstream(temp) >> num;
old->setPreviousRoom(&oldroom[num]);
}

string Record::readtxt(string filename, int line)
{
	ifstream text;
	text.open(filename, ios::in);

	vector<string> lines;
	while (!text.eof())
	{
		string wds;
		getline(text, wds, '\n');
		lines.push_back(wds);
	}
	return lines[line-1];
}
