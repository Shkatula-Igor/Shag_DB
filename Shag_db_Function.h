//Заголовочный файл с функциями в которых производится ввод данных
#pragma once
#ifndef SHAG_DB_FUNCTION
#define SHAG_DB_FUNCTION
#include "Shag_db_Struct.h"

#include <iostream>
using namespace std;

//------------------------------------------------Ввод данных-----------------------------------------------
void InputStudentInfo(struct Student *stud)
{
	cout << "Введите фамилию студента" << endl;
	cin >> stud->people.family;
	cout << endl;
	cout << "Введите имя студента" << endl;
	cin >> stud->people.name;
	cout << endl;
	cout << "Введите адрес студента" << endl;
	cin >> stud->people.contact.address;
	cout << endl;
	cout << "Введите телефон студента" << endl;
	cin >> stud->people.contact.tel;
	cout << endl;
}

void InputStudentVisit(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Введите день посещения занятия студентом" << endl;
		cin >> stud->visit[j].date.day;
		cout << endl;
		cout << "Введите месяц посещения занятия студентом" << endl;
		cin >> stud->visit[j].date.month;
		cout << endl;
		cout << "Введите год посещения занятия студентом" << endl;
		cin >> stud->visit[j].date.year;
		cout << endl;

		do
		{
			cout << "Введите статус посещения занятия студентом (0 - отсутствовал, 1 - присутствовал, 2 - болел)" << endl;
			cin >> stud->visit[j].status;
			cout << endl;
		} while (stud->visit[j].status < 0 || stud->visit[j].status > 2);
	}
}

void InputStudentAc(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Введите дату оценки (день, месяц, год)" << endl;
		cout << "День" << endl;
		cin >> stud->ac_perf[j].date.day;
		cout << endl;
		cout << "Месяц" << endl;
		cin >> stud->ac_perf[j].date.month;
		cout << endl;
		cout << "Год" << endl;
		cin >> stud->ac_perf[j].date.year;
		cout << endl;
		cout << "Введите оценку полученную на уроке" << endl;
		cin >> stud->ac_perf[j].ac_status;
		cout << endl;
	}
}

void InputStudentHome(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Введите дату оценки (день, месяц, год)" << endl;
		cout << "День" << endl;
		cin >> stud->homework[j].date.day;
		cout << endl;
		cout << "Месяц" << endl;
		cin >> stud->homework[j].date.month;
		cout << endl;
		cout << "Год" << endl;
		cin >> stud->homework[j].date.year;
		cout << endl;
		cout << "Введите оценку полученную за домашнюю работу" << endl;
		cin >> stud->homework[j].ac_status;
		cout << endl;
	}
}

void InputStudentTest(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Введите дату оценки (день, месяц, год)" << endl;
		cout << "День" << endl;
		cin >> stud->test[j].date.day;
		cout << endl;
		cout << "Месяц" << endl;
		cin >> stud->test[j].date.month;
		cout << endl;
		cout << "Год" << endl;
		cin >> stud->test[j].date.year;
		cout << endl;
		cout << "Введите оценку полученную за контрольную работу" << endl;
		cin >> stud->test[j].ac_status;
		cout << endl;
	}
}

void InputStudentLab(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Введите дату оценки (день, месяц, год)" << endl;
		cout << "День" << endl;
		cin >> stud->lab[j].date.day;
		cout << endl;
		cout << "Месяц" << endl;
		cin >> stud->lab[j].date.month;
		cout << endl;
		cout << "Год" << endl;
		cin >> stud->lab[j].date.year;
		cout << endl;
		cout << "Введите оценку полученную за лабораторную работу" << endl;
		cin >> stud->lab[j].ac_status;
		cout << endl;
	}
}

void CalcStudentMiddleAc(struct Student *stud, int m)
{
	int n = 0;
	int middle = 0;

	for (int k = 0; k < m; k++)
	{
		if (stud->ac_perf[k].ac_status != 0)
		{
			middle = middle + stud->ac_perf[k].ac_status;
			n++;
		}

		if (stud->homework[k].ac_status != 0)
		{
			middle = middle + stud->homework[k].ac_status;
			n++;
		}

		if (stud->test[k].ac_status != 0)
		{
			middle = middle + stud->test[k].ac_status;
			n++;
		}

		if (stud->lab[k].ac_status != 0)
		{
			middle = middle + stud->lab[k].ac_status;
			n++;
		}

	}

	stud->middle_ac = float(middle / n);
}

void InputeStudentAcPerf(struct Student *stud, int m)
{
	InputStudentAc(stud, m);

	InputStudentHome(stud, m);

	InputStudentTest(stud, m);

	InputStudentLab(stud, m);
}

void InputStudentFaculty(struct Student *stud)
{
	cout << "Введите название факультета" << endl;
	cin >> stud->facult.name;
	cout << endl;
	cout << "Введите название группы" << endl;
	cin >> stud->facult.group;
	cout << endl;
	stud->facult.actual = true;
	cout << endl;
}

//----------------------------------------------Вывод данных------------------------
void OutputStudentInfo(struct Student *stud)
{
	cout << stud->id << endl;

	cout << stud->people.family << " " << stud->people.name << endl;
	cout << stud->people.contact.address << endl;
	cout << "+7 " << stud->people.contact.tel << endl;

}

void OutpuStudentVisit(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Дата посещения " << stud->visit[j].date.day << "." << stud->visit[j].date.month << "." << stud->visit[j].date.year << " г." << endl;
		cout << endl;
		cout << "Статус посещения: " << stud->visit[j].status << endl;
	}
}

void OutpuStudentAc(struct Student *stud, int n)
{
	for (int j = 0; j < n; j++)
	{
		cout << "Дата оценки " << stud->ac_perf[j].date.day << "." << stud->ac_perf[j].date.month << "." << stud->ac_perf[j].date.year << " г." << endl;
		cout << endl;
		cout << "Статус посещения: " << stud->ac_perf[j].ac_status << endl;
	}
}
#endif
