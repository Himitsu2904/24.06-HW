//#include "printer.h"
//#include <string.h>
//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
//printer::printer(int a)
//{
//    max_queue_length = a;
//    file_queue = new string[max_queue_length];
//    priority = new int[max_queue_length];
//    queue_length = 0;
//}
//
//void printer::Add_to_queue(string file, int prio)
//{
//    if (!IsFull())
//    {
//        file_queue[queue_length] = file;
//        priority[queue_length] = prio;
//        queue_length++;
//    }
//}
//
//string printer::Get()
//{
//    if (!IsEmpty())
//    {
//        int max_pri = 0, max_prio_pos = 0;
//        for (int i = 0; i < queue_length; i++)
//        {
//            if (priority[i] > max_pri)
//            {
//                max_pri = priority[i];
//                max_prio_pos = i;
//            }
//        }
//        string temp = file_queue[max_prio_pos];
//        for (int i = max_prio_pos; i < queue_length - 1; i++)
//        {
//            file_queue[i] = file_queue[i + 1];
//            priority[i] = priority[i + 1];
//        }
//        queue_length--;
//        return temp;
//    }
//    else return nullptr;
//}
//
//void printer::Clear()
//{
//    queue_length = 0;
//}
//
//bool printer::IsEmpty()
//{
//    return queue_length == 0;
//}
//
//bool printer::IsFull()
//{
//    return queue_length == max_queue_length - 1;
//}
//
//int printer::GetCount()
//{
//    return queue_length + 1;
//}
//
//void printer::Print(string file)
//{
//    file += ".txt";
//    FILE* f = fopen(file.c_str(), "rt");
//    if (f == NULL)
//    {
//        cout << "File " << file << " can't be opened.";
//        return;
//    }
//    char buff[100];
//    while (fgets(buff, 100, f))
//    {
//        cout << buff;
//    }
//    fclose(f);
//}
//
//printer::~printer()
//{
//    delete[] file_queue;
//    delete[] priority;
//}
