#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<cmath>

using namespace std;

int main(){
	int n;
	cin >> n ;
	vector<int> x(n);
	vector<int> y(n);
	for (int i = 0; i < n; i++)
		cin >> x[i] >> y[i];
	//初始化长度
	int curr = 0, minVal = INT_MAX;
	sort(x.begin(), x.end());
	for (auto a : x)
		curr += (a - x[0]);
	for (int i = 1; i < n; i++)
	{
		curr = curr + i*(x[i] - x[i - 1]) - (n - i)*(x[i] - x[i - 1]);
		minVal = min(minVal, curr);
	}
	cout << minVal;
	system("pause");
	return 0;
}
 
