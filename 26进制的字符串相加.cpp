void func()
	{
		string str1, str2;
		cin >> str1 >> str2;
		stack<int> num1, num2, res;
		for (int i = 0; i < str1.size(); i++)
			num1.push(str1[i] - 'a');
		for (int i = 0; i < str2.size(); i++)
			num2.push(str2[i] - 'a');
		int carry = 0;
		while (!num1.empty() || !num2.empty())
		{
			int x, y;
			if (num1.empty())
				x = 0;
			else
			{
				x = num1.top();
				num1.pop();
			}
			if (num2.empty())
				y = 0;
			else
			{
				y = num2.top();
				num2.pop();
			}
			res.push((x + y) % 26 + carry);
			carry = (x + y) / 26 ? 1 : 0;
		}
		while (!res.empty())
		{
			char ch = res.top() + 'a';
			res.pop();
			cout << ch;
		}
	}
