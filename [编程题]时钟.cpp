#include<iostream>
#include<string>

using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--)
    {
        string str;
        cin>>str;
        int h, m, s;
        h = stoi(str.substr(0,2));
        m = stoi(str.substr(3,2));
        s = stoi(str.substr(6,2));
        if(h>=24)
        {
            h %= 10;
        }
        if(m>=60)
        {
            m %= 10;
        }
        if(s>=60)
        {
            s %= 10;
        }
    if(h<10)
        cout<<"0";
    cout<<h<<":";
    if(m<10)
        cout<<"0";
    cout<<m<<":";
    if(s<10)
        cout<<"0";
    cout<<s<<endl;
    }

    return 0;
}
