/*
ID: angelav1
PROG: beads
LANG: C++
*/
#include <iostream>
#include <fstream>
#include <cstring>

using namespace std;
char comodin = 'w';

int contarAdelante(string collar,int largo,int i)
{
	if(i+1 == largo) i = -1;
	i++;
	
	char colorBead = collar[i];
	int nroBeans = 0;
	while(colorBead == comodin && nroBeans != largo)
	{
		nroBeans++;	i++ ;
		if(i == largo)i = 0;
		colorBead = collar[i];		
	}
	char stopCounting = (colorBead == 'r')?'b':'r';
	
	while(nroBeans != largo && collar[i]!= stopCounting)
	{
		nroBeans++;
		i++;	
		if(	i == largo)i = 0;
	}
	return nroBeans;	
}

int contarAtras(string collar, int largo, int i)
{	
	char colorBead = collar[i];
	int nroBeans = 0;
	while(colorBead == comodin && nroBeans != largo)
	{
		nroBeans++; i--;
		if(	i == -1)i = largo - 1;
		colorBead = collar[i];
	}
	char stopCounting = (colorBead == 'r')?'b':'r';
	
	while(nroBeans != largo && collar[i]!= stopCounting)
	{
		nroBeans++;
		i--;	
		if(	i == -1)i = largo - 1;
	}
	return nroBeans;
}

int main(int argc, char** argv)
{
	int contarActual = 0;
	int contarMax = 0;
	string collar;
	
	int nroBeads;
	
	ifstream abrir;
	abrir.open("beads.in");
	abrir >> nroBeads;
	getline(abrir, collar);
	getline(abrir,collar);
	
	abrir.close();
	
	for(unsigned int i = 0; i< collar.length() && contarMax != nroBeads; i++)
	{
		contarActual += contarAdelante(collar, nroBeads, i);
		if(contarActual < nroBeads) contarActual += contarAtras(collar,nroBeads,i);
		if(contarActual > contarMax) contarMax = contarActual;
		contarActual = 0;
	}
	
	ofstream cerrar;
	cerrar.open("beads.out");
	cerrar << contarMax <<"\n";
	cerrar.close();
	return 0;
}
