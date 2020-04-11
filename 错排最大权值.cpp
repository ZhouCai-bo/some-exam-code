#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
//#include<set>

using namespace std;

int minval;
int findpos(vector<int> &curr, int x);
int helper(map<int, int> &v, vector<int> &curr);
bool judge(vector<int> &curr);

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		minval = INT_MAX;
		int n;
		int temp;
		cin >> n;
		vector<int> nums(n);
		map<int, int> v;
		for (int i = 0; i<n; i++)
		{
			//考虑元素序号即可
			cin >> temp;
			nums[i] = i;
		}
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		vector<int> curr(nums.begin(), nums.end());
		while (next_permutation(curr.begin(), curr.end()))
		{
			if (judge(curr))
				minval = min(minval, helper(v, curr));
		}
		cout << minval << endl;
	}
	return 0;
}

bool judge(vector<int> &curr)
{
	for (int i = 0; i < curr.size(); i++)
	{
		if (curr[i] == i)
			return false;
	}
	return true;
}

int helper(map<int, int> &v, vector<int> &curr)
{
	int val = 0;
	for (int i = 0; i<curr.size(); i++)
	{
		val += v[i] * abs(i - findpos(curr, i));
	}
	return val;
}

int findpos(vector<int> &curr, int x)
{
	for (int i = 0; i<curr.size(); i++)
	if (curr[i] == x)
		return i;
	return -1;
}
#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<climits>
//#include<set>

using namespace std;

int minval;
int findpos(vector<int> &curr, int x);
int helper(map<int, int> &v, vector<int> &curr);
bool judge(vector<int> &curr);

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		minval = INT_MAX;
		int n;
		int temp;
		cin >> n;
		vector<int> nums(n);
		map<int, int> v;
		for (int i = 0; i<n; i++)
		{
			//考虑元素序号即可
			cin >> temp;
			nums[i] = i;
		}
		for (int i = 0; i<n; i++)
		{
			cin >> v[i];
		}
		vector<int> curr(nums.begin(), nums.end());
		while (next_permutation(curr.begin(), curr.end()))
		{
			if (judge(curr))
				minval = min(minval, helper(v, curr));
		}
		cout << minval << endl;
	}
	return 0;
}

bool judge(vector<int> &curr)
{
	for (int i = 0; i < curr.size(); i++)
	{
		if (curr[i] == i)
			return false;
	}
	return true;
}

int helper(map<int, int> &v, vector<int> &curr)
{
	int val = 0;
	for (int i = 0; i<curr.size(); i++)
	{
		val += v[i] * abs(i - findpos(curr, i));
	}
	return val;
}

int findpos(vector<int> &curr, int x)
{
	for (int i = 0; i<curr.size(); i++)
	if (curr[i] == x)
		return i;
	return -1;
}
