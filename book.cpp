#include "book.h"
#include<cctype>



Book::Book(std::string& book_name, const Author& author, Genre genre, const Chrono::Date& registration_date, const std::string& ISBN)
	:book_name(book_name), author(author),genre(genre)
{

	for (size_t i = 0; i < author.name.size(); i++)
	{
		if (!std::isalpha(author.name[i]))
		{
			throw Invalid();
		}
	}

	for (size_t i = 0; i < author.surname.size(); i++)
	{
		if (!std::isalpha(author.surname[i]))
		{
			throw Invalid();
		}
	}

	if (!Chrono::is_date(registration_date.year(), registration_date.month(), registration_date.day())) {
		throw Invalid();
	}

	if (!is_ISBN(ISBN)) {
		throw Invalid();
	}
	on_hands = false;
	
}

Book::~Book()
{
}



//check if is correct ISBN code
bool is_ISBN(const std::string& ISBN) 
{
	//where  format "n-n-n-x",  n - int; х - digit or latter


	if (ISBN.empty() || ISBN.length() < 7)return false;
	const char delimeter = '-';
	const int delimeter_count = 3;//how many delimeters in ISBN string
	const int x_count = 1;
	std::size_t found = 0;
	std::size_t previous_found = 0;


	if (!std::isdigit(ISBN[0]))return false;
	int i = 0;
	while ((found = ISBN.find(delimeter, found + 1)) != std::string::npos) {

		// in case if two delimeters are along side
		// TODO; DEscribe what previous_found !=0 means!
		if (ISBN[previous_found + 1] == delimeter && (previous_found != 0))return false;

		//+1 because previous_found contains delimeter pos but need to check next one from delimeter
		for (size_t delimeter_count = previous_found + 1; delimeter_count < found; ++delimeter_count) {
			if (!std::isdigit(ISBN[delimeter_count]))return false;

		}
		previous_found = found;
		++i;
	}

	if (delimeter_count != i)
	{
		return false;
	}

	// (last index of string ) - index of last found delimeter 
	// should be x length in thid case 1 digit big
	//
	if (((ISBN.length() - 1) - previous_found) != x_count)
	{
		return false;
	}

	//if not digit and char return
	if ((!std::isalpha(ISBN.back())) && !std::isdigit(ISBN.back())) { return false; }

	return true;
}

Author::Author()
{
}

bool operator==(const Book& a, const Book& b)
{
	return  a.get_ISBN()==b.get_ISBN();
}

bool operator!=(const Book& a, const Book& b)
{
	return !(a == b);
}

std::ostream& operator<<(std::ostream& os, const Book& b)
{
	return os << b.get_name() << '\n'
		<< b.get_author().surname << '\n'
		<< b.get_ISBN() << '\n';
}
