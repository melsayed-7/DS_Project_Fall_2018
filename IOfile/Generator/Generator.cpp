// Generator.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>



using namespace std;

int* type_generator(int no_of_enemies)
{
	int* array = new int[no_of_enemies];
	int random = 0;
	for (int i = 0; i < no_of_enemies; i++)
	{
		random = rand() % 100 + 1;
		if (random > 0 && random <= 20)		array[i] = 3;
		else if (random > 20 && random <= 50) array[i] = 2;
		else if (random > 50 && random <= 100) array[i] = 1;
	}

	return array;
}



char region_generator()
{
	int random = rand() % 4 + 1;
	switch (random)
	{
	case 1 : return 'A';
	case 2: return 'B';
	case 3: return 'C';
	case 4: return 'D';
	}
}


double power_generator(int type)
{
	switch (type)
	{
	case 1: return 30;
	case 2: return 30;
	case 3: return 30;
	}
}



int main()
{
	int no_enemies = 20;
	int* type_array = new int[no_enemies];
	type_array = type_generator(no_enemies);
	char region;
	double power;

	for (int i = 0; i < no_enemies; i++)
	{
		cout << type_array[i] << endl;
	}


	double tower_health = 200;
	int tower_no_of_attacks = 10;
	double tower_power = 50;

	double* health_array = new double[no_enemies];
	double* power_array = new double[no_enemies];
	int* reload_array = new int[no_enemies];
	char* region_array = new char[no_enemies];

	ofstream out_file;
	out_file.open("input_25_nov.txt");


	out_file << tower_health << "\t" << tower_no_of_attacks << "\t" << tower_power;



	for (int i = 0; i < no_enemies; i++)
	{
		region = region_generator();
		power = power_generator(type_array[i]);
	}


}