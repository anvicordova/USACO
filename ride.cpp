/*
ID: angelav1
PROG: ride
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>


using namespace std;

int main()
{
	ifstream fabrir;
	fabrir.open("ride.in");
	string comet,group;
	
	getline(fabrir,comet);
	getline(fabrir,group);
	fabrir.close();
	
	long long totalComet = 1, totalGroup = 1;
	for(unsigned int i= 0; i < comet.length(); i++)
	{		
		totalComet *= int(comet[i]) - 64;
	}
	
	totalComet = totalComet % 47;
	
	
	for(unsigned int i = 0; i< group.length(); i++)
	{
		totalGroup  *= int(group[i]) - 64;
	}
	
	totalGroup = totalGroup % 47;
		
	ofstream f;
	f.open("ride.out");	
	
	if(totalGroup == totalComet)f << "GO\n";
	else f << "STAY\n";
	
	f.close();
	return 0;	
}

