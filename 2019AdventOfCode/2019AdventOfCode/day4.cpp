#include "day4.h"

#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
int count_num_password() {
	int count = 0;
	int num;
	std::vector<int> v;
	for (int i = 265275; i <= 781584; i++) {
		num = i;
		for (int j = num;j>0; j /= 10) {
			int value = j % 10;
			v.push_back(value);
		}
		std::reverse(v.begin(), v.end());
		if (check_increase(v) && check_pair(v)) {
			count++;
		}

		v.erase(v.begin(), v.end());
	}


	
	
	

	
	return count;
}
bool check_increase(const std::vector<int>& v) {
	
	for (int i = 0; i < v.size(); i++) {
		int j = i;
		for (; j < v.size(); j++) {
			if (v.at(i) > v.at(j)) {
				return false;
			}
		}
	}
	return true;
}
bool check_pair(const std::vector<int>& v) {
	std::vector<int>::const_iterator it;
	it = std::adjacent_find(v.begin(), v.end());
	while (it != v.end()) {
		if (*(it + 2) == *it && *(it + 3) != *it) {
			return false;
		}
		it++;
		it = std::adjacent_find(v.begin(), v.end());
	}

	if (std::adjacent_find(v.begin(), v.end()) != v.end()) {
		return true;
	}
	return false;
}
void print_array(const std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i);
	}
}
