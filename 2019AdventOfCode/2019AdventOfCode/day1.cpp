#include "day1.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
int fuel_sum() {
	std::fstream in("Text.txt");
	std::string line;
	double num;
	double fuelnum;
	int sum = 0;
	

	while (std::getline(in, line)) {
		std::stringstream ss(line);
		ss>> num;
		num = std::floor(num / 3) - 2;
		sum += num + fuel_fuel_sum(num);

		
	}
	return sum;
}
double fuel_fuel_sum(double n) {
	n = std::floor(n / 3) - 2;
	if (n < 1 ) {
		return 0;
	}
	
	return fuel_fuel_sum(n)+n;
}