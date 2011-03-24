/*
ID: angelav1
PROG: gift1
LANG: C++
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstring>

//Ausencia de manejo de parámetros del problema
//No se tiene conciencia de la cantidad máxima 
//de información que va a utilizar el problema

using namespace std;

struct person
{
	string name;
//Las operaciones se hacen sobre estas dos variables
//ellos trabajan directamente sobre el total
	int moneyGive;
	long moneyReceive;
};
//El NO uso de variables globales hace que
//Se tengan que pasar las estructuras por parámetro
//Recordar que esto implica en algunos casos pérdida de
//tiempo ya que deben copiarse todos los datos


//Retorna el índice de la estructura buscada
//Se tienen los problemas del retorno de -1
int buscarIndice(person array[], int size, string nombre)
{
	for(int i = 0; i < size; i++)
	{
		if(array[i].name == nombre) return i;
	}
	return -1;
}


int main()
{
	ifstream fabrir;
	fabrir.open("gift1.in");
	
	int np;
	int indice, indice2;
//Yo trabajo con los índices
	int receivers;
	int toGive;
	string nActual;
	fabrir >> np;
	getline(fabrir,nActual);
	//es una variable global en el otro programa
	person array[np];
	
	for(int i = 0; i < np; i++)
	{
		getline(fabrir,array[i].name);
		array[i].moneyReceive = 0;			
	}
	
	for(int i = 0; i < np; ++i)
	{		
		getline(fabrir, nActual);
		indice = buscarIndice(array,np,nActual);
		fabrir >> array[indice].moneyGive;
		fabrir >> receivers;
		getline(fabrir,nActual);
	//Mucho más trabajo para la actualización de los totales
	//Código más desordenado y menos entendible
		if(receivers != 0)
		{
			cout << receivers << endl;
			toGive = array[indice].moneyGive/receivers;
			array[indice].moneyReceive += array[indice].moneyGive % receivers;
			for(int j = 0; j < receivers; j++)
			{
				fabrir >> nActual;
				indice2 = buscarIndice(array,np,nActual);
				array[indice2].moneyReceive += toGive;
			}
			getline(fabrir,nActual);
		}			
	}
	
	fabrir.close();
	ofstream fcerrar;
	fcerrar.open("gift1.out");
//exactamente igual
	for(int i = 0; i < np; i++)
	{
		fcerrar << array[i].name << " " << array[i].moneyReceive -array[i].moneyGive << "\n";
	}
	fcerrar.close();
	return 0;	
}

/*nota: en mi solución se ve claramente
que se ha mezclado la lectura de los datos
con el proceso lógico de los datos. lo que hace más
engorroso de leer y de codificar.

Persiste el problema de separación de funciones
Se recomienda analizar bien; Y PENSAR antes de codificar
sobre todo tener en cuenta cuales son las funciones
repetitivas que tiene que hacer el programa.

Otro asunto importante fue el uso de variables globales 
por parte de ellos, lo que evita
claramente, el problema de paso de estructuras grandes

OJO: sus variables globales son aquellas que tienen sentido
en el programa

Se tiene un serio problema con el manejo de streams
el cual es que el cursor en el archivo NO lee toda la linea
sino que se queda al final 
"para evitar complicaciones probar el uso de freopen"

LA idea fue claramente la misma pero la implementación
fue inferior, esto se denotó sobre todo en el hecho
de que yo devolví un entero, y ellos la estructura

Ellos comprueban en todo momento que los datos
no se salgan de los parámetros indicados en el 
problema, para asegurar la consistencia de los datos*/


