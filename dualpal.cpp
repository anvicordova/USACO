/*
ID: angelav1
PROG: dualpal
LANG: C++
*/

#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

#define MIN_BASE 2
#define MAX_BASE 10

string toBase(int base, int number){
	int digit;
	string newNumber = "";
	string stringNumber;
	
	while(number > 0){
		digit = number % base;
		newNumber += char(digit + 48);
		number /= base;		
	}
	
	int size = newNumber.length();
	for(int i = size - 1; i >= 0; i--) stringNumber += newNumber[i];
	return stringNumber;
}
bool isPalindrom(string n1){
	
	string n2;
	int size = n1.length();
	
	for(int i = size - 1; i >= 0; i--){
		 n2 += n1[i];
	}
	
	if( n1 == n2) return true;
	return false;

}
int main(){
	
	freopen("dualpal.in","r",stdin);
	freopen("dualpal.out","w",stdout);
	
	int n;
	int s;
	string number;
	cin >> n >> s;
	
	int actualNumber = s;
	
	while(n > 0){		
		actualNumber = actualNumber + 1;
		int times = 0;
		
		for(int base = MIN_BASE; base <= MAX_BASE; base++){
			
			number = toBase(base, actualNumber);
			
			if(isPalindrom(number)){ 
				times += 1;
			}
			if(times == 2){
				cout << actualNumber << "\n";
				n--;
				base = MAX_BASE + 1;
			}
		}
	}
	
	return 0;
}
