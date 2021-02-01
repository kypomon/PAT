//pat¼×¼¶1002
#include<iostream>
#include<string
#include <iomanip> 
using namespace std;


struct polynomial
{
	int K;
	int exponent;
	float coefficient;
	polynomial* next;
};

void creatpoly(polynomial* poly)
{
	cin >> poly->K;
	polynomial* p;
	p = poly;
	for (int i = 0; i < poly->K ; i++)
	{
		polynomial*temp = new polynomial();
		cin >> temp->exponent >> temp->coefficient;
		p->next = temp;
		p = temp;

	}
	p->next = NULL;
}

void showpoly(polynomial* poly)
{
	polynomial* temp;
	temp = poly;
	temp = temp->next;
	int K = poly->K;
	cout << K;
	while (temp!=NULL)
	{
		
		cout << " " << temp->exponent << " " << temp->coefficient;
		temp = temp->next;
	}
}

void addpoly(polynomial*A, polynomial*B)
{
	polynomial*C = new polynomial();
	C->K = 0;
	polynomial* cp = C;
	polynomial* p, *q;
	
	p = A->next;
	q = B->next;
	
	while (p != NULL && q != NULL)
	{
		polynomial* temp = new polynomial();
		C->K++;

		if(p->exponent==q->exponent)
		{
			temp->coefficient = p->coefficient + q->coefficient;
			temp->exponent = p->exponent;
	
			p = p->next;
			q = q->next;

		}
		else
			if(p->exponent>q->exponent)
			{
				temp->exponent = p->exponent;
				temp->coefficient = p->coefficient;
				p = p->next;
			}
			else
			{
				temp->exponent = q->exponent;
				temp->coefficient = q->coefficient;
				q = q->next;
			}
		if (temp->coefficient != 0)
		{
			cp->next = temp;
			cp = cp->next;
		}
		else
			C->K--;

	}
	while (p != NULL)
	{
		C->K++;
		polynomial* temp = new polynomial();
		temp->exponent = p->exponent;
		temp->coefficient = p->coefficient;
		p=p->next;
		cp->next = temp;
		cp = cp->next;

	}
	while (q != NULL)
	{
		C->K++;
		polynomial* temp = new polynomial();
		temp->exponent = q->exponent;
		temp->coefficient = q->coefficient;
		q = q->next;
		cp->next = temp;
		cp = cp->next;

	}

	showpoly(C);
}

int main()
{
	polynomial*A=new polynomial();
	polynomial*B = new polynomial();
	creatpoly(A);
	creatpoly(B);
	//showpoly(A);
	//showpoly(B);
	addpoly(A,B);

	//system("pause");
	return 0;
}

