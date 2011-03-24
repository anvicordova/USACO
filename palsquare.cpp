/*
ID: angelav1
PROG: palsquare
LANG: C++
*/

#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

char toChar(int n)
{	
	switch(n)
	{
		case 10: return 'A';
		case 11: return 'B';
		case 12: return 'C';
		case 13: return 'D';
		case 14: return 'E';
		case 15: return 'F';
		case 16: return 'G';
		case 17: return 'H';
		case 18: return 'I';
		case 19: return 'J';
	}
	return 'K';
}
string converToBase(int base, int n)
{
	string number;
	string number1;
	int digit;
	
	while(n > 0)
	{
		digit = (n%base);
		if(digit >= 10) number += toChar(digit);
		else number += (char)(digit + 48);
		n /= base;		
	}	
	
	int size = number.length();
	for(int i= size - 1; i >= 0; i--) number1 += number[i];
	return number1;	
}

bool isPalindrome(string number)
{
	string num2;
	int size = number.length();
	for(int i = size - 1; i >= 0;i--)
	{
		num2 += number[i];
	}
	if(num2 == number) return true;
	return false;
}

int main()
{
	int base;
	int square;
	string baseSquare;
	
	freopen("palsquare.in","r",stdin);
	freopen("palsquare.out","w",stdout);
	
	cin >> base;
	
	for(int i = 1; i <= 300; i++)
	{
		square = i*i;
		baseSquare = converToBase(base,square);
		if(isPalindrome(baseSquare))
		{
			cout << converToBase(base,i) <<" " << baseSquare << "\n";			
		}		
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}

/*ERRORES QUE TUVE:
 * 1.- mezclar dos ideas en el proceso
 * 2.- me olvide de voltear el string en converToBAse
 * PD EL PROBLEMA FUE ACEPTADO A LA PRIMERA*/
