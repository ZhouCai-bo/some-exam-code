#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int find(vector<vector<int>> &map, int d, int x, int y);

int main()
{
    int n, d, maxval = 0;
    cin>>n>>d;
    vector<vector<int>> map(n, vector<int>(n));
    for(auto &a: map)
        for(auto &b: a)
            cin>>b;
    for(int i=0; i<n ;i++)
        for(int j=0; j<n; j++)
            maxval = max(maxval, find(map, d, i, j));
    cout<<maxval;
    return 0;
}

int find(vector<vector<int>> &map, int d, int x, int y)
{
    int maxval = 0;
    if(y + d <= map[0].size())
    {
        int num = 0, i = 0;
        while(i<d)
        {
            num += map[x][y + i];
            i++;
        }
        maxval = max(maxval, num);
    }
    if(x + d <= map.size())
    {
        int num = 0, i = 0;
        while(i<d)
        {
            num += map[x + i][y ];
            i++;
        }
        maxval = max(maxval, num);
    }
    if(x + d <= map.size() && y + d <= map[0].size())
    {
        int num = 0, i = 0;
        while(i<d)
        {
            num += map[x + i][y + i];
            i++;
        }
        maxval = max(maxval, num);
    }
    if(x + d <= map.size() && y - d >= -1)
    {
        int num = 0, i = 0;
        while(i<d)
        {
            num += map[x + i][y - i];
            i++;
        }
        maxval = max(maxval, num);
    }
    return maxval;
}
