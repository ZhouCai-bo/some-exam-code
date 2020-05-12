#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>

using namespace std;

int main() {
	vector<int> vec{ 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15 };
	priority_queue<int, vector<int>, greater<int>> pq(vec.begin(), vec.begin() + 10);
	for (int i = 10; i < vec.size(); i++)
	{
		if (vec[i] > pq.top())
		{
			pq.push(vec[i]);
			pq.pop();
		}
	}
	while (!pq.empty())
	{
		cout << pq.top() << " ";
		pq.pop();
	}
		
	return 0;
}
