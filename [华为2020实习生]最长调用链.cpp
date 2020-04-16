#include<iostream>
#include<vector>
#include<algorithm>
#include<set>
#include<map>

using namespace std;

int maxval = 0;
map<int, int> cache;

int calcu(vector<vector<int>> &call, set<int> &memo, int index, vector<int> &val, int curr);

int main(){
	int n;
	cin >> n;
	vector<int> temp(n + 1);
	for (int i = 1; i <= n; i++)
		cin >> temp[i];
	vector<vector<int>> call(n + 1);
	vector<int> val(n + 1);
	for (int i = 1; i <= n; i++)
	{
		int x, v;
		cin >> x >> v;
		val[x] = v;
		for (int j = 0; j<temp[i]; j++)
		{
			int x;
			cin >> x;
			call[i].push_back(x);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (temp[i] != 0)
		{
			set<int> memo;
			if (calcu(call, memo, i, val, 0) == -1)
			{
				cout << "R";
				return 0;
			}
		}
	}
	cout << maxval;
	return 0;
}

int calcu(vector<vector<int>> &call, set<int> &memo, int index, vector<int> &val, int curr)
{
	if (memo.count(index))
	{
		return -1;
	}
	if (cache.count(index))
	{
		curr += cache[index];
		maxval = max(maxval, curr);
		return curr;
	}
	curr += val[index];
	memo.insert(index);
	if (call[index].size() == 0)
	{
		maxval = max(maxval, curr);
		return curr;
	}
	for (auto v : call[index])
	{
		int temp = calcu(call, memo, v, val, curr);
		if (temp == -1)
			return -1;
		cache[index] = max(cache[index], temp - curr);
		memo.erase(v);
	}
	//no use
	return curr;
}
