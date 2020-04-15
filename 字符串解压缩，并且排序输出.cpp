void func()
	{
		vector<node> res;
		string str;
		cin >> str;
		int index = 0;
		string temp = "";
		while (index < str.size())
		{
			char ch = str[index];
			if (isalpha(ch))
				temp += str[index++];
			else
			{
				int start = index, end = start;
				while (end<str.size() && isdigit(str[end]))
					end++;
				index = end;
				res.push_back(node(temp, stoi(str.substr(start, end - start))));
				temp = "";
			}
			//index++;
		}
		sort(res.begin(), res.end(), 
			[](const node &n1, const node &n2){return n1.cnt != n2.cnt ? (n1.cnt < n2.cnt) : n1.str > n2.str; }
			);
		for (node n : res)
		{
			for (int i = 0; i < n.cnt; i++)
				cout << n.str;
		}
	}
