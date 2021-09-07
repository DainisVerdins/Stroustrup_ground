#include "Chrono.h"
namespace Chrono {
	const Date& default_date() {
		static Date dd(2001, Month::jan, 1); // Начало XXI века
		return dd;
	}

	Date::Date(int yy, Month mm, int dd)
		: y{ yy }, m{ mm }, d{ dd }
	{
		if (!is_date(yy, mm, dd)) throw Invalid{};
	}

	Date::Date()
		: y{ default_date().year() },
		m{ default_date().month() },
		d{ default_date().day() }
	{

	}

	void Date::add_day(int n)
	{
		if (n < 1 || n>31) { throw Invalid(); }

		d += n;

		int days_in_month = 31; // В месяце не более 31 дня
		//detect current months day count
		switch (m) {
		case Month::fеb: // Длина февраля бывает разной
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun:
		case Month::sep: case Month::nov:
			days_in_month = 30; // В этих месяцах 30 дней
			break;
		}
		//if days are more than in current month day have
		//if so means what need change month to forward
		if (d > days_in_month)
		{
			this->add_month(1);
			d -= days_in_month; //set new date to changed month
		}

	}

	void Date::add_month(int n)
	{
		if (n < int(Month::jan) || n>int(Month::dec)) throw Invalid();

		// TODO: Make to possible add more than 12 month at any time for example 10004 months

		int months_before_year_change = int(Month::dec) - int(m);//before year trigger

		//check if added month triggers change of year
		if (months_before_year_change < n)
		{
			this->add_year(1); //adds year
			m = Month(n - months_before_year_change);

			// TODO: February problem what date cannot be more than 29 in leap year
			// also if omonth have 31 day and add year move actualy if for 2 months and change of date
		}
		else {
			m = Month(int(m) + n);
		}

	}

	void Date::add_year(int n)
	{
		if (m == Month::fеb && d == 29 &&
			!leapyear(y + n)) { // В невисокосный год
			m = Month::mar; // 29 февраля превраща ется в 1 марта
			d = 1;
		}
		y += n;
	}


	bool is_date(int y, Month m, int d)
	{
		// Полагаем у корректным
		if (d <= 0) return false; // d должно быть положительным
		if (m < Month::jan || Month::dec < m) return false;

		int days_in_month = 31; // В месяце не более 31 дня

		switch (m) {
		case Month::fеb: // Длина февраля бывает разной
			days_in_month = (leapyear(y)) ? 29 : 28;
			break;
		case Month::apr: case Month::jun:
		case Month::sep: case Month::nov:
			days_in_month = 30; // В этих месяцах 30 дней
			break;
		}
		if (days_in_month < d) return false;
		return true;
	}

	bool leapyear(int y)
	{

		if (y % 4 == 0)
		{
			if (y % 100 == 0)
			{
				if (y % 400 == 0) {
					return true;
				}
				else
				{
					return false;
				}
			}
			else
			{
				return true;
			}

		}
		else {
			return false;
		}

	}

	bool operator==(const Date& a, const Date& b)
	{
		return a.year() == b.year()
			&& a.month() == b.month()
			&& a.day() == b.day();

	}
	bool operator!=(const Date& a, const Date& b)
	{
		return !(a == b);
	}
	std::ostream& operator<<(std::ostream& os, const Date& d)
	{
		return os << '(' << d.year()
			<< ',' << int(d.month())
			<< ',' << d.day() << ')';
	}
	std::istream& operator>>(std::istream& is, Date& dd)
	{
		int y, m, d;
		char ch1, ch2, сhЗ, ch4;
		is >> ch1 >> y >> ch2 >> m >> сhЗ >> d >> ch4;
		if (!is) return is;

		if (ch1 != '(' || ch2 != ',' || //format error
			сhЗ != ',' || ch4 != ')') {
			is.clear(std::ios_base::failbit); // Устанавлива ем бит ошибки
			return is;
		}
		dd = Date(y, Month(m), d);
		return is;
	}

	Day day_of_week(const Date& d)
	{
		//algorithms https://www.youtube.com/watch?v=TKSpLH9CK_c 

		const int months_codes[12] = { 1,4,4,0,2,5,0,3,6,1,4,6 };
		const int century_codes[4] = { 0,6,4,2 };

		const int base = 100;
		int century = d.year() / base;//get first two digits of year
		int years = d.year() % base;//year of centurary
		int leapyears = years / 4;
		int century_code = century_codes[(century+1) % 4];
		int month_code = months_codes[int(d.month())];
		//months start with 1
		int sum = d.day() + month_code + century_code + years+ leapyears;
		Day day = Day::monday;//default is monday

		switch (sum % 7)//becasuse 7 days in month
		{
		case 0:
			day = Day::saturday;
			break;
		case 1:
			day = Day::sunday;
			break;
		case 2:
			day = Day::monday;
			break;
		case 3:
			day = Day::tuesday;
			break;
		case 4:
			day = Day::wednesday;
			break;
		case 5:
			day = Day::thursday;
			break;
		case 6:
			day = Day::friday;
			break;
		default:
			break;
		}

		return day;
	}

	//Date next_Sunday(const Date& d) {
	//	// ...
	//}
	//Date next_weekday(const Date& d) {
	//	// ...
	//}
}
