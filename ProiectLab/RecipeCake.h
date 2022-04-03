#pragma once
using namespace std;
#include<string>
class RecipeCake
{
	string name;
	int time;
public:
	RecipeCake() {}
	RecipeCake(string n, int t) {
		name = n; time = t;
	}
	string getname() {
		return name;
	}
	int getTime() {
		return time;
	}
};

