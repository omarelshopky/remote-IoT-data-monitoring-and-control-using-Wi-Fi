/*
 * remote-IoT-data-monitoring-and-control-using-Wi-Fi.cpp
 *
 * Created: 4/20/2023 7:48:39 A
 * Author: Omar Elshopky
 */ 

#include "include/driver.h"


int main()
{
	initialize_device();
	
	while (1)
	{
		run_device();
	}
}
