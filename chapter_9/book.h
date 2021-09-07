#pragma once
#include<string>
#include"Chrono.h"
//author struct name and surname
//isbn struct

struct Author {
	std::string name;
	std::string surname;
	Author(const std::string& name, const std::string& surname) :name{ name }, surname{ surname } {};
	Author();//DELETE
};

enum class Genre {
	scify = 0, prose, periodic,biography,
	child_lit
};

class Book {
public:


	//status of the book if it is given or not to someone
	bool is_given()const { return on_hands; }

	//sets what book isi given to user
	void given() { on_hands = true; }
	//return ISBN code 
	std::string get_ISBN()const { return ISBN; }
	Author get_author()const { return author; }
	std::string get_name()const { return book_name; };

	Book(std::string& book_name, const Author& author, Genre genre, const Chrono::Date& date, const std::string& ISBN);
	~Book();
	Book() { genre = Genre::prose; on_hands = false; };// TODO fix

	
private:
	std::string ISBN; //holds ISBN string //where  format "n-n-n-x",  n - int; х - digit or latter
	//date ofregistration //probably as separate class

	Author author; //holds name and surname
	
	std::string book_name;
	bool on_hands;//if book was given to someone
	Chrono::Date registration_date;
	Genre genre;
	class Invalid { }; // Для генерации исключений

};
bool operator == (const Book& а, const Book& b);
bool operator!=(const Book& a, const Book& b);
std::ostream& operator<< (std::ostream& os, const Book& b);
bool is_ISBN(const std::string& ISBN);