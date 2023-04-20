/*
 * Remote IoT data monitoring and control using Wi-Fi.c
 *
 * Created: 4/20/2023 4:32:39 AM
 * Author : Omar Elshopky
 */ 

#include <avr/io.h>
#include "include/driver.h"


int main()
{
    initialize_device();
	
    while (1) 
    {
		run_device();
    }
}

