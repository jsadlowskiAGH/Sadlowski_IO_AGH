#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Secretary {
	string name, firstName;
	int id;


	bool checkDate() {

		return true;
	}

public:
	Date getInput() {
		Date date;
		cout << "Enter date = day.month.year";
	}
};

class Date {
	int day, month, year;
	string hour;
	
	void setDay(int day) {
		this->day = day;
	}

	void setMonth(int month) {
		this->month = month;
	}

	void setYear(int year) {
		this->year = year;
	}
};

int main() {
	
	return 0;
}