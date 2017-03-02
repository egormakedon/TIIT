#include <iostream>
#include <fstream>
using namespace std;

struct st {
	char s1[1000];
	int i;
}a[1000],b[1000];

int main()
{
	ifstream f1("1.txt");

	int p, i, j,k,l,xx,yy,kk,kol,h,kol12,I,U;
	char x,y;
	char st1[1000],st2[1000];
	bool q[1000];
	bool a11[1000];

	i = 0;
	while (true)
	{
		f1 >> x;
		if (x == '|') break;
		i++;
		st1[i] = x;
	}
	xx = i;


	i = 0;
	while (true)
	{
		f1 >> y;
		if (y == '|') break;
		i++;
		st2[i] = y;
	}
	yy = i;



	
	
	p = 2;//запоминание позиции ,
	j = 1;//дл€ перечислени€ элементов множества
	k = 0;//кол-во элементов 1-го множества
	kol = 0;
	for (i = 2; i < xx; i++)
	{
		if ((st1[i] == '{') || (st1[i] == '<')) kol++;
		if ((st1[i] == '}') || (st1[i] == '>')) kol--;
		if ((st1[i] == ',') && (kol==0))
		{
			k++;
			l = 0;
			for (j = p; j < i; j++)
			{
				l++;
				a[k].s1[l] = st1[j];
			}
			a[k].i = l;
			p = i + 1;
		}
	}

	k++;
	l = 0;
	a[k].i = 0;
	for (j = p; j < xx; j++)
	{
		l++;
		a[k].s1[l] = st1[j];
		a[k].i++;
	}
	
		

	p = 2;//запоминание позиции ,
	j = 1;//дл€ перечислени€ элементов множества
	kk = 0;//кол-во элементов 1-го множества
	kol = 0;
	for (i = 2; i < yy; i++)
	{
		if ((st2[i] == '{') || (st2[i] == '<')) kol++;
		if ((st2[i] == '}') || (st2[i] == '>')) kol--;
		if ((st2[i] == ',')&&(kol==0))
		{
			kk++;
			l = 0;
			for (j = p; j < i; j++)
			{
				l++;
				b[kk].s1[l] = st2[j];
			}
			b[kk].i = l;
			p = i + 1;
		}
	}

	kk++;
	l = 0;
	b[kk].i = 0;
	for (j = p; j < yy; j++)
	{
		l++;
		b[kk].s1[l] = st2[j];
		b[kk].i++;
	}


	for (i = 1; i <= kk; i++)
		q[i] = false;
	
	cout << "{";
	for (i = 1; i <= k; i++)
	{
		kol = 0;
		for (j = 1; j <= kk; j++)
		{
			kol12 = 0;
			if (a[i].i == b[j].i) kol12++;

			if (kol12 == 1)
			{
				for (I = 1; I <= b[j].i; I++)
					a11[I] = false;

				
				for (I = 1; I <= a[i].i; I++)
				{
					for (U = 1; U <= b[j].i;U++)
						if ((a[i].s1[I] == b[j].s1[U]) && (a11[U] == false))
						{
							a11[U] = true;
							break;
						}
				}

				kol12 = 0;
				for (I = 1; I <= b[j].i; I++)
					if (a11[I] == true) kol12++;

				if (kol12==b[j].i)	kol12 = 2;
				else kol12 = 1;
			}
			
			if ((kol12==2) && (q[j] == false))
			{
				kol++;
				q[j] = true;
				break;
			}
		}

		if (kol == 0)
		{
			for (h = 1; h <= a[i].i; h++)
				cout << a[i].s1[h];
			cout << ",";
		}
	}

	cout << "}";	
	
	
	/*for (i = 1; i <= k; i++)
	{
		for (j = 1; j <= a[i].i; j++)
			cout << a[i].s1[j];
		cout << endl;
	}
	
	cout << endl;

	for (i = 1; i <= kk; i++)
	{
		for (j = 1; j <= b[i].i; j++)
			cout << b[i].s1[j];
		cout << endl;
	}*/
	
	f1.close();
	return 0;
}