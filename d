#include <iostream>
using namespace std;

class Date {
	int year, month, day;
public :
	Date(int y, int m, int d) { year = y; month = m; day = d; }
	Date( char *nal ) ;
	void show() { cout << year << "년" << month << "월" << day << "일" << endl; }
	int getYear() { return year; }
	int getMonth() { return month; }
	int getDay() { return day; }
};

int main() {
	Date birth1(2014, 3, 20);
  Date birth2(1945, 8, 15);

	 birth2.show();
	cout << birth1.getYear() << ',' << birth1.getMonth() << ',' << birth1.getDay() << endl;
}
