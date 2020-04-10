#include<iostream>
#include<vector>
#include<string>

using namespace std;

int main(){
    vector<int> val(26);
    for(auto &a : val)
        cin>>a;
    string str;
    cin>>str;
    int len = 0, row = 1;
    for(int i=0; i<str.size(); i++)
    {
        if(len + val[str[i] - 'a'] <= 100)
            len += val[str[i] - 'a'];
        else
        {
            row++;
            len = val[str[i] - 'a'];
        }
    }
    cout<<row<<" "<<len;
    return 0;
}
