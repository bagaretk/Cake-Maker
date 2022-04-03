#pragma once
#include<list>
#include"RecipeCake.h"
#include"CommandTaker.h"
#include<iostream>
class CommandPanel
{
	list<RecipeCake> menu;
	CommandTaker commandtaker;
public:
	CommandPanel() {
		
	}
	void showProducts() {
		cout << "*-----------------------------------------------------------------------------------------------*\n";
		for (auto product : menu) {
			cout << "Nume: " << product.getname() << " Timp de preparare: " << product.getTime() << " secunde\n";
		}
		cout << "*-----------------------------------------------------------------------------------------------*\n";
	}
	void selectProduct(string nume) {
		int i = 0;
		Cake cakeOrdered;
		for (auto recipe : menu)
			if (recipe.getname() == nume) {
				i = 1;
				commandtaker.carouselRecipe = recipe;// creez variabila recipe command taker
				break;
			}
			if (i) {
			cakeOrdered = commandtaker.takeCommand(commandtaker.carouselRecipe); // am returnat rezultatul din command taker.
				// daca exista in carusel il scoate de acolo, daca nu exista il face in cakemaker si il returneaza;
				cout<<"Tortul este gata pentru servire. Pofta buna!\n\n";
				//cakesInCarousel = commandtaker.getCakesFromCarousel();
				//for()// trebuie cautat in carusel daca exista tortul nostru. Daca nu exista trebuie facut cu cakemakerul. cauta o vezi ce elemente ai in carusel.
			}
			else
				cout << "Produsul nu exista.\n";
	}
	void selectProduct(string nume, int numberOfProducts) {
		int i = 0;
		Cake* cakesOrdered;
		for (auto recipe : menu)
			if (recipe.getname() == nume) {
				i = 1;
				commandtaker.carouselRecipe = recipe;// creez variabila recipe command taker
				break;
			}
		if (i) {
			cakesOrdered = commandtaker.takeCommand(commandtaker.carouselRecipe,numberOfProducts); // am returnat rezultatul din command taker.
				// daca exista in carusel il scoate de acolo, daca nu exista il face in cakemaker si il returneaza;
			cout << "Torturile sunt gata pentru servire. Pofta buna!\n\n";
		}
		else
			cout << "Produsul nu exista.\n";
	}
	void showProductsInCarousel() {
		int i;
		Cake cakesInCarousel[10];
		Cake* tort = commandtaker.getCakesFromCarousel();
		for (i = 0; i < 10; i++)
			cakesInCarousel[i] = *(tort + i);
		cout << "In carousel avem : ";
		for (i = 0; i < 10; i++)
		{
			if (cakesInCarousel[i].getName() != "")
				cout << cakesInCarousel[i].getName()<<" ";
		}
		cout << endl;
	}
	friend int main();
};

