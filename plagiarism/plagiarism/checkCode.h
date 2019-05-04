#pragma once
#include <string>
#include <fstream>
#include <algorithm>
#include <vector>
#include <cmath>
#include <iostream>

using namespace std;

class checkCode
{
	vector<string> code;
	int all_size;
	int LevenshtainDist(string a, string b);
	pair<int, int> LevenshtainDistOfAll(checkCode &check_cur);
	void parseCode(ifstream &s);
public:
	checkCode(ifstream &a);
	double plagiarism(checkCode checkVal);
	vector<string> getCode();
	int getSize();
	~checkCode();
};

