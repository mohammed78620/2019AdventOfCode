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
bool check_pair(std::vector<int>& v) {
	std::vector<int>::iterator it;
	it = std::adjacent_find(v.begin(), v.end());
	while (it != v.end()) {
		if (check_if_odd(it, v)) {
			return false;
		}
		
		it = std::adjacent_find(++it, v.end());
	}
	return true;
}
bool check_if_odd(std::vector<int>::iterator &it,const std::vector<int>& v) {
	int count = 0;
	int value = *it;
	
	while (it!=v.end() && *it == value) {
		count++;
		it++;
	}
	if (count % 2 != 0) {
		return false;
	}
	return true;

}
void print_array(const std::vector<int>& v) {
	for (int i = 0; i < v.size(); i++) {
		std::cout << v.at(i);
	}
}
