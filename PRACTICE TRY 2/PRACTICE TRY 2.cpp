#include <iostream>
#include <iomanip>
#include <Windows.h>
#include <cstdlib>
#include <fstream>
#include <ctime>
using namespace std;

enum MENU // Перечисления для пунктов меню
{
	INPUT_BASE = 1,
	LOAD_TEXT,
	LOAD_BIN,
	OUTPUT_BASE,
	EXP_TEXT,
	EXP_BIN,
	ADD_ELEMENT,
	EDITING,
	DEL,
	SORT_BASE,
	REQUEST_PRINT,
	EXIT = 0,
};

struct STUDENT //Структура студента
{
	char NAME[40]= "\0";
	char SURNAME[40]= "\0";
	char PATRON[40]= "\0";
	char ENTRANCE[5] = "\0";
	char GROUP[15]="\0";
	unsigned int MATH = '\0';
	unsigned int GEOMETRY;
	unsigned int ENGLISH;
	unsigned int RUSSIAN;
	float MIDDLE = 0.0;
};
STUDENT students[5];

int COUNTER{0};

void CREATE_BASE(STUDENT *students) // ФУНКЦИЯ СОЗДАНИЯ БАЗЫ С НУЛЯ
{
	COUNTER = 0;
	do
	{
		bool check = true;
		system("cls");

		cout << "Entering information about student number " << COUNTER + 1 << endl;
		//ВВОД ИМЕНИ
		while(check)
		{
			cout << "Enter student's Name: " << endl;
			cin >> students[COUNTER].NAME;
			if (islower(students[COUNTER].NAME[0])) students[COUNTER].NAME[0] = toupper(students[COUNTER].NAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[COUNTER].NAME); i++)
			{
				if (!isalpha(students[COUNTER].NAME[i]) && students[COUNTER].NAME[i] != '-' && students[COUNTER].NAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[COUNTER].NAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Name must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		//ВВОД ФАМИЛИИ
		check = true;
		while (check)
		{
			cout << "Enter student's Surname: " << endl;
			cin >> students[COUNTER].SURNAME;
			if (islower(students[COUNTER].SURNAME[0])) students[COUNTER].SURNAME[0] = toupper(students[COUNTER].SURNAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[COUNTER].SURNAME); i++)
			{
				if (!isalpha(students[COUNTER].SURNAME[i]) && students[COUNTER].SURNAME[i] != '-' && students[COUNTER].SURNAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[COUNTER].SURNAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Surname must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		//ВВОД ОТЧЕСТВА
		check = true;
		while (check)
		{
			cout << "Enter student's Patron: " << endl;
			cin >> students[COUNTER].PATRON;
			if (islower(students[COUNTER].PATRON[0])) students[COUNTER].PATRON[0] = toupper(students[COUNTER].PATRON[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[COUNTER].PATRON); i++)
			{
				if (!isalpha(students[COUNTER].PATRON[i]) && students[COUNTER].PATRON[i] != '-' && students[COUNTER].PATRON[i] != '\'') c++;
			}
			if (c || strlen(students[COUNTER].PATRON) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Patron must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		//ВВОД ГОДА ПОСТУПЛЕНИЯ
		check = true;
		while(check)
		{
			cout << "Enter an entrance year: " << endl;
			cin >> students[COUNTER].ENTRANCE;

			int c = 0;

			for (int i = 0; i < 4; i++)
			{
				if (!(isdigit(students[COUNTER].ENTRANCE[i]))) c++;
			}

			if (strlen(students[COUNTER].ENTRANCE) < 4 || strlen(students[COUNTER].ENTRANCE) > 4 || c)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (students[COUNTER].ENTRANCE[0] != '2' || students[COUNTER].ENTRANCE[1] != '0' || (int)students[COUNTER].ENTRANCE[2] > 50)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (!c && students[COUNTER].ENTRANCE[0] == '2' && students[COUNTER].ENTRANCE[1] == '0' || (int)students[COUNTER].ENTRANCE[2] < 50) check = false;
		}
		//ВВОД ГРУППЫ
		check = true;
		while(check)
		{
			cout << "Enter student's group: \n";
			cin >> students[COUNTER].GROUP;
			if (strlen(students[COUNTER].GROUP) > 15)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Too long Group's name\n";
			}
			else check = false;
		}
		//ВВОД МАТЕМАТИКИ
		check = true;
		while (check)
		{
			cout << "Enter Math's grade: \n";
			cin >> students[COUNTER].MATH;
			if (cin.fail() || students[COUNTER].MATH < 2 || students[COUNTER].MATH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[COUNTER].MATH > 1 && students[COUNTER].MATH < 6) check = false;
		}
		//ВВОД ГЕОМЕТРИИ
		check = true;
		while (check)
		{
			cout << "Enter Geometry's grade: \n";
			cin >> students[COUNTER].GEOMETRY;
			if (cin.fail() || students[COUNTER].GEOMETRY < 2 || students[COUNTER].GEOMETRY > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[COUNTER].GEOMETRY > 1 && students[COUNTER].GEOMETRY < 6) check = false;
		}
		//ВВОД АНГЛИЙСКОГО
		check = true;
		while (check)
		{
			cout << "Enter English's grade: \n";
			cin >> students[COUNTER].ENGLISH;
			if (cin.fail() || students[COUNTER].ENGLISH < 2 || students[COUNTER].ENGLISH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[COUNTER].ENGLISH > 1 && students[COUNTER].ENGLISH < 6) check = false;
		}
		//ВВОД РУССКОГО
		check = true;
		while (check)
		{
			cout << "Enter Russian's grade: \n";
			cin >> students[COUNTER].RUSSIAN;
			if (cin.fail() || students[COUNTER].RUSSIAN < 2|| students[COUNTER].RUSSIAN > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[COUNTER].RUSSIAN > 1 && students[COUNTER].RUSSIAN < 6) check = false;
		}
		//ПОДСЧЁТ СРЕДНЕГО АРИФМЕТИЧЕСКОГО
		students[COUNTER].MIDDLE = (((float)(students[COUNTER].MATH) + ((float)students[COUNTER].GEOMETRY) + ((float)students[COUNTER].ENGLISH) + ((float)students[COUNTER].RUSSIAN ))/ 4);
		//ПРОВЕРКА ВВЕДЁННЫХ ДАННЫХ
		unsigned int ch = 0;
		check = true;
		system("cls");
		while(check)
		{
			cout << "Please, check the information:\n";
			cout << students[COUNTER].NAME << " " << students[COUNTER].SURNAME << " " << students[COUNTER].PATRON << endl;
			cout << "Group: " << students[COUNTER].GROUP << ". Entrance year: " << students[COUNTER].ENTRANCE << endl;
			cout << "Math: " << students[COUNTER].MATH << ". Geometry: " << students[COUNTER].GEOMETRY << ". Russian: " << students[COUNTER].RUSSIAN << ". English: " << students[COUNTER].ENGLISH << ".\n";
			cout << "Do you want to change anything?\n";
			cout << "1. Yes\n";
			cout << "0. No\n";

			bool what = true;
			cin >> ch;
			while(what)
			{
				if (cin.fail() || ch < 0 || ch > 1)
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Wrong! Enter correct option.\n";
				}
				else if (!cin.fail() && (ch == 1 || ch == 0)) what = false;
			}
			

			if (ch == 1)
			{
				system("cls");
				int k = 0;

				bool enter = true;
				while(enter)
				{
					cout << "What do you want to change?" << endl;
					cout << "1. Whole information.\n";
					cout << "2. Name, Surname and Patron.\n";
					cout << "3. Entrance Year.\n";
					cout << "4. Group.\n";
					cout << "5. Grades.\n";

					cin >> k;

					if (cin.fail())
					{
						cin.clear();
						cin.ignore(1000, '\n');
						cout << "Error! Please enter correct option.\n";
					}
					else if (!cin.fail()) enter = false;
				}
				
				switch (k)
				{
				case(1):
				{
					bool check = true;
						system("cls");

						cout << "Entering information about student number " << COUNTER + 1 << endl;

						while (check)
						{
							cout << "Enter student's Name: " << endl;
							cin >> students[COUNTER].NAME;
							if (islower(students[COUNTER].NAME[0])) students[COUNTER].NAME[0] = toupper(students[COUNTER].NAME[0]);
							int c = 0;
							for (int i = 0; i < strlen(students[COUNTER].NAME); i++)
							{
								if (!isalpha(students[COUNTER].NAME[i]) && students[COUNTER].NAME[i] != '-' && students[COUNTER].NAME[i] != '\'')
								{
									c++;
								}
							}
							if (c || strlen(students[COUNTER].NAME) > 20)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Error! Name must contain only letters.\n";
							}
							else if (!c) check = false;
						}

						check = true;
						while (check)
						{
							cout << "Enter student's Surname: " << endl;
							cin >> students[COUNTER].SURNAME;
							if (islower(students[COUNTER].SURNAME[0])) students[COUNTER].SURNAME[0] = toupper(students[COUNTER].SURNAME[0]);
							int c = 0;
							for (int i = 0; i < strlen(students[COUNTER].SURNAME); i++)
							{
								if (!isalpha(students[COUNTER].SURNAME[i]) && students[COUNTER].SURNAME[i] != '-' && students[COUNTER].SURNAME[i] != '\'')
								{
									c++;
								}
							}
							if (c || strlen(students[COUNTER].SURNAME) > 20)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Error! Surname must contain only letters.\n";
							}
							else if (!c) check = false;
						}

						check = true;
						while (check)
						{
							cout << "Enter student's Patron: " << endl;
							cin >> students[COUNTER].PATRON;
							if (islower(students[COUNTER].PATRON[0])) students[COUNTER].PATRON[0] = toupper(students[COUNTER].PATRON[0]);
							int c = 0;
							for (int i = 0; i < strlen(students[COUNTER].PATRON); i++)
							{
								if (!isalpha(students[COUNTER].PATRON[i]) && students[COUNTER].PATRON[i] != '-' && students[COUNTER].PATRON[i] != '\'') c++;
							}
							if (c || strlen(students[COUNTER].PATRON) > 20)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Error! Patron must contain only letters.\n";
							}
							else if (!c) check = false;
						}
						//ГОД
						check = true;
						while (check)
						{
							cout << "Enter an entrance year: " << endl;
							cin >> students[COUNTER].ENTRANCE;

							int c = 0;

							for (int i = 0; i < 4; i++)
							{
								if (!(isdigit(students[COUNTER].ENTRANCE[i]))) c++;
							}

							if (strlen(students[COUNTER].ENTRANCE) < 4 || strlen(students[COUNTER].ENTRANCE) > 4 || c)
							{
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Error! Wrong year format.\n";
							}

							else if (students[COUNTER].ENTRANCE[0] != '2' || students[COUNTER].ENTRANCE[1] != '0' || (int)students[COUNTER].ENTRANCE[2] > 50)
							{
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Error! Wrong year format.\n";
							}

							else if (!c && students[COUNTER].ENTRANCE[0] == '2' && students[COUNTER].ENTRANCE[1] == '0' || (int)students[COUNTER].ENTRANCE[2] < 50) check = false;
						}

						//ГРУППА
						check = true;
						while (check)
						{
							cout << "Enter student's group: \n";
							cin >> students[COUNTER].GROUP;
							if (strlen(students[COUNTER].GROUP) > 15)
							{
								cin.clear();
								cin.ignore(1000, '\n');
								cout << "Error! Too long Group's name\n";
							}
							else check = false;
						}
						//МАТЕМАТИКА
						check = true;
						while (check)
						{
							cout << "Enter Math's grade: \n";
							cin >> students[COUNTER].MATH;
							if (cin.fail() || students[COUNTER].MATH < 2 || students[COUNTER].MATH > 5)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Incorrect enter. Please, enter correct grade.\n";
							}
							else if (!cin.fail() && students[COUNTER].MATH > 1 && students[COUNTER].MATH < 6) check = false;
						}
						//ВВОД ГЕОМЕТРИИ
						check = true;
						while (check)
						{
							cout << "Enter Geometry's grade: \n";
							cin >> students[COUNTER].GEOMETRY;
							if (cin.fail() || students[COUNTER].GEOMETRY < 2 || students[COUNTER].GEOMETRY > 5)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Incorrect enter. Please, enter correct grade.\n";
							}
							else if (!(cin.fail()) && students[COUNTER].GEOMETRY > 1 && students[COUNTER].GEOMETRY < 6) check = false;
						}
						//ВВОД АНГЛИЙСКОГО
						check = true;
						while (check)
						{
							cout << "Enter English's grade: \n";
							cin >> students[COUNTER].ENGLISH;
							if (cin.fail() || students[COUNTER].ENGLISH < 2 || students[COUNTER].ENGLISH > 5)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Incorrect enter. Please, enter correct grade.\n";
							}
							else if (!(cin.fail()) && students[COUNTER].ENGLISH > 1 && students[COUNTER].ENGLISH < 6) check = false;
						}
						//ВВОД РУССКОГО
						check = true;
						while (check)
						{
							cout << "Enter Russian's grade: \n";
							cin >> students[COUNTER].RUSSIAN;
							if (cin.fail() || students[COUNTER].RUSSIAN < 2 || students[COUNTER].RUSSIAN > 5)
							{
								cin.clear();
								cin.ignore(10000, '\n');
								cout << "Incorrect enter. Please, enter correct grade.\n";
							}
							else if (!cin.fail() && students[COUNTER].RUSSIAN > 1 && students[COUNTER].RUSSIAN < 6) check = false;
						}
						//ПОДСЧЁТ СРЕДНЕГО АРИФМЕТИЧЕСКОГО
						students[COUNTER].MIDDLE = (((float)(students[COUNTER].MATH) + ((float)students[COUNTER].GEOMETRY) + ((float)students[COUNTER].ENGLISH) + ((float)students[COUNTER].RUSSIAN)) / 4);
					} 
					break;
				case(2):
				{
					bool check = true;
					system("cls");

					cout << "Entering information about student number " << COUNTER + 1 << endl;

					while (check)
					{
						cout << "Enter student's Name: " << endl;
						cin >> students[COUNTER].NAME;
						if (islower(students[COUNTER].NAME[0])) students[COUNTER].NAME[0] = toupper(students[COUNTER].NAME[0]);
						int c = 0;
						for (int i = 0; i < strlen(students[COUNTER].NAME); i++)
						{
							if (!isalpha(students[COUNTER].NAME[i]) && students[COUNTER].NAME[i] != '-' && students[COUNTER].NAME[i] != '\'')
							{
								c++;
							}
						}
						if (c || strlen(students[COUNTER].NAME) > 20)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Error! Name must contain only letters.\n";
						}
						else if (!c) check = false;
					}

					check = true;
					while (check)
					{
						cout << "Enter student's Surname: " << endl;
						cin >> students[COUNTER].SURNAME;
						if (islower(students[COUNTER].SURNAME[0])) students[COUNTER].SURNAME[0] = toupper(students[COUNTER].SURNAME[0]);
						int c = 0;
						for (int i = 0; i < strlen(students[COUNTER].SURNAME); i++)
						{
							if (!isalpha(students[COUNTER].SURNAME[i]) && students[COUNTER].SURNAME[i] != '-' && students[COUNTER].SURNAME[i] != '\'')
							{
								c++;
							}
						}
						if (c || strlen(students[COUNTER].SURNAME) > 20)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Error! Surname must contain only letters.\n";
						}
						else if (!c) check = false;
					}

					check = true;
					while (check)
					{
						cout << "Enter student's Patron: " << endl;
						cin >> students[COUNTER].PATRON;
						if (islower(students[COUNTER].PATRON[0])) students[COUNTER].PATRON[0] = toupper(students[COUNTER].PATRON[0]);
						int c = 0;
						for (int i = 0; i < strlen(students[COUNTER].PATRON); i++)
						{
							if (!isalpha(students[COUNTER].PATRON[i]) && students[COUNTER].PATRON[i] != '-' && students[COUNTER].PATRON[i] != '\'') c++;
						}
						if (c || strlen(students[COUNTER].PATRON) > 20)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Error! Patron must contain only letters.\n";
						}
						else if (!c) check = false;
					}
				}
					break;
				case(3):
				{
					check = true;
					while (check)
					{
						cout << "Enter an entrance year: " << endl;
						cin >> students[COUNTER].ENTRANCE;

						int c = 0;

						for (int i = 0; i < 4; i++)
						{
							if (!(isdigit(students[COUNTER].ENTRANCE[i]))) c++;
						}

						if (strlen(students[COUNTER].ENTRANCE) < 4 || strlen(students[COUNTER].ENTRANCE) > 4 || c)
						{
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Error! Wrong year format.\n";
						}

						else if (students[COUNTER].ENTRANCE[0] != '2' || students[COUNTER].ENTRANCE[1] != '0' || (int)students[COUNTER].ENTRANCE[2] > 50)
						{
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Error! Wrong year format.\n";
						}

						else if (!c && students[COUNTER].ENTRANCE[0] == '2' && students[COUNTER].ENTRANCE[1] == '0' || (int)students[COUNTER].ENTRANCE[2] < 50) check = false;
					}
				}
					break;
				case(4):
				{
					check = true;
					while (check)
					{
						cout << "Enter student's group: \n";
						cin >> students[COUNTER].GROUP;
						if (strlen(students[COUNTER].GROUP) > 15)
						{
							cin.clear();
							cin.ignore(1000, '\n');
							cout << "Error! Too long Group's name\n";
						}
						else check = false;
					}
				}
					break;
				case(5):
					check = true;
					while (check)
					{
						cout << "Enter Math's grade: \n";
						cin >> students[COUNTER].MATH;
						if (cin.fail() || students[COUNTER].MATH < 2 || students[COUNTER].MATH > 5)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Incorrect enter. Please, enter correct grade.\n";
						}
						else if (!cin.fail() && students[COUNTER].MATH > 1 && students[COUNTER].MATH < 6) check = false;
					}
					//ВВОД ГЕОМЕТРИИ
					check = true;
					while (check)
					{
						cout << "Enter Geometry's grade: \n";
						cin >> students[COUNTER].GEOMETRY;
						if (cin.fail() || students[COUNTER].GEOMETRY < 2 || students[COUNTER].GEOMETRY > 5)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Incorrect enter. Please, enter correct grade.\n";
						}
						else if (!(cin.fail()) && students[COUNTER].GEOMETRY > 1 && students[COUNTER].GEOMETRY < 6) check = false;
					}
					//ВВОД АНГЛИЙСКОГО
					check = true;
					while (check)
					{
						cout << "Enter English's grade: \n";
						cin >> students[COUNTER].ENGLISH;
						if (cin.fail() || students[COUNTER].ENGLISH < 2 || students[COUNTER].ENGLISH > 5)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Incorrect enter. Please, enter correct grade.\n";
						}
						else if (!(cin.fail()) && students[COUNTER].ENGLISH > 1 && students[COUNTER].ENGLISH < 6) check = false;
					}
					//ВВОД РУССКОГО
					check = true;
					while (check)
					{
						cout << "Enter Russian's grade: \n";
						cin >> students[COUNTER].RUSSIAN;
						if (cin.fail() || students[COUNTER].RUSSIAN < 2 || students[COUNTER].RUSSIAN > 5)
						{
							cin.clear();
							cin.ignore(10000, '\n');
							cout << "Incorrect enter. Please, enter correct grade.\n";
						}
						else if (!cin.fail() && students[COUNTER].RUSSIAN > 1 && students[COUNTER].RUSSIAN < 6) check = false;
					}
					//ПОДСЧЁТ СРЕДНЕГО АРИФМЕТИЧЕСКОГО
					students[COUNTER].MIDDLE = (((float)(students[COUNTER].MATH) + ((float)students[COUNTER].GEOMETRY) + ((float)students[COUNTER].ENGLISH) + ((float)students[COUNTER].RUSSIAN)) / 4);
					break;
				}
				cout << "Edited information:\n";
			}
			
			else if (ch == 0) 
			{
				COUNTER++;
				check = false;
			}
			else if (!cin >> ch)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Choose correct option.\n";
				system("cls");
			}
		}

		if (COUNTER < 5)
		{
			int i = 0;
			cout << "Do you whant to continue?\n";
			cout << "1. Continue\n";
			cout << "0. Stop\n";
			check = true;
			while(check)
			{
				cin >> i;
				if (i == 1) check = false;
				else if (i == 0) return;
				if (!cin >> i)
				{
					cin.clear();
					cin.ignore(1000, '\n');
				}
			}
		}
		if (COUNTER == 5) return;
	} while (true);
}

