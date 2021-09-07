#pragma once
#include<string>
class Patron{
public:
	Patron(std::string& patron_name, int patron_number);
	~Patron();

	double get_memb_fee() { return fee_amount; }
	void set_memb_fee(double new_fee) { fee_amount = new_fee; }
	std::string get_name() { return patron_name; }
	int get_lib_card_num() { return patron_number; }
	bool is_fee_owed() { return fee_owed; }
private:
	std::string patron_name;//name of patron
	int patron_number;//number of library card
	double fee_amount;//size of membership fee in dollars
	bool fee_owed;

};


