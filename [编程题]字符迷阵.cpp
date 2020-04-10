#include<iostream>
#include<vector>
#include<string>

using namespace std;

int find(vector<vector<char>> &map, string str, int x, int y);

int main(){
	int t;
	cin >> t;
	while (t--)
	{
		int m, n, cnt = 0;
		cin >> m >> n;
		string str;
		vector<vector<char>> map(m, vector<char>(n));
		for (auto &a : map)
		for (auto &b : a)
			cin >> b;
		cin >> str;
		for (int i = 0; i<m; i++)
		for (int j = 0; j<n; j++)
			cnt += find(map, str, i, j);
		cout << cnt << endl;
	}
	return 0;
}

int find(vector<vector<char>> &map, string str, int x, int y)
{
	if (str[0] != map[x][y])
		return 0;
	int cnt = 0;
	int i = 0;
	bool right = true, down = true, tri = true;
	while (i<str.size() && (right || down || tri))
	{
		if (y + i >= map[0].size() || map[x][y + i] != str[i])
		{
			right = false;
		}
		if (x + i >= map.size() ||map[x + i][y] != str[i])
		{
			down = false;
		}
		if ((y + i >= map[0].size() || x + i >= map.size()) || map[x + i][y + i] != str[i])
		{
			tri = false;
		}
		i++;
	}
	return cnt + right + down + tri;
}
