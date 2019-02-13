#pragma once
#ifndef SHAG_DB_FILE
#define SHAG_DB_FILE

#include "Shag_db_Struct.h"

#include <iostream>
#include <fstream>                              // Позволяет как записывать, так и считывать из файла
#include <string>
using namespace std;

void StudentOutputFile(Student stud)
{
	ofstream file_student("Student_Info.txt");   // создаём объект класса ofstream для записи и связываем его с файлом text.txt

	if (!file_student.is_open())
	{
		cout << "ERROR OPEN FILE (Student_Info.txt)";
	}
	else
	{
		file_student << stud.id << ";";
		file_student << stud.people.family << ";" << stud.people.name << ";" << stud.people.contact.address << ";" << stud.people.contact.tel << ";";
		file_student << stud.middle_ac << ";";
		file_student << stud.facult.actual << ";" << stud.facult.group << ";" << stud.facult.name << endl;
	}
	file_student.close();
}

void OutputVisitFile(Student stud)
{
	ofstream file_vizit("Student_Vizit.txt");   

	if (!file_vizit.is_open())
	{
		cout << "ERROR OPEN FILE (Student_Vizit.txt)";
	}
	else
	{
		file_vizit << stud.id << ";" << stud.visit->date.day << ";" << stud.visit->date.month << ";" << stud.visit->date.year << ";" << stud.visit->status << endl;
		
	}
	file_vizit.close();
}

void OutputAcPerfFile(Student stud)
{
	ofstream file_acperf("Student_AcPerf.txt");  
	if (!file_acperf.is_open())
	{
		cout << "ERROR OPEN FILE (Student_AcPerf.txt)";
	}
	else
	{
		file_acperf << stud.id << ";" << stud.ac_perf->date.day << ";" << stud.ac_perf->date.month << ";" << stud.ac_perf->date.year << ";" << stud.ac_perf->ac_status << endl;

	}
	file_acperf.close();
}
void OutputHomeWorkFile(Student stud)
{
	ofstream file_homework("Student_HomeWork.txt");  

	if (!file_homework.is_open())
	{
		cout << "ERROR OPEN FILE (Student_HomeWork.txt)";
	}
	else
	{
		file_homework << stud.id << ";" << stud.homework->date.day << ";" << stud.homework->date.month << ";" << stud.homework->date.year << ";" << stud.homework->ac_status << endl;

	}
	file_homework.close();
}
void OutputTestFile(Student stud)
{
	ofstream file_test("Student_Test.txt");   

	if (!file_test.is_open())
	{
		cout << "ERROR OPEN FILE (Student_Test.txt)";
	}
	else
	{
		file_test << stud.id << ";" << stud.test->date.day << ";" << stud.test->date.month << ";" << stud.test->date.year << ";" << stud.test->ac_status << endl;

	}
	file_test.close();
}
void OutputLabFile(Student stud)
{
	ofstream file_lab("Student_Lab.txt");

	if (!file_lab.is_open())
	{
		cout << "ERROR OPEN FILE (Student_Lab.txt)";
	}
	else
	{
		file_lab << stud.id << ";" << stud.lab->date.day << ";" << stud.lab->date.month << ";" << stud.lab->date.year << ";" << stud.lab->ac_status << endl;

	}
	file_lab.close();
}

/* название используемых файлов
     Student_Info.txt
	 Student_Vizit.txt
	 Student_AcPerf.txt
	 Student_HomeWork.txt
	 Student_Test.txt
	 Student_Lab.txt

*/

void ImportStudentDataBase(Student *stud)
{
	int pos, id1;
	double middle_ac1;
	string buffer;
	string str1, str2, str3, str4, str5, str6, str7, str8, str9;
	string sub_str1, sub_str2, sub_str3, sub_str4, sub_str5, sub_str6, sub_str7, sub_str8, sub_str9;
		
	ifstream file_st_db("Student_Info.txt");

	if (!file_st_db.is_open())
	{
		cout << "ERROR OPEN FILE (Student_Info.txt)";
	}
	else
	{
		getline(file_st_db, buffer);                 // берём строку из файла Student_Info.txt и помещаем её в переменную buffer типа string

		pos = buffer.find(";");                      // находим позицию на которой стоит ; и записываем в переменную pos типа int
		sub_str1 = buffer.substr(0, pos);             // копируем часть строки начиная с 0-го элемента до элемента с индексом pos
		str1 = buffer.substr(pos+1);                 // записываем в переменную str2 типа string строку которая начинается с элемента pos+1  до конца строки
		
		pos = str1.find(";");                        // в строке str1 находим позицию на которой стоит ; и записываем в переменную pos типа int
		sub_str2 = str1.substr(0, pos);
		str2 = str1.substr(pos + 1);
		
		pos = str2.find(";");
		sub_str3 = str2.substr(0, pos);
		str3 = str2.substr(pos + 1);
		
		pos = str3.find(";");
		sub_str4 = str3.substr(0, pos);
		str4 = str3.substr(pos + 1);

		pos = str4.find(";");
		sub_str5 = str4.substr(0, pos);
		str5 = str4.substr(pos + 1);

		pos = str5.find(";");
		sub_str6 = str5.substr(0, pos);
		str6 = str5.substr(pos + 1);

		pos = str6.find(";");
		sub_str7 = str6.substr(0, pos);
		str7 = str6.substr(pos + 1);

		pos = str7.find(";");
		sub_str8 = str7.substr(0, pos);
		str8 = str7.substr(pos + 1);

		pos = str8.find(";");
		sub_str9 = str8.substr(0, pos);
		

	}
	file_st_db.close();

	cout << sub_str1 << " ; " << sub_str2 << " ; " << sub_str3 << " ; " << sub_str4 << " ; " << sub_str5 << " ; ";    // выводим результат в консоли для проверки (для себя)
	cout << sub_str6 << " ; " << sub_str7 << " ; " << sub_str8 << " ; " << sub_str9 << endl;

	id1 = atoi(sub_str1.c_str());
	stud->id = id1;                                   // заносим id в структуру
	stud->people.family = sub_str2;                   // заносим фамилию в структуру
	stud->people.name = sub_str3;                     // заносим имя в структуру
	stud->people.contact.address = sub_str4;          // заносим адрес в структуру
	stud->people.contact.tel = sub_str5;              // заносим телефон в структуру
	middle_ac1 = atof(sub_str6.c_str());              // преобразуем переменную sub_str6 типа float в тип double и записываем в переменную middle_ac1
	stud->middle_ac = middle_ac1;                     // заносим среднюю оценку в структуру
	if (sub_str7 == "0")                              // делаем проверку на 0
	{
		stud->facult.actual = false;                  // записываем в актуальность false
	}
	else
	{
		stud->facult.actual = true;                   // записываем в актуальность true
	}
	stud->facult.group = sub_str8;                    // заносим № группы в структуру
	stud->facult.name = sub_str9;                     // заносим название факультета в структуру
}

#endif
