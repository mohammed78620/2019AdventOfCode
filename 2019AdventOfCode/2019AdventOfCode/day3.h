#ifndef DAY_3
#define DAY_3
#include <iostream>
#include <string>
#include <vector>
#include <map>
int get_manhattan_distance();
void add_to_grid(std::vector<std::pair<int, int>>& m, std::string word, int& xstart, int& ystart);
void print_array(std::vector<std::pair<int, int>>m);
void print_map(std::map<std::pair<int, int>, int>& m);
int calculate_Manhattan_distance(std::pair<int, int>& p);

#endif // !DAY_3
