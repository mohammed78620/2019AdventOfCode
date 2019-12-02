#include <iostream>
#include "day2.h"
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
int get_position0(int noun,int verb) {
	std::vector<int> v;
	std::vector<int>::iterator it;
	std::fstream in("Text1.txt");
	std::string line;
	std::string word;
	int x;
	std::getline(in, line);
	auto start = std::find_if_not(line.cbegin(), line.cend(), is_comma);
	//puts input values into vector v
	while (start != line.cend()) {
		auto end = std::find_if(start, line.cend(), is_comma);
		word = std::string(start, end);
		std::stringstream ss(word);
		ss >> x;
		v.push_back(x);
		
		start = std::find_if_not(end, line.cend(), is_comma);
	}

	//

	//it = v.begin();
	//while (it != v.begin()) {
	//	if (*it == 99) {
	//		break;
	//	}
	//	else if ((*it) == 1) {
	//		*(it + 4)= *(it + 2) + *(it + 3);
	//		it+=4;
	//	}
	//	else if ((*it) == 2) {
	//		*(it + 4) = *(it + 2) * *(it + 3);
	//		it += 4;
	//	}
	//}

	v.at(1) = noun;
	v.at(2) = verb;

	for (int i = 0; i < v.size(); i+=4) {
		if (v.at(i) == 99 && v.at(0) == 19690720) {
			std::cout << 100 * v.at(1) + v.at(2) <<"\n";
			return 19690720;
		}
		else if (v.at(i) == 1) {
			v.at(v.at(i + 3)) = v.at(v.at(i + 1)) + v.at(v.at(i + 2));
		}
		else if (v.at(i) == 2) {
			v.at(v.at(i + 3)) = v.at(v.at(i + 1)) * v.at(v.at(i + 2));
		}
	}

	//for (int i = 0; i < v.size(); i++) {
	//	std::cout << v.at(i)<<"\n";
	//}
	return v.at(0);
}
bool is_comma(char c) {
	return c == ',';
}
void check_equals() {


	for (int i = 0; i <= 99;i++) {
		for (int j = 0; j <= 99;j++) {
			if (get_position0(i, j) == 19690720) {
				std::cout << "YES IT WORKS";
				return;
			}
		}
	}
}

