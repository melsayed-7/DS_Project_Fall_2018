// IOfile.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include"Queue.h"
#include<string>

using namespace std;

Queue<int*>* get_file_2_queue(string str = "input_file.txt")// this function takes the input file and get the
{
	ifstream input_file(str.c_str());
	if (!input_file)
	{
		cout << "the file name is not correct";
		return nullptr;
	}

	int col = 7;
	int*tower_vector = new int[col];
	Queue<int*> *enemy_queue = new Queue<int*>;

	for (int i = 0; i < 3; i++)
	{
		input_file >> tower_vector[i];
	}
	for (int i = 3; i < 7; i++)
	{
		tower_vector[i] = 0;
	}
	enemy_queue->enque(tower_vector);
	int dummy;
	do
	{
		input_file >> dummy;
		if (dummy != -1)
		{
			int*enemy_vector = new int[col];
			enemy_vector[0] = dummy;
			for (int i = 1; i < 7; i++)
			{
				input_file >> enemy_vector[i];
			}
			enemy_queue->enque(enemy_vector);
		}

	} while (dummy != -1);

	input_file.close();
	return enemy_queue;

}


using namespace std;

int main()
{
	// this is a test and demo for how to use the function
	Queue<int*> *enemy_queue = get_file_2_queue();

	int*print_vector = new int[7];
	int size = enemy_queue->getsize();

	for (int i = 0; i < size; i++)
	{
		print_vector = enemy_queue->deque();
		for (int i = 0; i < 7; i++)
		{
			cout << print_vector[i] << " ";
		}
		cout << endl;
	}
}
