#pragma once
#include"book.h"
#include"Chrono.h"
#include"patron.h"

#include<vector>
#include<string>

class Library
{
public:
	class Invalid { }; // Для генерации исключений
	void add_book(const Book& b);
	void add_patron(const Patron& p);

	//check if book is librarys property
	//returns -1 if nout found
	// if found returns position of element in colection
	int book_belongs(const std::string& ISBN);

	//check if patron aka user is libraries user
	//returns -1 if nout found
	// if found returns position of element in colection
	bool is_lib_patron(int patron_num);
	//check if patron aka user is libraries user
	//returns -1 if nout found
	// if found returns position of element in colection
	int find_patron(int patron_num);


	bool taking_book(const std::string& ISBN, int patron_num);

private:
	struct Transaction
	{
		Chrono::Date date;
		Book book;
		Patron patron;
		Transaction(const Chrono::Date &date, const Book &book,const Patron &p)
			:date(date),book(book),patron(p)
		{}
	};
	std::vector<Transaction>transactions;
	std::vector<Book>books;
	std::vector<Patron>patrons;
};

