/*
Author: Michelle Wen
Course: CSCI-135
Instructor: Mike Zamansky
Assignment: Lab 3 Task A,B,C,D

Main function to test and also input.
*/

#include <iostream>
#include "reservoir.h"
int main()
{
	get_east_storage("01/09/2018");
	get_east_storage("05/25/2018");
	get_east_storage("10/11/2018");
	get_min_east();
	get_max_east();

	return 0;
}
