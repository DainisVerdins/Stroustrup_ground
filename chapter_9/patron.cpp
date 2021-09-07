#include "patron.h"

Patron::Patron(std::string& patron_name, int patron_number)
	:patron_name(patron_name), patron_number(patron_number)
{
	fee_owed = false;
	fee_amount = 0;
}

Patron::~Patron()
{
}
