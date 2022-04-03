#pragma once
#include"Cake.h"
#include"RecipeCake.h"
#include <chrono>
#include <thread>
#include<iostream>
using namespace std;
using namespace std::this_thread;
using namespace std::chrono;
class CakeMaker
{
public:
	CakeMaker() {}
	Cake takeCommand(RecipeCake recipe) {
		Cake cake(recipe.getname()); 
		cout << "Se pregateste prajitura . . .\n";
		sleep_for(seconds(recipe.getTime())); // se asteapta cat timp este in reteta
		cout << recipe.getname() << " este gata de servire\n";
		return cake;		// se returneaza noul cake
	}
};

