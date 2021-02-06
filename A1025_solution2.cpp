//pat甲级 1025 PAT Ranking 
//参考算法笔记上的解决方案
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
struct student
{
	char id[15];
	int score;
	int location_number;
	int local_rank;
} stu[30010];

//sort默认为是升序的
//cmp实现从大到小的排序方法
bool cmp(student a, student b)
{
	if (a.score != b.score) return a.score > b.score;//分数从大到小
	else return strcmp(a.id, b.id)<0;//id保证从小到大
}

int main()
{
	int n, k, num; //num为总考生数
	scanf("%d", &n);//n为考场数
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &k);
		for (int j = 0; j < k; j++)
		{
			scanf("%s %d", stu[num].id, &stu[num].score);
			stu[num].location_number = i;
			num++;
		}

		sort(stu + num - k, stu + num, cmp);
		stu[num - k].local_rank = 1;
		for (int j = num - k + 1; j < num; j++)
		{
			if (stu[j].score == stu[j - 1].score)
				stu[j].local_rank = stu[j - 1].local_rank;
			else
			{
				stu[j].local_rank = j + 1 - (num - k);
			}
		}
	}
	printf("%d\n", num);
	sort(stu, stu + num, cmp);
	int r = 1;
	for (int i = 0; i < num; i++)
	{
		if (i > 0 && stu[i].score != stu[i - 1].score)
		{
			r = i + 1;
		}
		printf("%s ", stu[i].id);
		printf("%d %d %d\n", r, stu[i].location_number, stu[i].local_rank);
	}
	return 0;
	
}