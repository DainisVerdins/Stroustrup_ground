#pragma once
#include <iostream>

namespace Chrono {
	enum class Month {
		jan = 1, fеb, mar, apr, may, jun,
		jul, aug, sep, oct, nov, dec
	};
	enum class Day {
		sunday, monday, tuesday, wednesday,
		thursday, friday, saturday
	};
	class Date
	{
	public:
		class Invalid { }; // Для генерации исключений
		Date(int уy, Month mm, int dd); // Проверка корректности
		// и инициализация
		Date(); // Конструктор по умолчанию
		// Копирование по умолчанию нас устраивает
		
		//Немодифицирующие операции :
		int day() const { return d; }
		Month month() const {return m;}
		int year() const { return y; };
		
		// Модифицирующие операции :
		void add_day(int n);
		void add_month(int n);
		void add_year(int n);
	private:
		int y;
		Month m;//month
		int d;
	};

	bool is_date(int у, Month m, int d); // true для корректной даты
	bool leapyear(int у); // true для високосного года
	bool operator== (const Date & a, const Date & b);
	bool operator !=(const Date& а, const Date& b);
	std::ostream& operator<< (std::ostream& os, const Date& d);
	std::istream& operator>> (std::istream& is, Date& dd);

	Day day_of_week(const Date& d);

} // Chrono