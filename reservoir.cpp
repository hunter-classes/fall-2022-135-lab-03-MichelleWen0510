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

double get_min_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
	std::string junk;
	getline(fin, junk);
	
	std::string date;
        double eastSt, eastEl, westSt, westEl, previous;
	int line=0;

        while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {

        fin.ignore(INT_MAX, '\n');
        
	if(line==0)
	{
		previous=eastSt;
		line++;
	}
	if(eastSt<previous)
	{
		previous=eastSt;
	}
        }
	std::cout << "Minimum "+std::to_string(previous) << std::endl;
        fin.close();

	return 0;
}

double get_max_east()
{
	std::ifstream fin("Current_Reservoir_Levels.tsv");
        std::string junk;
        getline(fin, junk);
        
        std::string date;
        double eastSt, eastEl, westSt, westEl, previous;
	int line=0;
        
        while(fin >> date >> eastSt >> eastEl >> westSt >> westEl) {

        fin.ignore(INT_MAX, '\n');
        
	if(line==0)
        {
                previous=eastSt;
                line++;
        }
        if(eastSt>previous)
        {
                previous=eastSt;
        }
        }
        std::cout << "Maximum "+std::to_string(previous) << std::endl;
        
        fin.close();
	return 0;
}

