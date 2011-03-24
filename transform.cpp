/*
ID: angelav1
PROG: transform
LANG: C++
*/

#include <iostream>
#include <cassert>
#include <cstdio>

#define MAX_SIZE 10
int size;

char orMat[MAX_SIZE][MAX_SIZE];
char fnMat[MAX_SIZE][MAX_SIZE];
char ptMat[MAX_SIZE][MAX_SIZE];
char aux[MAX_SIZE][MAX_SIZE];

using namespace std;

void copiarMat(char source[][MAX_SIZE], char destination[][MAX_SIZE])
{
		for(int i = 0; i < size; i++)
		{
			for(int j = 0; j < size; j++)
			{
				destination[i][j] = source[i][j];
			}
		}		
}

void rotar90()
{	
	copiarMat(ptMat,aux);
	
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			ptMat[i][j] = aux[size - 1 -j][i];			
		}
	}	
}

bool sonIguales(char source[][MAX_SIZE], char dest[][MAX_SIZE])
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			if(source[i][j] != dest[i][j]) return false;
		}
	}
	return true;
}

void reflejar()
{
	copiarMat(ptMat,aux);
	for(int i = 0; i < size; i++)
	{
		for(int j= 0; j < size; j++)
		{
			ptMat[i][j] = aux[i][size - 1 -j];
		}
	}
}

void leerMatriz(char matrix[MAX_SIZE][MAX_SIZE])
{
	for(int i = 0; i < size; i++)
	{
		for(int j = 0; j < size; j++)
		{
			cin >> matrix[i][j];
		}
	}
}


int main()
{
	freopen("transform.in","r",stdin);
	freopen("transform.out","w",stdout);
	
	cin >> size;
	leerMatriz(orMat);
	leerMatriz(fnMat);
	int resul = 0;
	
	
		copiarMat(orMat,ptMat);
		for(int i = 0; i <3; i++)
		{
			rotar90();
			resul++;
			if(sonIguales(ptMat,fnMat))
			{
				 cout << resul <<"\n";
				 return 0;
			}
		}
		rotar90();
		
		resul++;
		reflejar();
		if(sonIguales(ptMat,fnMat))
		{
			cout <<resul<<"\n";
			return 0;
		} 
		
		resul++;
		for(int  i= 1; i <= 3; i++)
		{
			rotar90();
			if(sonIguales(ptMat,fnMat))
			{
				cout << resul <<"\n";
				return 0;
			}
		}		
	
		if(sonIguales(orMat,fnMat))
		{ 
		cout << "6\n";
		return 0;
		}
	cout << "7\n";
	return 0;
}


/*ERRORES EN LA RESOLUCIÓN DEL PROBLEMA:
 * 1.- NO LEER BIEN CUAL ERA LA REFLEXION
 * 2.- DENUEVO EL NO VERIFICAR BIEN ANTES DE BORARR 
 * 		O CAMBIAR ALGO!!
 * 3.- NO SE INCLUYÓ EL STDIO.H PARA EL FREOPEN
 * 4.-  NO SE LEYO BIEN QUE SE TENÍA QUE PONER EL MENOR, SE ASUMIÓ
 * 		QUE UN MENOR NO PODÍA REEMPLAZAR AL 6*/
