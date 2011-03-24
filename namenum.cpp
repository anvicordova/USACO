/*
ID: angelav1
PROG: namenum
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <string.h>
#include <stdio.h>

using namespace std;

long long decode(string name)
{
	long long code = 0;
	for(unsigned int i = 0; i < name.length();i++)
	{
		switch(name[i])
		{
			case 'A':case 'B':case 'C': code += 2;break;
			case 'D':case 'E':case 'F': code += 3;break;
			case 'G':case 'H':case 'I': code += 4;break;
			case 'J':case 'K':case 'L': code += 5;break;
			case 'M':case 'N':case 'O': code += 6;break;
			case 'P':case 'R':case 'S': code += 7;break;
			case 'T':case 'U':case 'V': code += 8;break;
			case 'W':case 'X':case 'Y': code += 9;break;
		}
		code *= 10;
	}
	code /= 10;
	return code;
}
void searchInDictionary(long long numberToS)
{	
	int counter = 0;
	freopen("dict.txt","r",stdin);
	freopen("namenum.out","w",stdout);
		
	string name;
	
	long long decodeName; 
	
	while(getline(cin,name))
	{
		decodeName = decode(name);		
		if(decodeName == numberToS)
		{ 
			cout << name << "\n";
			counter++;
		}
	}	
	if(counter == 0) cout <<"NONE\n";
}

int main()
{
	ifstream fin;
	fin.open("namenum.in");
	
	long long number;
	fin >> number;
	fin.close();	
  
	searchInDictionary(number);
	
	return 0;
}

/*Problemas:
 * Faltó el NONE
 * No consideré que dejaba multiplicado el numero por 10 al final
 * Tuve dificultades para poner bien las letras, no leí que Q y z no iban*/
