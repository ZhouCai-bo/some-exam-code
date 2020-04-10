#include<iostream>
#include<unordered_map>
#include<vector>
#include<string>

using namespace std;

int main(){
	string str;
	getline(cin, str);
	str += " ";
	vector<int> candy;
	int start = 0, end = 0;
	while (end<str.size())
	{
		if (str[end] == ' ')
		{
			candy.push_back(stoi(str.substr(start, end - start)));
			start = end + 1;
		}
		end++;
	}
	unordered_map<int, int> res;
	for (auto a : candy)
	{
		res[a]++;
	}
	int cnt = 0;
	for (auto a : res)
	{
		if (a.first == 0)
        {
            cnt += a.second;
            continue;
        }
		int num = a.first + 1;
		cnt += (a.second / num) * num;
		if (a.second % num)
			cnt += num;
	}
	cout << cnt;
	return 0;
}
