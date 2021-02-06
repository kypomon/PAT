//PAT A1025
#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
#include<string.h>
using namespace std;
struct student
{
	char id[6];
	int C;
	int c_rank;
	int M;
	int m_rank;
	int E;
	int e_rank;
	int A;
	int a_rank;
}stu[2010];
bool cmpC(student a, student b)
{
	if (a.C != b.C) return a.C > b.C;//�����Ӵ�С
	else return strcmp(a.id, b.id)<0;//id��֤��С����
}
bool cmpM(student a, student b)
{
	if (a.M != b.M) return a.M > b.M;//�����Ӵ�С
	else return strcmp(a.id, b.id)<0;//id��֤��С����
}
bool cmpA(student a, student b)
{
	if (a.A != b.A) return a.A > b.A;//�����Ӵ�С
	else return strcmp(a.id, b.id)<0;//id��֤��С����
}
bool cmpE(student a, student b)
{
	if (a.E != b.E) return a.E > b.E;//�����Ӵ�С
	else return strcmp(a.id, b.id)<0;//id��֤��С����
}
int main()
{
	int N, M;
	scanf("%d", &N);
	scanf("%d", &M);
	//����ѧ������
	for (int i = 0; i < N; i++)
	{
		scanf("%s %d %d %d", stu[i].id, &stu[i].C, &stu[i].M, &stu[i].E);
		//����ƽ����A;
		stu[i].A = (stu[i].C + stu[i].M + stu[i].E) / 3;
	}
	//�ֱ�ͳ�Ƹ��������rank
	sort(stu, stu + N, cmpC);
	int r = 1;
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && stu[i].C != stu[i - 1].C)
		{
			r = i + 1;
		}
		stu[i].c_rank = r;
	}

	sort(stu, stu + N, cmpM);
	 r = 1;
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && stu[i].M != stu[i - 1].M)
		{
			r = i + 1;
		}
		stu[i].m_rank = r;
	}

	sort(stu, stu + N, cmpE);
	r = 1;
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && stu[i].E != stu[i - 1].E)
		{
			r = i + 1;
		}
		stu[i].e_rank = r;
	}

	sort(stu, stu + N, cmpA);
	r = 1;
	for (int i = 0; i < N; i++)
	{
		if (i > 0 && stu[i].A != stu[i - 1].A)
		{
			r = i + 1;
		}
		stu[i].a_rank = r;
	}

	//�������rank
	for (int i = 1; i <= M; i++)
	{
		char ID[6];
		scanf("%s", ID);
		bool judge = false;

		for (int j = 0; j < N; j++)
		{
			
			if ( strcmp(stu[j].id, ID) == 0 )
			{
				judge = true;//
				if (stu[j].a_rank <= stu[j].c_rank && stu[j].a_rank <= stu[j].m_rank && stu[j].a_rank <= stu[j].e_rank)
					cout << stu[j].a_rank << " A";
				else
					if(stu[j].c_rank <= stu[j].m_rank && stu[j].c_rank<=stu[j].e_rank)
						cout<< stu[j].c_rank << " C";
					else
						if(stu[j].m_rank<=stu[j].e_rank)
							cout << stu[j].m_rank << " M";
						else
							cout<< stu[j].e_rank << " E";
				break;
			}
			
		}

		if (judge != true)
		{
			cout << "N/A";
		}

		cout << endl;
	}

	//system("pause");
	return 0;
}