void PRINT_BASE(STUDENT *students) // ФУНКЦИЯ ВЫВОДА БАЗЫ
{
	cout << "№----|-----NAME----|------SURNAME------|------PATRON------|--YEAR--|-----GROUP-----||--MATH--|--GEOM--|-RUS-|-ENG-|||" << endl;
	for (int i = 0; i < 5; i++)
	{
		cout << setw(4) << i+1 << setw(16) << students[i].NAME << setw(19) << students[i].SURNAME
			<< setw(18) << students[i].PATRON << setw(8) << students[i].ENTRANCE << setw(15) << students[i].GROUP
			<< setw(10) << students[i].MATH << setw(10) << students[i].GEOMETRY << setw(6) << students[i].RUSSIAN << setw(6) << students[i].ENGLISH << endl;
		cout << "-----|-------------|-------------------|------------------|--------|---------------||--------|--------|-----|-----|||" << endl;
	}
}

void PRINT_REQUEST(STUDENT* students) // ФУНКЦИЯ ВЫВОДА ПО ЗАПРОСУ
{
	STUDENT group_students[5];
	char group[10]="\0";
	int k{};
	cout << "Введите группу: \n";
	cin >> group;
	cout << "Этой группе принадлежат студенты: \n";
	for (int i = 0; i < 5; i++)
	{
		if (!strcmp(group, students[i].GROUP))
		{
			cout << students[i].NAME << " " << students[i].SURNAME << endl;
			cout << "Средний балл " << students[i].MIDDLE << endl;
			group_students[k] = students[i];
			k++;
		}
	}
	for (int i = 0; i < k; i++)
	{
		for (int j = 0; j < k; k++) 
		{
			if (group_students[j].MIDDLE < group_students[j+1].MIDDLE)
			{
				group_students[j] = group_students[j + 1];
			}
		}
	}
	cout << "Студент " << group_students[0].NAME << " " << group_students[0].SURNAME << " со средним баллом " << group_students[0].MIDDLE << endl;
}

