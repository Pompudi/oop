#include <stdio.h>
#include <string.h>

typedef struct date_t {
	int day;
	int month;
	int year;
	} date_t;


date_t parse_date(char *s) {
	date_t date;
	sscanf(s, "%2d%2d%4d", &date.month, &date.day, &date.year);
	if (strlen(s) == 6) // если короткий формат даты
		date.year += 2000; // прибавляем 2000
	return date;
}

// проверка года на високосность
int is_year_leap(int year) {
	return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
}

// дней в году
int days_in_year(int year) {
	return is_year_leap(year) ? 366 : 365;
}

// дней в месяце
int days_in_month(int month, int year) {
switch (month) {
	case 1: 
	case 3: 
	case 5: 
	case 7: 
	case 8: 
	case 10: 
	case 12: 
		return 31;

	case 4: 
	case 6: 
	case 9: 
	case 11:
		return 30;

	case 2: 
		return is_year_leap(year) ? 29 : 28;
	}
}

int proverka(int year)
{
  int op;
  if ((year>=5 && year<=20) || (year%10>=5 && year%10<=9) || year%10==0)
  {
		op=1;
  }
  else   
	  if (year%10==1)
	  {
		  op=2;
	  }
  else
  	if (year%10>=2 && year%10<=4)
	  {
		  op=3;
	  }
  else
  {
	  op=4;
  }
  return op;
}

char* form_y(int year)
{
  int op;
  op=proverka(year);
  switch(op)
  {
  case 1:return "лет";break;
  case 2:return "год";break;
  case 3:return "года";break;
  case 4:return "год";break;	
  } 
}
char* form_d(int day)
{
  int op;
  op=proverka(day);
  switch(op)
  {
  case 1:return "дней";break;
  case 2:return "день";break;
  case 3:return "дня";break;
  case 4:return "день";break;	
  } 
}

// проверка, что первая дата меньше второй
int is_less(date_t date2, date_t date1) {
	if (date1.year != date2.year)
		return date2.year < date1.year;
	if (date1.month != date2.month)
		return date2.month < date1.month;
	return date2.day < date1.day;
}

// получение количества дней
int to_days(date_t date) {
	int days = date.day;
	for (int y = 0; y < date.year; y++)
		days += days_in_year(y);
	for (int m = 1; m < date.month; m++)
		days += days_in_month(m, date.year);
	return days;
}

int main(int argc, char **argv) {
	if (argc != 3) {
		printf("Invalid args\n");
	return -1;
	}
	date_t date1 = parse_date(argv[1]);
	date_t date2 = parse_date(argv[2]);

	if (is_less(date2, date1)) {
		date_t tmp = date1;
		date1 = date2;
		date2 = tmp;
	}
// получаем количество дней всего
	int days1 = to_days(date1);
	int days2 = to_days(date2);
	int days = days2 - days1; // разница в днях
	int years = 0; 

// пока не дойдём до того же года
	while (date1.year < date2.year && days > 0) {
		days -= days_in_year(date1.year); // вычитаем из дней дни в году
		date1.year++; 
		years++;
	}

	if (days <= 0) {
		days += days_in_year(date1.year - 1); // прибавляем число дней прошлого года
		years--; 
	}
	printf("Времени прошло: %d %s %d %s\n", years,form_y(years), days - 1, form_d(days-1)); 
}
