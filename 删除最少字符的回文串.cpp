#include<iostream>
#include<vector>
#include<unordered_set>
#include<algorithm>
#include<string>

using namespace std;

int main(){
	string str;
	cin >> str;
	string temp(str);
	reverse(temp.begin(), temp.end());
	int size = str.size();
	vector<vector<int>> dp(size + 1, vector<int>(size + 1));
	for (int i = 0; i <= size; i++)
		dp[0][i] = dp[i][0] = 0;
	for (int i = 1; i <= size; i++)
	{
		for (int j = 1; j <= size; j++)
		{
			if (str[i - 1] == temp[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	cout << size - dp[size][size];
	system("pause");
	return 0;
}