void EDIT(STUDENT* students) // ФУНКЦИЯ ИЗМЕНЕНИЯ ЗАПИСИ
{
	system("cls");
	PRINT_BASE(students);
	int y = 0;
	int k = 0;
	cout << "Which item do you wnat to Edit?" << endl;
	cin >> y;
	cout << "What do you want yo edit?" << endl;
	cout << "1. Whole information.\n";
	cout << "2. Name, Surname and Patron.\n";
	cout << "3. Entrance Year.\n";
	cout << "4. Group.\n";
	cout << "5. Grades.\n";
	cin >> k;
	bool check = true;

	while(check)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(100, '\n');
			cout << "Error! Enter valid option.\n";
			cin >> k;
		}
		else if (!cin.fail()) check = false;
	}
	check = true;
	switch (k) 
	{//ИЗМЕНЕНИЕ ВСЕЙ ЗАПИСИ
	case(1):
		cout << "Enter new information: \n";
		while (check)
		{
			cout << "Enter student's Name: " << endl;
			cin >> students[y - 1].NAME;
			if (islower(students[y - 1].NAME[0])) students[y - 1].NAME[0] = toupper(students[y - 1].NAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[y - 1].NAME); i++)
			{
				if (!isalpha(students[y - 1].NAME[i]) && students[y - 1].NAME[i] != '-' && students[y - 1].NAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[y - 1].NAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Name must contain only letters.\n";
			}
			else if (!c) check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter student's Surname: " << endl;
			cin >> students[y - 1].SURNAME;
			if (islower(students[y - 1].SURNAME[0])) students[y - 1].SURNAME[0] = toupper(students[y - 1].SURNAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[y - 1].NAME); i++)
			{
				if (!isalpha(students[y - 1].SURNAME[i]) && students[y - 1].SURNAME[i] != '-' && students[y - 1].SURNAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[y - 1].SURNAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Surname must contain only letters.\n";
			}
			else if (!c) check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter student's Patron: " << endl;
			cin >> students[y - 1].PATRON;
			if (islower(students[y - 1].PATRON[0])) students[y - 1].PATRON[0] = toupper(students[y - 1].PATRON[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[y - 1].PATRON); i++)
			{
				if (!isalpha(students[y - 1].PATRON[i]) && students[y - 1].PATRON[i] != '-' && students[y - 1].PATRON[i] != '\'') c++;
			}
			if (c || strlen(students[y - 1].PATRON) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Patron must contain only letters.\n";
			}
			else if (!c) check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter an entrance year: " << endl;
			cin >> students[y-1].ENTRANCE;

			int c = 0;

			for (int i = 0; i < 4; i++)
			{
				if (!(isdigit(students[y-1].ENTRANCE[i]))) c++;
			}

			if (strlen(students[y-1].ENTRANCE) < 4 || strlen(students[y-1].ENTRANCE) > 4 || c)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (students[y-1].ENTRANCE[0] != '2' || students[y-1].ENTRANCE[1] != '0' || (int)students[y-1].ENTRANCE[2] > 50)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (!c && students[y-1].ENTRANCE[0] == '2' && students[y-1].ENTRANCE[1] == '0' || (int)students[y-1].ENTRANCE[2] < 50) check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter student's group: \n";
			cin >> students[y - 1].GROUP;
			if (strlen(students[y - 1].GROUP) > 15)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Too long Group's name\n";
			}
			else check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter Math's grade: \n";
			cin >> students[y-1].MATH;
			if (cin.fail() || students[y-1].MATH < 2 || students[y-1].MATH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[y-1].MATH > 1 && students[y-1].MATH < 6) check = false;
		}
		//ВВОД ГЕОМЕТРИИ
		check = true;
		while (check)
		{
			cout << "Enter Geometry's grade: \n";
			cin >> students[y-1].GEOMETRY;
			if (cin.fail() || students[y-1].GEOMETRY < 2 || students[y-1].GEOMETRY > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[y-1].GEOMETRY > 1 && students[y-1].GEOMETRY < 6) check = false;
		}
		//ВВОД АНГЛИЙСКОГО
		check = true;
		while (check)
		{
			cout << "Enter English's grade: \n";
			cin >> students[y-1].ENGLISH;
			if (cin.fail() || students[y-1].ENGLISH < 2 || students[y-1].ENGLISH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[y-1].ENGLISH > 1 && students[y-1].ENGLISH < 6) check = false;
		}
		//ВВОД РУССКОГО
		check = true;
		while (check)
		{
			cout << "Enter Russian's grade: \n";
			cin >> students[y-1].RUSSIAN;
			if (cin.fail() || students[y-1].RUSSIAN < 2 || students[y-1].RUSSIAN > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[y-1].RUSSIAN > 1 && students[y-1].RUSSIAN < 6) check = false;
		}
		//ПОДСЧЁТ СРЕДНЕГО АРИФМЕТИЧЕСКОГО
		students[y-1].MIDDLE = (((float)(students[y-1].MATH) + ((float)students[y-1].GEOMETRY) + ((float)students[y-1].ENGLISH) + ((float)students[y-1].RUSSIAN)) / 4);
		break;
	case(2):
	{
		cout << "Enter new information: \n";
		check = true;
		while (check)
		{
			cout << "Enter student's Name: " << endl;
			cin >> students[y - 1].NAME;
			if (islower(students[y - 1].NAME[0])) students[y - 1].NAME[0] = toupper(students[y - 1].NAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[y - 1].NAME); i++)
			{
				if (!isalpha(students[y - 1].NAME[i]) && students[y - 1].NAME[i] != '-' && students[y - 1].NAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[y - 1].NAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Name must contain only letters.\n";
			}
			else if (!c) check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter student's Surname: " << endl;
			cin >> students[y - 1].SURNAME;
			if (islower(students[y - 1].SURNAME[0])) students[y - 1].SURNAME[0] = toupper(students[y - 1].SURNAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[y - 1].NAME); i++)
			{
				if (!isalpha(students[y - 1].SURNAME[i]) && students[y - 1].SURNAME[i] != '-' && students[y - 1].SURNAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[y - 1].SURNAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Surname must contain only letters.\n";
			}
			else if (!c) check = false;
		}

		check = true;
		while (check)
		{
			cout << "Enter student's Patron: " << endl;
			cin >> students[y - 1].PATRON;
			if (islower(students[y - 1].PATRON[0])) students[y - 1].PATRON[0] = toupper(students[y - 1].PATRON[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[y - 1].PATRON); i++)
			{
				if (!isalpha(students[y - 1].PATRON[i]) && students[y - 1].PATRON[i] != '-' && students[y - 1].PATRON[i] != '\'') c++;
			}
			if (c || strlen(students[y - 1].PATRON) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Patron must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		break;
	}
	case(3):
	{
		check = true;
		while (check)
		{
			cout << "Enter an entrance year: " << endl;
			cin >> students[y-1].ENTRANCE;

			int c = 0;

			for (int i = 0; i < 4; i++)
			{
				if (!(isdigit(students[y-1].ENTRANCE[i]))) c++;
			}

			if (strlen(students[y-1].ENTRANCE) < 4 || strlen(students[y-1].ENTRANCE) > 4 || c)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (students[y-1].ENTRANCE[0] != '2' || students[y-1].ENTRANCE[1] != '0' || (int)students[y-1].ENTRANCE[2] > 50)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (!c && students[y-1].ENTRANCE[0] == '2' && students[y-1].ENTRANCE[1] == '0' || (int)students[y-1].ENTRANCE[2] < 50) check = false;
		}
		break;
	}
	case(4):
	{
		check = true;
		while (check)
		{
			cout << "Enter student's group: \n";
			cin >> students[y - 1].GROUP;
			if (strlen(students[y - 1].GROUP) > 15)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Too long Group's name\n";
			}
			else check = false;
		}
		break;
	}
	case(5):
	{
		//students[y - 1].MIDDLE = ((students[y - 1].MATH - '0') + (students[y - 1].GEOMETRY - '0') + (students[y - 1].ENGLISH - '0') + (students[y - 1].RUSSIAN - '0')) / 4;
		check = true;
		while (check)
		{
			cout << "Enter Math's grade: \n";
			cin >> students[y - 1].MATH;
			if (cin.fail() || students[y - 1].MATH < 2 || students[y - 1].MATH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[y - 1].MATH > 1 && students[y - 1].MATH < 6) check = false;
		}
		//ВВОД ГЕОМЕТРИИ
		check = true;
		while (check)
		{
			cout << "Enter Geometry's grade: \n";
			cin >> students[y - 1].GEOMETRY;
			if (cin.fail() || students[y - 1].GEOMETRY < 2 || students[y - 1].GEOMETRY > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[y - 1].GEOMETRY > 1 && students[y - 1].GEOMETRY < 6) check = false;
		}
		//ВВОД АНГЛИЙСКОГО
		check = true;
		while (check)
		{
			cout << "Enter English's grade: \n";
			cin >> students[y - 1].ENGLISH;
			if (cin.fail() || students[y - 1].ENGLISH < 2 || students[y - 1].ENGLISH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[y - 1].ENGLISH > 1 && students[y - 1].ENGLISH < 6) check = false;
		}
		//ВВОД РУССКОГО
		check = true;
		while (check)
		{
			cout << "Enter Russian's grade: \n";
			cin >> students[y - 1].RUSSIAN;
			if (cin.fail() || students[y - 1].RUSSIAN < 2 || students[y - 1].RUSSIAN > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[y - 1].RUSSIAN > 1 && students[y - 1].RUSSIAN < 6) check = false;
		}
		//ПОДСЧЁТ СРЕДНЕГО АРИФМЕТИЧЕСКОГО
		students[y - 1].MIDDLE = (((float)(students[y - 1].MATH) + ((float)students[y - 1].GEOMETRY) + ((float)students[y - 1].ENGLISH) + ((float)students[y - 1].RUSSIAN)) / 4);
		break;
	}
	}
}

