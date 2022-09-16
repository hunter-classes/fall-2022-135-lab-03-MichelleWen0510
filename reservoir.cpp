/*
Author: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 3 Task A,B,C

get_east_storage Function to get gallons using date given.
get_min_east Function to get minimum.
get_max_east Function to get maximum.
compare_basins Which basin is higher.
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
		return eastSt;
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
	return previous;
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
        return previous;
        
        fin.close();
	return 0;
}

std::string compare_basins(std::string date)
{
        std::ifstream fin("Current_Reservoir_Levels.tsv");
        std::string junk;
        getline(fin, junk);

        std::string day;
        double eastSt, eastEl, westSt, westEl;
	double curEast, curWest;

        while(fin >> day >> eastSt >> eastEl >> westSt >> westEl) {

        fin.ignore(INT_MAX, '\n');
        if(day==date)
        {
		if(eastEl>westEl){                
			return "East";
       		} else if (westEl>eastEl){
			return "West";
		} else {
			return "Equal";
		}
	}
        }
        fin.close();
        return "a";
}
