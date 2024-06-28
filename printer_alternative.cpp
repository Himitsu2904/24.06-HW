#define _CRT_SECURE_NO_WARNINGS
#include "printer_alternative.h"
#include <iostream>
using namespace std;

printer_alternative::printer_alternative(int a)
{
	max_queue_length = a;
	file_queue = new char*[max_queue_length];
	for (int i = 0; i < max_queue_length; i++)
	{
		file_queue[i] = nullptr;
	}
	priority = new int[max_queue_length];
	statistics = new char* [max_queue_length];
	for (int i = 0; i < max_queue_length; i++)
	{
		statistics[i] = nullptr;
	}
	queue_length = 0;
	stat_ind = 0;
}

void printer_alternative::Add(const char* file, int prio)
{
	if (!IsFull())
	{
		if (file_queue[queue_length] != nullptr)
		{
			delete[] file_queue[queue_length];
		}
		file_queue[queue_length] = new char[strlen(file) + 1];
		strcpy(file_queue[queue_length], file);
		file_queue[queue_length][strlen(file)] = '\0';
		priority[queue_length] = prio;
		queue_length++;
	}
}

const char* printer_alternative::Pop()
{
	if (!IsEmpty())
	{
		int max_pri = 0, max_prio_pos = 0;
		for (int i = 0; i < queue_length; i++)
		{
			if (priority[i] > max_pri)
			{
				max_pri = priority[i];
				max_prio_pos = i;
			}
		}
		char* temp = new char[strlen(file_queue[max_prio_pos]) + 1];
		strcpy(temp, file_queue[max_prio_pos]);
		temp[strlen(file_queue[max_prio_pos])] = '\0';
		for (int i = max_prio_pos; i < queue_length - 1; i++)
		{
			delete[] file_queue[i];
			int size = strlen(file_queue[i + 1]);
			file_queue[i] = new char[size + 1];
			strcpy(file_queue[i], file_queue[i + 1]);
			file_queue[i][size] = '\0';
			priority[i] = priority[i + 1];
		}
		queue_length--;
		return temp;
	}
	else return nullptr;
}

void printer_alternative::Clear()
{
	queue_length = 0;
}

bool printer_alternative::IsEmpty()
{
	return queue_length == 0;
}

bool printer_alternative::IsFull()
{
	return queue_length == max_queue_length;
}

int printer_alternative::GetCount()
{
	return queue_length + 1;
}

void printer_alternative::Print()
{
	if (!IsEmpty())
	{
		int max_pri = 0, max_prio_pos = 0;
		for (int i = 0; i < queue_length; i++)
		{
			if (priority[i] > max_pri)
			{
				max_pri = priority[i];
				max_prio_pos = i;
			}
		}
		char* name = new char[strlen(file_queue[max_prio_pos]) + 1];
		strcpy(name, file_queue[max_prio_pos]);
		name[strlen(name)] = '\0';
		char* file = new char[strlen(file_queue[max_prio_pos]) + 1];
		strcpy(file, file_queue[max_prio_pos]);
		strcat(file, ".txt");
		file[strlen(file)] = '\0';
		cout << "Enter username: ";
		char buff[100];
		gets_s(buff, 100);
		cin.ignore();
		if (stat_ind == max_queue_length)
		{
			for (int i = 0; i < max_queue_length - 1; i++)
			{
				delete[] statistics[i];
				statistics[i] = new char[strlen(statistics[i + 1]) + 1];
				strcpy(statistics[i], statistics[i + 1]);
				statistics[i][strlen(statistics[i + 1])] = '\0';
			}
			stat_ind--;
		}
		if (statistics[stat_ind] != nullptr)
		{
			delete[] statistics[stat_ind];
		}
		statistics[stat_ind] = new char[strlen(buff) + 1];
		strcpy(statistics[stat_ind], buff);
		statistics[stat_ind][strlen(buff)] = '\0';
		char date[50] = {};
		time_t Time = time(nullptr);
		ctime_s(date, sizeof(date) / sizeof(date[0]), &Time);
		strcat(statistics[stat_ind], "\t\"");
		strcat(statistics[stat_ind], name);
		strcat(statistics[stat_ind], "\"\t");
		strcat(statistics[stat_ind], date);
		FILE* f = fopen(file, "rt");
		if (f == NULL)
		{
			cout << "File " << file_queue[max_prio_pos] << " can't be opened." << endl;
			return;
		}
		while (fgets(buff, 100, f))
		{
			cout << buff;
		}
		cout << endl;
		fclose(f);
		Pop();
		stat_ind++;
		delete[] name;
		//delete[] file;
	}
	else cout << "No files to print." << endl;
}

void printer_alternative::Queue()
{
	if (!IsEmpty())
	{
		cout << "File queue with priority:" << endl;
		for (int i = 0; i < queue_length; i++)
		{
			cout << file_queue[i] << " - " << priority[i] << endl;
		}
	}
	else cout << "No files in queue." << endl;
}

void printer_alternative::Statistics()
{
	cout << "Printing statistics (last " << max_queue_length << " prints):" << endl;
	cout << "USER || FILE || DATE" << endl;
	for (int i = 0; i < stat_ind; i++)
	{
		if (statistics[i] != nullptr)
		{
			cout << statistics[i];
		}
	}
}

printer_alternative::~printer_alternative()
{
	for (int i = 0; i < max_queue_length; i++)
	{
		if (file_queue[i] != nullptr)
		{
			delete[] file_queue[i];
		}
	}
	delete[] file_queue;
	delete[] priority;
	for (int i = 0; i < max_queue_length; i++)
	{
		if (statistics[i] != nullptr)
		{
			delete[] statistics[i];
		}
	}
	delete[] statistics;
}