void DELETING(STUDENT* students) // ФУНКЦИЯ УДАЛЕНИЯ СТУДЕНТА
{
	int l{};
	int k = 5;
	cout << "Which item do you want to Delete?\n";

	bool check = true;
	while (check)
	{
		cin >> l;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error! Wrong option.";
		}

		else if(!cin.fail())
		{
			int j = l;

			if (l == 5)
			{
				for (int i = 0; i < 20; i++)
				{
					students[l].NAME[i] = '\0';
					students[l].SURNAME[i] = '\0';
					students[l].PATRON[i] = '\0';
					students[l].ENTRANCE[i] = '\0';
					students[l].GROUP[i] = '\0';
				}

				students[l].MATH = '\0';
				students[l].GEOMETRY = '\0';
				students[l].RUSSIAN = '\0';
				students[l].MIDDLE = '\0';
				check = false;
			}
			for (l--; l < k; l++)
			{
				students[l] = students[l + 1];
				j++;
			}
			check = false;
			COUNTER--;
		}
	}
}

void print_menu() // ФУНКЦИЯ ВЫВОДА МЕНЮ
{
	system("cls");
	cout << "MENU" << endl;
	cout << "1. CREATE DATA BASE." << endl;
	cout << "2. LOAD DATABASE FROM .txt FILE." << endl;
	cout << "3. LOAD DATABASE FROM BINARY FILE." << endl;
	cout << "4. PRINT BASE." << endl;
	cout << "5. EXPORT TO .txt." << endl;
	cout << "6. EXPORT .txt to BINARY." << endl;
	cout << "7. ADD ITEM." << endl;
	cout << "8. EDIT ITEM." << endl;
	cout << "9. DELETE ITEM." << endl;
	cout << "10. SORT DATABASE." << endl;
	cout << "11. REQUEST." << endl;
	cout << "0. EXIT." << endl;
}

