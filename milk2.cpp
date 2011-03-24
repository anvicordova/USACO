/*
ID: angelav1
PROG: milk2
LANG: C++
*/
#include <iostream>
#include <fstream>
using namespace std;
struct farmer
{
	int start;
	int end;
};

void ordenar(farmer array[], int length)
{
	farmer aux;
	for(int i = 0; i < length -1;i++)
	{
		for(int j = i +1; j < length; j++)
		{
			if(array[i].start > array[j].start)
			{
				aux = array[i];
				array[i] = array[j];
				array[j] = aux;
			}
		}
	}	
}

void calculateTime(farmer array[],int length, int &pTime, int &mTime)
{
	int pauseTime = 0;
	int start = array[0].start;
	int end = array[0].end;
	int maxTimeM  = end - start;
	cout << "Start: " << start << " End: " << end << endl;
	for(int i = 1; i < length; i++)
	{
		cout << "i = " << i <<": " << array[i].start  << " " << array[i].end << endl;
		if(array[i].start <= end)
		{
			if(end < array[i].end)end = array[i].end;	
				
		}
		else
		{
			if(array[i].start - end > pauseTime) pauseTime = array[i].start - end;
			if((end - start) > maxTimeM) maxTimeM = end - start;
			start = array[i].start;
			end = array[i].end;
		}
	}	
	
	if((end - start) > maxTimeM) maxTimeM = end - start;
	pTime = pauseTime;
	mTime = maxTimeM;
}

int main(int argc, char** argv)
{
	int length, milkTime, pauseTime;
	string s;
	ifstream fin;
	fin.open("milk2.in");
	
	fin >> length;
	cout << "length " <<length << endl;
	farmer array[length];
	
	getline(fin,s);
	for(int i = 0; i < length; i++)
	{
		fin >> array[i].start;
		fin >> array[i].end;
		getline(fin,s);
	}
	fin.close();
	
	ordenar(array,length);
	
	ofstream fout;
	fout.open("milk2.out");
	
	calculateTime(array,length, pauseTime, milkTime);
	
	fout << milkTime <<" " << pauseTime <<"\n";
	fout.close();
	return 0;
}
