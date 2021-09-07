#pragma once

#include <iostream>
#include <string>
#include<vector>
#include<algorithm>
#include<cmath>
#include<fstream>
#include<random>
#include <stdlib.h> //bad one


using namespace std;
void error(string s) {
	throw runtime_error(s);
}
void error(string s1, string s2) {
	throw runtime_error(s1 + s2);
};
inline void keepwindow_open() { char ch; cin >> ch; }