void ADDITION(STUDENT* students) // ФУНКЦИЯ ДОБАВЛЕНИЯ ЗАПИСИ
{
	if (COUNTER == 5)
	{
		cout << "It is impossible to Add new item.";
		return;
	}
	else 
	{//ИМЯ
		bool check = true;
		while (check)
		{
			cout << "Enter student's Name: " << endl;
			cin >> students[COUNTER].NAME;
			if (islower(students[COUNTER].NAME[0])) students[COUNTER].NAME[0] = toupper(students[COUNTER].NAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[COUNTER+1].NAME); i++)
			{
				if (!isalpha(students[COUNTER].NAME[i]) && students[COUNTER].NAME[i] != '-' && students[COUNTER+1].NAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[COUNTER].NAME) > 20)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Name must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		//ФАМИЛИЯ
		check = true;
		while (check)
		{
			cout << "Enter student's Surname: " << endl;
			cin >> students[COUNTER].SURNAME;
			if (islower(students[COUNTER].SURNAME[0])) students[COUNTER].SURNAME[0] = toupper(students[COUNTER].SURNAME[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[COUNTER].NAME); i++)
			{
				if (!isalpha(students[COUNTER].SURNAME[i]) && students[COUNTER].SURNAME[i] != '-' && students[COUNTER].SURNAME[i] != '\'')
				{
					c++;
				}
			}
			if (c || strlen(students[COUNTER].SURNAME) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Surname must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		//ОТЧЕСТВО
		check = true;
		while (check)
		{
			cout << "Enter student's Patron: " << endl;
			cin >> students[COUNTER].PATRON;
			if (islower(students[COUNTER].PATRON[0])) students[COUNTER].PATRON[0] = toupper(students[COUNTER].PATRON[0]);
			int c = 0;
			for (int i = 0; i < strlen(students[COUNTER].PATRON); i++)
			{
				if (!isalpha(students[COUNTER].PATRON[i]) && students[COUNTER].PATRON[i] != '-' && students[COUNTER].PATRON[i] != '\'') c++;
			}
			if (c || strlen(students[COUNTER].PATRON) > 20)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Error! Patron must contain only letters.\n";
			}
			else if (!c) check = false;
		}
		//ГОД
		check = true;
		while (check)
		{
			cout << "Enter an entrance year: " << endl;
			cin >> students[COUNTER].ENTRANCE;

			int c = 0;

			for (int i = 0; i < 4; i++)
			{
				if (!(isdigit(students[COUNTER].ENTRANCE[i]))) c++;
			}

			if (strlen(students[COUNTER].ENTRANCE) < 4 || strlen(students[COUNTER].ENTRANCE) > 4 || c)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (students[COUNTER].ENTRANCE[0] != '2' || students[COUNTER].ENTRANCE[1] != '0' || (int)students[COUNTER].ENTRANCE[2] > 50)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Wrong year format.\n";
			}

			else if (!c && students[COUNTER].ENTRANCE[0] == '2' && students[COUNTER].ENTRANCE[1] == '0' || (int)students[COUNTER].ENTRANCE[2] < 50) check = false;
		}
		//ГРУППА
		check = true;
		while (check)
		{
			cout << "Enter student's group: \n";
			cin >> students[COUNTER].GROUP;
			if (strlen(students[COUNTER].GROUP) > 15)
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Error! Too long Group's name\n";
			}
			else check = false;
		}
		//МАТЕМАТИКА
		check = true;
		while (check)
		{
			cout << "Enter Math's grade: \n";
			cin >> students[COUNTER].MATH;
			if (cin.fail() || students[COUNTER].MATH < 2 || students[COUNTER].MATH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[COUNTER].MATH > 1 && students[COUNTER].MATH < 6) check = false;
		}
		//ВВОД ГЕОМЕТРИИ
		check = true;
		while (check)
		{
			cout << "Enter Geometry's grade: \n";
			cin >> students[COUNTER].GEOMETRY;
			if (cin.fail() || students[COUNTER].GEOMETRY < 2 || students[COUNTER].GEOMETRY > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[COUNTER].GEOMETRY > 1 && students[COUNTER].GEOMETRY < 6) check = false;
		}
		//ВВОД АНГЛИЙСКОГО
		check = true;
		while (check)
		{
			cout << "Enter English's grade: \n";
			cin >> students[COUNTER].ENGLISH;
			if (cin.fail() || students[COUNTER].ENGLISH < 2 || students[COUNTER].ENGLISH > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!(cin.fail()) && students[COUNTER].ENGLISH > 1 && students[COUNTER].ENGLISH < 6) check = false;
		}
		//ВВОД РУССКОГО
		check = true;
		while (check)
		{
			cout << "Enter Russian's grade: \n";
			cin >> students[COUNTER].RUSSIAN;
			if (cin.fail() || students[COUNTER].RUSSIAN < 2 || students[COUNTER].RUSSIAN > 5)
			{
				cin.clear();
				cin.ignore(10000, '\n');
				cout << "Incorrect enter. Please, enter correct grade.\n";
			}
			else if (!cin.fail() && students[COUNTER].RUSSIAN > 1 && students[COUNTER].RUSSIAN < 6) check = false;
		}
		//ПОДСЧЁТ СРЕДНЕГО АРИФМЕТИЧЕСКОГО
		students[COUNTER].MIDDLE = (((float)(students[COUNTER].MATH) + ((float)students[COUNTER].GEOMETRY) + ((float)students[COUNTER].ENGLISH) + ((float)students[COUNTER].RUSSIAN)) / 4);

		COUNTER++;
	}
}

