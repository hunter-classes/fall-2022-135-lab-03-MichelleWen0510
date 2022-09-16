/*
Author: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 3 Task A,B,C,D

Main function to test and also input.
*/

#include <iostream>
#include "reservoir.h"
#include "reverseorder.h"
int main()
{
	std::cout<< "01/09/2018 "+std::to_string(get_east_storage("01/09/2018"))<<std::endl;
	std::cout<< "05/17/2018 "+std::to_string(get_east_storage("05/17/2018"))<<std::endl;
	std::cout<< "12/20/2018 "+std::to_string(get_east_storage("12/20/2018"))<<std::endl;
	std::cout<< "Min "+std::to_string(get_min_east())<<std::endl;
	std::cout<< "Max "+std::to_string(get_max_east())<<std::endl;
	std::cout<< "01/01/2018 "+compare_basins("01/01/2018")<<std::endl;
	std::cout<< "08/13/2018 "+compare_basins("08/13/2018")<<std::endl;
	std::cout<< "12/23/2018 "+compare_basins("12/23/2018")<<std::endl;
	return 0;
}
