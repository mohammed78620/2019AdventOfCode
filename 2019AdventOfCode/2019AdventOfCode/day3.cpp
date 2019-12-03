#include <iostream>
#include "day3.h"
#include "day2.h"
#include <string>
#include <fstream>
#include <vector>
#include <algorithm>
#include <sstream>
#include <map>
int get_manhattan_distance() {
	std::fstream in("Text2.txt");
	std::string line;
	
	std::map<std::pair<int,int>,int> m;
	std::vector<std::pair<int, int>> v;
	std::map<std::pair<int, int>, int>::iterator it_map;
	std::vector<std::pair<int, int>> v_intersect;
	std::vector<std::pair<int, int>>::iterator it;
	

	int xstart=0;
	int ystart=0;
	while (std::getline(in, line)) {
		auto start = std::find_if_not(line.cbegin(), line.cend(), is_comma);
		while (start != line.cend()) {
			auto end = std::find_if(start, line.cend(), is_comma);
			std::string word(start, end);
			add_to_grid(v, word, xstart, ystart);
			start = std::find_if_not(end, line.cend(), is_comma);
		}
		xstart = 0;
		ystart = 0;
	}
	
	


	for (it = v.begin(); it != v.end(); ++it) {
		if (it->first != 0 && it->second != 0) {
			++m[*it];
		}
		
	}

	for (it_map = m.begin(); it_map != m.end(); ++it_map) {
		if (it_map->second > 1) {
			v_intersect.push_back(it_map->first);
		}
	}
	int min = calculate_Manhattan_distance(v_intersect[0]);
	
	for (it = v_intersect.begin(); it != v_intersect.end();++it) {
		if (calculate_Manhattan_distance(*it) < min) {
			min = calculate_Manhattan_distance(*it);
		}
	}
	

	
	return min;
}
void add_to_grid(std::vector<std::pair<int, int>> &v,std::string word,int &xstart,int &ystart) {
	int num;
	char direction = word[0];
	word = word.substr(1, word.size() - 1);	
	std::stringstream ss(word);
	ss >> num;
	if (direction == 'R') {
		for (int i = 0; i <= num; i++) {
			std::pair<int, int> p(xstart + i , ystart);
			v.push_back(p);
			/*std::cout << p.first << "  " << p.second<<"\n";*/
			/*++m[std::make_pair(xstart + i + 1, ystart)];*/
		}
		xstart = xstart + num ;
		
	}
	else if (direction == 'L') {
		for (int i = 0; i <= num; i++) {
			std::pair<int, int> p(xstart - i , ystart);
			v.push_back(p);
			/*std::cout << p.first << "  " << p.second << "\n";*/
			/*++m[std::make_pair(xstart - i - 1, ystart)];*/

			
		}
		xstart = xstart - num;
	}
	else if (direction == 'U') {
		for (int i = 0; i <= num; i++) {
			std::pair<int, int> p(xstart, ystart + i );
			v.push_back(p);
			/*std::cout << p.first << "  " << p.second << "\n";*/
			/*++m[std::make_pair(xstart , ystart+ i + 1)];*/

			
		}
		ystart = ystart + num ;
	}
	else if (direction == 'D') {
		for (int i = 0; i <= num; i++) {
			std::pair<int, int> p(xstart, ystart - i );
			v.push_back(p);
			/*std::cout << p.first << "  " << p.second << "\n";*/
			/*++m[std::make_pair(xstart , ystart - i - 1)];*/

			
		}
		ystart = ystart - num ;
	}
	
	

}
void print_array(std::vector<std::pair<int, int>>v) {
	std::vector<std::pair<int, int>>::iterator it;
	for (it = v.begin(); it != v.end();++it) {
		std::cout << "x value is: " << it->first << " y value is: " << it->second<<"\n";
	}
}
void print_map(std::map<std::pair<int, int>,int> &m) {
	std::map<std::pair<int, int>,int>::iterator it;
	for (it = m.begin(); it != m.end(); ++it) {
		std::cout << "x value is yes: " << it->first.first << " y value is: " << it->first.second <<" number of time mentioned: "<<it->second <<"\n";
	}
}
int calculate_Manhattan_distance(std::pair<int, int> &p) {
	return abs(0 - p.first) + abs(0 - p.second);
}