void SURNAME_SORT_DOWN(STUDENT* students, int rec, int symb, int cic) 
{
	STUDENT temp;

	if (!(strncmp(students[cic].SURNAME, students[cic + 1].SURNAME, rec)))
	{
		SURNAME_SORT_DOWN(students, rec + 1, symb + 1, cic);
	}
	else if ((int)students[cic].SURNAME[symb] > (int)students[cic  + 1].SURNAME[symb])
	{
		temp = students[cic];
		students[cic] = students[cic + 1];
		students[cic + 1] = temp;
	}

}

void SURNAME_SORT_UP(STUDENT* students, int rec, int symb, int cycle)
{
	STUDENT temp;

	if (!(strncmp(students[cycle].SURNAME, students[cycle + 1].SURNAME, rec)))
	{
		if (rec == 6) return;
		SURNAME_SORT_UP(students, rec + 1, symb + 1, cycle);
	}
	else if ((int)students[cycle].SURNAME[symb] < (int)students[cycle + 1].SURNAME[symb])
	{
		temp = students[cycle];
		students[cycle] = students[cycle + 1];
		students[cycle + 1] = temp;
	}
}

void NAME_SORT_DOWN(STUDENT* students, int rec, int symb, int cic)
{
	STUDENT temp;

	if (!(strncmp(students[cic].NAME, students[cic + 1].NAME, rec)))
	{
		NAME_SORT_DOWN(students, rec + 1, symb + 1, cic);
	}
	else if ((int)students[cic].NAME[symb] > (int)students[cic + 1].NAME[symb])
	{
		temp = students[cic];
		students[cic] = students[cic + 1];
		students[cic + 1] = temp;
	}
}

void NAME_SORT_UP(STUDENT* students, int rec, int symb, int cic)
{
	STUDENT temp;

	if (!(strncmp(students[cic].NAME, students[cic + 1].NAME, rec)))
	{
		NAME_SORT_UP(students, rec + 1, symb + 1, cic);
	}
	else if ((int)students[cic].NAME[symb] < (int)students[cic + 1].NAME[symb])
	{
		temp = students[cic];
		students[cic] = students[cic + 1];
		students[cic + 1] = temp;
	}
}

void PATRON_SORT_DOWN(STUDENT* students, int rec, int symb, int cic)
{
	STUDENT temp;

	if (!(strncmp(students[cic].PATRON, students[cic + 1].PATRON, rec)))
	{
		PATRON_SORT_DOWN(students, rec + 1, symb + 1, cic);
	}
	else if ((int)students[cic].PATRON[symb] > (int)students[cic + 1].PATRON[symb])
	{
		temp = students[cic];
		students[cic] = students[cic + 1];
		students[cic + 1] = temp;
	}
}

void PATRON_SORT_UP(STUDENT* students, int rec, int symb, int cic)
{
	STUDENT temp;

	if (!(strncmp(students[cic].PATRON, students[cic + 1].PATRON, rec)))
	{
		PATRON_SORT_UP(students, rec + 1, symb + 1, cic);
	}
	else if ((int)students[cic].PATRON[symb] < (int)students[cic + 1].PATRON[symb])
	{
		temp = students[cic];
		students[cic] = students[cic + 1];
		students[cic + 1] = temp;
	}
}

void YEAR_SORTING_BY_ASC(STUDENT* students) //ГОД ПО ВОЗРАСТАНИЮ
{
	STUDENT temp;
	for (int i = 0; i < 4; i++)
	{
		if ((int)students[i].ENTRANCE[2] > (int)students[i+1].ENTRANCE[2])
		{
			temp = students[i];
			students[i] = students[i + 1];
			students[i + 1] = temp;
		}
		else if ((int)students[i].ENTRANCE[2] == (int)students[i+1].ENTRANCE[2])
		{
			if((int)students[i].ENTRANCE[3] > (int)students[i+1].ENTRANCE[3])
			{
				temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;
			}
		}
	}
}

