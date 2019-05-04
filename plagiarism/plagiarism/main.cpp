#include "checkCode.h"

#include <iostream>
#include <fstream>

using namespace std;


int main()
{
	ifstream f1("codeforces_670_a.cpp");
	checkCode a(f1);
	f1.close();
	f1.open("codeforces_670_a_111.cpp");
	checkCode b(f1);
	f1.close();
	vector<string> aa = a.getCode();
	vector<string> bb = b.getCode();
	for (int i = 0; i < aa.size(); ++i)
		cout << aa[i] << '\n';
	for (int i = 0; i < bb.size(); ++i)
		cout << bb[i] << '\n';
	
	int x = a.plagiarism(b);
	system("pause");
	

}