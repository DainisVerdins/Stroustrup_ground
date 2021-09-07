
//******************************************************************************* /

#include"std_lib_facilities.h"
using namespace std;
//388
#include<vector>
#include<cctype>
#include<utility>
#include"Chrono.h"



int main()
{
	Chrono::Date date(2021, Chrono::Month::sep, 12);
	auto dates = Chrono::next_weekday(date);
	std::cout<<dates<<std::endl;
	int day = 6;
	int month = 9;
	int year = 2021;

	return 0;
}