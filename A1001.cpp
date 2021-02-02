//patA1001
#include<iostream>
#include<string>
using namespace std;

int main()
{
	int a, b;
	cin >> a >> b;
	int c;
	c = a + b;
	string s = to_string(c);
	if(s[0]=='-')
	for (int i = 0; i < s.length(); i++)
	{
		cout << s[i];
		if ( i!= 0 && i != s.length() - 1 && i % 3 == (s.length()-1)%3 )
		{
			cout << ",";
		}
	}
	else
	{
		for (int i = 0; i < s.length(); i++)
		{
			cout << s[i];
			if ( i != s.length() - 1 && (i+1) % 3 == s.length()%3)
			{
				cout << ",";
			}
		}
	}
	//system("pause");
	return 0;
}

