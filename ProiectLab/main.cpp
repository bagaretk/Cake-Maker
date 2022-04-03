#include"CommandPanel.h"
#include<iostream>
using namespace std;
int main() {
	int opt,cantitate;
	string produs;
	list<RecipeCake> menu;
	RecipeCake recipe1("Ecler", 3);   //am declar un meniu cu niste prajituri ce mi-au venit pe moment
	menu.push_back(recipe1);		  
	RecipeCake recipe2("Tiramisu", 5);
	menu.push_back(recipe2);
	RecipeCake recipe3("Diplomat", 2);
	menu.push_back(recipe3);
	CommandPanel commandPanel; 
	commandPanel.menu = menu;
	while (1) {
		cout << "1.Afisare produse din meniu\n2.Selecteaza un produs\n3.Afiseare produse din carusel\n4.Oprite CakeMaker\n\nOptiune: ";
		cin >> opt;
		switch (opt) {
		case 1:commandPanel.showProducts();
			break;
		case 2:cout << "Numele produsul dorit: "; cin >> produs;
			cout << "Cantitate(max. 20): "; cin >> cantitate; //max 20 o data, se poate apela de multiple ori. CakeMakerul nu are mai mult spatiu
															  //unde sa le puna dupa ce le face. 
			if (cantitate == 1)
				commandPanel.selectProduct(produs);
			else {
				if (cantitate <= 20)
					commandPanel.selectProduct(produs, cantitate);
				else
					cout << "Cantitate prea mare\n\n";
			}
			break;
		case 3:commandPanel.showProductsInCarousel();
			break;
		case 4:exit(0);
			break;
		default: cout << "Optiune invalida";
		}
	}
	return 0;
}