#pragma once
class printer_alternative
{
	char** file_queue;
	int* priority;
	char** statistics;
	int max_queue_length;
	int queue_length;
	int stat_ind;
public:
	printer_alternative(int a);
	void Add(const char* file, int prio);
	const char* Pop();
	void Clear();
	bool IsEmpty();
	bool IsFull();
	int GetCount();
	void Print();
	void Queue();
	void Statistics();
	~printer_alternative();
};

