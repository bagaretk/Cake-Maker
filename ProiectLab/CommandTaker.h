#pragma once
#include"RecipeCake.h"
#include"CakeMaker.h"
#include"CarouselOfCakes.h"
#include<iostream>
class CommandTaker
{
	RecipeCake carouselRecipe;
	CakeMaker cakeMaker;
	CarouselOfCakes carousel;
public:
	CommandTaker() {
	}
	Cake takeCommand(RecipeCake recipe) {
		if (checkCarouselOfCakes()) { //la fiecare comanda trebuie verificat daca in carousel sunt numarul minim de torturi
			refillCarousel();
			cout << "Carouselul a fost umplut.\n";
		}
		Cake carouselCake; //  cake-ul  din carousel
		carouselCake = carousel.getCake(recipe.getname()); // imi cauta in carousel daca e.
		if (carouselCake.getName() == "") // daca nu este in carousel,functia returneaza un cake cu numele "" si se face cu cakemakerul
			return cakeMaker.takeCommand(recipe);
		else
			return carouselCake; //daca e in carousel se scoate de acolo si se returneaza
	}
	Cake* takeCommand(RecipeCake recipe, int numberOfCakes) {
		Cake cakes[20];
		Cake defaultcake("");
		int i;
		for (i = 0; i < numberOfCakes; i++) // se repeta prima functie de numberOfCakes ori
		{
			if (checkCarouselOfCakes()) {
				refillCarousel();
			}
			Cake searchedCake(recipe.getname()), carouselCake;
			carouselCake = carousel.getCake(recipe.getname());
			if (carouselCake.getName() == "")
				cakes[i] = cakeMaker.takeCommand(recipe);
			else
				cakes[i] = carouselCake;
		}
		for (i = carousel.getCurrentCapacity(); i < 20; i++)
			cakes[i] = defaultcake;
		return cakes;
	}
	/*Cake takeCommand(string nameOfCake) { nu inteleg ce trebuia sa faca fct asta

	}*/
	Cake* getCakesFromCarousel() {
		return carousel.storage;
	}
	bool checkCarouselOfCakes() {
		int i, contor = 0;
		for (i = 0; i < carousel.maxCapacity; i++)
			if (carousel.storage[i].getName() != "")
				contor++;
		if (contor < carousel.lowLimit) //am mai putin de 2 locuri ocupate in carousel, deci sub minim
			return 1; // returneaza true/1 daca trebuie dat refill
		else
			return 0; // returneaza false/0 daca nu trebuie at refill
	}
	void refillCarousel() { // se apeleaza cand am mai putin de 2 torturi in carousel . min meu din carousel este 2
		int i,caz;
		cout << "*-----------------------------------------------------------------------------------------------*\n";
		cout << " Se reumple caroselul . . . \n";
		for(i=carousel.getCurrentCapacity();i<carousel.maxCapacity;i++) 
			if (carousel.storage[i].getName() == "") // daca e loc liber in carousel
			{
				caz = rand() % 3; //se umple random cu ce este in meniu 
				RecipeCake c1("Ecler",3); RecipeCake c2("Tiramisu",5); RecipeCake c3("Diplomat",2);
				switch (caz) {
				case 0:carousel.storage[i] = cakeMaker.takeCommand(c1);
					break;
				case 1:carousel.storage[i] = cakeMaker.takeCommand(c2);
					break;
				case 2:carousel.storage[i] = cakeMaker.takeCommand(c3);
					break;
				}
			}
		cout << "Carouselul a fost reumplut :)\n";
		cout << "*-----------------------------------------------------------------------------------------------*\n";
	}
	friend class CommandPanel;
};