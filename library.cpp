#include "library.h"

void Library::add_book(const Book& b)
{
	books.push_back(b);
}

void Library::add_patron(const Patron& p)
{
	patrons.push_back(p);
}






int Library::book_belongs(const std::string& ISBN)
{
	for (size_t i = 0; i < books.size(); i++)
	{
		if (books[i].get_ISBN() == ISBN) {
			return i;
		}
	}
	return -1;
}

bool Library::is_lib_patron(int patron_num)
{
	for (size_t i = 0; i < patrons.size(); i++)
	{
		if (patrons[i].get_lib_card_num() == patron_num)
		{
			return true;
		}
	}
	return false;
}

int Library::find_patron(int patron_num)
{
	for (size_t i = 0; i < patrons.size(); i++)
	{
		if (patrons[i].get_lib_card_num() == patron_num)
		{
			return i;
		}
	}
	return -1;
}

bool Library::taking_book(const std::string& ISBN, int patron_num)
{
	int book_index = this->book_belongs(ISBN);
	int patron_index = this->find_patron(patron_num);

	if (book_index == -1)
	{
		std::cout << "books ISBN do not belongs to library\n";//probably throw Invadi class must be 
		return false;
	}
	if (patron_index==-1)
	{
		std::cout << "patron does not belongs to library\n";
		return false;
	}

	if (patrons[patron_index].is_fee_owed())
	{
		std::cout << "patron have a fee\n";
		return false;
	}

	if (!books[book_index].is_given())
	{
		books[book_index].given();

		Chrono::Date date;
		transactions.push_back(Transaction(date, books[book_index], patrons[patron_index]));
		return true;
	}
	else {
		std::cout << " err Cannot give twice given book!\n";
	}
	return false;
}



