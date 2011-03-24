/*
ID: angelav1
PROG: friday
LANG: C++
*/
#include <iostream>
#include <cassert>
#include <fstream>

#define MAX_N 400
#define START_YEAR 1900
int days[7] = {0,0,0,0,0,0,0};
const int months[12] = {31,28,31,30,31,30,31,31,30,31,30,31};

using namespace std;
bool isLeapYear(int year)
{
	if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
	return true;
	return false;	
}

int main(int argc, char** argv)
{
	ifstream fabrir;
	fabrir.open("friday.in");
	int n;
	fabrir >> n;
	if(n <= 0) assert(0);
	n--;
	fabrir.close();
	
	
	
	int sumOfDays = 1;
	
//problema: yo no tomé sábado igual a cero
//desde el principio, y después hice una conversión
//sin ver que era innecesaria. Otra diferencia es que
//mientras que ellos se ubican defrente en el día
//mi objetivo principal está en hacer la suma de los días
//para después hacer la conversión.
	for(int i = START_YEAR; i <= 1900 + n;i++)
	{
		for(int j = 0; j < 12; j++)
		{
		//Aqui yo me ubiqué supuestamente en sabado
		//Ellos simplemente tomaron el sábado com cero
		//y no se hicieron bolas ...
	//¿El asunto es por qué yo si me hice bolas?
		//Esta función interna está por las puras
			days[((sumOfDays + 13) % 7)]++;
			sumOfDays += months[j];
			//Esto se evita con la función mlen de ellos
			if(isLeapYear(i) && j == 1)sumOfDays++;		
		}
	}
	
	ofstream fcerrar;
	fcerrar.open("friday.out");
	for(int i= 0; i < 7; i++)
	{
		//Esta parte hay una diferencia fundamental
		//En la forma en que se imprime
		//Ellos aprovechan las variables del for.!!
		//De manera que sea más natural, también un poco
		//más tricky
		fcerrar << days[i];
		if(i!=6)fcerrar <<" ";
	}
	fcerrar <<"\n";
	fcerrar.close();
	
	
	
	return 0;
}

/*Conclusión: no tienes claras las propiedades
 del módulo, ni como utilizarlas, ni cuándo utilizarlas

Trata de ver siempre que es lo más cómodo, tu te enfocaste
en la suma de los días, ellos se enfocaron en obtener
el día en que caía dicha suma.

Nuevamente faltó el uso de freopen*/
