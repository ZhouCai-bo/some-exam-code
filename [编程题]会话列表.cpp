#include<iostream>
#include<vector>
#include<set>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        vector<int> mes(n);
        vector<int> res;
        set<int> cache;
        for(auto &a: mes)
            cin>>a;
        for(int i = mes.size() - 1; i>=0; i--)
        {
            if(cache.find(mes[i]) == cache.end())
            {
                cache.insert(mes[i]);
                res.push_back(mes[i]);
            }
        }
        for(auto a: res)
            cout<<a<<" ";
        cout<<endl;
    }
    
    return 0;
}
