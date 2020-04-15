void func()
	{
		set<char> s1, s2;
		string str1, str2;
		cin >> str1 >> str2;
		for (auto a : str1)
			s1.insert(a);
		for (auto ch : str2)
		{
			if (s2.count(ch))
				continue;
			else if (!s1.count(ch))
			{
				cout << "false";
				return;
			}
		}
		cout << "true";
	}
