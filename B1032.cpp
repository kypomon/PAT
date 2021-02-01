//pat乙级1032 挖掘机技术哪家强
#include<iostream>
#include<string>
#include <iomanip> 
using namespace std;

int main()
{
	int N;
	cin >> N;
	int dataset[100001] = { 0 };
	int schoolnum=1;
	for (int i = 0; i <= N - 1; i++)
	{

		int a, b;
		cin >> a >> b;
		dataset[a] += b;
		if (schoolnum < a)schoolnum = a;
	}
	int winner,winnerscore=0;
	for (int i = 1; i <= schoolnum; i++)
	{
		if (dataset[i] > winnerscore)
		{
			winnerscore = dataset[i];
			winner = i;
		}
	}
	cout << winner << " " << winnerscore;
	system("pause");
	return 0;
}

