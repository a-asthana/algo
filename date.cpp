#include <bits/stdc++.h>

using namespace std;

typedef struct date {
	int date;
	int month;
	int year;
} date;


int cmpyear(const void *d1,const void *d2) {
	date *y1 = (date *)d1;
	date *y2 = (date *)d2;
	if (y1->year != y2->year)
		return y1->year - y2->year;
	else 
		if (y1->month != y2->month)
			return y1->month - y2->month;
		else
			return y1->date - y2->date;
}

int main() {

	int i;
	date dates[] = {{20,1,2014},
                  {25,3,2010},
                  {3,12,2010},
                  {18,11,2010},
                   {1,10,2010},
                    {12,11,2010},
                     {8,11,2010},
                      {5,11,2010},
                       {2,11,2010},
                  {19,4,2015},
                  {9,7,2005}};

	qsort(dates, 11, sizeof(date),cmpyear);



	for (i = 0; i < 11; i++) {
		cout << dates[i].date <<" " << dates[i].month <<" " << dates[i].year << endl;
	}
	return 0;
}