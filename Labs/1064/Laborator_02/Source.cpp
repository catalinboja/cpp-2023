#include <stdio.h>
#include<iostream>
using namespace std;

void afisareValori(int valoare1, int valoare2) {
	std::cout << std::endl << "valoare 1 = " << valoare1 << " valoare 2 = " << valoare2;
}

void interschimbare(int valoare1, int valoare2) {
	int temp = valoare1;
	valoare1 = valoare2;
	valoare2 = temp;
}

void interschimbare2(int* pv1, int* pv2) {
	int temp = *pv1;
	*pv1 = *pv2;
	*pv2 = temp;
}

void interschimbare3(int& pv1, int& pv2) {
	int temp = pv1;
	pv1 = pv2;
	pv2 = temp;
}







int main() {

	int nrStudenti = 0;
	
	//definire pointeri
	//pointerul este o variabila numerica
	//pointerul stocheaza numere ce sunt adrese
	int* pointerNrStudenti = nullptr;

	nrStudenti = 2000;
	//pointerNrStudenti = (int*)1000;
	pointerNrStudenti = &nrStudenti;

	//utilizare pointeri
	//citire valoare de la o anumita adresa
	printf("\n Valoare int de la adresa pointerului este %d", *pointerNrStudenti);

	//scriem valoare la o anumita adresa
	*pointerNrStudenti = 3000;

	printf("\n Numar studenti: %d", nrStudenti);

	//de ce avem nevoie de pointeri ?
	//1. pentru a gestiona spatiu in HEAP
	int* valori = new int[1000];
	int* valoare = new int;

	//stergem spatiul alocat
	delete[] valori;
	delete valoare;

	//initializam pointerii iar cu null
	valori = nullptr;
	valoare = nullptr;

	int valoare1 = 10;
	int valoare2 = 20;

	std::cout << std::endl << "valoare 1 = " << valoare1 << " valoare 2 = " << valoare2;

	int temp = valoare1;
	valoare1 = valoare2;
	valoare2 = temp;

	afisareValori(valoare1, valoare2);

	interschimbare(valoare1, valoare2);
	afisareValori(valoare1, valoare2);

	interschimbare2(&valoare1, &valoare2);
	afisareValori(valoare1, valoare2);

	interschimbare3(valoare1 , valoare2);
	afisareValori(valoare1, valoare2);

}