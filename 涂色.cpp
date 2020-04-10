#include<iostream>
#include<vector>

using namespace std;

void recurse(vector<vector<int>> &map, vector<int> col, int x, int y);

bool tag = false;

int main(){
	int n, m, c;
	cin >> n >> m >> c;
	vector<int> col(c);
	for (auto &a: col)
	{
		cin >> a;
	}
	vector<vector<int>> map(n, vector<int>(m, -1));
	recurse(map, col, 0, 0);
	cout << (tag ? "YES" : "NO");
	system("pause");
	return 0;
}

void recurse(vector<vector<int>> &map, vector<int> col, int x, int y)
{
	if (tag) return;
	if (y >= map[0].size())
	{
		y = 0;
		x++;
	}
	if (x >= map.size())
	{
		tag = true;
		return;
	}
	for (int i = 0; i < col.size(); i++)
	{
		if (y - 1<0 || (col[i] > 0 && map[x][y - 1] != i))
		if (x - 1<0 || (col[i] > 0 && map[x - 1][y] != i))
		{
			map[x][y] = i;
			col[i]--;
			recurse(map, col, x, y + 1);
			col[i]++;
			map[x][y] = -1;
		}
	}
}
