#include <iostream>
#include <iomanip>
#include <Windows.h>
using namespace std;
struct STUDENT
{
	char NAME[20];
	char SURNAME[20];
	char PATRON[20];
	int ENTRANCE;
	int GROUP;
	float MATH;
	float GEOMETRY;
	float ENGLISH;
	float RUSSIAN;
	float MIDDLE;
};
STUDENT students[3];
int Taken{};

void CREATE_BASE()
{
	cout << "Введите имя: " << endl;
	cin >> students[Taken].NAME;
	cout << "Введите Фамилию: " << endl;
	cin >> students[Taken].SURNAME;
	cout << "Введите отчество: \n";
	cin >> students[Taken].SURNAME;
	cout << "Введите год поступления: " << endl;
	cin >> students[Taken].ENTRANCE;
	cout << "Введите группу: \n";
	cin >> students[Taken].GROUP;
	cout << "Введите оценку по математике: \n";
	cin >> students[Taken].MATH;
	cout << "Введите оценку по геометрии: \n";
	cin >> students[Taken].GEOMETRY;
	cout << "Введите оценку по английскому языку: \n";
	cin >> students[Taken].ENGLISH;
	cout << "Введите оценку по русскому языку: \n";
	cin >> students[Taken].RUSSIAN;
	students[Taken].MIDDLE = (students[Taken].MATH + students[Taken].GEOMETRY + students[Taken].ENGLISH + students[Taken].RUSSIAN) / 4;
	Taken++;
}

void PRINT_BASE()
{
	cout << "№---|----ИМЯ----|--ФАМИЛИЯ---|-ОТЧЕСТВО---|--ГОД--|-ГРУППА-||" << endl;
	for (int i = 0; i < 3; i++)
	{	
		cout << setw(4) << i + 1 << setw(12) << students[i].NAME << setw(12) << students[i].SURNAME << setw(12) << students[i].PATRON << setw(6) << students[i].ENTRANCE << endl;
		/*cout << " MATH | GEOM |  ENG | RUS ||\n";
		cout << setw(6) << students[i].MATH << setw(6) << students[i].GEOMETRY << setw(6) << students[i].ENGLISH << setw(6) << students[i].RUSSIAN << endl;*/
	}
}

void PRINT_REQUEST()
{
	STUDENT group_students[3];
	int group;
	int k{};
	cout << "Введите номер группы: \n";
	cin >> group;
	cout << "Этой группе принадлежат студенты: \n";
	for (int i = 0; i < 3; i++)
	{
		if (group == students[i].GROUP)
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

void print_menu()
{
	system("cls");
	cout << "МЕНЮ" << endl;
	cout << "1. Создать БД." << endl;
	cout << "2. Загрузить БД из текстового файла." << endl;
	cout << "3. Загрузить БД из бинарного файла." << endl;
	cout << "4. Вывести БД на экран." << endl;
	cout << "5. Перевести БД в текстовый файл." << endl;
	cout << "6. Перевести текстовый файл с БД в бинарный файл." << endl;
	cout << "7. Добавить запись." << endl;
	cout << "8. Изменить запись." << endl;
	cout << "9. Удалить запись." << endl;
	cout << "10. Сортировать БД." << endl;
	cout << "11. Вывод по запросу." << endl;
	cout << "0. Выход." << endl;
}

int main()
{
	bool cic = true;
	int a{};
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	while (cic) 
	{
		print_menu();
		cin >> a;
		switch (a)
		{
		case (1):
			for (int i = 0; i < 3; i++)
			{
				cout << "Ввод данных студента номер " << i + 1 << endl;
				CREATE_BASE();
				cout << "\n";
			}
			cout << "База данных создана." << endl;
			system("pause");
			break;
		case (2):
			//Загрузить БД из текстового файла
			break;
		case(3):
			// Загрузить БД из бинарного файла
			break;
		case(4):
			PRINT_BASE();
			system("pause");
			break;
		case(5):
			//5. Перевести БД в текстовый файл
			break;
		case(6):
			// Перевести текстовый файл с БД в бинарный файл
			break;
		case(7):
			// Добавить запись
			break;
		case(8):
			// Изменить запись
			break;
		case(9):
			//Удалить запись
			break;
		case(10):
			// Сортировать БД	
			break;
		case(11):
			PRINT_REQUEST();
			system("pause");
			break;
		case(0):
			cout << "Завершаем работу." << endl;
			cic = false;
			break;
		default:
			cout << "Ошибка! Введите корректный номер!" << endl;
			cin.ignore(10, '\n');
		}
	}
}
