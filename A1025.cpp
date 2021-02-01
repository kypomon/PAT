//pat甲级 1025 PAT Ranking 
//我这个代码有点问题，有两个测试点过不了。
#include<iostream>
#include<string>
#include<string.h>
using namespace std;

struct testee
{
	int K=0;
	char regnum[15];//
	int score=0;
	int finalrank=0;//
	int localrank=0;//
	int locationnum=0;//
	testee*next = NULL;
	testee*front = NULL;
};

void creatAgroup(testee* loca, int locanum) 
{
	cin >> loca->K;
	testee* p = loca;//当前操作指针
	for (int i = 0; i < loca->K; i++)
	{
		//cout << i;
		testee* temp = new testee();
		cin >> temp->regnum;
		cin >> temp->score;
		temp->locationnum = locanum;
		
		//p指针前移
		
		while (temp->score > p->score || (temp->score == p->score && strcmp(temp->regnum, p->regnum) < 0))
		{
			if(p->front!=NULL)
				p = p->front;
			else
			{
				break;
			}
		}
		
		//插入节点,temp插入到p节点的后面
		temp->next = p->next;
		if(p->next!=NULL)
		p->next->front = temp;
		p->next = temp;
		temp->front = p;
		while (p->next != NULL)p = p->next;//将指针p调整至队列尾部
		
	}
	//local rank
	int localrank = 1;
	p = loca->next;
	while (p != NULL)
	{
		/*p->localrank = localrank;
		if (p->next != NULL && p->next->score != p->score)
		{
			localrank++;
		}
		p = p->next;*/

		if(p->front!=NULL && p->score == p->front->score )
			
				p->localrank = p->front->localrank;
			
			
		else 
		{
			p->localrank = localrank;
			
		}
		localrank++;
		p = p->next;
	}
}

void showgroup(testee*loca)
{
	testee*p = loca;
	cout << p->K << endl;
	p = p->next;
	while (p != NULL)
	{
		cout << p->regnum << " " <<p->finalrank<<" "<< p->locationnum << " " << p->localrank<<endl;
		p = p->next;
	}
}

//list2合并到list1上
void mergegroup(testee*list1,testee*list2)
{
	list1->K = list1->K + list2->K;
	
	testee* p1 = list1->next;
	testee* p2 = list2->next;

	while (p2 !=NULL)
	{
		//cout << "yes";
		testee* tttp = NULL;
		//查找list1上的插入点
		//cout << "p1指针代号为：" << p1->regnum << endl;
		while (p1!= NULL && ( p1->score > p2->score || (p1->score == p2->score && strcmp(p1->regnum, p2->regnum) < 0) ) )
		{
			//cout << "ok";
			tttp = p1;
			p1 = p1->next;
			
		}
		//cout << "p1指针代号为：" << p1->regnum << endl;
		//cout << "p1前面指针代号为：" << p1->front->regnum << endl;
		//cout << "jump!";
		//临时指针
		testee * tp = p2->next;
		if (p1 != NULL)
		{
			//插入位置为p1前面的节点
			p2->next = p1;
			p2->front = p1->front;
			p1->front->next = p2;
			p1->front = p2;

			
		}
		else
		{
			//说明list2链的后继部分可以直接拼接到list1上
			p2->front = tttp;
			tttp->next = p2;
			//跳出循环
			break;
			

		}
		//指针重置，p1重置为list第一个节点
		//p2后移一位
		p1 = list1->next;
		p2 = tp;
	}
	
	//finalrank
	int finalrank = 1;
	p1 = list1->next;
	while (p1 != NULL)
	{
		

		if (p1->front != NULL && p1->score == p1->front->score)

			p1->finalrank = p1->front->finalrank;


		else
		{
			p1->finalrank = finalrank;

		}
		finalrank++;
		p1 = p1->next;
	}

}
int main()
{
	int N;
	cin >> N;

	testee* testgroup1 = new testee();
	creatAgroup(testgroup1, 1);
	if (N == 1)
	{
		testee*p = testgroup1;
		cout << p->K << endl;
		p = p->next;
		while (p != NULL)
		{
			cout << p->regnum << " " << p->localrank << " " << p->locationnum << " " << p->localrank << endl;
			p = p->next;
		}
	}
	else {
		for (int i = 1; i < N; i++)
		{
			testee* testemp = new testee();
			creatAgroup(testemp, i + 1);
			mergegroup(testgroup1, testemp);
		}
		showgroup(testgroup1);
	}
	//system("pause");
	return 0;
}

