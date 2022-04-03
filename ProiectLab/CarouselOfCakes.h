#pragma once
#include"Cake.h"
#include<string>
using namespace std;
class CarouselOfCakes
{
	static int curent;//cate sunt in carousel in momentul actual
	const unsigned int maxCapacity = 10;
	const unsigned int lowLimit = 2;
	Cake storage[10];//0 - eclere, 1- tiramisu, 2-diplomat, 3-ecler, 4 - ecler, 5-diplomat
public:
	CarouselOfCakes() { // setez niste torturi care erau deja inainte in carousel. Poate fi omis, e optional. Daca nu setez valori initiale intra in 
						//refillcarousel
		Cake c1("Ecler"); Cake c2("Ecler"); Cake c3("Diplomat"); Cake cakedefault("");// cake default pt getcurrentcapacity
		storage[0] = c1;	storage[1] = c2;	storage[2] = c3;
		for (int i = 3; i <= 9; i++) //asta e necesar pentru functionarea corecta a programului
			storage[i] = cakedefault;
	}
	/*bool addCake(Cake cake) { daca adaug aici o sa trebuiasca sa declar cele 3 retete din meniu si aici. am considerat ca e acelasi lucru
								asa ca am adaugat in commandtaker
	}*/
	Cake getCake(string name) {
		int contor = getCurrentCapacity(); 
		Cake gasit;
		Cake cakedefault("");
		for (int i = 0; i < contor;i++) // cautam in storage daca exista cake-ul
		{
			if (storage[i].getName() == name) // daca il gasi il salvam in variabila "gasit" si stergem din storage
			{
				gasit = storage[i];
				for (int j = i; j < contor - 1; j++) // stergere din storage
					storage[j] = storage[j + 1];
				storage[contor-1] = cakedefault; // da valoare default fostului ultim element din storage
				return gasit; //daca il gaseste in storage il sterge si retureneaza 
			}
		}
		return cakedefault; // daca nu il gaseste returneaza un tort fictiv cu numele ""
	}
	int getCurrentCapacity() {
		int contor = 0;
		for (auto cake : storage)				//parcurge storage-ul si daca gaseste un element cu nume diferit de "" atunci aduna 1 la contor
			if (cake.getName() != "")
				contor++;
		return contor;
	}
	friend class CommandTaker;
	friend int main();
};

