#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

int main() {
	//vectori
	//siruri de caractere
	//vectori de numere/obiecte/entitati

	//static
	//dinamic

	unsigned char caracter = 48;
	caracter += 1;

	cout << endl << "Caracterul este " << caracter;

	caracter = 'a';

	cout << endl << "Caracterul este " << caracter;

	//definire siruri de caractere statice
	char nume[20];
	char prenume[] = "Gigel";

	const int nr_max_studenti = 100;

	//nr_max_studenti = 1000;

	//nume = "Popescu";
	//prenume = "Ana";

	//nume[19] = '\0';

	cout << endl << "Numele este " << nume;

	//initializare siruri de caractere
	nume[0] = 'A';
	nume[1] = 'n';
	nume[2] = 'a';
	nume[3] = '\0';
	cout << endl << "Numele este " << nume;

	//strcpy(nume, "Popescu");
	strcpy_s(nume, 20, "Popescu");
	cout << endl << "Numele este " << nume;


	//dinamice
	char* adresa;

	//initializare siruri dinamice
	//adresa = "Calea Dorobanti";

	//1 alocare spatiu
	adresa = new char[strlen("Calea Dorobanti") + 1];


	//2. copiem valoarea
	strcpy_s(adresa, strlen("Calea Dorobanti") + 1, "Calea Dorobanti");

	cout << endl << "Adresa este " << adresa;

	//evitam memory leak prin eliberarea spatiului alocat anterior
	delete[] adresa;

	adresa = new char[strlen("Calea Victoriei") + 1];

	strcpy_s(adresa, strlen("Calea Victoriei") + 1, "Calea Victoriei");

	cout << endl << "Adresa este " << adresa;

	//delete[] adresa;

	string numeStudent = "Gigel";
	numeStudent += " Ionut";
	numeStudent = "Ion";

}