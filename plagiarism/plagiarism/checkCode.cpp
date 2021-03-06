#include "checkCode.h"



int checkCode::LevenshtainDist(string a, string b)
{
	vector<int> d(b.length() + 1, 0), temp(b.length() + 1, 0);
	d[0] = 0;
	for (int j = 1; j <= b.length(); ++j)
		d[j] = d[j - 1] + 1;
	
	for (int i = 1; i <= a.length(); ++i) 
	{
		temp[0] = d[0] + 1;
		for (int j = 1; j <= b.length(); ++j)
		{
			int k = !(b[j-1] == a[i-1]);
			temp[j] = min(d[j] + 1, min(temp[j - 1] + 1, d[j - 1] + k));
		}
		d = temp;
	}
	return d[b.length()];
}

pair<int,int> checkCode::LevenshtainDistOfAll(checkCode &checkVal)
{
	vector<string> checkCodStr = checkVal.getCode();
	int ans = 0;
	for (int i = 0; i < min(checkCodStr.size(), code.size()); ++i) {
		ans += LevenshtainDist(checkCodStr[i], code[i]);
	}
	return {ans, abs(int(checkCodStr.size())-int(code.size()))};
}

void checkCode::parseCode(ifstream &f)
{
	string ans = "";
	for (; !f.eof();)
	{
		getline(f, ans);
		if (ans != "") 
		{
			code.push_back(ans);
		}
	}
	all_size = 0;
	for (int j = 0; j < code.size(); ++j)
	{
		string s = code[j];
		ans = "";
		for (int i = 0; i < s.length(); ++i)
		{
			if ((s[i] == ' ' || s[i] == '\t') && (i == 0 || s[i - 1] == ' ' || s[i - 1] == '\t'))
				continue;
			ans += s[i];
		}	
		code[j] = ans;
		all_size += ans.length();
	}
}

checkCode::checkCode(ifstream &a)
{
	parseCode(a);
}

double checkCode::plagiarism(checkCode checkVal)
{
	pair<int,int> forAns1= LevenshtainDistOfAll(checkVal);
	int sizeDiff = abs(all_size - checkVal.getSize());

	double ans1;
	if (forAns1.first == 0)
		ans1 = 100.0;
	else
		ans1 = (double(sizeDiff + 0.99) / (double(forAns1.first) + 1.0) + 1.0 / (double(forAns1.second) + 1.0)) / 2.0*100.0;
	//TGraph graph1(*this), graph2(checkVal);
	//double ans2 = compareGraphs(graph1, graph2);
	//double ans3 = checkHash(code, checkVal);

	//return (ans1 + ans2 + ans3)/3.0;
	return ans1;
}

vector<string> checkCode::getCode()
{
	return code;
}

int checkCode::getSize()
{
	return all_size;
}


checkCode::~checkCode()
{
}
