#pragma once
#include "Data_strutres_in_use/Queue/Queue.h"
#include <iostream>
#include <fstream>
#include<string>

using namespace std;
Queue<int*>* get_file_2_queue(string str = "input_file_test.txt")// this function takes the input file and get the data
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