void YEAR_SORTING_BY_DESC(STUDENT* students) //ГОД ПО УБЫВАНИЮ
{
	STUDENT temp;
	for (int i = 0; i < 4; i++)
	{
		if ((int)students[i].ENTRANCE[2] < (int)students[i + 1].ENTRANCE[2])
		{
			temp = students[i];
			students[i] = students[i + 1];
			students[i + 1] = temp;
		}
		else if ((int)students[i].ENTRANCE[2] == (int)students[i + 1].ENTRANCE[2])
		{
			if ((int)students[i].ENTRANCE[3] < (int)students[i + 1].ENTRANCE[3])
			{
				temp = students[i];
				students[i] = students[i + 1];
				students[i + 1] = temp;
			}
		}
	}
}

void SORT_ING(STUDENT* students) // ФУНКЦИЯ СОРТИРОВКИ, ПОКА ТОЛЬКО ФАМИЛИЯ
{
	cout << "How do you want to sort your DataBase?\n";
	cout << "1. By Surname.\n";
	cout << "2. By Name.\n";
	cout << "3. By Patron.\n";
	cout << "4. By Entrance Year.\n";

	int choice = 0;
	
	cin >> choice;

	bool checking = true;
	while (checking)
	{
		if (cin.fail())
		{
			cin.clear();
			cin.ignore(1000, '\n');
			cout << "Error! Please enter valid option.\n";
			cin >> choice;
		}
		else if (!cin.fail())
		{
			checking = false;
		}
	}
	switch (choice)
	{
	case 1: //ГОТОВО!
		{
			int symbol = 0;
			int number = 1;

			cout << "How do you want to sort your base?\n";
			cout << "1.By ascending order.\n";
			cout << "2.By descending order.\n";

			int up_down = 0;
			cin >> up_down;

			bool what = true;
			while(what)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Error! Choose valid option!\n";
				}
				else if (!(cin.fail())) what = false;
			}

			switch (up_down)
			{
				case 1:
					{
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							SURNAME_SORT_DOWN(&students[0], number, symbol,j);
						}		
					}	
					break;
					}
				case 2:
					{
					for (int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							SURNAME_SORT_UP(&students[0], number, symbol, j);
						}
					}
					break;
					}
			}
			cout << "Your DataBase has been sorted by Surnames.\n";
			system("pause");
			break;
		}	
	case 2: //ГОТОВО!
		{
			int symbol = 0;
			int number = 1;

			cout << "How do you want to sort your base?\n";
			cout << "1.By ascending order.\n";
			cout << "2.By descending order.\n";

			int up_down = 0;
			cin >> up_down;

			bool what = true;
			while (what)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Error! Choose valid option!\n";
				}
				else if (!(cin.fail())) what = false;
			}

			switch (up_down)
			{
				case 1:
				{
					for (int i = 0; i < 5; i++)
					{
						for(int j = 0; j < 4; j++)
						{
							NAME_SORT_DOWN(&students[0], number, symbol, j);
						}
					}
					break;
				}
				case 2:
				{
					for(int i = 0; i < 5; i++)
					{
						for (int j = 0; j < 4; j++)
						{
							NAME_SORT_UP(&students[0], number, symbol, j);
						}
					}
					break;
				}
			}
			cout << "Your DataBase has been sorted by Names.\n";
			system("pause");
			break;
		}
	case 3:
		{
			int symbol = 0;
			int number = 1;

			cout << "How do you want to sort your base?\n";
			cout << "1.By ascending order.\n";
			cout << "2.By descending order.\n";

			int up_down = 0;
			cin >> up_down;

			bool what = true;
			while (what)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Error! Choose valid option!\n";
				}
				else if (!(cin.fail())) what = false;
			}

			switch (up_down)
			{
			case 1: 
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						PATRON_SORT_DOWN(&students[0], number, symbol, j);
					}
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						PATRON_SORT_UP(&students[0], number, symbol, j);
					}
				}
				break;
			}
			}
			cout << "Your DataBase has been sorted.\n";
			system("pause");
			break;
		}
	case 4:
		{				
			int symbol = 0;
			int number = 1;

			cout << "How do you want to sort your base?\n";
			cout << "1.By ascending order.\n";
			cout << "2.By descending order.\n";

			int up_down = 0;
			cin >> up_down;

			bool what = true;
			while (what)
			{
				if (cin.fail())
				{
					cin.clear();
					cin.ignore(100, '\n');
					cout << "Error! Choose valid option!\n";
				}
				else if (!(cin.fail())) what = false;
			}

			switch (up_down)
			{
			case 1:
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						YEAR_SORTING_BY_ASC(&students[0]);
					}
				}
				break;
			}
			case 2:
			{
				for (int i = 0; i < 5; i++)
				{
					for (int j = 0; j < 4; j++)
					{
						YEAR_SORTING_BY_DESC(&students[0]);
					}
				}
				break;
			}
			}
			cout << "DataBase sorted.\n";
			system("pause");
			break;
		}		
	}	
}

void TEXT_INPUT(STUDENT* students)
{
	char txtname[20] = "\0";
	cout << "Enter file name with '.txt'\n";
	//ПРОВЕРКА НА НАЛИЧИЕ ".txt"
	cin >> txtname;

	if (txtname[strlen(txtname) - 1] != 'T' && txtname[strlen(txtname) - 2] != 'X' && txtname[strlen(txtname) - 3] != 'T' && txtname[strlen(txtname) - 4] != '.')
	{
		txtname[strlen(txtname) - 1] = 't';
		txtname[strlen(txtname) - 2] = 'x';
		txtname[strlen(txtname) - 3] = 't';
		txtname[strlen(txtname) - 4] = '.';
	}
	if (txtname[strlen(txtname) - 1] != 't' && txtname[strlen(txtname) - 2] != 'x' && txtname[strlen(txtname) - 3] != 't' && txtname[strlen(txtname) - 4] != '.')
	{
		const char _txt[] = ".txt";
		strcat(txtname, _txt);
	}

	ofstream outF;
	outF.open(txtname);
	for (int i = 0; i < COUNTER; i++)
	{
		outF << students[i].SURNAME << " " << students[i].NAME << " " << students[i].PATRON << " " << students[i].ENTRANCE << " "
			<< students[i].GROUP << " " << students[i].MATH << " " << students[i].GEOMETRY << " " << students[i].ENGLISH << " "
			<< students[i].RUSSIAN << " " << students[i].MIDDLE << "\n";
	}
	outF.close();
}

