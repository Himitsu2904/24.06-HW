#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "printer_alternative.h"
using namespace std;

int main()
{
	printer_alternative Laserjet(5);
	Laserjet.Add("F1", 1);
	Laserjet.Add("F3", 4);
	Laserjet.Add("F5", 2);
	Laserjet.Print();
	Laserjet.Statistics();
	//cout << "Welcome to printer imitation." << endl;
	//int operation = 0;
	//while(operation!=5)
	//cout << "Which operation would you like to do ? " << endl;
	//cout << "1. Print\n2. Add file\n3. Delete file\n4. Veiw printing queue\n5. Show statistics of printing\n6. Stop printing" << endl;
	//cin >> operation;
	//char buff[100];
	//switch (operation)
	//{
	//case 1:
	//	//cout << "---";
	//case 2:
	//	cout << "Enter file name: ";
	//	gets_s(buff, 100);
	//	int prio = 0;
	//	while (prio < 0)
	//	{
	//		cout << "Enter file's priority (>0): ";
	//		cin.ignore();
	//		cin >> prio;
	//	}
	//	char* name = new char[strlen(buff) + 1];
	//	strcpy(name, buff);
	//	name[strlen(buff)] = '\0';
	//	Laser.Add(name, prio);
	//case 3:

	//}
}