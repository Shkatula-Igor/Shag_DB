//Заголовочный файл в котором хроняться структуры данных
#pragma once
#ifndef SHAG_DB_STRUCT
#define SHAG_DB_STRUCT
#include <string>
using namespace std;

const int N = 1;

struct Contact
{
	string address;    // адрес
	string tel;        // телефон без +7 и без пробелов
};

struct People
{
	string family;       // фамилия
	string name;         // имя
	Contact contact;     // контактная информация
};

struct Date
{
	int day;              // день
	int month;            // месяц
	int year;             // год
};

struct Visit
{
	Date date;            // день, месяц, год
	int status;           // статус посещения (0 - отсутствовал, 1 - присутствовал, 2 - болел)
};

struct AcadPerf
{
	Date date;            // день, месяц, год
	int ac_status;        // оценка
};

struct Facultet
{
	string name;           // название факультета
	string group;          // название группы
	bool actual;           // актуальность (числиться или нет)
};

struct Student
{
	int id;                   // уникальный идентификатор
	People people;            // фамилия, имя, контактная информация (адрес и телефон)
	Visit visit[N];           // посещаемость

	AcadPerf ac_perf[N];      // текушая успеваемость (оценка)
	AcadPerf homework[N];     // оценка за домашнюю работу
	AcadPerf test[N];         // оценка за контрольную работу
	AcadPerf lab[N];          // оценка за лабораторную
	float middle_ac;          // средневзвещенная оценка  

	Facultet facult;          // факультет
};

#endif
