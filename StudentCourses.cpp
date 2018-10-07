#include<iostream>
#include<string>
#include <stdio.h>
#include <cstdlib>
using namespace std;
class taree5y
{
	int day, month, year;
public:
	void setdate(string date)
	{
		int count = 0;
		string	tmpd, tmpm, tmpy;
		char dateArray[20];
		strncpy_s(dateArray, date.c_str(), sizeof(dateArray));
		dateArray[sizeof(dateArray) - 1] = 0;
		for (int i = 0; dateArray[i] != 0; i++)
		{
			if (dateArray[i] == '/')
			{
				count++;
				continue;
			}
			if (count == 0)
				tmpd += dateArray[i];
			else if (count == 1)
				tmpm += dateArray[i];
			else if (count == 2)
				tmpy += dateArray[i];
		}
		day = atoi(tmpd.c_str());
		month = atoi(tmpm.c_str());
		year = atoi(tmpy.c_str());
	}
	int getday()
	{
		return day;
	}
	int getmonth()
	{
		return month;
	}
	int getyear()
	{
		return year;
	}
	taree5y fExams_Start_Date(taree5y d[], int noofsemicolon)
	{
		taree5y tmpyear[100];
		int a2lsana = d[0].year, no_a2lsana = 0;
		for (int i = 0; i <= noofsemicolon; i++)
		{
			if (d[i].year < a2lsana)
				a2lsana = d[i].year;
		}
		for (int i = 0; i <= noofsemicolon; i++)
		{
			if (d[i].year == a2lsana)
			{
				tmpyear[no_a2lsana] = d[i];
				no_a2lsana++;
			}
		}
		taree5y tmpshahr[100];
		int a2lshahr = tmpyear[0].month, no_a2lshahr = 0;
		for (int i = 0; i < no_a2lsana; i++)
		{
			if (tmpyear[i].month < a2lshahr)
				a2lshahr = tmpyear[i].month;
		}
		for (int i = 0; i < no_a2lsana; i++)
		{
			if (tmpyear[i].month == a2lshahr)
			{
				tmpshahr[no_a2lshahr] = tmpyear[i];
				no_a2lshahr++;
			}
		}
		taree5y tmpyoum;
		int a2lyoum = tmpshahr[0].day;
		for (int i = 0; i < no_a2lshahr; i++)
		{
			if (tmpshahr[i].day < a2lyoum)
				a2lyoum = tmpshahr[i].day;
		}
		for (int i = 0; i < no_a2lshahr; i++)
		{
			if (tmpshahr[i].day == a2lyoum)
				tmpyoum = tmpshahr[i];
		}
		return tmpyoum;
	}
	taree5y fExams_End_Date(taree5y d[], int noofsemicolon)
	{
		taree5y tmpyear[100];
		int akbrsana = d[0].year, no_akbrsana = 0;
		for (int i = 0; i <= noofsemicolon; i++)
		{
			if (d[i].year >akbrsana)
				akbrsana = d[i].year;
		}
		for (int i = 0; i <= noofsemicolon; i++)
		{
			if (d[i].year == akbrsana)
			{
				tmpyear[no_akbrsana] = d[i];
				no_akbrsana++;
			}
		}
		taree5y tmpshahr[100];
		int akbrshahr = tmpyear[0].month, no_akbrshahr = 0;
		for (int i = 0; i < no_akbrsana; i++)
		{
			if (tmpyear[i].month > akbrshahr)
				akbrshahr = tmpyear[i].month;
		}
		for (int i = 0; i < no_akbrsana; i++)
		{
			if (tmpyear[i].month == akbrshahr)
			{
				tmpshahr[no_akbrshahr] = tmpyear[i];
				no_akbrshahr++;
			}
		}
		taree5y tmpyoum;
		int akbryoum = tmpshahr[0].day;
		for (int i = 0; i < no_akbrshahr; i++)
		{
			if (tmpshahr[i].day > akbryoum)
				akbryoum = tmpshahr[i].day;
		}
		for (int i = 0; i < no_akbrshahr; i++)
		{
			if (tmpshahr[i].day == akbryoum)
				tmpyoum = tmpshahr[i];
		}
		return tmpyoum;
	}
	int fExams_Period_InDays(taree5y Exams_Start_Date, taree5y Exams_End_Date)
	{
		int per;
		if (((Exams_Start_Date.year) % 4 == 0 && (Exams_Start_Date.year) % 100 != 0) || (Exams_Start_Date.year) % 400 == 0)
		{
			switch (Exams_Start_Date.month)
			{
			case 1:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case 2:
				per = (29 - Exams_Start_Date.day) + 1;
				break;
			case  3:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case  4:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  5:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case   6:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  7:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case  8:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case    9:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  10:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case    11:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  12:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			}
			per += Exams_End_Date.day;
		}
		else if (!((Exams_Start_Date.year) % 4 == 0 && (Exams_Start_Date.year) % 100 != 0) || (Exams_Start_Date.year) % 400 == 0)
		{
			switch (Exams_Start_Date.month)
			{
			case 1:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case 2:
				per = (28 - Exams_Start_Date.day) + 1;
				break;
			case  3:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case  4:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  5:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case   6:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  7:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case  8:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case    9:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  10:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			case    11:
				per = (30 - Exams_Start_Date.day) + 1;
				break;
			case  12:
				per = (31 - Exams_Start_Date.day) + 1;
				break;
			}
			per += Exams_End_Date.day;
		}
		return per;
	}
};
int fNumber_Students(int no_semicolon)
{
	no_semicolon++;
	return no_semicolon;
}
int fNumber_Courses(int  noofsemicolon)
{
	noofsemicolon++;
	return noofsemicolon;
}
int fNumber_Halls(string hallname[], int noofsemicolon)
{
	string delwa2ty;
	noofsemicolon++;
	int  halls = 0;
	for (int i = 0; i < noofsemicolon; i++)
	{
		int flag = 1;
		delwa2ty = hallname[i];
		for (int j = 0; j < i; j++)
		{
			if (delwa2ty == hallname[j])
				flag = 0;
		}
		if (flag)
			halls++;
	}
	return halls;
}
int fStudent_ID_Min(int stucodeint[], int no_semicolon)
{
	int minid = stucodeint[0];
	for (int i = 0; i <= no_semicolon; i++)
	{
		if (minid > stucodeint[i])
			minid = stucodeint[i];
	}
	return minid;
}
int fStudent_ID_Max(int stucodeint[], int no_semicolon)
{
	int maxid = stucodeint[0];
	for (int i = 0; i <= no_semicolon; i++)
	{
		if (maxid < stucodeint[i])
			maxid = stucodeint[i];
	}
	return maxid;
}
void fStudents_Dropped_IDs(int stucodeint[], int no_semicolon, int maxid, int minid, int &no_drop, int Students_Dropped_IDs[])
{
	no_drop = 0;
	for (int j = minid; j <= maxid; j++)
	{
		int flag = 1;
		for (int i = 0; i <= no_semicolon; i++)
		{
			if (stucodeint[i] == j)
				flag = 0;

		}
		if (flag)
		{
			Students_Dropped_IDs[no_drop] = j;
			no_drop++;
		}
	}
}
void strcodeint(string stucode[], int stucodeint[], int no_semicolon)
{
	no_semicolon++;
	for (int i = 0; i < no_semicolon; i++)
	{
		stucodeint[i] = atoi(stucode[i].c_str());
	}
}
int main()
{
	string stu, stucode[100], stuname[100], courstu[100];
	int no_comma = 0, no_semicolon = 0, do5olmofag2 = 0, no2comma = 0;
	int countofcomma = 0, noofsemicolon = 0;
	string cou, code[100], nameofcourse[100], date[100], hallname[100];
	int stucodeint[100];
	int no_drop = 0;
	taree5y d[100];
	int Number_Students, Number_Courses, Number_Halls, Student_ID_Min, Student_ID_Max, Students_Dropped_IDs[100],
		Exams_Period_InDays;
	taree5y Exams_Start_Date, Exams_End_Date;
	getline(cin, cou);
	getline(cin, stu);
	char charArray[5000];
	strncpy_s(charArray, cou.c_str(), sizeof(charArray));
	charArray[sizeof(charArray) - 1] = 0;
	for (int i = 14; charArray[i] != 0; i++)
	{
		if (charArray[i] == ']')
			break;
		if (charArray[i] == ',')
		{
			countofcomma++;
			continue;
		}
		if (charArray[i] == ';')
		{
			noofsemicolon++;
			countofcomma = 0;
			continue;
		}
		if (countofcomma == 0)
			code[noofsemicolon] += charArray[i];
		else if (countofcomma == 1)
			nameofcourse[noofsemicolon] += charArray[i];
		else if (countofcomma == 2)
			date[noofsemicolon] += charArray[i];
		else if (countofcomma == 3)
			hallname[noofsemicolon] += charArray[i];
	}
	char stuArray[5000];
	strncpy_s(stuArray, stu.c_str(), sizeof(stuArray));
	stuArray[sizeof(stuArray) - 1] = 0;
	for (int i = 10; stuArray[i] != 0; i++)
	{
		if (stuArray[i] == ']')
			break;
		if (stuArray[i] == ',')
		{
			no_comma++;
			continue;
		}
		else if (stuArray[i] == ';')
		{
			no_semicolon++;
			no_comma = 0;
			do5olmofag2 = 0;
			continue;
		}
		if ((stuArray[i] == '(' || do5olmofag2) && (stuArray[i] != ')'))
		{
			do5olmofag2 = 1;
			if (stuArray[i] == ',')
			{
				no2comma++;
				continue;
			}
			if (stuArray[i] == '(')
				continue;
			courstu[no_semicolon] += stuArray[i];
		}
		if (no_comma == 0)
			stucode[no_semicolon] += stuArray[i];
		if (no_comma == 1)
			stuname[no_semicolon] += stuArray[i];
	}
	strcodeint(stucode, stucodeint, no_semicolon);
	for (int i = 0; i <= noofsemicolon; i++)
	{
		d[i].setdate(date[i]);
	}
	Number_Students = fNumber_Students(no_semicolon);
	Number_Courses = fNumber_Courses(noofsemicolon);
	Number_Halls = fNumber_Halls(hallname, noofsemicolon);
	Student_ID_Min = fStudent_ID_Min(stucodeint, no_semicolon);
	Student_ID_Max = fStudent_ID_Max(stucodeint, no_semicolon);
	fStudents_Dropped_IDs(stucodeint, no_semicolon, Student_ID_Max, Student_ID_Min, no_drop, Students_Dropped_IDs);
	Exams_Start_Date = Exams_Start_Date.fExams_Start_Date(d, noofsemicolon);
	Exams_End_Date = Exams_End_Date.fExams_End_Date(d, noofsemicolon);
	Exams_Period_InDays = Exams_Start_Date.fExams_Period_InDays(Exams_Start_Date, Exams_End_Date);
	string op;
	int flag = 1;
	while (flag)
	{
	cin >> op;
	if (op == "Number_Students")
	cout << Number_Students<<endl;
	else if (op == "Number_Courses")
	cout << Number_Courses<<endl;
	else if (op == "Number_Halls")
	cout << Number_Halls << endl;
	else if (op == "Student_ID_Min")
	cout << Student_ID_Min << endl;
	else if (op == "Student_ID_Max")

	cout << Student_ID_Max << endl;
	else if (op == "Students_Dropped_IDs")
	for (int i = 0; i < no_drop; i++)
	{
	cout << Students_Dropped_IDs[i]<<endl;
	}
	else if (op == "Exams_Start_Date")
	cout << Exams_Start_Date.getday() << "/" << Exams_Start_Date.getmonth() << "/" << Exams_Start_Date.getyear()<<endl;
	else if (op == "Exams_End_Date")
	cout << Exams_End_Date.getday() << "/" << Exams_End_Date.getmonth() << "/" << Exams_End_Date.getyear()<<endl;
	else if (op == "Exams_Period_InDays")
	cout << Exams_Period_InDays<<endl;
	else if (op == "Quit")
	{
	flag = 0;
	cout << "Thanks!" << endl ;
	}
	}
	return 0;
}