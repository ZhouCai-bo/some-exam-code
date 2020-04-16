#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<string>
#include<set>

using namespace std;

bool contain(string &s1, string &s2);

struct person{
	string name;
	int vote;
	person(string s, int v):name(s),vote(v){}
};

int main(){
	string str;
	cin >> str;
	vector<string> names;
	map<string, int> votes;
	int start = 0, end = 0;
	while (end != str.size())
	{
		if (str[end] == ',')
		{
			string name = str.substr(start, end - start);
			names.push_back(name);
			start = end + 1;
			end++;
		}
		else if (isalpha(str[end]))
			end++;
		else
        {
            cout << "error.0001";
            return 0;
        }
	}
	names.push_back(str.substr(start, end - start));
	for (auto &n : names)
		votes[n]++;
	vector<person> ps;
	for (auto v : votes)
		ps.push_back(person(v.first, v.second));
	sort(ps.begin(), ps.end(),
		[&votes](const person &p1, const person &p2){
		if (p1.vote != p2.vote)
			return p1.vote > p2.vote;
		else if (contain(p1.name, p2.name))
			return p1.name.size() < p2.name.size();
		else
			return p1.name < p2.name ;
	}
	);
	cout << ps[0].name;
	return 0;
}

bool contain(string &s1, string &s2)
{
	if (s1.size() < s2.size())
	{
		string temp = s2;
		s2 = s1;
		s1 = temp;
	}
	for (int i = 0; i<=s1.size() - s2.size(); i++)
	{
		if (s1[i] == s2[0])
        {
            bool tag = true;
            int j = 0;
            while(j < s2.size())
            {
                if(s1[i + j] != s2[j])
                {
                    tag = false;
                    break;
                }
                j++;
            }
            if(tag) return true;
        }
	}
	return false;
}
