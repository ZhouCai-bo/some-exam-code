#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;

int maxVal = 0;

void recurse(vector<vector<int>> &card, unordered_set<int> cache, int chance, int curr);

int main()
{
	int n;
	cin >> n;
	vector<vector<int>> card(n, vector<int>(2));
	for (auto &ele : card)
	{
		cin >> ele[0] >> ele[1];
	}
	sort(card.begin(), card.end(),
		[](const vector<int> &v1, const vector<int> &v2){return v1[0] > v2[0]; }
	);
	recurse(card, unordered_set<int>(), 1, 0);
	cout << maxVal;
	system("pause");
	return 0;
}

void recurse(vector<vector<int>> &card, unordered_set<int> cache, int chance, int curr)
{
	if (chance == 0)
	{
		maxVal = max(maxVal, curr);
		return;
	}
	for (int i = 0; i<card.size(); i++)
	{
		if (cache.count(i) == 0)
		{
			cache.insert(i);
			recurse(card, cache, chance - 1 + card[i][1], curr + card[i][0]);
			cache.erase(i);
		}
	}

}
