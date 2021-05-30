#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <ctime>
using namespace std;
enum Special { KN, IN, ME, FI, WT };
string Specialities[5] = { "KN","IN","ME","FI","TTI" };
struct Student {
	string LastName;
	int Curs;
	int Fiz;
	int Math;
	int Informatika;
	Special Type_Special;
};

void Print(Student* students, const int size);
void AutoInput(Student* students, int size);
void UserInput(Student* students, int size);
void PhysicSort(Student* students, int size);
int* IndexSort(Student* students, int size);
void IndexPrint(Student* students, int size);
int Find(Student* students, int size);
int main()
{
	srand(time(NULL));
	Student* arr = new Student[0];
	int size = 0;
	int choice;

	cout << "Enter array size: ";
	cin >> size;
	arr = new Student[size];
	bool initialized = false;
	do
	{
		cout << "====Menu====" << endl;
		cout << "1.Create a list of students." << endl;
		cout << "2.Print array" << endl;
		cout << "3.Sort your list physically" << endl;
		cout << "4.Sort by index method" << endl;
		cout << "5.Find a student." << endl;
		cout << endl;
		cout << "Enter your choice: "; cin >> choice;
		cout << endl;
		switch (choice)
		{
		case 1:
		{
			initialized = true;
			cout << endl;
			//AutoInput(arr, size);
			UserInput(arr, size);
			Print(arr, size);
			break;
		}
		case 2:
		{
			if (!initialized)
			{
				cout << "You try to print a not initialized array!" << endl;
				break;
			}
			else
			{
				Print(arr, size);
				cout << endl;
			}
			break;
		}
		case 3:
		{
			cout << endl;
			PhysicSort(arr, size);
			cout << "done" << endl;
			cout << endl;
			Print(arr, size);
			cout << endl;
			break;
		}
		case 4:
		{
			if (!initialized)
			{
				cout << "You try to print a not initialized array!" << endl;
				break;
			}
			else {
				cout << endl;
				IndexPrint(arr, size);
				cout << "done" << endl;
				cout << endl;
			}
			break;
		}
		case 5:
		{
			if (!initialized)
			{
				cout << "You try to print a not initialized array!" << endl;
				break;
			}
			else {
				cout << endl;	cout << endl;
				int i = Find(arr, size);
				if (i != -1)
				{
					cout << i << "\t| " << arr[i].LastName;
					cout << " |\t" << arr[i].Curs;
					cout << " |\t" << Specialities[(int)arr[i].Type_Special] << "\t";
					cout << " |\t" << arr[i].Fiz;
					cout << " |\t" << arr[i].Informatika;
					cout << " |\t" << arr[i].Math << "|";
					cout << endl;
				}
				else
					cout << "Could not find a student." << endl;
				cout << "done" << endl;
				cout << endl;
				cout << endl;
			}
			break;
		}
		default:
		{
			cout << "You entered the incorrect command." << endl;
			break;
		}
		}
	} while (choice != 0);
	system("pause");
}
void Print(Student* students, int size)
{
	cout << endl;
	cout << "===================================================================" << endl;
	cout << "Number \t|Name\t|Course   |\tSpec\t | Physics|IT\t  |Math\t|" << endl;
	cout << "===================================================================" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << i << "\t| " << students[i].LastName;
		cout << " |\t" << students[i].Curs;
		cout << " |\t" << Specialities[(int)students[i].Type_Special] << "\t";
		cout << " |\t" << students[i].Fiz;
		cout << " |\t" << students[i].Informatika;
		cout << " |\t" << students[i].Math << "|";
		cout << endl;
	}
	cout << "===================================================================" << endl;
	cout << endl << endl;
}
void AutoInput(Student* students, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		students[i].Curs = rand() % 5 + 1;
		students[i].Fiz = rand() % 5 + 1;
		students[i].Math = rand() % 5 + 1;
		cout << "Enter students names" << endl;
		students[i].LastName = "UserNAMETEST";
		students[i].Informatika = rand() % 4 + 1;
		students[i].Type_Special = (Special)(rand() % 5);
	}
}
void UserInput(Student* students, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << "Last Name: "; cin >> students[i].LastName;
		cout << "Course: "; cin >> students[i].Curs;
		int t;
		cout << "(O.KN\n1.IN\n2.ME\n3.FI\n4.TTI)";
		cout << "Speciality: "; cin >> t;
		switch (t)
		{
		case 0:
		{
			students[i].Type_Special = Special::KN;
			break;
		}
		case 1:
		{
			students[i].Type_Special = Special::IN;
			break;
		}
		case 2:
		{
			students[i].Type_Special = Special::ME;
			break;
		}
		case 3:
		{
			students[i].Type_Special = Special::FI;
			break;
		}
		case 4:
		{
			students[i].Type_Special = Special::WT;
			break;
		}
		default:
		{
			cout << "You entered the incorrect data!" << endl;
			return;
		}
		}
		cout << "Physeics mark: "; cin >> students[i].Fiz;
		cout << "Math mark: "; cin >> students[i].Math;
		cout << "IT mark: "; cin >> students[i].Informatika;
	}
}
int* IndexSort(Student* students, int size)
{
	int* I = new int[size];
	for (size_t i = 0; i < size; i++)
	{
		I[i] = i;
	}

	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			int Maths = students[I[j]].Math;
			int Maths1 = students[I[j + 1]].Math;

			if (Specialities[students[I[j]].Type_Special][0] >
				Specialities[students[I[j + 1]].Type_Special][0])
				swap(I[j], I[j + 1]);

			if ((Specialities[students[I[j]].Type_Special][0] ==
				Specialities[students[I[j + 1]].Type_Special][0])
				&& (Maths > Maths1))
				swap(I[j], I[j + 1]);

			if ((Specialities[students[I[j]].Type_Special][0] ==
				Specialities[students[I[j + 1]].Type_Special][0])
				&& (Maths == Maths1)
				&& (students[I[j]].LastName[0] > students[I[j + 1]].LastName[0]))
				swap(I[j], I[j + 1]);

		}
	}
	return I;
}
void PhysicSort(Student* students, int size)
{
	for (size_t i = 0; i < size; i++)
	{
		for (size_t j = 0; j < size - i - 1; j++)
		{
			int Maths = students[j].Math;
			int Maths1 = students[j + 1].Math;

			if (Specialities[students[j].Type_Special][0] >
				Specialities[students[j + 1].Type_Special][0])
				swap(students[j], students[j + 1]);

			if ((Specialities[students[j].Type_Special][0] ==
				Specialities[students[j + 1].Type_Special][0])
				&& (Maths > Maths1))
				swap(students[j], students[j + 1]);

			if ((Specialities[students[j].Type_Special][0] ==
				Specialities[students[j + 1].Type_Special][0])
				&& (Maths == Maths1)
				&& (students[j].LastName[0] > students[j + 1].LastName[0]))
				swap(students[j], students[j + 1]);
		}
	}
}
void IndexPrint(Student* students, int size)
{
	int* B = IndexSort(students, size);
	cout << "Sorted Array: " << endl;
	cout << "===================================================================" << endl;
	cout << "Number \t|Name\t|Course   |\tSpec\t | Physics|IT\t  |Math\t|" << endl;
	cout << "===================================================================" << endl;
	for (size_t i = 0; i < size; i++)
	{
		cout << i << "\t| " << students[B[i]].LastName;
		cout << " |\t" << students[B[i]].Curs;
		cout << " |\t" << Specialities[(int)students[B[i]].Type_Special] << "\t";
		cout << " |\t" << students[B[i]].Fiz;
		cout << " |\t" << students[B[i]].Informatika;
		cout << " |\t" << students[B[i]].Math << "|";
		cout << endl;
	}
	cout << "===================================================================" << endl;
	cout << endl << endl;
}

int Find(Student* students, int N)
{
	cout << "Last Name: ";
	string ln; cin >> ln;
	cout << "Maths mark: ";
	int MathsMark; cin >> MathsMark;
	int L = 0, R = N - 1, m;     do {
		m = (L + R) / 2;
		if ((students[m].Math)
			== MathsMark && students[m].LastName == ln)
			return m;
		if ((((students[m].Math)) < MathsMark) || ((students[m].Math)
			== MathsMark && students[m].LastName == ln))
		{
			L = m + 1;
		}
		else { R = m - 1; }
	} while (L <= R);
	return -1;
}