void EXP(STUDENT* students)
{
	COUNTER = 0;
	ifstream inF;
	char filename[20] = "\0";
	cout << "Enter file name with '.txt'\n";
	//ЕСТЬ ЛИ .txt В КОНЦЕ?
	cin >> filename;

	if (filename[strlen(filename) - 1] == 'T' && filename[strlen(filename) - 2] == 'X' && filename[strlen(filename) - 3] == 'T' && filename[strlen(filename) - 4] == '.')
	{
		filename[strlen(filename) - 1] = 't';
		filename[strlen(filename) - 2] = 'x';
		filename[strlen(filename) - 3] = 't';
		filename[strlen(filename) - 4] = '.';
	}

	if (filename[strlen(filename) - 1] != 't' && filename[strlen(filename) - 2] != 'x' && filename[strlen(filename) - 3] != 't' && filename[strlen(filename) - 4] != '.')
	{
		const char _txt[] = ".txt";
		strcat(filename, _txt);
	}
	
	inF.open(filename);

	if(!inF.is_open())
	{
		cout << "Error! Could not find the file!\n";
		system("pause");
		return;
	}

	short n = 0;
	while (!inF.eof())
	{
		if (inF.get() == '\n') ++n;
	}
	inF.clear();
	inF.seekg(0);
	for (int i = 0; i < n; ++i)
	{
		inF >> students[i].SURNAME >> students[i].NAME >> students[i].PATRON >> students[i].ENTRANCE >> students[i].GROUP >> students[i].MATH
			>> students[i].GEOMETRY >> students[i].ENGLISH >> students[i].RUSSIAN >> students[i].MIDDLE;
		COUNTER++;
	}
	inF.close();
}

void TEXT_TO_BIN(STUDENT* student)
{
	char bin[20] = "\0";
	cout << "Input name of binary file with '.bin'.\n";
	cin >> bin;

	if (bin[strlen(bin) - 1] == 'N' && bin[strlen(bin) - 2] == 'I' && bin[strlen(bin) - 3] == 'B' && bin[strlen(bin) - 4] == '.')
	{
		bin[strlen(bin) - 1] = 'n';
		bin[strlen(bin) - 2] = 'i';
		bin[strlen(bin) - 3] = 'b';
		bin[strlen(bin) - 4] = '.';
	}

	if (bin[strlen(bin) - 1] != 'n' && bin[strlen(bin) - 2] != 'i' && bin[strlen(bin) - 3] != 'b' && bin[strlen(bin) - 4] != '.')
	{
		const char _txt[] = ".bin";
		strcat(bin, _txt);
	}

	ofstream binfile(bin, ios::binary | ios::out);

	char txtname[20] = "\0";
	cout << "Enter file name with '.txt'\n";
	//ПРОВЕРКА НА НАЛИЧИЕ ".txt"

	cin >> txtname;

	if (txtname[strlen(txtname) - 1] != 'T' && txtname[strlen(txtname) - 2] != 'X' && txtname[strlen(txtname) - 3] != 'T' && txtname[strlen(txtname) - 4] != '.')
	{
		txtname[strlen(txtname) - 1] = 't';
		txtname[strlen(txtname) - 2] = 'x';
		txtname[strlen(txtname) - 3] = 't';
		txtname[strlen(txtname) - 4] = '.';
	}
	if (txtname[strlen(txtname) - 1] != 't' && txtname[strlen(txtname) - 2] != 'x' && txtname[strlen(txtname) - 3] != 't' && txtname[strlen(txtname) - 4] != '.')
	{
		const char _txt[] = ".txt";
		strcat(txtname, _txt);
	}

	ifstream txtfile(txtname);
	//ПРОВЕРКА НА НАЛИЧИЕ
	if(!txtfile.is_open())
	{
		cout << "Error! Could not find the file!\n";
		system("pause");
		return;
	}
	char temp;
	if(txtfile.is_open())
	{
		while(!txtfile.eof())
		{
			txtfile.read(&temp, sizeof(temp));
			binfile.write(&temp, sizeof(temp));
		}
		txtfile.close();
		binfile.close();
	}
}

void LOAD_BIN_(STUDENT* student)
{
	COUNTER = 0;

	char bin[20] = "\0";
	cout << "Input name of binary file with '.bin'.\n";
	cin >> bin;

	if (bin[strlen(bin) - 1] == 'N' && bin[strlen(bin) - 2] == 'I' && bin[strlen(bin) - 3] == 'B' && bin[strlen(bin) - 4] == '.')
	{
		bin[strlen(bin) - 1] = 'n';
		bin[strlen(bin) - 2] = 'i';
		bin[strlen(bin) - 3] = 'b';
		bin[strlen(bin) - 4] = '.';
	}

	if (bin[strlen(bin) - 1] != 'n' && bin[strlen(bin) - 2] != 'i' && bin[strlen(bin) - 3] != 'b' && bin[strlen(bin) - 4] != '.')
	{
		const char _txt[] = ".bin";
		strcat(bin, _txt);
	}

	ifstream BIN(bin, ios::binary | ios::in);
	//ПРОВЕРКА СУЩЕСТВОВАНИЯ
	if(!BIN.is_open())
	{
		cout << "Error! Could not find the file!\n";
		system("pause");
		return;
	}

	short n = 0;
	while (!BIN.eof())
	{
		if (BIN.get() == '\n') ++n;
	}
	BIN.clear();
	BIN.seekg(0);
	for (int i = 0; i < n; ++i)
	{
		BIN >> students[i].SURNAME >> students[i].NAME >> students[i].PATRON >> students[i].ENTRANCE >> students[i].GROUP >> students[i].MATH
			>> students[i].GEOMETRY >> students[i].ENGLISH >> students[i].RUSSIAN;
		COUNTER++;
	}
	BIN.close();
}

int main()
{
	for (int i = 0; i < 5; i++)
	{
		students[i].SURNAME[0] = '\0';
		students[i].NAME[0] = '\0';
		students[i].PATRON[0] = '\0';
		students[i].ENTRANCE[0] = '\0';
		students[i].GROUP[0] = '\0';
		students[i].MATH = '\0';
		students[i].GEOMETRY = '\0';
		students[i].RUSSIAN = '\0';
		students[i].ENGLISH = '\0';
	}

	const int n = 5;
	bool menu = true;

	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (menu) 
	{
		print_menu();
		unsigned int a = 0;

		bool ch = true;
		cin >> a;
		
		while (ch)
		{
			if (cin.fail())
			{
				cin.clear();
				cin.ignore(1000, '\n');
				cout << "Incorrect option. Please enter correct option.";
				cin >> a;
			}
			else if(!cin.fail()) ch = false;
		}
		switch (a)
		{
		case (INPUT_BASE):
			{
				CREATE_BASE(&students[0]);
				cout << "\n";
			}
			cout << "DataBase has been created." << endl;
			system("pause");
			break;
		case (LOAD_TEXT):
			EXP(&students[0]);
			break;
		case (LOAD_BIN):
			LOAD_BIN_(&students[0]);// Загрузить БД из бинарного файла
			break;
		case (OUTPUT_BASE):
			PRINT_BASE(&students[0]);
			system("pause");
			break;
		case (EXP_TEXT):
		{
			TEXT_INPUT(&students[0]);
			system("pause");
			break;
		}	
		case (EXP_BIN):
			TEXT_TO_BIN(&students[0]);
			break;
		case (ADD_ELEMENT):
			ADDITION(&students[0]);
			system("pause");
			break;
		case (EDITING):
			EDIT(&students[0]);
			system("pause");
			break;
		case (DEL):
			DELETING(&students[0]);
			system("pause");
			break;
		case (SORT_BASE):
			SORT_ING(&students[0]);
			break;
		case (REQUEST_PRINT):
			PRINT_REQUEST(&students[0]);
			system("pause");
			break;
		case (EXIT):
			cout << "Exit. . .\n" << endl;
			menu = false;
			break;
		default:
			cout << "Error! Please choose valid option!\n" << endl;
			cin.ignore(10, '\n');
		}
	}
}