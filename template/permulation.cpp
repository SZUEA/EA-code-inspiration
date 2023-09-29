#include <iostream>
#include <vector>
#include"time.h"
using namespace std;

vector<int> getPrimeNum(int range);

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Solution
{
	vector<vector<string>> ans;
	int max = 0;
	void helper(const vector<string> &str, int index, vector<string> path)
	{
		if (index == str.size())
		{
			int x_ = 0, y_ = 0;
			for (string xx : path)
			{
				vector<string> unit;
				split(xx, ' ', unit);
				int x = stoi(unit.at(0)), y = stoi(unit.at(1));
				x_ += x;
				y_ += y;
			}
			int d = pol(x_, y_);
			if (d > max)
			{
				max = d;
			}
			return;
		}

		helper(str, index + 1, path);
		path.insert(path.begin(), str[index]);
		helper(str, index + 1, path);
	}
	void split(const string &str, const char split, vector<string> &res)
	{
		if (str == "")
			return;
		string strs = str + split;
		size_t pos = strs.find(split);

		while (pos != strs.npos)
		{
			string temp = strs.substr(0, pos);
			res.push_back(temp);
			strs = strs.substr(pos + 1, strs.size());
			pos = strs.find(split);
		}
	}

	int pol(int x, int y)
	{
		return x * x + y * y;
	}
public:
	vector<vector<string>> getAllSubSequences(vector<string> src)
	{
		vector<string> path;
		helper(src, 0, path);
		cout << max;
		return ans;
	}
};

int main()
{
	time_t st,en;
	time(&st);
	freopen("1.in", "r", stdin);
	freopen("1.out", "w", stdout);
	int count;
	string t;
	getline(cin, t);
	count = stoi(t);
	vector<string> ins;
	while (count--)
	{
		string s;
		getline(cin, s);
		ins.push_back(s);
	}
	vector<vector<string>> ans = Solution().getAllSubSequences(ins);
	time(&en);
	cout<<endl<<(st-en);
	return 0;
}

vector<int> getPrimeNum(int range)
{
	vector<int> s;
	for (int i = 2; i <= range; i++)
	{
		for (int j = 2;; j++)
		{
			if (i % j == 0 && j != i)
			{
				break;
			}
			if (i == j)
			{
				s.push_back(i);
				break;
			}
		}
	}
	return s;
}
