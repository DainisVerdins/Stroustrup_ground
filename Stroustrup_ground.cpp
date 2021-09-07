
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
	Chrono::Date date(1999, Chrono::Month::fеb, 25);
 std::cout<<int(Chrono::day_of_week(date))<<std::endl;
	int day = 6;
	int month = 9;
	int year = 2021;

	return 0;
}