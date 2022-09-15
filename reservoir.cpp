/*
Author: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 3 Task A

Function to get gallons using date given.
*/

#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reservoir.h"

double get_east_storage(std::string date)
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	if(fin.fail()){
		std::cout << "File cannot be opened for reading." << std::endl;
		exit(1);
	}
	std::string junk;
	getline(fin, junk);
	
	std::string day;
	double eastSt, eastEl, westSt, westEl;

	while(fin >> day >> eastSt >> eastEl >> westSt >> westEl) {
	
	fin.ignore(INT_MAX, '\n');
	if(day==date)
	{
		std::cout << date + " " + std::to_string(eastSt) << std::endl;
	}
	}	
	fin.close();
	return 0;
}
