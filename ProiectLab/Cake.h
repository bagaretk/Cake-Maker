#pragma once
using namespace std;
#include <string>
class Cake
{
	string name;	
public:
	Cake() {}
	Cake(string n) {
		name = n;	
	}
	string getName() {
		return name;
	}
};

