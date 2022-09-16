uthor: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 3 Task D

Print out dates and elevation in reserve for west.
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <climits>
#include "reverseorder.h"

void reverse_order(std::string date1, std::string date2)
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
	std::string date[];
	std::string west[];
	int i=0;

        while(fin >> day >> eastSt >> eastEl >> westSt >> westEl) {

        fin.ignore(INT_MAX, '\n');
        date[i]=day;
	west[i]=std::to_string(westEl);
	i++
        }
	int start,end;
	for(int j=0;j<sizeof(date)/sizeof(date[0]);j++)
	{
		if(date[j]==date1)
		{start=j;}
		if(date[j]==date2)
		{end=j;}
	}
	for(int k=end;k>=start;k--)
	{
		std::cout << date[k] << west[k] << std::endl;
	}



        
	fin.close();
}
