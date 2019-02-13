// Les34_zagolovochnie_file.cpp : Заголовочные файлы
//

// Используем код программы из проекта Les23_DB
//

#include "pch.h"
#include <iostream>
                                                        
#include "Shag_db_Function.h"                           //файл Shag_db_Struct.h  подключен в файле Shag_db_Function.h
#include "Shag_db_File.h"                               // подключаем заголовочный файл в котором функция записывания данных о студентах в файл "Student_info.txt"
                                                        

using namespace std;



Student student_shag[N];                                //константа N инициализирована в файле Shag_db_Struct.h 
/*
void InputStudentInfo(struct Student *stud);            // Ввод информации о студенте
void InputStudentVisit(struct Student *stud, int n);    // Ввод посещения студентом
void InputStudentAc(struct Student *stud, int n);       // Ввод информации об оценках на уроке
void InputStudentHome(struct Student *stud, int n);     // Ввод информации об оценках по домашним 
void InputStudentTest(struct Student *stud, int n);     // Ввод информации об оценках за контрольные
void InputStudentLab(struct Student *stud, int n);      // Ввод информации об оценках за лабораторные

void CalcStudentMiddleAc(struct Student *stud, int m);  // Расчёт средней оценки студента

void InputeStudentAcPerf(struct Student *stud, int m);  // Функция которая вызывает функции по вводу данных об оценках

void InputStudentFaculty(struct Student *stud);         // Ввод информации о факультете

void OutputStudentInfo(struct Student *stud);           // Вывод информации о студенте
void OutpuStudentVisit(struct Student *stud, int n);    // Вывод информации о студентом
void OutpuStudentAc(struct Student *stud, int n);       // Вывод информации об оценках на уроке
*/

int main()
{
	setlocale(LC_ALL, "rus");
	/*
	//-----------------------------------------------------------Меню программы-----------------------------------
	cout << "Меню программы" << endl;
	cout << "1. Ввод данных о студенах;" << endl;
	cout << "2. Вывод данных о студентах;" << endl;
	cout << "3. Очистка всех данных;" << endl;
	cout << "4. Сортировка;" << endl;
	cout << "5. Поиск записи о студенте;" << endl;
	cout << "Необходимо выбрать необходимый пунк меню" << endl;
	char a;

	
	// НУЖНО СДЕЛАТЬ ПРОВЕРКУ ИЗ ФАЙЛА Les7 (проверка на ввод числа, а не символа)
	switch (a)
	{
	   case 1:
	      {

	      }
	      break;
	   case 2:
	      {

	      }
	      break;
	   case 3:
	      {

	      }
	      break;
	   case 4:
	      {

	      }
	      break;
	   case 5:
	      {

	      }
	      break;
	}

	*/

	//-----------------------------------------------------------Ввод информайии о студентах----------------------
	for (int i = 0; i < N; i++)
	{
		student_shag[i].id = i;

		//-------------------------------------------------------Вызов функций------------------------------------
		InputStudentInfo(&student_shag[i]);
		InputStudentVisit(&student_shag[i], N);
		InputeStudentAcPerf(&student_shag[i], N);
		CalcStudentMiddleAc(&student_shag[i], N);
		InputStudentFaculty(&student_shag[i]);
		//---------------------------------------------------------------------------------------------------------
	}
	//---------------------------------------------------------Вывод данных о студентах----------------------------
	for (int i = 0; i < N; i++)
	{
		//-------------------------------------------------------Вызов функций------------------------------------
		OutputStudentInfo(&student_shag[i]);
		OutpuStudentVisit(&student_shag[i], N);
		OutpuStudentAc(&student_shag[i], N);
		//---------------------------------------------------------------------------------------------------------
	}
	//-------------------------------------------------------Запись данных о студентах в файлы---------------------
	for (int i = 0; i < N; i++)
	{
		//-------------------------------------------------------Вызов функций------------------------------------
		StudentOutputFile(student_shag[i]);
		OutputVisitFile(student_shag[i]);
		OutputAcPerfFile(student_shag[i]);
		OutputHomeWorkFile(student_shag[i]);
		OutputTestFile(student_shag[i]);
		OutputLabFile(student_shag[i]);
		ImportStudentDataBase(&student_shag[i]);
		//---------------------------------------------------------------------------------------------------------
	}

}

