#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

int main(){
	string str, sta;
	cin >> str >> sta;
	string temp;
	int start = 0, end = 0;
	while (end != sta.size())
	{
		if (sta[end] == '[')
		{
			string s = sta.substr(start, end - start);
			start = end + 1;
			end++;
			if (str == s)
			{
				while (sta[end] != ']')
				{
					if (sta[end] == '=')
					{
						start = end + 1;
						end++;
					}
					else if (sta[end] == ',')
					{
						string s = sta.substr(start, end - start);
						cout << s << " ";
						start = end + 1;
						end++;
					}
					else
						end++;
				}
				string s = sta.substr(start, end - start);
				cout << s << " ";
				cout << endl;
			}
		}
		else if (sta[end] == ',')
		{
			start = end + 1;
			end++;
		}
		else
			end++;
	}
	return 0;
}
